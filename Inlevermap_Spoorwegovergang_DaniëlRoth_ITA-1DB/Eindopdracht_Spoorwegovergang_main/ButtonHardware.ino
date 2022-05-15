// Module ButtonHardware

// Configuratie en uitlezen van de fysieke knop
const int BUTTON_PIN = A0;

const int BUTTON_PINS[N_BUTTONS] = 
{
  A0,
  A1,
  A2,
  A3
};

// --- Setup -------------------
void buttonHardware_Setup() {
  for(int i = 0; i < N_BUTTONS; i++)
  {
    pinMode(BUTTON_PINS[i], INPUT);
  }
}

// --- Events -----------
boolean buttonHardware_Down(int pin) {
  // Pull up resistor used.
  return (digitalRead(BUTTON_PINS[pin]) == LOW);
}

boolean buttonHardware_Up(int pin) {
  return !buttonHardware_Down(pin);
}
