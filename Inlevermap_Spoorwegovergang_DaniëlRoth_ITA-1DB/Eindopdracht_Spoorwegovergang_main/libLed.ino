/*
   Library om leds mee aan te sturen
   Daniël Roth
   02-04-2022
*/

unsigned long blinkTimer = 0;

void ledOn(int ledNummer)
{
  digitalWrite(ledNummer, HIGH);
}

void ledOff(int ledNummer)
{
  digitalWrite(ledNummer, LOW);
}

void ledBlink(int ledNummer, unsigned long timer, unsigned long interval)
{
  if (timerIntervalVoorbij(timer, interval))
  {
    blinkTimer = millis();
    if (digitalRead(ledNummer) == HIGH) {
      digitalWrite(ledNummer, LOW);
    }
    else if (digitalRead(ledNummer) == LOW) {
      digitalWrite(ledNummer, HIGH);
    }
  }
}
