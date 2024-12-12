#include "index.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t * skorowidz ) {
	int i;
	skorowidz->ile_slow= argc-2;
	skorowidz->slowa = malloc( skorowidz->ile_slow * sizeof * skorowidz->slowa );
  	skorowidz->vec = init_dyn_vec2D(argc);
	
	for( i= 2; i < argc; i++ ) 
	{
		skorowidz->slowa[i-2] = argv[i];
  	}
}

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia) 
{
	skorowidz->vec->counter[i] += 1;
	add_to_dyn_vec2D(skorowidz->vec, i, linia);
}

void wypisz_skorowidz( skorowidz_t *skorowidz ) 
{
  	int i;
  
  	for( i= 0; i < skorowidz->ile_slow; i++ ) 
	{
    		if( skorowidz->vec->counter[i] > 0 ) 
		{
			int numkd = 0;
      			printf( "słowo \"%s\" wystąpiło w liniach:", skorowidz->slowa[i] );
      			for(int j = 1; j <= skorowidz->vec->counter[i]; j++)		 
			{
        			printf( " %d", skorowidz->vec->tab[i][numkd+1] );
					numkd++;
			}

      			printf( "\n" );

    		} 
		
		else 
		{
      			printf( "nie napotkano słowa \"%s\"\n", skorowidz->slowa[i] );
    		}
  	}
}
