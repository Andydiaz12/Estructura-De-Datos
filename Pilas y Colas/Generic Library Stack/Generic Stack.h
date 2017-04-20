#include <stdlib.h>

typedef struct nodo{
	StackData data;
	struct nodo *next;
}Tnodo, *ptrnodo;

typedef struct stack{
	ptrnodo top;
}Tstack, *stack;

stack initstack(){
	stack s = (stack) malloc(sizeof(Tstack));
	s -> top = NULL;
}

void push(stack s, StackData valor){
	ptrnodo NEW = (ptrnodo) malloc(sizeof(Tnodo));
	NEW -> data = valor;
	NEW -> next = s -> top;
	s -> top = NEW; 
}

StackData pop(stack s){
	if(s -> top == NULL)
		exit(1);
	else{
		ptrnodo temp = s -> top;
		StackData valor = s -> top -> data;
		s -> top = s -> top -> next; 
		free(temp);
		return valor;
	}
}

int empty(stack s){
	if(s -> top == NULL)
		return 1;
	else
		return 0;
}
