#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

#include "dyn_vec2D.h"
#include "index.h"

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB

int main(int argc, char **argv) 
{
  	int i;
  	int nr_linii;
  	char buf[BUFSIZE];

  	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : NULL;

	skorowidz_t skorowidz;

	if( in == NULL )
	{
    		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
    		return EXIT_FAILURE;
  	}

  	if(argc == 2) 
	{
    		fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;

  	}

	zainicjuj_skorowidz(argc, argv, &skorowidz);

  	nr_linii= 0;
  	while( fgets( buf, BUFSIZE, in ) != NULL ) 
  	{
		nr_linii++;
    		for(i = 0; i < skorowidz.ile_slow; i++ )
		{
			
			bool found = true;
			char *temp = buf;
			char *str = skorowidz.slowa[i];
			

			while(found)
			{
				if(strstr(temp, skorowidz.slowa[i]) != NULL && strstr(temp, skorowidz.slowa[i]) != buf)
      				{
					char *temp2 = strstr(temp, skorowidz.slowa[i]);
					temp = strstr(temp, skorowidz.slowa[i]);
					temp--;

					if(((temp[strlen(str)+1] == ' ' || temp[strlen(str)+1] == '\n' || temp[strlen(str)+1] == ',' || temp[strlen(str)+1] == '.') && temp[0] == ' '))
					{
						dodaj_pozycje_skorowidza(&skorowidz, i, nr_linii);
						found = false;
					}

					else	
						temp += 2;
				}

				else if(strstr(temp, skorowidz.slowa[i]) != NULL && strstr(temp, skorowidz.slowa[i]) == buf)
				{
					if(temp[strlen(str)] == ' ')
					{
						dodaj_pozycje_skorowidza(&skorowidz, i, nr_linii);
						found = false;
					}

					else
						temp++;

				}

				else
					found = false;		
			}
		}
  	}

  	wypisz_skorowidz( &skorowidz );

	free(skorowidz.slowa);
	free_dyn_vec2D(skorowidz.vec, argc);
	fclose(in);

  	return EXIT_SUCCESS;
}
