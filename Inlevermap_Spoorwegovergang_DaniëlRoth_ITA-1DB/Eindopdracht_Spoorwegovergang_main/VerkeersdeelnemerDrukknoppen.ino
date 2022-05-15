/*
 * Module om de verkeersdeelnemer drukknoppen in te abstraheren
 * Daniël Roth
 * 06-04-2022
 */

// CONSTANTE WAARDES OM MEE TE VERWIJZEN NAAR DE RICHTINGEN
const int N = 0;
const int Z = 1;

boolean verkeersdeelnemerDrukknopNoordIngedrukt()
{
  return buttonRememberedClick(N);
}

boolean verkeersdeelnemerDrukknopZuidIngedrukt()
{
  return buttonRememberedClick(Z);
}

void verkeersdeelnemerDrukknopNoordResetHasEvent()
{
  buttonResetClickHasEvent(N);
}

void verkeersdeelnemerDrukknopZuidResetHasEvent()
{
  buttonResetClickHasEvent(Z);
}
