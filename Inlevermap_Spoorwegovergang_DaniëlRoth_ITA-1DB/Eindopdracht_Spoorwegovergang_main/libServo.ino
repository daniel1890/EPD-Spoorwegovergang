/*
 * Servo library om de servo mee te besturen
 * Gebruikte libraries: Servo
 * Daniël Roth
 * 02-04-2022
 */

#include <Servo.h>
 
const int SERVOPIN = 3;
const int WAIT = 25;

unsigned long prev;

int positie = servoMin();
int richting = 1;

Servo servo;

void servoSetup() 
{
  prev = 0 - WAIT;
  servo.attach(SERVOPIN);
}

void servoMove(int newPositie) 
{
  if (millis() >= prev + WAIT) 
  {
    prev = millis();
    if (newPositie > positie) 
    {
      positie = positie + 1;
    } else if  (newPositie < positie) 
    {
      positie = positie - 1;
    } else 
    {
      //
    }

    servo.write(positie);
  }
}

int servoGetPos()
{
  return positie;
}

int servoMin()
{
  return 15;
}

int servoMax()
{
  return 165;
}
