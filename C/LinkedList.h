#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct tagnode {
	int Val;
	struct tagnode* Link;
}Node;

Node* InitNode(int Value) {
	Node *New = (Node*)malloc(sizeof(Node));
	New->Val = Value;
	New->Link = NULL;

	return New;
}

void InsertBeg(Node** Start, int Value) {
	Node* New = InitNode(Value);

	if (*Start == NULL) {
		*Start = New;
	}
	else {
		New->Link = *Start;
		(*Start) = New;
	}
}

void InsertEnd(Node** Start, int Value) {
	Node* New = InitNode(Value);
	Node* Temp = *Start;


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
	if (*Start == NULL) {
		printf("Underflow");
		return;
	}

	Node *Temp = *Start;
	*Start = (*Start)->Link;

	free(Temp);
}

void DeleteEnd(Node **Start) {

	if (*Start == NULL) {
		printf("Underflow");
		return;
	}

	Node *Temp = *Start;	
	Node *Save = *Start;

	if (Temp->Link == NULL)
		*Start = NULL;
	else {
		while (Temp->Link) {

			Save = Temp;
			Temp = Temp->Link;
		}
		(Save)->Link = NULL;
	}
	free(Temp);
}

void DeleteVal(Node **Start, int Value) {

	if (*Start == NULL) {
		printf("Underflow");
		return;
	}

	Node *Temp = *Start;
	Node *Save = *Start;

	while (Temp && Temp->Val != Value) {
		if (Temp->Link == NULL)
			printf("\nElement not found");
			return ;

		Save = Temp;
		Temp = Temp->Link;

	}

	//if only element of list
	if (Temp->Link == NULL)
		*Start = NULL;

	//if first element is to be deleted
	else if (Temp == Save) {
		*Start = (*Start)->Link;
	}
	else {
		Save->Link = (Temp->Link);
	}

	free(Temp);
}

void ClearList(Node **Start) {
	while (Start) {
		DeleteBeg(Start);
	}
}

void InsertMenu(Node **Start) {
	int choice;
	int Value;
	printf("\n\n1. Insert at Beginning");
	printf("\n2. Insert at End\n");
	scanf("%d", &choice);

	printf("\n Enter the Element :");
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
	printf("\n3. Delete Value\n");
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

		printf("\nEnter the Value to Delete :");
		scanf("%d", &Value);

		DeleteVal(Start, Value);
	}
			break;
	}
}

void LinkedListPrint(Node *Start) {
	printf("\List\n");
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
		printf("\n4. Exit\n");

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
