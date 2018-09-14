#pragma once
#include<iostream>



class Heap {
public:

	inline int size() { return Size; }
	inline int parent(int index) { return index / 2; }
	inline int lChild(int index) { return 2 * index; }
	inline int rChild(int index) { return (index + 1) * 2; }

	void maxHeapify(int index);
	void minHeapify(int index);


	void buildMaxHeap();
	void buildMinHeap();


private:
	int *Container;
	int Size;
};

void Heap::maxHeapify(int index) {
	int Left = lChild(index);
	int Right = rChild(index);
	int largest;

	if (Left<Size && Container[Left]>Container[index])
		largest = Left;
	else if (Right < Size && Container[Right] > Container[index])
		largest = Right;
	else
		largest = index;

	if (largest != index) {
		int temp = Container[index];
		Container[index] = Container[largest];
		Container[largest] = temp;

		maxHeapify(largest);
	}

}

void Heap::minHeapify(int index) {
	int Left = lChild(index);
	int Right = rChild(index);
	int smallest;

	if (Left < Size && Container[Left] < Container[index])
		smallest = Left;
	else if (Right < Size && Container[Right] < Container[index])
		smallest = Right;
	else
		smallest = index;

	if (smallest != index) {
		int temp = Container[index];
		Container[index] = Container[smallest];
		Container[smallest] = temp;

		maxHeapify(smallest);
	}
}

