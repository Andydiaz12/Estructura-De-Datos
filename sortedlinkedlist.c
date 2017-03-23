#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int x;
	struct nodo *next;
}Tnodo, *ptrNodo;

ptrNodo MakeNodo(int valor){

	
	ptrNodo new = (ptrNodo) malloc(sizeof(Tnodo)); 
	new->x = valor;
	new->next = NULL;

	return new;
}

ptrNodo insert(ptrNodo top, int valor){
	ptrNodo current, temporal = NULL, new;

	new = MakeNodo(valor);
	current = top;
	while(current != NULL && new->x > current->x){
		temporal = current;
		current = current -> next;
		}

		if(temporal == NULL){
			new->next = top;
			return new;
		}
		else{
			temporal -> next = new;
			new -> next = current;
			return top;
		}
}

void printList(ptrNodo top){
	while(top != NULL){
		printf("%d\n", top->x);
		top=top->next;
	}
}

int main(){

	int numero;
	ptrNodo top = NULL;

	while(scanf("%d", &numero) && numero != 0){
		top = insert(top, numero);
		}
	printList(top);
	return 0;
}
