#include <Wire.h> 
#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = 5;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = 4;     // Configurable, see typical pin layout above
constexpr uint8_t ctsPin = 6;

int greenLedPin = 3; 
int redLedPin = 4;  

int inputPin = 9;     
int pirState = LOW;   
int val = 0;    

int piezoPin = 16;     

MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];

void setup() { 
  pinMode(greenLedPin, OUTPUT);     
  pinMode(redLedPin, OUTPUT);
  pinMode(inputPin, INPUT);   
   
  Serial.begin(115200);
  SPI.begin(); // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  Serial.println(F("This code scan the MIFARE Classsic NUID."));
  Serial.print(F("Using the following key:"));
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
}
 
void loop() {

  val = digitalRead(inputPin);  

  if (val == HIGH)
  {
    digitalWrite(redLedPin, HIGH);
    
    
    tone(piezoPin, 2000); 
    if (digitalRead(ctsPin)==HIGH)
    {
     // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
      }

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
      }
      Serial.println(F("**Card Detected:**"));
      mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid)); //dump some details about the card


      
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      noTone(piezoPin);
            Serial.println();
            delay(2000);
      
    }
  }
  else  
  {
    digitalWrite(redLedPin, LOW);
  }
 digitalWrite(greenLedPin, LOW);
}


/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
 * Helper routine to dump a byte array as dec values to Serial.
 */
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
