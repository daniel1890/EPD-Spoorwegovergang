/*
   Buzzer library, bevat functies om de piezo buzzer aan te sturen
   Daniël Roth
   13-02-2022
*/

const int BUZZER_PIN = 2;
const int TONE_FREQUENTIE = 250;
unsigned long buzzerTimer = 0;
boolean isOn = false;

void buzzerSetup()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void buzzerBuzz(int toonHoogte)
{
  tone(BUZZER_PIN, toonHoogte);
}

void buzzerOff()
{
  noTone(BUZZER_PIN);
}

void buzzerTik(unsigned long interval)
{
  if (timerIntervalVoorbij(buzzerTimer, interval))
  {
    buzzerTimer = millis();

    if (!isOn) {
      buzzerBuzz(TONE_FREQUENTIE);
    }
    else {
      buzzerOff();
    }

    isOn = !isOn;
  }
}

void buzzerTikDrieMaalSnelMetPauze()
{
  int secondeInMillis = 1000;
  int pauze = secondeInMillis - 400;
  int tikDuratie = 600 / 6;

  if (timerIntervalVoorbij(buzzerTimer, pauze))
  {
    for (int i = 0; i < 6; i++)
    {
      buzzerTik(tikDuratie);
    }
  }
}
