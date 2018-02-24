#include "ll.h"

/*
 * insert(mylist *head, int val)
 * Inserts val at the tail end of list
 */

void insert(mylist **head, int val) {
	mylist *temp;
	mylist *current;
	
	temp = malloc(sizeof(mylist));
	temp->data = val;
	temp->next = NULL;

	if (*head == NULL) {
		*head = temp;
		return;
	}
	current = *head;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = temp;
}

/*
 * void display(mylist *head)
 * - Displays the list pointed by head pointer
 */
void display(mylist *head) {
	mylist *current;

	current = head;
	while(current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

#if 0
/* Test program for the above libs */
int main() {
	mylist *head = NULL;
	
	insert(&head, 10);
	insert(&head, 1);
	insert(&head, 30);
	insert(&head, 20);
	display(head);
	return 0;
}
#endif
