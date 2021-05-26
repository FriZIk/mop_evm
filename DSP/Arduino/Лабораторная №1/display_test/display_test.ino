// Скетч к обзору модуля RFID RC522
// Вывод UID и типа метки
// 3d-diy.ru
// Подключение библиотек
#include <SPI.h>
#include <MFRC522.h>
// контакты
const int reset = 9;
const int ss = 10;
// Создание экземпляра объекта MFRC522
MFRC522 rider(reset, ss);
void setup() {
// запуск Serial
Serial.begin(9600);
// запуск SPI
SPI.begin();
// инициализация MFRC522
rider.PCD_Init();
}
void loop() {
// Ожидание
if ( ! rider.PICC_IsNewCardPresent())
return;
// чтение
if ( ! rider.PICC_ReadCardSerial())
return;
// вывод данных
Serial.print("UID=");
view_data(rider.uid.uidByte,rider.uid.size);
Serial.println();
Serial.print("type=");
byte piccType = rider.PICC_GetType(rider.uid.sak);
Serial.print(rider.PICC_GetTypeName(piccType));
Serial.println();
delay(1000);
}
// преобразование в HEX
void view_data (byte *buf, byte size) {
for (byte j = 0; j < size; j++) {
Serial.print(buf [j]);
Serial.print(buf [j], HEX);
}
}
