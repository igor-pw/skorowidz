#include "dyn_vec2D.h"
#include <stdlib.h>

dyn_vec2D_t init_dyn_vec2D(int argc)
{
	dyn_vec2D_t vec = malloc(sizeof *vec);
	vec->tab = malloc(sizeof vec->tab * (argc-2));
	vec->size = malloc(sizeof(int) * (argc-2));
	vec->counter = malloc(sizeof(int) * (argc-2));	
	

	for(int i = 0; i < (argc-2); i++)
	{
		vec->counter[i] = 0;
		vec->size[i] = 4;
		vec->tab[i] = malloc(sizeof(int) * 4);
	}
	return vec;
}

void add_to_dyn_vec2D(dyn_vec2D_t vec, int index, int line) 
{
	if(vec->size[index] == vec->counter[index])
	{
		vec->size[index] *= 2;
		vec->tab[index] = realloc(vec->tab[index], sizeof(int) * vec->size[index]);
	       	vec->tab[index][vec->counter[index]] = line;	
	}		
	
	else
	{
		vec->tab[index][vec->counter[index]] = line;
	}	
}

void free_dyn_vec2D(dyn_vec2D_t vec, int argc)
{
	for(int i = 0; i < argc-2; i++)
		free(vec->tab[i]);

	free(vec->tab);
	free(vec->size);
	free(vec->counter);
	
	free(vec);
}

