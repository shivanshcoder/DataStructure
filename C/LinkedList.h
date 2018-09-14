#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct tagnode {
	int Val;
	struct tagnode* Link;
}Node;

void InsertBeg(Node** Start, int Value) {
	Node* New = (Node*)malloc(sizeof(Node));
	New->Val = Value;
	New->Link = NULL;

	if (*Start == NULL) {
		*Start = New;
		return;
	}
	New->Link = *Start;
	(*Start) = New;

}

void InsertEnd(Node** Start, int Value) {
	Node* New = (Node*)malloc(sizeof(Node));
	Node* Temp = *Start;

	New->Val = Value;
	New->Link = NULL;

	if (*Start == NULL) {
		*Start = New;
		return;
	}

	while (Temp->Link) {
		Temp = Temp->Link;
	}

	Temp->Link = New;

}


void DeleteBeg(Node **Start) {
	Node *Temp = *Start;
	*Start = (*Start)->Link;

	free(Temp);
}

void DeleteEnd(Node **Start) {
	Node *Temp = *Start;
	Node *Save = *Start;

	if (*Start == NULL) {
		printf("Underflow");
		return;
	}

	while (Temp->Link) {
		Save = Temp;
		Temp = Temp->Link;
	}
	(Save)->Link = NULL;

	free(Temp);
}

void DeleteVal(Node **Start, int Value) {
	Node *Temp = *Start;
	Node *Save = *Start;
	while (Temp->Link && Temp->Val != Value) {
		Save = Temp;
		Temp = Temp->Link;
	}

	if (Temp->Link == NULL)
		*Start = NULL;
	else {
		Save->Link = (Temp->Link);
	}

	free(Temp);
}

void InsertMenu(Node **Start) {
	int choice;
	int Value;
	printf("\n\n1. Insert at Beginning");
	printf("\n2. Insert at End");
	scanf("%d", &choice);

	printf("\n Enter the Element");
	scanf("%d", &Value);


	switch (choice) {
	case 1: {
		InsertBeg(Start, Value);
	}
			break;

	case 2: {
		InsertEnd(Start, Value);
	}
			break;
	}
}

void DeleteMenu(Node **Start) {

	int choice;
	int Value;

	printf("\n\n1. Delete at Beginning");
	printf("\n2. Delete at End");
	printf("\n3. Delete Value");
	scanf("%d", &choice);

	switch (choice) {
	case 1: {
		DeleteBeg(Start);
	}
			break;

	case 2: {
		DeleteEnd(Start);
	}
			break;

	case 3: {

		printf("\nEnter the Value to Delete");
		scanf("%d", &Value);

		DeleteVal(Start, Value);
	}
			break;
	}
}

void LinkedListPrint(Node *Start) {
	printf("\nArray\n");
	while (Start) {
		printf("%d  ", Start->Val);
		Start = Start->Link;
	}
}

void LinkedListMenu() {
	Node *Start = NULL;
	int choice;

	while (1) {
		printf("\n\LinkedList Operation!");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Print List");
		printf("\n4. Exit");

		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			InsertMenu(&Start);
		}
				break;

		case 2: {
			DeleteMenu(&Start);
		}
				break;

		case 3: {
			LinkedListPrint(Start);
		}
				break;

		case 4:
			exit(0);
		}

	}
}
