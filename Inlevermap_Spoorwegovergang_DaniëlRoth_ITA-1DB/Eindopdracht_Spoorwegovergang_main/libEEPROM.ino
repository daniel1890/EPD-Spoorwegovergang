/*
 * EEPROM library 
 * bevat functies voor interactie met het EEPROM geheugen
 * Daniël Roth
 * 13-03-2022
 */
 
#include <EEPROM.h>

byte EEPROMlees(int adres)
{
  return EEPROM.read(adres);
}

void EEPROMschrijf(int adres, byte waarde)
{
  // Gebruik update omdat deze de waarde van het adres overschrijft wanneer het een nieuw waarde verkrijgt
  EEPROM.update(waarde, adres);
}
