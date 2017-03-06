'''
分治法求最大子数组：
采用递归的思想，不断将待求子数组划分为三部分：
1，中点左侧
2，中点右侧
3，跨越中点两侧
注意到重点在于：跨越中点的最大子数组，搜索次数仅为n次，递归次数为lgn次，所以需要的时间为nlgn
'''

import random

def FindMaxCrossSubarray(A, low, mid, high):
    crossLow = mid
    crossHigh = mid

    leftSum = 0
    nowSum = 0    
    i = mid
    while i >= low:
        nowSum += A[i]
        if nowSum > leftSum:
            leftSum = nowSum
            crossLow = i
        i -= 1

    rightSum = 0
    nowSum = 0
    j = mid + 1
    while j <= high:
        nowSum += A[j]
        if nowSum > rightSum:
            rightSum = nowSum
            crossHigh = j
        j += 1
    return leftSum + rightSum, crossLow, crossHigh


def FindMaxSubarray(A, low, high):
    if low == high:
        return A[low], low, high
    mid = int((low + high) / 2)

    leftSum, leftLow, leftHigh = FindMaxSubarray(A, low, mid)
    rightSum, rightLow, rightHigh = FindMaxSubarray(A, mid + 1, high)
    crossSum, crossLow, crossHigh = FindMaxCrossSubarray(A, low, mid, high)

    if (leftSum > rightSum) and (leftSum > crossSum):
        return leftSum, leftLow, leftHigh
    elif (rightSum > leftSum) and (rightSum > crossSum):
        return rightSum, rightLow, rightHigh
    else:
        return crossSum, crossLow, crossHigh

if __name__ == "__main__":
    #A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    A = []
    for i in range(10):
        A.append(random.randint(-10, 10))
    maxSum, start, end = FindMaxSubarray(A, 0, len(A) - 1)
    print(A)
    print(maxSum, start, end)
    
    
