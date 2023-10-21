#include <stdio.h>
#include <stdlib.h>


struct node {
	int info;
	struct node* next;
};


struct node* last = NULL;


void insertAtFront(int data)
{
	
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	
	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}

	
	else {
		temp->info = data;
		temp->next = last->next;

		last->next = temp;
	}
}


void viewList()
{
	
	if (last == NULL)
		printf("\nList is empty\n");

	
	else {
		struct node* temp;
		temp = last->next;

	
		do {
			printf("\nData = %d", temp->info);
			temp = temp->next;
		} while (temp != last->next);
	}
}


int main()
{
	
	insertAtFront(10);
	insertAtFront(20);
	insertAtFront(30);


	viewList();

	return 0;
}
