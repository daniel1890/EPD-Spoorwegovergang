/*
   Stoplicht module om de NOORD/ZUID stoplichten mee aan te spreken
   Daniël Roth
   03-04-2022
*/

//   LED PINS PER KANT
const int NOORD_ROOD = 13;
const int NOORD_GEEL = 12;
const int NOORD_GROEN = 11;
const int ZUID_ROOD = 7;
const int ZUID_GEEL = 6;
const int ZUID_GROEN = 5;

unsigned long stoplichtNoordTimer = 0;
unsigned long stoplichtZuidTimer = 0;
boolean noordOn = false;
boolean zuidOn = false;

// Functionaliteit voor het stoplicht wat wijst naar de noordelijke kant //
void stoplichtNoordRoodOn()
{
  ledOn(NOORD_ROOD);
}

void stoplichtNoordRoodOff()
{
  ledOff(NOORD_ROOD);
}

void stoplichtNoordGeelOn()
{
  ledOn(NOORD_GEEL);
}

void stoplichtNoordGeelOff()
{
  ledOff(NOORD_GEEL);
}

void stoplichtNoordGroenOn()
{
  ledOn(NOORD_GROEN);
}

void stoplichtNoordGroenOff()
{
  ledOff(NOORD_GROEN);
}

void stoplichtNoordGeelKnipper()
{
  if (timerIntervalVoorbij(stoplichtNoordTimer, 250))
  {
    stoplichtNoordTimer = millis();

    if (digitalRead(NOORD_GEEL) == HIGH) {
      stoplichtNoordGeelOff();
    }
    else if (digitalRead(NOORD_GEEL) == LOW) {
      stoplichtNoordGeelOn();
    }
  }
}

// Functionaliteit voor het stoplicht wat wijst naar de zuidelijke kant //
void stoplichtZuidRoodOn()
{
  ledOn(ZUID_ROOD);
}

void stoplichtZuidRoodOff()
{
  ledOff(ZUID_ROOD);
}

void stoplichtZuidGeelOn()
{
  ledOn(ZUID_GEEL);
}

void stoplichtZuidGeelOff()
{
  ledOff(ZUID_GEEL);
}

void stoplichtZuidGroenOn()
{
  ledOn(ZUID_GROEN);
}

void stoplichtZuidGroenOff()
{
  ledOff(ZUID_GROEN);
}

void stoplichtZuidGeelKnipper()
{
  if (timerIntervalVoorbij(stoplichtZuidTimer, 250))
  {
    stoplichtZuidTimer = millis();

    if (digitalRead(ZUID_GEEL) == HIGH) {
      stoplichtZuidGeelOff();
    }
    else if (digitalRead(ZUID_GEEL) == LOW) {
      stoplichtZuidGeelOn();
    }
  }
}
