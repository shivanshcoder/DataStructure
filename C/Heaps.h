#pragma once
#include<limits.h>

#define Parent(index) (int)index / 2
#define LChild(index) index * 2
#define RChild(index) index * 2 + 1


void maxHeapify(int Heap[], int index, int size) {
	int largest;
	int lchild = LChild(index);
	int rchild = RChild(index);

	if (Heap[lchild] > Heap[index] && lchild < size)
		largest = lchild;
	else
		largest = index;

	if (Heap[rchild] > Heap[index] && rchild < size)
		largest = rchild;

	if (largest != index) {
		int temp = Heap[index];
		Heap[index] = Heap[largest];
		Heap[largest] = temp;
		maxHeapify(Heap, largest, size);
	}
}


void minHeapify(int Heap[], int index, int size) {
	int smallest;
	int lchild = LChild(index);
	int rchild = RChild(index);

	if (Heap[lchild] > Heap[index] && lchild < size)
		smallest = lchild;
	else
		smallest = index;

	if (Heap[rchild] > Heap[index] && rchild < size)
		smallest = rchild;

	if (smallest != index) {
		int temp = Heap[index];
		Heap[index] = Heap[smallest];
		Heap[smallest] = temp;
		maxHeapify(Heap, smallest, size);
	}
}


void buildMaxHeap(int Heap[], int size) {
	for (int i = size / 2; i > 0; i--)
		maxHeapify(Heap, i, size);
}

void buildMinHeap(int Heap[], int size) {
	for (int i = size / 2; i > 0; i--)
		minHeapify(Heap, i, size);
}

void heapSort(int Heap[], int size, bool Asc) {

	if (Asc == true)
		buildMaxHeap(Heap, size);
	else
		buildMinHeap(Heap, size);

	while (size--) {
		int temp = Heap[size];
		Heap[size] = Heap[0];
		Heap[0] = temp;

		if (Asc == true)
			maxHeapify(Heap, 0, size);
		else
			minHeapify(Heap, 0, size);
	}
}

void test() {
	int Heap[10];

}