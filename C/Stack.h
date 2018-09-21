#pragma once
#include<stdio.h>
#include<stdlib.h>

extern int const StackSize;

/*Array Implementation*/
void Push(int Stack[], int *Top, int Value) {
	if (*Top == StackSize - 1) {
		printf("Overflow");
		return;
	}

	Stack[++(*Top)] = Value;
}

int Peek(int Stack[], int Top) {
	if (Top == -1) {
		printf("Underflow");
		return ;
	}
	return Stack[Top];
}

int Pop(int Stack[], int *Top) {
	return Peek(Stack, (*Top)--);
}


/*Linked List Implementation*/



typedef struct tagNode {
	int Val;
	struct tagNode *Bottom;

}Node;

void LPush(Node** Top, int Value) {
	Node* New = (Node*)malloc(sizeof(Node));

	if (*Top == NULL) {
		New->Bottom = NULL;
		*Top = New;
	}
	else {
		New->Bottom = (*Top);
	}
	New->Val = Value;
	(*Top) = New;
}

int LPop(Node** Top) {
	Node* old = *Top;
	int Val = old->Val;

	(*Top) = (*Top)->Bottom;
	free(old);
	return Val;
}

   
void Stackprint(Node* Top) {
	printf("Satck: ");
	while (Top) {
		printf("%d  ", Top->Val);
		Top = Top->Bottom;
	}
}

void StackLMenu() {
	Node *Top = NULL;
	int Value;
	int choice;
	while (1) {
		printf("\nStack Menu");
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Print");
		printf("\n4. Exit");

		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			printf("\nEnter element");
			scanf("%d", &Value);

			LPush(&Top, Value);
		}
				break;

		case 2: {
			printf("\nElement popped %d", LPop(&Top));
		}
				break;

		case 3: {
			Stackprint(Top);
		}
				break;
		case 4:
			exit(0);
		}
	}
}

