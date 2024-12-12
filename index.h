#ifndef _SKOROWIDZ_H
#define _SKOROWIDZ_H

#include "dyn_vec2D.h"

typedef struct {
	int ile_slow;
	char **slowa;  
	dyn_vec2D_t vec;  	//wskaznik na strukture
} skorowidz_t;
	
void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t *s );

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia);

void wypisz_skorowidz( skorowidz_t *s );

#endif
