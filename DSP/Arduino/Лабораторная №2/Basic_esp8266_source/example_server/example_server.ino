#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>


// SPI setup
#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;     // Configurable, see typical pin layout above

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;

String tag;

int val;               // Переменная для считывания состояния PIR
int inputPin = A0;     // Пин подключения датчика
int ctsPin = 4;        // пин для епкостного датчика касания
int piezoPin = 5;     // Пин для пищалки

// Replace with your network credentials
const char* ssid = "хохохаза";
const char* password = "aaaaoooo";

float s = 0.0;
float m = 0.0;
float r = 0.0;

float movement = 0;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
unsigned long previousMillis = 0;

// Updates DHT readings every 10 seconds
const long interval = 10000;
const char index_html[] PROGMEM = R"rawliteral(
  <!DOCTYPE HTML>
  <html>
    <head>
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
      <style>
        html {
          font-family: Arial;
          display: inline-block;
          margin: 0px auto;
          text-align: center;
        }
        h2 { font-size: 3.0rem; }
        p { font-size: 3.0rem; }
        .units { font-size: 1.2rem; }
        .dht-labels{
          font-size: 1.5rem;
          vertical-align:middle;
          padding-bottom: 15px;
       }
      </style>
    </head>
    <body>
      <h2>ESP8266 security systems</h2>
      <p>
        <i class="fas fa-shield-alt" style="color:#808000;"></i>
        <span class="dht-labels">Security status</span>
        <span id="security_status">%SECURITY_STATUS%</span>
        <sup class="units">&deg;C</sup>
      </p>
      <p>
        <i class="fas fa-compress-arrows-alt" style="color:#FF00FF;"></i>
        <span class="dht-labels">Movement</span>
        <span id="movement">%MOVEMENT%</span>
        <sup class="units">&deg;C</sup>
      </p>
      <p>
        <i class="fas fa-id-card" style="color:#00add6;"></i>
        <span class="dht-labels">Rfid card</span>
        <span id="rfid_card">%RFID_CARD%</span>
        <sup class="units">&deg;C</sup>
      </p>
    </body>
    <script>
    
      setInterval(function ( ) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) 
          {
            document.getElementById("security_status").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "/security_status", true);
        xhttp.send();
      }, 1000 ) ;
      
      setInterval(function ( ) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) 
          {
            document.getElementById("movemen").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "/movemen", true);
        xhttp.send();
      }, 1000 ) ;

      setInterval(function ( ) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) 
          {
            document.getElementById("rfid_card").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "/rfid_card", true);
        xhttp.send();
      }, 1000 ) ;

      
    </script>
  </html> 
)rawliteral";

// Replaces placeholder with DHT values
String processor(const String& var) 
{
  //Serial.println(var);
  if(var == "SECURITY_STATUS")
  {
    return String(s);
  }
  else if(var == "MOVEMENT")
  {
    return String(m);
  }
  else if(var == "RFID_CARD")
  {
    return String(r);
  }
  return String();
}

void setup()
{
  pinMode(inputPin,INPUT); 

  
  Serial.begin(115200);

  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println(".");
  }
  // Print ESP8266 Local IP Address
  Serial.println(WiFi.localIP());
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/html", index_html, processor);
  });
  
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", String(s).c_str());
  });
  
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", String(m).c_str());
  });

  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", String(r).c_str());
  });
  
  server.begin();
}

void loop() 
{
  // PIR block
  movement = analogRead(inputPin);
//  Serial.println(val);
  delay(500); 
  if (movement > 100)
  {
    s = 1;
    m = 1;
    tone(piezoPin, 2000);
     Serial.println("Зафиксированно движение!!");
     // Button block
     if (digitalRead(ctsPin)==HIGH)
     {
        Serial.println("Кнопка нажата!!!");
        // RFID BLOCK
        delay(500);
        if ( ! rfid.PICC_IsNewCardPresent())
          return;
        if (rfid.PICC_ReadCardSerial()) 
        {
          for (byte i = 0; i < 4; i++) 
          {
            tag += rfid.uid.uidByte[i];
          }
        }
        Serial.println(tag);
        if (tag == "14424717686") 
        {
          noTone(piezoPin);
          s = 0;
          r = 1;
           m = 0;
          Serial.println("Правильный ключ!!");
          movement = 0;
          delay(10000);
        }
        if (tag == "221227218217") 
        {
          r = 0;
          Serial.println("Неправильный ключ!!");
        }
        tag = "";
        rfid.PICC_HaltA();
        rfid.PCD_StopCrypto1();
       
     }
  }
}
