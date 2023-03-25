#include <stdio.h>
#include <stdlib.h>

#include "bitvector.h"
/*
 *author: Abraham Austin
 *uses the functions created in bitvector.c to filter through all the prime
 *numbers till a given number
*/
int
main(void)
{
	int n, i, j;
	int isFirst = 1;
	struct bit_vector *vec;

	printf("Enter max int-> ");
	scanf("%d", &n);

	vec = bv_create(n + 1);

	//inserts into the vector
	for(i = 2; i<=n; i++){
		bv_insert(vec, i);

	}	

	//filters through the array by removing the multiples
	for(j = 2; j<n; j++){
		for(i = j+1; i<=n; i++){
			if (i%j == 0){
				bv_remove(vec, i);
			}
	
		}
	}
	//prints the vector after filtering it
	printf("Vec = {");
	for(i = 2; i<=n; i++){
		if (bv_contains(vec, i)) {
			if (!isFirst)
				printf(", ");
			printf("%d", i);
			isFirst = 0;
		}
	}
	printf("}\n");	
	bv_destroy(vec);
	

	return 0;
}
