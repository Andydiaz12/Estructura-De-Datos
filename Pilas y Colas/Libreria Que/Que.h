#include <stdlib.h>

typedef struct nodo{
	int numero;
	struct nodo *next;
}Tnodo, *ptrnodo;

typedef struct{
	ptrnodo tail, top;
}Tcola, *cola;

cola initcola(){
	cola c = (cola)malloc(sizeof(Tcola));
	c -> top = c -> tail = NULL;
	return c;
}

void push(cola c, int num){
	ptrnodo NEW = (ptrnodo)malloc(sizeof(Tnodo));
	NEW -> numero = num;
	if(empty(c)){
		c -> top = c -> tail = NEW;
	}
	else{
		c -> tail -> next = NEW;
		c -> tail =NEW;
	}
}

int pop(cola c){		
	if(empty(c))
		exit(1);
	else{
		ptrnodo tempo = c -> top; 
		int temp = c -> top -> numero;		
		c -> top = c -> top -> next;
		free(tempo);
		return temp;
	}	
}

int empty(cola c){
	return (c -> top == NULL);
}