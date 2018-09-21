
"""
    Complexity: O(log(n))
    return: Index of Peek
"""
def PeekFinder1D(Array, low, high):
    mid = int((low + high) / 2)

    if(mid > 0 and Array[mid] > Array[mid - 1] and Array[mid] > Array[mid + 1]):
        return mid
    elif(mid>0 and Array[mid]<Array[mid-1]):
        return PeekFinder1D(Array, low, mid-1)
    else:
        return PeekFinder1D(Array, mid+1, high)



def PeekFinder2D(Array, Row, Col):
    Column = int(Col/2)

    maxIndex = 0
    maxElem = Array[maxIndex]

    for i in range(len(Array)):
        if maxElem < Array[i]:
            maxElem = Array[i]
            maxIndex = i

    """
    """
    


def test1D():
    Array = [1,3,4,5,4,3,2,1]
    print(PeekFinder1D(Array, 0, len(Array)-1))

test1D()