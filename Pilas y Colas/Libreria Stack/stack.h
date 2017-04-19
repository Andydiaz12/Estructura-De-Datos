#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next;
}Tnodo, *ptrnodo;

typedef struct stack{
	ptrnodo top;
}Tstack, *stack;

stack initstack(){
	stack s = (stack)malloc(sizeof(Tstack));
	s -> top = NULL;
	return s;
}

int empty(stack s){
	if(s -> top == NULL) 
		return 1;
	else
		return 0;
}

int pop(stack s){
	if(empty(s))
		exit(1);
	ptrnodo temp = s -> top;
	int numero = s -> top -> num;
	s -> top = s -> top -> next;
	free(temp);

	return numero;
}

void push(stack s, int numero){
	ptrnodo NEW = (ptrnodo)malloc(sizeof(Tnodo));
	NEW -> num = numero;
	NEW -> next = s -> top;
	s -> top = NEW;
}