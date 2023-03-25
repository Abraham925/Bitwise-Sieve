#include <stdlib.h>
#include <stdio.h>

#include "bitvector.h"
int
numBytes(int size)
{	

	if(size%8 > 0 ){
		return (size/8) + 1;
	}
	return size/8;

}

struct bit_vector *
bv_create(int size)
{
	int bytes = numBytes(size);
	struct bit_vector *bv = malloc(sizeof(struct bit_vector));
	bv->size = size;
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
	
	int byte = v->vector[i/8];
	unsigned char mask = 1<<(i%8);

	if((byte&mask) > 0){return 1;}
	else{return 0;}
}

void
bv_insert(struct bit_vector *v, int i)
{
	// or is used in insert
	int byte = v->vector[i/8];
	unsigned char mask = 1<<(i%8);
	v->vector[i/8] = byte|mask;
 	


	
}

void
bv_remove(struct bit_vector *v, int i)
{
	// ~(mask) == ~(1<<i) remove 
	// use &
	int byte = v->vector[i/8];
	unsigned char mask = ~(1<<(i%8));
	v->vector[i/8] = byte&mask;
}

struct bit_vector *
bv_complement(struct bit_vector *v)
{
	int bytes = numBytes(v->size);
	struct bit_vector *x = bv_create(v->size);
	for(int i= 0; i<bytes; i++){
		x->vector[i] = ~(v->vector[i]);
	}
	
	return x;
	
	
}

struct bit_vector *
bv_union(struct bit_vector *v1, struct bit_vector *v2)
{

	int bytes = numBytes(v1->size);
	struct bit_vector *x = bv_create(v1->size);
	for(int i= 0; i<bytes; i++){
		x->vector[i] = v1->vector[i]|v2->vector[i];
	}
	
	return x;
	
}

struct bit_vector *
bv_intersection(struct bit_vector *v1, struct bit_vector *v2)
{
	int bytes = numBytes(v1->size);
	struct bit_vector *x = bv_create(v1->size);
	for(int i= 0; i<bytes; i++){
		x->vector[i] = v1->vector[i]&v2->vector[i];
	}
	
	return x;
}

struct bit_vector *
bv_difference(struct bit_vector *v1, struct bit_vector *v2)
{
	int bytes = numBytes(v1->size);
	struct bit_vector *x = bv_create(v1->size);
	for(int i= 0; i<bytes; i++){
		x->vector[i] = v1->vector[i]&~(v2->vector[i]);
	}

	return x;
}

