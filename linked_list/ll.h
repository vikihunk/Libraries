/*
 * Header file for linked list library
 * Library maintains a simple linked list
 * with operations like insert, delete
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINKS	20

typedef struct mylist {
	int data;
	struct mylist *next;
} mylist;

/* Functions */
void insert(mylist **head, int val);
void display(mylist *head);
