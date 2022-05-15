/*
   Patronen library
   Daniël Roth
   02-04-2022
   BITMAP PATRONEN 0 t/m 9
   H = HIGH, L = LOW
   0 = A - H, B - H, C - H, D - H, E - H, F - H, G - L, DP - L, 0b11111100,
   1 = A - L, B - H, C - H, D - L, E - L, F - L, G - L, DP - L  0b01100000,
   2 = A - H, B - H, C - L, D - H, E - H, F - L, G - H, DP - L  0b11011010,
   3 = A - H, B - H, C - H, D - H, E - L, F - L, G - H, DP - L  0b11110010,
   4 = A - L, B - H, C - H, D - L, E - L, F - H, G - H, DP - L  0b01100110,
   5 = A - H, B - L, C - H, D - H, E - L, F - H, G - H, DP - L  0b10110110,
   6 = A - H, B - L, C - H, D - H, E - H, F - H, G - H, DP - L  0b10111110,
   7 = A - H, B - H, C - H, D - L, E - L, F - L, G - L, DP - L  0b11100000,
   8 = A - H, B - H, C - H, D - H, E - H, F - H, G - H, DP - L  0b11111110,
   9 = A - H, B - H, C - H, D - H, E - L, F - H, G - H, DP - L  0b11110110,
   L = A - L, B - L, C - L, D - H, E - H, F - H, G - L, DP - L  0b00011100
*/

byte patronenSevenSegment0Tot10[] =
{
  0b11111100,
  0b01100000,
  0b11011010,
  0b11110010,
  0b01100110,
  0b10110110,
  0b10111110,
  0b11100000,
  0b11111110,
  0b11110110,
};

byte patronenSevenSegmentL = 0b00011100;

byte patronenGetSevenSegment0Tot10(int index)
{
  return patronenSevenSegment0Tot10[index];
}

byte patronenGetSevenSegmentL()
{
  return patronenSevenSegmentL;
}
