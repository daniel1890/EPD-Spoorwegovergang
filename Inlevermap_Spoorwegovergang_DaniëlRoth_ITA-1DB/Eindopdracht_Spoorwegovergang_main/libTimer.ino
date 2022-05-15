/*
 * Timerlibrary geschreven om software timers makkelijker te declareren
 * Daniël Roth
 * ITA-1DB
 * 15-02-2022
 */

unsigned long timerSetup(unsigned long timer)
{
  timer = 0;
  return timer;
}

unsigned long timerReset() 
{
  return millis();
}

boolean timerIntervalVoorbij(unsigned long timer, unsigned long interval) 
{
  unsigned long currentMillis  = millis();
  if (currentMillis - timer >= interval)
  {
    return true;
  }
  else return false;
}
