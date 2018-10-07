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

QNode* QInitNode(int Value){
	QNode *New = (QNode*)malloc(sizeof(QNode));

	New->Link = NULL;
	New->Value = Value;
	return New;
}

void LInsert(QNode **Front, QNode **Rear, int Value) {
	QNode *New = QInitNode(Value);

	if (*Rear == NULL) {
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
		printf("\n4. Exit\n");

		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			printf("\nEnter element :");
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
