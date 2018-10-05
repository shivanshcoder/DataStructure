#pragma once
#include<stdio.h>
#include<stdlib.h>

extern int const QueueSize = 10;

void Insert(int Queue[], int Value, int *Front, int *Rear) {
	if (*Rear == QueueSize) {
		printf("Overflow");
		return;
	}

	if (*Rear == -1) {
		*Front = 0;
	}
	Queue[++(*Rear)] = Value;

}

int Delete(int Queue[], int *Front, int *Rear) {
	if (*Rear < *Front) {
		printf("Underflow");
		return ;
	}

	return Queue[(*Front)++];
}

typedef struct tagnode {
	int Value;
	struct tagnode *Link;
}QNode;

void LInsert(QNode **Front, QNode **Rear, int Value) {
	QNode *New = (QNode*)malloc(sizeof(QNode));


	//if (New == NULL) {
	//	printf("Overflow");
	//	return;
	//}

	New->Link = NULL;
	New->Value = Value;

	if (*Front == NULL) {
		*Rear = *Front = New;
	}
	else {
		(*Rear)->Link = New;
		*Rear = New;
	}
}

int LDelete(QNode **Front, QNode **Rear) {
	QNode *Temp = *Front;
	int val;

	if (Temp == NULL) {
		printf("UnderFlow");
		return;
	}

	val = (*Front)->Value;
	*Front = (*Front)->Link;

	//if the queue becomes empty
	//if (*Front == NULL)
	//	*Rear = NULL;

	free(Temp);
	return val;
}

void Queueprint(QNode* Front) {
	printf("Queue: ");
	while (Front) {
		printf("%d  ", Front->Value);
		Front = Front->Link;
	}
}


void QueueMenu() {
	QNode *Front = NULL;
	QNode *Rear = NULL;
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
			Queueprint(Front);
		}
				break;
		case 4:
			exit(0);
		}
	}
}
