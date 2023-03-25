#include <stdlib.h>
#include <stdio.h>

#include "bitvector.h"
/*
 *makes functions to operate within a vector using bitwise operators
 *
 *
 *author: Abraham Austin
 *
 */
/*
 *helper function to get the number of bytes in using the given number of bits
 *@param: number of bits
 *@return: returns the number of bytes
 */
int
numBytes(int size)
{	

	if(size%8 > 0 ){
		return (size/8) + 1;
	}
	return size/8;

}
/*
 *function to make a bit_vector struct
 *initializes the size and the array
 *@param: takes the number of bits
 *@return: returns the bit_vector struct
 *
 */
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
/*
 *Removes the data allocated for the vector and the bit_vector
 *@param bit_vector
 *
 */
void
bv_destroy(struct bit_vector *v)
{
	free(v->vector);
	free(v);
	
	
}
/*
 *Checks if the vector contains a bit
 *@param: takes a bit_vector and the bit
 *@return: returns true or false
 *
 */
int
bv_contains(struct bit_vector *v, int i)
{
	
	int byte = v->vector[i/8];
	unsigned char mask = 1<<(i%8);

	if((byte&mask) > 0){return 1;}
	else{return 0;}
}
/*
 *Inserts a new bit in place of another
 *@param bit_vector and the bit
 *
 */
void
bv_insert(struct bit_vector *v, int i)
{

	int byte = v->vector[i/8];
	unsigned char mask = 1<<(i%8);
	v->vector[i/8] = byte|mask;
 	


	
}
/*
 *Removes the a bit from the vector
 *@param bit_vector and the bit
 *
 */
void
bv_remove(struct bit_vector *v, int i)
{

	int byte = v->vector[i/8];
	unsigned char mask = ~(1<<(i%8));
	v->vector[i/8] = byte&mask;
}
/*
 *Makes new bit_vector and makes a vector that is the opposite of the original
 *@param: takes 2 bit_vectors
 *@return: returns the bit_vector
 *
 */
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
/*
 *Makes new bit_vector and makes a vector a combination of the two given vectors
 *@param: takes 2 bit_vectors
 *@return: returns the bit_vector
 *
 */
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
/*
 *Makes new bit_vector and makes a vector that is overlapping values of the two vectors
 *@param: takes two bit_vectors
 *@return: returns the bit_vector
 *
 */
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
/*
 *Makes new bit_vector and makes a vector that has the values 
 *of the first vector that don't overlap with the values of the second
 *@param: takes two bit_vectors
 *@return: returns the bit_vector
 *
 */
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

