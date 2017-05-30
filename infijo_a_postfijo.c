#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	char valor;
	struct nodo *next;
}Tnodo, *ptrnodo;

typedef struct stack{
	ptrnodo top, tail;	
}Tpila, *ptrpila;

void push(ptrpila s, char Valor){
	ptrnodo new = (ptrnodo) malloc(sizeof(Tnodo));
	new -> valor = Valor;
	new -> next = s -> top;
	s -> top = new;
}

void pop(ptrpila s){
	if(empty(s))
		exit(1);
	else{
		ptrnodo temporal = s -> top;
		s -> top = s -> top -> next;
		free(temporal);
	}
}

ptrpila initstack(){
	ptrpila s = (ptrpila) malloc(sizeof(Tpila));
	s -> top = s -> tail = NULL;
	return s;
}

int empty(ptrpila s){
	return (s -> top == NULL);
}

char top(ptrpila s){
	return (s -> top -> valor);
}

int precedence(char x){
	if(x == '(')
		return 0;
	else if(x == '+' || x == '-')
		return 1;
	else
		return 2;
}

int main(){
	ptrpila stack = initstack();
	char car, resultado[500];
	int i = 0;

	while(scanf("%c", &car) && car != '\n'){
		if(car == ' ')
			continue;
		else if(car >= '0' && car <= '9')
			resultado[i++] = car;
		else if(car == '(')
			push(stack, car);
		else if(car == ')'){
			while(stack -> top -> valor != '('){
				resultado[i++] = stack -> top -> valor;
				pop(stack);
			}
			pop(stack);
		}
		else if(car == '+' || car == '-' || car == '*' || car == '/'){
			while(!empty(stack) && precedence(car) <= precedence(stack -> top -> valor)){
				resultado[i++] = stack -> top -> valor;
				pop(stack);
			}
			push(stack, car);
		}

	}

		while(stack -> top != NULL){
			resultado[i++] = stack -> top -> valor;
			pop(stack);
		}
		resultado[i++] = '\0';

	printf("%s\n", resultado);


	return 0;
		
}