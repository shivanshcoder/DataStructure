#pragma once
#include<stdio.h>
#include<stdlib.h>


extern const int ArraySize ;

int ArrayInsert(int Array[], int LBound, int UBound, int Location, int Value) {

	//Checks if the array is already full
	if (ArraySize - 1 == UBound) {
		//Failed
		return 0;
	}

	int Index = UBound;

	while (Index >= Location) {
		Array[Index + 1] = Array[Index];
		Index--;
	}

	Array[Location] = Value;

	//Successful
	return 1;
}

int ArrayDelete(int Array[], int LBound, int UBound, int Location) {
	//Undeflow
	if (UBound == -1) {
		return 0;
	}

	int Value = Array[Location];

	int Index = Location;

	while (Index < UBound) {
		Array[Index] = Array[Index + 1];
		Index++;
	}

	return 1;
}

void ArrayMerge(int Array1[], int LBound1, int UBound1, int Array2[], int LBound2, int UBound2, int ArrayDes[]) {

	int Index1 = LBound1;
	int Index2 = LBound2;
	int IndexDes = 0;

	while (Index1 <= UBound1 && Index2 <= UBound2) {
		if (Array1[Index1] > Array2[Index2]) {
			ArrayDes[IndexDes] = Array2[Index2];
			Index2++;
			IndexDes++;
		}
		else {
			ArrayDes[IndexDes] = Array1[Index1];
			Index1++;
			IndexDes++;
		}
	}

	while (Index1 <= UBound1) {
		ArrayDes[IndexDes] = Array1[Index1];
		Index1++;
		IndexDes++;
	}

	while (Index2 <= UBound2) {
		ArrayDes[IndexDes] = Array2[Index2];
		Index2++;
		IndexDes++;
	}

}

int ArraySearch(int Array[], int LBound, int UBound, int Value) {
	for (int i = LBound; i <= UBound; ++i) {
		if (Value == Array[i])
			return i;
	}

	//Unsucessful
	return -1;
}

void ArrayCopy(int ArraySrc[], int LBound, int UBound, int ArrayDes[]) {
	int Index = LBound;

	while (Index <= UBound) {
		ArrayDes[Index] = ArraySrc[Index];
	}
}

int InsertMenu(int Array[], int LBound, int UBound) {
	int choice;
	int Value;
	int Loc;
	printf("\n\n1. Insert at Beginning");
	printf("\n2. Insert at End");
	printf("\n3. Insert at Location\n");
	scanf("%d", &choice);

	printf("\n Enter the Element");
	scanf("%d", &Value);


	switch (choice) {
	case 1: {
		return ArrayInsert(Array, LBound, UBound, 0, Value);
	}

	case 2: {
		return ArrayInsert(Array, LBound, UBound, UBound + 1, Value);
	}

	case 3: {

		printf("\nEnter the Location :");
		scanf("%d", &Loc);

		if (Loc > UBound)
			return 0;
		return ArrayInsert(Array, LBound, UBound, Loc, Value);
	}
	}
}

int DeleteMenu(int Array[], int LBound, int UBound) {
	int choice;
	int Value;
	int Loc;
	printf("\n\n1. Delete at Beginning");
	printf("\n2. Delete at End");
	printf("\n3. Delete at Location\n");
	//printf("\n4. Back to Main Menu");
	scanf("%d", &choice);

	switch (choice) {
	case 1: {
		return ArrayDelete(Array, LBound, UBound, 0);
	}

	case 2: {
		return ArrayDelete(Array, LBound, UBound, UBound);
	}

	case 3: {

		printf("\nEnter the Location :");
		scanf("%d", &Loc);

		return ArrayDelete(Array, LBound, UBound, Loc);
	}

			/*case 4: {

			}
					break;*/
	}
}

void Arrayprint(int Array[], int UBound) {
	printf("\nArray\n");
	for (int i = 0; i <= UBound; ++i)
		printf(" %d  ", Array[i]);
}

void ArrayMenu(int Array[]) {
	int UBound = -1, LBound = 0;
	int choice;


	while (1) {
		printf("\n\nArray Operation!");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Print Array");
		printf("\n4. Search Element");
		//printf("\n5. Merge Another sorted Array");
		printf("\n5. Exit\n");

		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			if( 1 == InsertMenu(Array, LBound, UBound))
				UBound++;
		}
				break;

		case 2: {
			if( 1 == DeleteMenu(Array, LBound, UBound))
				UBound--;
		}
				break;

		case 3: {
			Arrayprint(Array, UBound);

		}
				break;

		case 4: {
			int Value;
			printf("Enter the Value to Search");
			scanf("%d", &Value);

			int index = ArraySearch(Array, LBound, UBound, Value);
			if (index != -1)
				printf("\n The value is present at index: %d", index);
			else
				printf("\n The value not found in Array.");
		}
				break;

		case 5:
			return;
		}
	}
}

