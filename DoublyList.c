#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next, *prev;
}Tnodo, *ptrnodo;

typedef struct DoublyList{
	ptrnodo top, tail;
}DoublyList;

DoublyList inserttop(DoublyList lista, int numero){
	ptrnodo new = (ptrnodo) malloc(sizeof(Tnodo));
	new -> next = NULL;
	new -> prev = NULL;
	new -> num = numero;

	if(lista.top == NULL){
		lista.top=new;
		lista.tail=new;
	}
	else{
		new -> prev = lista.top;
		lista.top -> next = new;
		lista.top = new;
	}
	return lista;
}

void impresion(DoublyList lista){
	printf("\n\nLOS VALORES EN REVERSA!!!!\n\n");
	while(lista.top != NULL){
		printf("%d\n", lista.top->num);
		lista.top = lista.top->prev;
	}

}

void impresion1(DoublyList lista){
	printf("\n\nAHORA VA COMO SE INGRESO!!!!\n\n");
	while(lista.tail != NULL){
		printf("%d\n", lista.tail->num);
		lista.tail = lista.tail->next;
	}
}


int main(){

	int valor;
	DoublyList lista;
	lista.top = NULL;
	lista.tail=NULL;


	while(scanf("%d", &valor) && valor != 0){
		lista=inserttop(lista, valor);
	}
	impresion(lista);
	impresion1(lista);

	return 0;
}