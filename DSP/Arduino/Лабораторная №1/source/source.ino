#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

#define ctsPin  6// пин для епкостного датчика касания

LiquidCrystal_I2C lcd(0x3f, 16, 2);

// RFID
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance
//MFRC522 rfid(SS_PIN, RST_PIN); 
//MFRC522::MIFARE_Key key;  
byte rightNuid[4]={0x90, 0xF7, 0xB0, 0x56};
byte wrongNuid[4];

int greenLedPin = 2; 
int redLedPin = 3;      

int inputPin = 4;     
int pirState = LOW;   
int val = 0;     

int piezoPin = 5;     
 
void setup() 
{ 
  pinMode(greenLedPin, OUTPUT);     
  pinMode(redLedPin, OUTPUT);
  pinMode(inputPin, INPUT);    

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Security system");

  Serial.begin(9600);
  SPI.begin();
//  rfid.PCD_Init();  
  
  mfrc522.PCD_Init();
}

void testLed()
{
  digitalWrite(greenLedPin, HIGH);  
  delay(500);                      
  digitalWrite(redLedPin, HIGH);   
  delay(500);                    
  digitalWrite(greenLedPin, LOW);   
  delay(500);               
  digitalWrite(redLedPin, LOW);   
  delay(500);  
}

void view_data (byte *buf, byte size) 
{
  for (byte j = 0; j < size; j++) 
  {
    Serial.print(buf [j]);
    Serial.print(buf [j], HEX);
  }
}

void loop()
{
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

      lcd.clear();
      lcd.print("Access granted");
      
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      noTone(piezoPin);
            Serial.println();
            delay(2 vc  000);
      
    }
  }
  else
  {
    digitalWrite(redLedPin, LOW);
  }
 digitalWrite(greenLedPin, LOW);
}
