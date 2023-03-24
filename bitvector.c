#include <stdlib.h>

#include "bitvector.h"

struct bit_vector *
bv_create(int size)
{
	int bytes = (size + 7)/8;
	struct bit_vector *bv = malloc(sizeof(struct bit_vector));
	unsigned char *vectorArray = calloc(bytes, sizeof(unsigned char));
	bv->vector = vectorArray;


	
	return bv;
}

void
bv_destroy(struct bit_vector *v)
{
	free(v->vector);
	free(v);
	
	
}

int
bv_contains(struct bit_vector *v, int i)
{
	// i is the the bit
	// i/8 is the byte
	// (byte)v->vector[i/8];
	// mask = 1<<i;
	// v->vector[i/8]&mask 
	// ~(mask) == ~(1<<i) remove 
	// or is used in insert
	
}

void
bv_insert(struct bit_vector *v, int i)
{
	
}

void
bv_remove(struct bit_vector *v, int i)
{

}

struct bit_vector *
bv_complement(struct bit_vector *v)
{
	return NULL;
}

struct bit_vector *
bv_union(struct bit_vector *v1, struct bit_vector *v2)
{
	return NULL;
}

struct bit_vector *
bv_intersection(struct bit_vector *v1, struct bit_vector *v2)
{
	return NULL;
}

struct bit_vector *
bv_difference(struct bit_vector *v1, struct bit_vector *v2)
{
	return NULL;
}
