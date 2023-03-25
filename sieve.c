#include <stdio.h>

#include "bitvector.h"

int
main(void)
{
	int n, i, j;
	struct bit_vector *vec;

	printf("Enter max int-> ");
	scanf("%d", &n);

	vec = bv_create(n + 1);

	for(i = 0; i<n; i++){
		bv_insert(vec, i);

	}	

	for(j = 0; j<n; j++){
		for(i = 0; i<n; i+j){
			if (vec->vector[i]%j == 0){
				bv_remove(vec, i);
			}
	
		}
	}
	printf("Vec = ");
	printVec(vec);

	bv_destroy(vec);
	

	return 0;
}
