from math import log

class Heap:

    def __init__(self, size):
        self.__size__ = size
        self.__array__ = [0] * (pow(2, int(log(size,2)) + 1) - 1)

    def size(self):
        return self.__size__
    
    def parent(self, index):
        return int(index / 2)

    def left(self, index):
        return (2 * index) + 1

    def right(self, index):
        return 2 * (index + 1)

    def fill(self):
        for i in range(0,self.size()):
            self.__array__[i] = int(input("Enter element number"))

    def minHeapify(self, index):
        l = self.left(index)
        r = self.right(index)

        if(l < self.size() and self.__array__[l] < self.__array__[index]):
            smallest = l
        else:
            smallest = index

        if(r < self.size() and self.__array__[r] < self.__array__[smallest]):
            smallest = r

        if smallest != index:
            self.__array__[index], self.__array__[smallest] = self.__array__[smallest], self.__array__[index]
            self.maxHeapify(smallest)

    
        
    
            
    def maxHeapify(self, index):     
        l = self.left(index)
        r = self.right(index)

        if(l < self.size() and self.__array__[l] > self.__array__[index]):
            largest = l
        else:
            largest = index

        if(r < self.size() and self.__array__[r] > self.__array__[largest]):
            largest = r

        if largest != index:
            self.__array__[index], self.__array__[largest] = self.__array__[largest], self.__array__[index]
            self.maxHeapify(largest)
 
    
            
    def buildMaxHeap(self):
        for i in range(int(self.size() / 2), -1, -1):
            self.maxHeapify(i)



    def buildMinHeap(self):
        for i in range(int(self.size() / 2), -1, -1):
            self.minHeapify(i)
        
    def heapSort(self, Order):

        if(Order == "asc"):
            self.buildMaxHeap()
        elif Order == "dsc":
            self.buildMinHeap()

        tempSize = self.size()

        while self.size() != 0:
            self.__array__[0], self.__array__[self.size() - 1] = self.__array__[self.size() - 1], self.__array__[0]

            self.__size__ = self.__size__ - 1
            if(Order == "asc"):
                self.maxHeapify(0)
            elif Order == "dsc":
                self.minHeapify(0)
            pass
        self.__size__ = tempSize

        print("Sorted Array")
        print(self.__array__)


temp = Heap(8)
temp.fill()
print(temp.__array__)
temp.buildMaxHeap()
temp.buildMinHeap()
print(temp.__array__)
temp.heapSort("asc")
print(temp.__array__)