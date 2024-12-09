#include "index.h"
#include <stdio.h>
#include <stdlib.h>

void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t * skorowidz ) {
	int i;
	skorowidz->ile_slow= argc-2;
	skorowidz->slowa = malloc( skorowidz->ile_slow * sizeof * skorowidz->slowa );
	//skorowidz->licznik = malloc( skorowidz->ile_slow * sizeof * skorowidz->licznik );	//wartosci licznikow zapisuaj sie w strukturze
	//skorowidz->vec = malloc(sizeof(struct dyn_vec2D)); 
   	//skorowidz->vec->tab = malloc(argc * sizeof(int *));	malloci sa zrobione w init_dyn_vec2D
  
	skorowidz->vec = init_dyn_vec2D(argc);
	for( i= 2; i < argc; i++ ) {
    skorowidz->slowa[i-2]= argv[i];
    //skorowidz->licznik[i-2]= 0;	//to nie potrzebne bo mamy jedna strukture a nie kilka list
		//skorowidz->linie[i-2]= NULL;
  }
}

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia) {
	skorowidz->vec->counter[i]++;
	//zamiast skorowidz dodaj lista to od i to add to dynamic vector			
	skorowidz->vec = add_to_dyn_vec2D(skorowidz->vec, i, linia);		//zamienione na add_to_vec
}

void wypisz_skorowidz( skorowidz_t *skorowidz ) {
  int i;
	//nie wypisuj z listy tylko z tablicy 
  for( i= 0; i < skorowidz->ile_slow; i++ ) {
    if( skorowidz->vec->counter[i] > 0 ) {
	int numkd = 0;
      	printf( "słowo \"%s\" wystąpiło w liniach:", skorowidz->slowa[i] );
      	for(int j = 0; j <= skorowidz->vec->counter[i]; j++)		//while( skorowidz->vec->tab[i][numkd] != NULL, tab[i][numkd] to int wiec nie mozna porownywac z NULL, 
	{
        	printf( " %d", skorowidz->vec->tab[i][numkd] );
		numkd++;
	}
      printf( "\n" );
    } else {
      printf( "nie napotkano słowa \"%s\"\n", skorowidz->slowa[i] );
    }
  }
}
