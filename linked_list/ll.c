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

void deletenode(mylist **head_ref, int key) {
	// Store head node
	mylist* temp = *head_ref, *prev;

	// If head node itself holds the key or multiple occurrences of key
	while (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;   // Changed head
		free(temp);               // free old head
		temp = *head_ref;         // Change Temp
	}

	// Delete occurrences other than head
	while (temp != NULL)
	{
		// Search for the key to be deleted, keep track of the
		// previous node as we need to change 'prev->next'
		while (temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}

		// If key was not present in linked list
		if (temp == NULL) return;

		// Unlink the node from linked list
		prev->next = temp->next;

		free(temp);  // Free memory

		//Update Temp for next iteration of outer loop
		temp = prev->next;
	}
}

#if __DEBUG__
/* Test program for the above libs */
int main() {
	mylist *head = NULL;
	
	insert(&head, 10);
	insert(&head, 30);
	insert(&head, 20);
	insert(&head, 10);
	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 10);
	display(head);
	deletenode(&head, 10);
	display(head);
	return 0;
}
#endif
