void setup()
{
  serialSetup(9600);          // setup serial op 9600 baud
  servoSetup();               // setup servomotor
  shiftRegisterSetup();       // setup shiftregister
  displaySetup();             // setup display
  buzzerSetup();              // setup buzzer
  buttonHardware_Setup();     // setup buttons hardware
  button_Setup();             // setup buttons statemachines
  spoorweg_Setup();           // setup statemachine
}

void loop()
{
  button_Loop();              // loop over button statemachines
  bepaalStates();             // bepaal a.d.h.v. een statemachine de state van het hoofdprogramma
}
