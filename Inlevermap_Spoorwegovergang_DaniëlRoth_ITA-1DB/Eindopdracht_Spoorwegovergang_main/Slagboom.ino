/*
   Slagboom module die gebruik maakt van de servoLib module
   Deze module bevat functies om de slagboom mee aan te sturen
   Daniël Roth
   03-04-2022
*/

const int SLAGBOOM_TELLER_ADRES = 0;
byte slagboomTeller = EEPROMlees(SLAGBOOM_TELLER_ADRES);

boolean slagboomGesloten()
{
  return servoGetPos() == servoMin();
}

boolean slagboomGeopend()
{
  return servoGetPos() == servoMax();
}

void slagboomVerhoogTeller()
{
  slagboomTeller++;
  EEPROMschrijf(SLAGBOOM_TELLER_ADRES, slagboomTeller);
  Serial.print("Aantal keren slagboom geopend: ");
  Serial.println(slagboomTeller);
}

void slagboomResetTeller()
{
  if (serialRead() == 'r')
  {
    slagboomTeller = 0;
    EEPROMschrijf(SLAGBOOM_TELLER_ADRES, slagboomTeller);
    serialFlush();
  }
}

void slagboomOpenen()
{
  servoMove(servoMax());
}

void slagboomSluiten()
{
  servoMove(servoMin());
}
