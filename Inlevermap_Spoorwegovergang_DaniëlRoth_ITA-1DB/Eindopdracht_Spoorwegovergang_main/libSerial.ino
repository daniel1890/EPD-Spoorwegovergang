/*
 * Serial library met functies om de serial monitor te benaderen
 * Daniël Roth
 * 02-11-2022
 */

void serialSetup(long baud)
{
  Serial.begin(baud);
}

char serialRead()
{
  if (Serial.available() > 0)
  {
    char tekst = Serial.read();
    Serial.println(tekst);
    return tekst;
  }
}

void serialFlush() 
{
  while (Serial.available()) 
  {
    Serial.read();
  }
}
