#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

int PeekFinder1D(std::vector<int>Array, int low, int high) {
	int mid = (low + high) / 2;

	if (mid >= 0 && Array[mid] < Array[mid - 1])
		return PeekFinder1D(Array, 0, mid - 1);
	else if (mid < high && Array[mid] < Array[mid + 1])
		return PeekFinder1D(Array, mid + 1, high);
	else
		return mid;
}




std::pair<int,int> PeekFinder2D(std::vector< std::vector<int> >Array, int uRow, int dRow) {
	int midRow = (uRow + dRow) / 2;

	std::vector<int>::iterator it = std::max_element(Array[midRow].begin(), Array[midRow].end());
	int maxCol = it - Array[midRow].begin();


	if (midRow > 0 && Array[midRow][maxCol] < Array[midRow - 1][maxCol])
		return PeekFinder2D(Array, uRow, midRow - 1);
	else if (midRow < dRow && Array[midRow][maxCol] < Array[midRow + 1][maxCol])
		return PeekFinder2D(Array, midRow + 1, dRow);
	else
		return std::make_pair(midRow, maxCol);
}

void PeekFinder1DTest() {
	std::vector<int>Array = { 1,2,3,4,5,6,7,8,9,10 };
	printf("The Peek exists at: %d", PeekFinder1D(Array, 0, 9));
}

void PeekFinder2DTest() {
	
	std::vector< std::vector<int> >Array = {
		{17, 20, 19, 12, 11},
		{19, 18, 9, 11, 21},
		{16, 5, 17, 19, 20},
		{16, 4, 17, 19, 20},
		{99, 19, 12, 11, 5}
	};

	std::pair<int,int> temp = PeekFinder2D(Array, 0, 4);
	printf("The Peek is at %t %d:%d", temp.first, temp.second);
}