/*
   Display library, bevat functies om de display aan te sturen
   Daniël Roth
   11-02-2022
*/

unsigned long displayTimer = 0;
int displayHuidigGetal;

void displaySetup()
{
  displayClear();
}

void displayClear()
{
  shiftRegisterClear();
  shiftRegisterSet(shiftRegisterGet());
}

void displayL()
{
  shiftRegisterSet(patronenGetSevenSegmentL());
}

void displayNumber(int getal)
{
  shiftRegisterSet(patronenGetSevenSegment0Tot10(getal));
}

void displaySetStartNumberToCountdownFrom(int getal)
{
  displayHuidigGetal = getal;
}

void displayCountdown()
{
  if (timerIntervalVoorbij(displayTimer, 1000))
  {
    if (displayHuidigGetal > 0) {
      displayNumber(displayHuidigGetal);
      displayHuidigGetal--;
    }
    displayTimer = millis();
  }
}
