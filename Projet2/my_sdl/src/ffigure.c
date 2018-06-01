/*
 * ffigure.c
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#include "ffigure.h"

#define blanc SDL_MapRGB(affichage->format, 0xFF, 0xFF, 0xFF)

SDL_Surface* affichage;

void setPixel(int x, int y, Uint32 coul)
{
  *((Uint32*)(affichage->pixels) + x + y * affichage->w) = coul;
}

void setPixelVerif(int x, int y, Uint32 coul)
{
  if (x >= 0 && x < affichage->w &&
      y >= 0 && y < affichage->h)
    setPixel(x, y, coul);
}

void barre(int x, int y, int w, int h, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;

  SDL_FillRect(affichage, &r, coul);
}

void ligneHorizontale(int x, int y, int w, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = 1;

  SDL_FillRect(affichage, &r, coul);
}

void ligneVerticale(int x, int y, int h, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = 1;
  r.h = h;

  SDL_FillRect(affichage, &r, coul);
}

void rectangle(int x, int y, int w, int h, Uint32 coul)
{
  ligneHorizontale(x, y, w, coul);
  ligneHorizontale(x, y + h - 1, w, coul);
  ligneVerticale(x, y + 1, h - 2, coul);
  ligneVerticale(x + w - 1, y + 1, h - 2, coul);
}

void effacerEcran(void)
{
  SDL_FillRect(affichage, NULL, blanc);
}

void echangerEntiers(int* x, int* y)
{
  int t = *x;
  *x = *y;
  *y = t;
}

void ligne(int x1, int y1, int x2, int y2, Uint32 coul)
{
  int d, dx, dy, aincr, bincr, xincr, yincr, x, y;

  if (abs(x2 - x1) < abs(y2 - y1)) {
    /* parcours par l'axe vertical */

    if (y1 > y2) {
      echangerEntiers(&x1, &x2);
      echangerEntiers(&y1, &y2);
    }

    xincr = x2 > x1 ? 1 : -1;
    dy = y2 - y1;
    dx = abs(x2 - x1);
    d = 2 * dx - dy;
    aincr = 2 * (dx - dy);
    bincr = 2 * dx;
    x = x1;
    y = y1;

    setPixelVerif(x, y, coul);

    for (y = y1+1; y <= y2; ++y) {
      if (d >= 0) {
	x += xincr;
	d += aincr;
      } else
	d += bincr;

      setPixelVerif(x, y, coul);
    }

  } else {
    /* parcours par l'axe horizontal */

    if (x1 > x2) {
      echangerEntiers(&x1, &x2);
      echangerEntiers(&y1, &y2);
    }

    yincr = y2 > y1 ? 1 : -1;
    dx = x2 - x1;
    dy = abs(y2 - y1);
    d = 2 * dy - dx;
    aincr = 2 * (dy - dx);
    bincr = 2 * dy;
    x = x1;
    y = y1;

    setPixelVerif(x, y, coul);

    for (x = x1+1; x <= x2; ++x) {
      if (d >= 0) {
	y += yincr;
	d += aincr;
      } else
	d += bincr;

      setPixelVerif(x, y, coul);
    }
  }
}

void cercle(int cx, int cy, int rayon, int coul)
{
  int d, y, x;

  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;

  while (y >= x) {
    setPixelVerif(cx + x, cy + y, coul);
    setPixelVerif(cx + y, cy + x, coul);
    setPixelVerif(cx - x, cy + y, coul);
    setPixelVerif(cx - y, cy + x, coul);
    setPixelVerif(cx + x, cy - y, coul);
    setPixelVerif(cx + y, cy - x, coul);
    setPixelVerif(cx - x, cy - y, coul);
    setPixelVerif(cx - y, cy - x, coul);

    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }

    x++;
  }
}

void disque(int cx, int cy, int rayon, int coul)
{
  int d, y, x;

  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;

  while (y >= x) {
    ligneHorizontale(cx - x, cy - y, 2 * x + 1, coul);
    ligneHorizontale(cx - x, cy + y, 2 * x + 1, coul);
    ligneHorizontale(cx - y, cy - x, 2 * y + 1, coul);
    ligneHorizontale(cx - y, cy + x, 2 * y + 1, coul);

    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }

    x++;
  }
}

