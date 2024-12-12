#ifndef _DYN_VEC2D_H_
#define _DYN_VEC2D_H_

typedef struct dyn_vec2D 
{
	int **tab;
	int *size;
	int *counter;

} *dyn_vec2D_t;

dyn_vec2D_t init_dyn_vec2D(int argc);

void add_to_dyn_vec2D(dyn_vec2D_t vec, int index, int line);

void free_dyn_vec2D(dyn_vec2D_t vec, int argc);

#endif
