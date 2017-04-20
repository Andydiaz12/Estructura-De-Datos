#include <stdio.h>

typedef struct{
	int bit;
}StackData;

#include "Generic Stack.h"

int main(){
	int numero;
	stack s = initstack();
	StackData temp; 

	while(scanf("%d", &numero) && numero != 0){
		while(numero > 0){
			temp.bit = numero&1;
			push(s, temp);
			numero>>= 1; 
		}

		while(!empty(s))
			printf("%d", pop(s).bit);
		printf("\n");
	}
	return 0;
}