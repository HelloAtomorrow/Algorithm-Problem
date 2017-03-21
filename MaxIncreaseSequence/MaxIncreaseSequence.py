'''
问题描述如下：求一个n个数的序列的最长单调递增子序列，只要求递增，不要求连续。
设计思想：设序列X(n)，最长递增子序列长度为m，考虑长度为i的递增子序列，这种序列有多个，
最小的末尾元素记为L(i)，可以得到 L(1) <= L(2) <= ... <= L(m)，
这个证明较简单，使用反证法即可。在这个递增的序列中使用十分法查找，则可以实现O(nlogn)的算法。
'''

'''
算法：
n = len(A)
L[1] = A[1]
for i=2 to n:
    left = 1
    right = len(L)
    while(left <= right)
        mid = (left + right) / 2
        if A[i] < L[mid]:
            right = mid - 1
        else:
            left = mid + 1
    L[left] = A[i]
'''

import random
MINIMUMVALUE = -10000

def ComputeSequence(A):
    n = len(A)
    previous = []
    L = []
    #L.append(A[0])
    for i in range(0, n):
        left = 0
        right = len(L) - 1
        while left <= right:
            mid = int((left + right) / 2)
            if A[i] < L[mid]:
                right = mid - 1
            else:
                left = mid + 1
        if left >= len(L):
            L.append(A[i])
        else:
            L[left] = A[i]
        print(L)
        if left <= 0:
            previous.append(None)
        else:
            previous.append(L[left-1])
    print(previous)
    return L, previous

if __name__ == '__main__':
    #A = [2, 1, 3, 0, 4, 1, 5, 2, 7]
    A = []
    for i in range(10):
        A.append(random.randint(-10, 10))
    print(A)
    L, previous = ComputeSequence(A)

'''
这个问题还有两种设计思想，它们的运行时间都是O(n^2):
1、对于序列A中的每一个元素，用一个数组L记录当该元素作为递增序列的最大值时，序列的长度，然后比较L中的最大值
2、学习过最长公共子序列后，可以对待求序列A排序，记为B。然后求A，B的最长公共子序列。
问题曾参考：
http://blog.csdn.net/wdq347/article/details/8978394
http://blog.csdn.net/wangche320/article/details/9185919
'''