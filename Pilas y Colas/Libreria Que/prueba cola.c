#include <stdio.h>
#include "Que.h"

int main(){

	int num;
	cola c = initcola();

	while(scanf("%d", &num) && num != 0){
		push(c, num);
	}

	while(!empty(c))
		printf("%d\n", pop(c));

	return 0;
}