#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next;
}Tnodo, *ptrNodo;

ptrNodo MakeNodo(int n){
	ptrNodo New = (ptrNodo) malloc(sizeof(Tnodo));
	New -> num = n;
	New -> next = NULL;
	return New;
}

void printList(ptrNodo top){
	while(top != NULL){
	printf("%d\t", top -> num);
	top = top -> next;
	}
}
int main(){	
	ptrNodo top = NULL, New;
	int n;

	while(scanf("%d", &n) && n != 0){
		New = MakeNodo(n);
		New -> next = top;
		top = New;
	}
	printList(top);
system("PAUSE");

	return 0;
}