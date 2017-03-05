'''
归并排序思想：
采用递归方法，不断将待排序序列划分成子序列
采用Merge策略归并
'''

def Merge(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    L = []
    R = []
    for i in range(n1):
        L.append(A[p+i])
    for j in range(n2):
        R.append(A[q+j+1])
    print("L: ", L)
    print("R: ", R)
    i = 0
    j = 0
    for k in range(p, r + 1):
        if i >= n1:
            A[k] = R[j]
            j += 1
        elif j >= n2:
            A[k] = L[i]
            i += 1
        elif L[i] < R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def MergeSort(A, p, r):
    if p < r:
        q = int((p + r) / 2)
        MergeSort(A, p, q)
        MergeSort(A, q + 1, r)
        Merge(A, p, q, r)

if __name__ == "__main__":
    sortList = [5, 4, 7, 3, 5, 2, 1]
    MergeSort(sortList, 0, 6)
    print("Result: ", sortList)
