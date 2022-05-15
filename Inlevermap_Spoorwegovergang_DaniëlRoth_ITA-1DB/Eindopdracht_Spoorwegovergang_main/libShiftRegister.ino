/*
   Shift register library, bevat functies om de shiftregister te benaderen.
   - De setup functie stelt de inputs in
   - De set functie stuurt een byte naar de shiftregister toe, aan de hand van deze byte worden de bits één voor één
     geschoven in het register, hierna wordt de latch hoog gezet waardoor de outputs op de juiste waarde ingesteld worden
   Daniël Roth
   13-02-2022
*/

byte shiftRegisterByte;

const int DATA_SERIAL_PIN = 8; // (DS) WITTE KABEL, ARDUINO PIN 8 VERBONDEN MET PIN 11
const int LATCH_CLOCK_PIN = 9; // (ST_CP) GROENE KABEL, ARDUINO PIN 9 VERBONDEN MET PIN 12
const int SHIFT_CLOCK_PIN = 10; // (SH_CP) GELE KABEL, ARDUINO PIN 10 VERBONDEN MET PIN 10

void shiftRegisterSetup()
{
  //deze functie initialiseert de drie outputpinnen
  pinMode(DATA_SERIAL_PIN, OUTPUT);
  pinMode(LATCH_CLOCK_PIN, OUTPUT);
  pinMode(SHIFT_CLOCK_PIN, OUTPUT);
}

byte shiftRegisterClear()
{
  //deze functie zet alle acht outputs van het shiftregister op 0 (doe dit met een for-loop)
  for (int i = 0; i < 8; i++)
  {
    shiftRegisterByte &= ~(1 << i);
  }
}

void shiftRegisterSet(byte pattern)
{
  //deze functie zet de acht outputs op het meegegeven bytepatroon
  digitalWrite(LATCH_CLOCK_PIN, LOW);

  for (int i = 0; i < 8; i++)
  {
    digitalWrite(DATA_SERIAL_PIN, pattern & (1 << i));
    digitalWrite(SHIFT_CLOCK_PIN, HIGH);
    digitalWrite(SHIFT_CLOCK_PIN, LOW);
  }

  digitalWrite(LATCH_CLOCK_PIN, HIGH);
}

byte shiftRegisterGet()
{
  return shiftRegisterByte;
}
