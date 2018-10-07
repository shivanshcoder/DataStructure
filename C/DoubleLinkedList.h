#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct tagnode{
	int Val;
	struct tagnode* Prev;
	struct tagnode* Next;
}Node;

Node* InitNode(int Value) {
	Node* New = (Node*)malloc(sizeof(Node));
	New->Val = Value;
	New->Next = NULL;
	New->Prev = NULL;

	return New;
}

void InsertBeg(Node** Start, int Value) {
	Node* New = InitNode(Value);

	if (*Start == NULL) {
		*Start = New;
		return;
	}
	New->Next = *Start;
	(*Start)->Prev = New;
	(*Start) = New;

}

void InsertEnd(Node** Start, int Value) {
	Node* New = InitNode(Value);
	Node* Temp = *Start;


	if (*Start == NULL) {
		*Start = New;
		return;
	}

	while (Temp->Next) {
		Temp = Temp->Next;
	}

	Temp->Next = New;
	New->Prev = Temp;

}


void DeleteBeg(Node **Start) {
	if (*Start == NULL) {
		printf("Underflow");
		return;
	}

	Node *Temp = *Start;
	*Start = (*Start)->Next;

	if(*Start != NULL)
		(*Start)->Prev = NULL;
	free(Temp);
}

void DeleteEnd(Node **Start) {
	if (*Start == NULL) {
		printf("Underflow");
		return;
	}

	Node *Temp = *Start;

	while (Temp->Next) {
		Temp = Temp->Next;
	}
	if ((Temp->Prev) == NULL)
		*Start = NULL;
	else
		(Temp->Prev)->Next = NULL;

	free(Temp);
}

void DeleteVal(Node **Start,int Value) {
	if (*Start == NULL) {
		printf("Underflow");
		return;
	}
	Node *ToDelete = *Start;

	while (ToDelete && ToDelete->Val != Value) {
		if (ToDelete->Next == NULL) {
			printf("\nElement not found.");
			return;
		}
		ToDelete = ToDelete->Next;
	}

	if ((ToDelete->Prev == NULL) && (ToDelete->Next == NULL) && ToDelete->Val == Value)
		*Start = NULL;
	else {
		(ToDelete->Prev)->Next = (ToDelete->Next);
		(ToDelete->Next)->Prev = (ToDelete->Prev);
	}
	
	free(ToDelete);
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
	printf("\n3. Delete Value \n");
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
	printf("\nArray\n");
	while (Start) {
		printf("%d  ", Start->Val);
		Start = Start->Next;
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

