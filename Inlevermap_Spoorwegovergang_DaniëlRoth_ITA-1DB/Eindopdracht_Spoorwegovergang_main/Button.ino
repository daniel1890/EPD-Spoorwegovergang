// Module Button

// --- States -----------
const int BUTTON_STATE_RELEASED = 1;
const int BUTTON_STATE_CHECK_PRESSED = 2;
const int BUTTON_STATE_PRESSED = 3;
const int BUTTON_STATE_CHECK_RELEASED = 4;

// Current state
const int N_BUTTONS = 4;
int button_States[N_BUTTONS] = {};

// Timer variables
const int BUTTON_INTERVAL = 10; // 10 msec
unsigned long button_Previous;

// Click variable
boolean button_Click;
boolean buttons_Click[N_BUTTONS] = {};

// Persistent button click array
boolean rememberedClicks[N_BUTTONS] = {};

// Houdt bij of een button een event heeft, wanneer de knop een event heeft wordt deze indrukking niet onthouden wanneer een event afgehandeld wordt
boolean buttonClickHasEvent[N_BUTTONS] = {};

    //const int N = 0;
    //const int Z = 1;
    //const int O = 2;
    //const int W = 3;


    // --- Setup -------------------
void button_Setup() {
  // Initialize
  //button_Click = false;
  for (int i = 0; i < N_BUTTONS; i++)
  {
    buttons_Click[i] = false;
  }


  // Start state
  for (int i = 0; i < N_BUTTONS; i++)
  {
    button_States[i] = BUTTON_STATE_RELEASED;
  }

  button_Released_Entry();
}

// --- Events -----------
boolean button_Clicked(int directie) {
  // If read, set back to false
  if (buttons_Click[directie] == true) {
    // reset value for click
    buttons_Click[directie] = false;
    return true;
  }
  else {
    return false;
  }
}

boolean buttonRememberedClick(int directie) {
  // If read, set back to false
  if (rememberedClicks[directie] == true) {
    // reset value for click
    rememberedClicks[directie] = false;
    buttonClickHasEvent[directie] = true;
    return true;
  }
  else {
    return false;
  }
}

void buttonResetClickHasEvent(int directie)
{
  buttonClickHasEvent[directie] = false;
}

// --- Loop --------------------
void button_Loop() {
  for (int i = 0; i < 4; i++)
  {
    switch (button_States[i]) {
      case BUTTON_STATE_RELEASED:
        button_Released_Do();
        if (buttonHardware_Down(i) == true) {
          button_Released_Exit();
          button_States[i] = BUTTON_STATE_CHECK_PRESSED;
          button_Check_Pressed_Entry();
        }
        break;
      case BUTTON_STATE_CHECK_PRESSED:
        button_Check_Pressed_Do();
        if (buttonHardware_Up(i) == true) {
          button_Check_Pressed_Exit();
          button_States[i] = BUTTON_STATE_RELEASED;
          button_Released_Entry();
        }
        else if ((buttonHardware_Down(i) == true)
                 && (millis() - BUTTON_INTERVAL >= button_Previous)) {
          button_Check_Pressed_Exit();
          button_States[i] = BUTTON_STATE_PRESSED;
          button_Pressed_Entry();
        }
        break;
      case BUTTON_STATE_PRESSED:
        button_Pressed_Do();
        if (buttonHardware_Up(i) == true) {
          button_Pressed_Exit();
          button_States[i] = BUTTON_STATE_CHECK_RELEASED;
          button_Check_Released_Entry();
        }
        break;
      case BUTTON_STATE_CHECK_RELEASED:
        button_Check_Released_Do();
        if (buttonHardware_Down(i) == true) {
          button_Check_Released_Exit();
          button_States[i] = BUTTON_STATE_PRESSED;
          button_Pressed_Entry();
        }
        else if ((buttonHardware_Up(i) == true)
                 && (millis() - BUTTON_INTERVAL >= button_Previous)) {
          button_Check_Released_Exit();
          button_States[i] = BUTTON_STATE_RELEASED;
          // On this transition the click has occured.
          Serial.print("clicked btn: ");
          Serial.println(i);
          buttons_Click[i] = true;

          if (!buttonClickHasEvent[i])  // negeer button kliks wanneer bijbehorende button een event afhandeld
          {
            rememberedClicks[i] = true;
          }
          button_Released_Entry();
        }
        break;
    }
  }
}

// --- BUTTON_STATE_RELEASED -----------
void button_Released_Entry() {
  // <nothing>
}

void button_Released_Do() {
  // <nothing>
}

void button_Released_Exit() {
  // <nothing>
}

// --- BUTTON_STATE_CHECK_PRESSED -----------
void button_Check_Pressed_Entry() {
  button_Previous = millis();
}

void button_Check_Pressed_Do() {
  // <nothing>
}

void button_Check_Pressed_Exit() {
  // <nothing>
}

// --- BUTTON_STATE_PRESSED -----------
void button_Pressed_Entry() {
  // <nothing>
}

void button_Pressed_Do() {
  // <nothing>
}

void button_Pressed_Exit() {
  // <nothing>
}

// --- BUTTON_STATE_CHECK_RELEASED -----------
void button_Check_Released_Entry() {
  button_Previous = millis();
}

void button_Check_Released_Do() {
  // <nothing>
}

void button_Check_Released_Exit() {
  // <nothing>
}
