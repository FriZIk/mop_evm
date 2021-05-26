/*
  Здаание: Тема 1. Охрана дома.
  Данные с входных датчиков отображаются в приложении и подается сигнал на выходные устройства. 
  ользователю в приложении отображаются сообщения о датчиках:
    1. о положении поставленной/снятой сигнализации;
    2. сообщение о том, кто вошел по карточке/ключу;
    3. произошло ли движение.
  Список подключаемых датчиков:
    1. Датчик касания
    2. HC-SR501 (PIR датчик)
    3. RFID МОДУЛЬ RC522 13.56MHZ + КАРТА + БРЕЛОК
    4. Светодиоды
    5. Пьезоизлучатель
*/

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

#define ctsPin  6     // пин для епкостного датчика касания

MFRC522 mfrc522(SS_PIN, RST_PIN);
byte rightNuid[4]={0x90, 0xF7, 0xB0, 0x56};

int greenLedPin = 2;  // Пин для зелёного светодиода
int redLedPin = 3;    // Пин для красного светодиода

int inputPin = 4;     // Для PIR датчика
int pirState = LOW;   // Для хранения состояния
int val = 0;          // Переменная для считывания состояния   

int piezoPin = 5;     // Пин для пищалки

 
// Функция для вывода инфомрации с rfid-метки
void view_data (byte *buf, byte size) 
{
  for (byte j = 0; j < size; j++) 
  {
    Serial.print(buf [j]);
    Serial.print(buf [j], HEX);
  }
}

void setup() 
{ 
  pinMode(greenLedPin, OUTPUT);     
  pinMode(redLedPin, OUTPUT);
  pinMode(inputPin, INPUT);    

  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
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
      // Зацикливаем loop() пока не будет найдена новая карта
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
      }

      // Выбор карточки
      if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
      }

      Serial.println(F("**Card Detected:**"));
      mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid)); 
      
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
