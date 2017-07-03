'''
计数排序思想：
计数排序不属于比较排序的范围，所以不受O(nlgn)的限制，
但是计数排序只能用于0~k之间的整数进行排序。
计数排序用到3个数组A，B，C，输入数组A[1...n]，输出数组B[1...n]，辅助数组C[0...k]。
初始时将C全部元素置为0，然后遍历A中的每一项A[i]，然后将C[A[i]]的值+1，于是C[A[i]]中保存的就是等于A[i]的元素个数。
然后对C中元素累加，使C[A[i]]保存输入元素小于等于A[i]的。
'''


def counting_sort(A, k):
    C = []
    for i in range(0, k+1):
        C.append(0)
    B = []
    for j in range(0, len(A)):
        B.append(0)
    for j in range(0, len(A)):
        C[A[j]] += 1
    for i in range(1, k+1):
        C[i] = C[i-1] + C[i]
    for j in range(len(A)-1, -1, -1):#这一行是从len(A)到0，降序遍历。
                                     #目的是为了保证排序前后相同大小的值相对次序不变，即计数排序是稳定的。
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1
    return B


def main():
    A = [2, 5, 3, 0, 2, 3, 0, 3]
    k = 5
    B = counting_sort(A, k)
    print(B)


if __name__ == '__main__':
    main()