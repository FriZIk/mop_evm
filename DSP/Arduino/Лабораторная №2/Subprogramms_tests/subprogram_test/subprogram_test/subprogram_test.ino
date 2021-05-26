#include <Arduino.h>

int val;

void setup() 
{  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  blink(); 
  delay(1000); 
}
