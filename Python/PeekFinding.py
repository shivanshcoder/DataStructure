
"""
    Complexity: O(log(n))
    return: Index of Peek
"""
def PeekFinder1D(Array, low, high):
    mid = int((low + high) / 2)


    if mid < high and Array[mid] < Array[mid + 1]:
        return PeekFinder1D(Array, mid+1, high)
    elif mid > 0 and Array[mid] < Array[mid - 1]:
        return PeekFinder1D(Array, 0, mid - 1)
    else:
        return mid




def PeekFinder2D(Array, lCol, rCol):
    #Column = int(Col/2)
    Column = int((lCol + rCol)/2)

    maxIndex = 0
    maxElem = Array[maxIndex][Column]

    for i in range(len(Array)):
        if maxElem < Array[i][Column]:
            maxElem = Array[i][Column]
            maxIndex = i

    if Column > lCol and Array[maxIndex][Column-1] > Array[maxIndex][Column]:
        return PeekFinder2D(Array, lCol, Column - 1)
    elif Column < rCol and Array[maxIndex][Column+1] > Array[maxIndex][Column]:
        return PeekFinder2D(Array, Column + 1, rCol)
    else:
        return (maxIndex, Column)
    


def test1D():
    Array = [6,5,3,2,5]
    print(PeekFinder1D(Array, 0, len(Array)-1))

def test2D():
    #Array = [0] * 4
    #for i in range(4):
    #    Array[i] = [0] * 4
    #    for j in range(4):
    #        Array[i][j] = int(input("Enter Value at" + str(i) + "," + str(j) + ": "))
    #    print("\n")

    Array = [
            [10,9,8,10,10],
            [19,99,19,12,11],
            [15,19,9,11,21],
            [16,5,17,19,20],
            [16,4,17,19,20]
        ]
    print(PeekFinder2D(Array,0,4))

test2D()