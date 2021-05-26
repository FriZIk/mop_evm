void blink()
{
  val = digitalRead(LED_BUILTIN);
  val=!val;
  digitalWrite(LED_BUILTIN,val);  
  Serial.println("Hello Buddy!!!");
}
