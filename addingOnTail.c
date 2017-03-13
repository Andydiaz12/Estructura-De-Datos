#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next;
}Tnodo, *ptrNodo;

ptrNodo MakeNodo(int);
void printfLint(ptrNodo);

int main(){
	ptrNodo top, tail, new;
	int n;

	while(scanf("%d", &n) && n != 0){
		new = MakeNodo(n);
		if(top == NULL)
			top = new;
		else
			tail -> next = new;
		tail = new;
	}

	printfLint(top);

	return 0;
}

ptrNodo MakeNodo(int n){
	ptrNodo new = (ptrNodo) malloc(sizeof(Tnodo));
	new -> num = n;
	new -> next = NULL;
	return new;
}

void printfLint(ptrNodo top){
	while(top != NULL){
		printf("%d\n", top -> num);
		top = top -> next;
	}
}