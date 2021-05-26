void setup()
{
  Serial.begin(9600);
}

void loop()
{
  read();
  extern const char index_html;
  Serial.println(strlen(index_html)); // 6
  for(int i = 0;i < strlen(index_html);i++)
  Serial.print(index_html[i]);
  Serial.println();
  delay(1000);
}
