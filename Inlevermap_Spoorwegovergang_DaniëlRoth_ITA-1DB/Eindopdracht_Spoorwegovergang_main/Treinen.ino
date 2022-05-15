/* Treinen Module
   Dit tabblad bevat functies die de "treinen" op de juiste manier laat functioneren.
   Daniël Roth
   03-04-2022
*/

// CONSTANTE WAARDES OM MEE TE VERWIJZEN NAAR DE RICHTINGEN
const int O = 2;
const int W = 3;

int laatsteRichting;

boolean treinGedecteerd()
{
  if (buttonRememberedClick(W))
  {
    laatsteRichting = W;
    rememberedClicks[W] = true;
  }
  else if (buttonRememberedClick(O))
  {
    laatsteRichting = O;
    rememberedClicks[O] = true;
  }
  else {
    return false;
  }

  return true;
}

boolean treinGepasseerd()
{
  if ((button_Clicked(W) && laatsteRichting == O ) ||
      (button_Clicked(O) && laatsteRichting == W))
  {
    rememberedClicks[W] = false;
    rememberedClicks[O] = false;
    return true;
  }

  return false;
}

void treinResetHasEvent()
{
  buttonResetClickHasEvent(O);
  buttonResetClickHasEvent(W);
}
