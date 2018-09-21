#pragma once
#include<stdlib.h>
#include<stdio.h>


typedef struct tagpoint {
	Points status;
	Points *Adjacent;

}Points;

typedef struct tagnode {
	Points Value;
	struct tagnode *Link;
}Node;

void LInsert(Node **Front, Node **Rear, Points Value) {
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

Points LDelete(Node **Front, Node **Rear) {
	Node *Temp = *Rear;
	Points val;
	if (Temp == NULL) {
		printf("UnderFlow");
		return;
	}
	val = (*Rear)->Value;
	*Rear = (*Rear)->Link;
	free(Temp);
	return val;
}


