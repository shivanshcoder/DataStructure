#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


int* InitFill1D(int size, ...) {
	va_list valist;
	int *temp = (int*)malloc(sizeof(int)*size);

	va_start(valist, size);

	for (int i = 0; i < size; ++i) {
		temp[i] = va_arg(valist, int);
	}

	va_end(valist);

	return temp;
}

int PeekFinder1D(int *Array, int low, int high) {
	int mid = (low + high) / 2;

	if (mid >= 0 && Array[mid] < Array[mid - 1])
		return PeekFinder1D(Array, 0, mid - 1);
	else if (mid < high && Array[mid] < Array[mid + 1])
		return PeekFinder1D(Array, mid + 1, high);
	else
		return mid;
}


typedef struct tagPoint {
	int r;
	int c;
}POINT;


POINT PeekFinder2D(int **Array, POINT arraySize, int lCol, int rCol) {
	int midCol = (lCol + rCol) / 2;

	int maxIndex = 0;
	int maxElem = Array[maxIndex][midCol];

	for (int i = 0; i < arraySize.r; ++i) {
		if (maxElem < Array[i][midCol]) {
			maxElem = Array[i][midCol];
			maxIndex = i;
		}
	}
	POINT temp = { maxIndex, midCol  };
	//temp.c = midCol;
	//temp.r = maxIndex;

	if (midCol > lCol && Array[maxIndex][midCol] < Array[maxIndex][midCol - 1])
		return PeekFinder2D(Array, arraySize, lCol, midCol - 1);
	else if (midCol < rCol && Array[maxIndex][midCol] < Array[maxIndex][midCol + 1])
		return PeekFinder2D(Array, arraySize, midCol + 1, rCol);
	else
		return  temp;
}

void PeekFinder1DTest() {
	int Array[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("The Peek exists at: %d", PeekFinder1D(Array, 0, 9));
}

void PeekFinder2DTest() {
	int **Array = (int**)malloc(sizeof(int*) * 5);

	POINT size = { 5,5 };

	Array[0] = InitFill1D(5, 19, 99, 19, 12, 11);
	Array[1] = InitFill1D(5, 15, 19, 9, 11, 21);
	Array[2] = InitFill1D(5, 16, 5, 17, 19, 20);
	Array[3] = InitFill1D(5, 16, 4, 17, 19, 20);
	Array[4] = InitFill1D(5, 99, 19, 12, 11, 5);

	
	POINT temp = PeekFinder2D(Array, size, 0, 4);
	printf("The Peek is at %t %d:%d", temp.r, temp.c);
}