#include <stdio.h>
#include "stack.h"

int main(){
	int bit, n;

	stack S = initstack();

	scanf("%d", &n);

	while(n){
		bit = n & 1;
		n >>= 1;
		push(S, bit);
	}

	while(!empty(S)){
		printf("%d", pop(S));
	}printf("\n");

	return 0;
}