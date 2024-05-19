#include <stdio.h>
#include <stdbool.h>

struct Node
{
	int value;
	struct Node* next;
} typedef Node;

bool isCircular(Node* head)
{
	Node *tortoise, *hare = tortoise = head;
	while(hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next;
		if(hare->next) hare = hare->next; else break;
		if(tortoise == hare) return true;
	}
	return false;
}

int main()
{
	Node head, body, tail;
	head.value = 5; head.next = &body;
	body.value = 7; body.next = &tail;
	tail.value = 2; tail.next = &head;
	if(isCircular(&head)) printf("Circular\n");
	else printf("Not circular\n");
	return 0;
}
