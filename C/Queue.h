#pragma once
#include<stdio.h>
#include<stdlib.h>

int const QueueSize = 10;

void Insert(int Queue[], int Value, int *Front, int *Rear) {
	if (*Front == QueueSize) {
		printf("Overflow");
		return;
	}

	if (*Front == -1) {
		*Rear = 0;
	}
	Queue[++(*Front)] = Value;

}

int Delete(int Queue[], int *Front, int *Rear) {
	if (*Front < *Rear) {
		printf("Underflow");
		return INT_MAX;
	}

	return Queue[(*Rear)++];
}

typedef struct tagnode {
	int Value;
	struct tagnode *Link;
}Node;

void LInsert(Node **Front, Node **Rear, int Value) {
	Node *New = (Node*)malloc(sizeof(Node));


	if (New == NULL) {
		printf("Overflow");
		return;
	}

	New->Link = NULL;
	New->Value = Value;

	if (*Rear == NULL) {
		*Rear = *Front = New;
	}
	else {
		(*Front)->Link = New;
		*Front = New;
	}
}

int LDelete(Node **Front, Node **Rear) {
	Node *Temp = *Rear;
	int val;
	if (Temp == NULL) {
		printf("UnderFlow");
		return;
	}
	val = (*Rear)->Value;
	*Rear = (*Rear)->Link;
	free(Temp);
	return val;
}

void Queueprint(Node* Rear) {
	printf("Queue: ");
	while (Rear) {
		printf("%d  ", Rear->Value);
		Rear = Rear->Link;
	}
}


void QueueMenu() {
	Node *Front = NULL;
	Node *Rear = NULL;
	int Value;
	int choice;
	while (1) {
		printf("\nQueue Menu");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Print");
		printf("\n4. Exit");

		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			printf("\nEnter element");
			scanf("%d", &Value);

			LInsert(&Front,&Rear, Value);
		}
				break;

		case 2: {
			printf("\nElement Deleted %d", LDelete(&Front, &Rear));
		}
				break;

		case 3: {
			Queueprint(Rear);
		}
				break;
		case 4:
			exit(0);
		}
	}
}
