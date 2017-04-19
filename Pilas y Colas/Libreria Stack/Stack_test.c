#include <stdio.h>
#include "stack.h"

int main(){
	int tc, n;

	stack S = initstack();

	scanf("%d", &tc);

	while(tc--){
		scanf("%d", &n);
		push(S, n);
	}

	while(!empty(S)){
		printf("%d ", pop(S));
	}printf("\n");

	return 0;
}