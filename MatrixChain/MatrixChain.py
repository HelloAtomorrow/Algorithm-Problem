'''
矩阵链乘法优化：
核心思想主要有两方面：
1、拿到这一问题，有正反两个思维方式，正向思维是先计算代价最小的两个矩阵————贪心
   逆向思维是递归求解当前迭代步骤代价的最小值————动态规划
   min{m[i,k] + m[k+1,j] + p[i-1]p[k]p[j]}  i<=k<j
2、在计算代价表格m[i,j]时，与之前遇到的动态规划不同，这一问题的动态规划表格是从对角线
   起手，逐渐向右上角依次计算。
'''

MAXIMUMVALUE = 10000000

'''(贪心算法，经验证没有得到最优解)
def Greedy(matrixPrice):
    totalPrice = 0
    while len(matrixPrice) > 2:
        maxPrice = 0
        for i in range(1, len(matrixPrice) - 1):
            if maxPrice < matrixPrice[i]:
                maxPrice = matrixPrice[i]
                location = i
        totalPrice += matrixPrice[location-1] * matrixPrice[location] * matrixPrice[location+1]
        matrixPrice.remove(maxPrice)
        print(maxPrice)
    return totalPrice
'''

def MatrixChainOrder(matrixPrice):
    n = len(matrixPrice) - 1
    priceM = []
    locationS = []

    for i in range(n):
        temp = [MAXIMUMVALUE] * n
        priceM.append(temp)
        locationS.append([0] * n)
        priceM[i][i] = 0

    for l in range(2, n + 1):
        for i in range(0, n - l + 1):
            j = i + l - 1
            for k in range(i, j):
                q = priceM[i][k] + priceM[k+1][j] + matrixPrice[i] * matrixPrice[k+1] * matrixPrice[j+1]
                if q < priceM[i][j]:
                    priceM[i][j] = q
                    locationS[i][j] = k
    return priceM, locationS

def PrintOptimalParens(locationS, i, j):
    if i == j:
        print('A' + str(i), end='')
    else:
        print('(', end='')
        PrintOptimalParens(locationS, i, locationS[i][j])
        PrintOptimalParens(locationS, locationS[i][j] + 1, j)
        print(')', end='')

if __name__ == '__main__':
    matrixPrice = [30, 35, 15, 5, 10, 20, 25]
    matrixPrice2 = [5, 10, 3, 12, 5, 50, 6]

    priceM, locationS = MatrixChainOrder(matrixPrice2)
    for price in priceM:
        print(price)
    print(priceM[0][5])
    PrintOptimalParens(locationS, 0, 5)
    '''
    totalPrice = Greedy(matrixPrice)
    print(totalPrice)
    '''

'''   习题15.2-2，要学会递归调用
MATRIX-CHAIN-MULITIPLY(A, s, i, j):  
    if i == j:  
        return A[i]  
    else:  
        B1 = MATRIX-CHAIN-MULITIPLY(A, s, i, s[i][j])  
        B2 = MATRIX-CHAIN-MULITIPLY(A, s, s[i][j]+1, j)  
        return B1*B2  
'''