'''
堆排序算法：核心思想在于利用堆这种结构的性质，即保证每个父节点大于等于他的两个孩子节点（最大堆）。
利用最大堆的性质，可以构建最大堆，方法就是从树的叶节点上面那一层开始，不断利用最大堆性质，直到根节点。
构建出最大堆后，利用最大堆的排序方法就是不断将根节点与数组尾部的叶子节点交换，再对新的根节点调用最大堆的性质。
'''

#对于一个树，由于数组下标从0开始和从1开始的差异，求节点的父亲和儿子的方法不同。
def Parent(i):
    return int(i / 2) + 1
def Left(i):
    return 2 * i + 1
def Right(i):
    return 2 * i + 2

def MaxHeap(A, i, heapSize):
    l = Left(i)
    r = Right(i)
    if l < heapSize and A[l] > A[i]:
        largest = l
    else:
        largest = i
    if r < heapSize and A[r] > A[largest]:
        largest = r
    if largest != i:
        temp = A[i]
        A[i] = A[largest]
        A[largest] = temp
        MaxHeap(A, largest, heapSize)

def BuildMaxHeap(A):
    heapSize = len(A)
    for i in range(int(heapSize / 2), -1, -1):
        MaxHeap(A, i, heapSize)

def HeapSort(A):
    heapSize = len(A)
    for i in range(heapSize - 1, 0, -1):
        temp = A[0]
        A[0] = A[i]
        A[i] = temp
        heapSize -= 1
        MaxHeap(A, 0, heapSize)

if __name__ == '__main__':
    A = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
    BuildMaxHeap(A)
    HeapSort(A)
    print(A)