'''
线性时间内找出最大子数组：
设最大子数组的和为maxSum，起点和终点位置为start，end；
正在扫描的子数组和为nowSum，起点和终点为i，j；

核心思想在于：
若nowSum的值为正，则和maxSum比较，如果大于maxSum，更新maxSum；
若nowSum的值为负，那么从i到j这一段的数字只能减少数组的和，要丢弃，使nowSum清零，并使i=j+1；
（可以思考一下最大子数组的曲线，一定是从某个最低点开始的）
'''
import random
def FindMaxSubarray(A):
    maxSum = 0
    start = -1
    end = -1

    nowSum = 0
    i = 0
    j = 0

    while j < len(A):
        nowSum += A[j]
        if nowSum > 0:
            if nowSum > maxSum:
                maxSum = nowSum
                start = i
                end = j
            j += 1
        else:
            j += 1
            i = j
            nowSum = 0
    return maxSum, start, end

if __name__ == "__main__":
    #A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    A = []
    for i in range(10):
        A.append(random.randint(-10, 10))
    maxSum, start, end = FindMaxSubarray(A)
    print(A)
    print(maxSum, start, end)
    
    
