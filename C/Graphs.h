#pragma once
/*
	This is just for College Data structure File purpose
	BFS Code
*/


#include<stdlib.h>
#include<stdio.h>
#include"Queue.h"
#include"Stack.h"


#ifndef ARRAY_SIZE
#define ARRAY_SIZE 5
#endif



enum STATUS {
	UNVISITED,
	WAITING,
	VISITED
};

typedef struct tagPoint {
	enum STATUS status;
}Point;


//typedef struct tagNode {
//	int Value;
//	struct tagNode *Link;
//}Node;
//
//void LInsert(Node **Front, Node **Rear, int Value) {
//	Node *New = (Node*)malloc(sizeof(Node));
//
//	if (New == NULL) {
//		printf("Overflow");
//		exit(-1);
//	}
//
//	New->Link = NULL;
//	New->Value = Value;
//
//	if (*Rear == NULL) {
//		*Rear = *Front = New;
//	}
//	else {
//		(*Front)->Link = New;
//		*Front = New;
//	}
//}
//
//int LDelete(Node **Front, Node **Rear) {
//	Node *Temp = *Rear;
//	Points val;
//	if (Temp == NULL) {
//		printf("UnderFlow");
//		exit(-1);
//	}
//
//	val = (*Rear)->Value;
//	*Rear = (*Rear)->Link;
//	free(Temp);
//	return val;
//}

void BFS(int links[ARRAY_SIZE][ARRAY_SIZE], Point points[], int Vertex) {
	QNode *Front = NULL;
	QNode *Rear = NULL;
	
	int Current;

	LInsert(&Front, &Rear, Vertex);
	points[0].status = WAITING;

	while (Front != NULL) {
		Current = LDelete(&Front, &Rear);

		printf("%d  ", Current);
		points[Current].status = VISITED;

		for (int i = 0; i < ARRAY_SIZE; ++i) {
			if (links[Current][i] == 1 && points[i].status == UNVISITED) {
				LInsert(&Front, &Rear, i);
				points[i].status = WAITING;
			}

		}


	}
}

void DFS(int links[ARRAY_SIZE][ARRAY_SIZE], Point points[], int Vertex) {
	SNode *Top = NULL;

	int Current;

	LPush(&Top, Vertex);
	points[0].status = WAITING;

	while (Top != NULL) {
		Current = LPop(&Top);

		printf("%d  ", Current);
		points[Current].status = VISITED;

		for (int i = 0; i < ARRAY_SIZE; ++i) {
			if (links[Current][i] == 1 && points[i].status == UNVISITED) {
				LPush(&Top, i);
				points[i].status = WAITING;
			}

		}


	}
}

//Makes the graph ready for Traversal and returns starting vertex
int TraversalReady (Point points[]) {
	int vertex;

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		points[i].status = UNVISITED;
	}
	printf("Enter the Starting vertex");
	scanf("%d", &vertex);

	return vertex;
}

void UndircreateEdge(int links[ARRAY_SIZE][ARRAY_SIZE], int start, int end) {
	links[start][end] = 1;
	links[end][start] = 1;
}

void DircreateEdge(int links[ARRAY_SIZE][ARRAY_SIZE], int start, int end) {
	links[start][end] = 1;
}

void DeleteEdge(int links[ARRAY_SIZE][ARRAY_SIZE], int start, int end) {
	links[start][end] = 0;
}

void EditGraph(int links[ARRAY_SIZE][ARRAY_SIZE], int choice) {

	int start, end;
	printf("Enter the Start and End points of edge: ");
	scanf("%d %d", &start, &end);

	if ((start >= ARRAY_SIZE || start < 0) || (end < 0 || end >= ARRAY_SIZE)) {
		printf("Index out of Range");
		return;
	}

	switch (choice) {

	case 1: {
		UndircreateEdge(links, start, end);
	}break;

	case 2: {
		UndircreateEdge(links, start, end);
	}break;

	case 3: {
		DeleteEdge(links, start, end);
	}break;

	}
}

void ClearGraph(int links[ARRAY_SIZE][ARRAY_SIZE]) {
	for (int i = 0; i < ARRAY_SIZE; ++i)
		for (int j = 0; j < ARRAY_SIZE; ++j)
			links[i][j] = 0;
}

void GraphMenu() {

	Point points[ARRAY_SIZE];
	int links[ARRAY_SIZE][ARRAY_SIZE] ;
	ClearGraph(links);
	int choice;

	while (1) {
		system("cls");
		printf("\nGraphs");
		printf("\nMainMenu");
		printf("\n1. Add Undirected Edge");
		printf("\n2. Add Directed Edge");
		printf("\n3. Delete Edge");
		printf("\n4. Clear Graph");
		printf("\n5. Breadth First Traversal");
		printf("\n6. Depth First Traversal");
		printf("\n7. Exit\n");

		scanf("%d", &choice);

		switch (choice) {
		case 1:
		case 2:
		case 3:
			EditGraph(links, choice);
			break;

		case 4:
			ClearGraph(links);
			break;

		case 5: {
			int vertex = TraversalReady(points);
			BFS(links, points, vertex);
		}break;

		case 6: {
			int vertex = TraversalReady(points);
			DFS(links, points, vertex);
		}
		case 7:
			return;
		}
		

//		_getch();
		printf("\n");
		system("pause");
	}
}

