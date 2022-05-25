#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static Node_t * createNode(int head) {
	Node_t * node = (Node_t *) malloc(sizeof(node));
	node->head = head;
	node->tail = NULL;
	return node;
}

void push(Node_t * root, int value) {
	Node_t * currentNode = root;
	if (currentNode != NULL) {
		while (currentNode->tail != NULL)//przechodzimy na koniec listy
			currentNode = currentNode->tail;
		currentNode->tail = createNode(value);//dodajemy element
	}
}

void printList(Node_t * root) {
	Node_t * currentNode = root;
	while (currentNode != NULL) {
		printf("%d\n", currentNode->head);
		currentNode = currentNode->tail;
	}
}
  Node_t * createList(unsigned int nodeCount, ...)
{  if(nodeCount==0)
{
	return NULL;
}
    va_list args; //tworzymy typ danych używany przez makra 

	va_start(args,nodeCount);//przekazanie ile bedzie elemntów za pomocą nodeCount;
    Node_t * root = createNode(va_arg(args,int));//tworzymy pierwszy elemnt listy z pierwszym argumentem
	//Node_t * bufor = root;
	for(unsigned int i = 1; i<nodeCount; ++i)//zaczynamy od jeden bo pierwszy element jest utworzony 
	{
       push(root,va_arg(args,int));//tworzymy kolejne elementy listy
	                        
	} 
  va_end(args);

 return root;
}