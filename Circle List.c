#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next;
}Tnodo, *ptrnodo;

ptrnodo makenodo(int valor){
	ptrnodo new = (ptrnodo) malloc(sizeof(Tnodo));
	new->num = valor;
	new->next = NULL;
	return new;
}

ptrnodo cicle_list(int canguros){
	ptrnodo first, new;
	int i;
	first = new = makenodo(1);
	for(i = 2 ; i <= canguros ; i++){
		new->next = makenodo(i);
		new = new->next;
	}
	new ->next = first;
	return first;
}

ptrnodo game(ptrnodo first, int iteraciones, int canguros){
int i, j;
ptrnodo temp=first, current;
	for(i = 0 ; i < (canguros-1) ; i++){
		for(j = 1 ; j < iteraciones ; j++){
			temp = current;
			current = current -> next;
		}
		temp->next = current -> next;
		free(current);
		current = temp->next;
		
	}
return current;
}

void printresultado(ptrnodo top){
	printf("ganador:\t%d\n", top->num);
}

int main(){
	ptrnodo first;
	int canguros, iteraciones, i;

	printf("Ingresa el numero de canguros y de iteraciones:\t");
	scanf("%d %d", &canguros, &iteraciones);

		first=cicle_list(canguros);

	first=game(first, iteraciones, canguros);
	printresultado(first);


	return 0;
}