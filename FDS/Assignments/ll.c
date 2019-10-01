#include<stdio.h>
#include<stdlib>

struct LinkedList
{
	int data;
	struct LinkedList *next;
};

typedef struct LinkedList *node;
node create()
{
	node temp;
	temp = (node)malloc(sizeof(struct LinkedList));
	temp->next = NULL;
	return temp;
}
