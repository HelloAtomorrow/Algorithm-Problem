'''
活动选择问题，又名区间调度问题，问题描述如下：
假定有一个n个活动的集合S={a1, a2, ..., an},这些活动共用同一资源，
而这个资源在某个时刻只能供一个活动使用。每个活动ai都有一个开始时间si
和结束时间fi。如果两个活动ai和aj满足[si, fi)和[sj, fj)不重叠，则称
它们是兼容的。我们希望求出一个最大兼容活动集。
'''

'''
设计思路1：采用贪心策略，从第一个活动开始，依次选择活动结束时间最早的活动，可以得到此问题的最优解。
除此之外，也可以从最后一个活动开始，依次选择活动开始时间最晚的活动，这种方法与上述方法对称，也能得到最优解。
'''
#传入的finish列表已经排好序
def GreedyActivitySelector(start, finish):
    A = []
    k = 0
    for i in range(1, len(start)):
        if start[i] >= finish[k]:
            A.append(i)
            k = i
    return A

'''
设计思路2：采用动态规划，令Sij表示在ai结束之后开始，aj开始之前结束的那些活动集合，
用c[i, j]表示集合Sij最优解的大小，可以得到递归关系式：
对于任意的ak属于Sij，有：
    c[i, j] = 0                           若Sij为空集
    c[i, j] = max{c[i, k] + c[k, j] + 1}  若Sij非空
根据递归关系式，算法设计思路类似于矩阵链乘法问题,都是三角形矩阵向右上角计算的方法。
'''
MAXIMUMVALUE = 10000000
def DynamicActivitySelector(start, finish, weight):
    length = len(start)
    c = []
    for i in range(length):
        temp = []
        for j in range(length):
            temp.append(0)
        c.append(temp)
    for l in range(1, length):
        for i in range(length-l):
            j = i + l
            for k in range(i+1, j):
                if start[k] >= finish[i] and finish[k] <= start[j]:
                    #c[i][j] = c[i][k] + c[k][j] + 1
                    '''
                    对于带权重的活动选择问题，只需要将递归关系式改为：
                    max{c[i, k] + c[k, j] + weight[k]}
                    '''
                    c[i][j] = c[i][k] + c[k][j] + weight[k]
    for temp in c:
        print(temp)
    return c[0][length-1]

'''
由此可以看出，动态规划每一步可能会产生多个子问题，而贪心算法每一步只会产生一个子问题。
对于这个问题中，当选择了贪心解时(结束时间最小的活动)，也是将原问题划分成了两个子问题，
但是其中一个子问题是空的，而我们只需要考虑另一个非空的子问题就可以了。
'''

if __name__ == '__main__':
    start = [0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12, MAXIMUMVALUE]
    finish = [0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16, MAXIMUMVALUE]
    weight = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0]
    A = GreedyActivitySelector(start, finish)
    print(A)
    print(DynamicActivitySelector(start, finish, weight))
