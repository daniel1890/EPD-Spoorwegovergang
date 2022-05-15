/*
   States tabblad van het Spoorwegovergang programma om de huidige toestand mee te bepalen en hiertussen te wisselen
   Daniël Roth
   02-02-2022
*/

const int SPOOR_STATE_IDLE = 0;
const int SPOOR_STATE_OVERSTEKEN_NOORD = 1;
const int SPOOR_STATE_WAARSCHUWING_NOORD = 2;
const int SPOOR_STATE_OVERSTEKEN_ZUID = 3;
const int SPOOR_STATE_WAARSCHUWING_ZUID = 4;
const int SPOOR_STATE_SLUITEN = 5;
const int SPOOR_STATE_PASSEREN = 6;
const int SPOOR_STATE_OPENEN = 7;
const int SPOOR_STATE_VRIJGEVEN = 8;

int spoor_State;
unsigned long spoorwegTimer;

void spoorweg_Setup()
{
  // begin spoorwegtimer op 0;
  timerSetup(spoorwegTimer);

  // Start state
  spoor_State = SPOOR_STATE_IDLE;
  spoor_Idle_Entry();
}

void bepaalStates()
{
  switch (spoor_State)
  {
    case SPOOR_STATE_IDLE:
      spoor_Idle_Do();

      if (treinGedecteerd()) // trein gedecteerd
      {
        spoor_Idle_Exit();
        spoor_State = SPOOR_STATE_SLUITEN;
        spoor_Sluiten_Entry();
      }

      else if (timerIntervalVoorbij(spoorwegTimer, 3000))
      {
        if (verkeersdeelnemerDrukknopNoordIngedrukt()) // knop ingedrukt NOORD
        {
          spoor_Idle_Exit();
          spoor_State = SPOOR_STATE_OVERSTEKEN_NOORD;
          spoor_Oversteken_Noord_Entry();
        }

        else if (verkeersdeelnemerDrukknopZuidIngedrukt()) // knop ingedrukt ZUID
        {
          spoor_Idle_Exit();
          spoor_State = SPOOR_STATE_OVERSTEKEN_ZUID;
          spoor_Oversteken_Zuid_Entry();
        }
      }

      break;

    case SPOOR_STATE_OVERSTEKEN_NOORD:
      spoor_Oversteken_Noord_Do();

      if (timerIntervalVoorbij(spoorwegTimer, 4000) || treinGedecteerd()) // timer voorbij OF treingedecteerd()
      {
        spoor_Oversteken_Noord_Exit();
        spoor_State = SPOOR_STATE_WAARSCHUWING_NOORD;
        spoor_Waarschuwing_Noord_Entry();
      }

      break;

    case SPOOR_STATE_WAARSCHUWING_NOORD:
      spoor_Waarschuwing_Noord_Do();

      if (timerIntervalVoorbij(spoorwegTimer, 2000)) // timer voorbij
      {
        spoor_Waarschuwing_Noord_Exit();
        spoor_State = SPOOR_STATE_IDLE;
        spoor_Idle_Entry();
      }

      break;

    case SPOOR_STATE_OVERSTEKEN_ZUID:
      spoor_Oversteken_Zuid_Do();

      if (timerIntervalVoorbij(spoorwegTimer, 4000) || treinGedecteerd()) // timer voorbij OF treingedecteerd()
      {
        spoor_Oversteken_Zuid_Exit();
        spoor_State = SPOOR_STATE_WAARSCHUWING_ZUID;
        spoor_Waarschuwing_Zuid_Entry();
      }

      break;

    case SPOOR_STATE_WAARSCHUWING_ZUID:
      spoor_Waarschuwing_Zuid_Do();

      if (timerIntervalVoorbij(spoorwegTimer, 2000))
      {
        spoor_Waarschuwing_Zuid_Exit();
        spoor_State = SPOOR_STATE_IDLE;
        spoor_Idle_Entry();
      }

      break;

    case SPOOR_STATE_SLUITEN:
      spoor_Sluiten_Do();

      if (slagboomGesloten()) // slagboomIsGesloten() == true
      {
        spoor_Sluiten_Exit();
        spoor_State = SPOOR_STATE_PASSEREN;
        spoor_Passeren_Entry();
      }

      break;

    case SPOOR_STATE_PASSEREN:
      spoor_Passeren_Do();

      if (treinGepasseerd()) // treinGepasseerd() == true
      {
        spoor_Passeren_Exit();
        spoor_State = SPOOR_STATE_OPENEN;
        spoor_Openen_Entry();
      }

      break;

    case SPOOR_STATE_OPENEN:
      spoor_Openen_Do();

      if (slagboomGeopend()) // slagboomIsGeopend() == true
      {
        spoor_Openen_Exit();
        spoor_State = SPOOR_STATE_VRIJGEVEN;
        spoor_Vrijgeven_Entry();
      }

      break;

    case SPOOR_STATE_VRIJGEVEN:
      spoor_Vrijgeven_Do();

      if (timerIntervalVoorbij(spoorwegTimer, 5000)) // vrijGegeven() == true count down van 5 naar 0
      {
        spoor_Vrijgeven_Exit();
        spoor_State = SPOOR_STATE_IDLE;
        spoor_Idle_Entry();
      }

      break;
  }
}

// --- SPOOR_STATE_IDLE -----------

void spoor_Idle_Entry() {
  spoorwegTimer = timerReset();
  stoplichtNoordRoodOn();
  stoplichtZuidRoodOn();
}

void spoor_Idle_Do() {
  slagboomOpenen();
}

void spoor_Idle_Exit() {
  // <nothing>
}

// --- SPOOR_STATE_OVERSTEKEN_NOORD -----------

void spoor_Oversteken_Noord_Entry() {
  spoorwegTimer = timerReset();
  stoplichtNoordGroenOn();
  stoplichtNoordRoodOff();
}

void spoor_Oversteken_Noord_Do() {
  // <nothing>
}

void spoor_Oversteken_Noord_Exit() {
  stoplichtNoordGroenOff();
}

// --- SPOOR_STATE_WAARSCHUWING_NOORD -----------

void spoor_Waarschuwing_Noord_Entry() {
  spoorwegTimer = timerReset();
  stoplichtNoordGeelOn();
  displaySetStartNumberToCountdownFrom(2);
}

void spoor_Waarschuwing_Noord_Do() {
  displayCountdown();
}

void spoor_Waarschuwing_Noord_Exit() {
  stoplichtNoordGeelOff();
  displayNumber(0);
  verkeersdeelnemerDrukknopNoordResetHasEvent();
}

// --- SPOOR_STATE_OVERSTEKEN_ZUID -----------

void spoor_Oversteken_Zuid_Entry() {
  spoorwegTimer = timerReset();
  stoplichtZuidGroenOn();
  stoplichtZuidRoodOff();
}

void spoor_Oversteken_Zuid_Do() {
  // <nothing>
}

void spoor_Oversteken_Zuid_Exit() {
  stoplichtZuidGroenOff();
}

// --- SPOOR_STATE_WAARSCHUWING_ZUID -----------

void spoor_Waarschuwing_Zuid_Entry() {
  spoorwegTimer = timerReset();
  stoplichtZuidGeelOn();
  displaySetStartNumberToCountdownFrom(2);
}

void spoor_Waarschuwing_Zuid_Do() {
  displayCountdown();
}

void spoor_Waarschuwing_Zuid_Exit() {
  stoplichtZuidGeelOff();
  displayNumber(0);
  verkeersdeelnemerDrukknopZuidResetHasEvent();
}

// --- SPOOR_STATE_SLUITEN -----------

void spoor_Sluiten_Entry() {
  spoorwegTimer = timerReset();
  stoplichtNoordRoodOn();
  stoplichtZuidRoodOn();
}

void spoor_Sluiten_Do() {
  slagboomSluiten();
  buzzerTik(100);
  stoplichtNoordGeelKnipper();
  stoplichtZuidGeelKnipper();
}

void spoor_Sluiten_Exit() {
  buzzerOff();
  stoplichtNoordGeelOff();
  stoplichtZuidGeelOff();
}

// --- SPOOR_STATE_PASSEREN -----------

void spoor_Passeren_Entry() {
  spoorwegTimer = timerReset();
}

void spoor_Passeren_Do() {
  stoplichtNoordGeelKnipper();
  stoplichtZuidGeelKnipper();
}

void spoor_Passeren_Exit() {
  stoplichtNoordGeelOff();
  stoplichtZuidGeelOff();
}

// --- SPOOR_STATE_OPENEN -----------

void spoor_Openen_Entry() {
  spoorwegTimer = timerReset();
}

void spoor_Openen_Do() {
  slagboomOpenen();
  buzzerTik(100);
  stoplichtNoordGeelKnipper();
  stoplichtZuidGeelKnipper();
}

void spoor_Openen_Exit() {
  slagboomVerhoogTeller();
  buzzerOff();
  stoplichtNoordGeelOff();
  stoplichtZuidGeelOff();
}

// --- SPOOR_STATE_VRIJGEVEN -----------

void spoor_Vrijgeven_Entry() {
  spoorwegTimer = timerReset();
  displaySetStartNumberToCountdownFrom(5);
}

void spoor_Vrijgeven_Do() {
  displayCountdown();
  buzzerTikDrieMaalSnelMetPauze();
  stoplichtNoordGeelKnipper();
  stoplichtZuidGeelKnipper();
}

void spoor_Vrijgeven_Exit() {
  buzzerOff();
  stoplichtNoordGeelOff();
  stoplichtZuidGeelOff();
  displayNumber(0);
  treinResetHasEvent();
}
