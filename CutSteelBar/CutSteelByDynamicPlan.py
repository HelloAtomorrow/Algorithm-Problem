'''
自底向上的方法求解钢条切割问题:
利用priceRecord数组记录长度为i的钢条切割的最优值，
i从小到大计算，所以当前长度的切割问题的子问题都是已经
计算过并保存到priceRecord里面的。
'''
MINIMUMVALUE = -10000

def CutFromBottom(price, length):
    priceRecord = []
    leftCut = []
    for i in range(length + 1):
        priceRecord.append(0)
        leftCut.append(0)

    for i in range(1, length + 1):
        maxPrice = MINIMUMVALUE
        for j in range(i):
            #maxPrice = max(maxPrice, price[j] + priceRecord[i-j-1])
            nowPrice = price[j] + priceRecord[i-j-1]
            if maxPrice < nowPrice:
                maxPrice = nowPrice
                leftCut[i] = j + 1  #保存每次切割的左侧长度，之后可以循环减去左侧长度，来计算切割方案
        priceRecord[i] = maxPrice

    print(priceRecord)
    return priceRecord[length], leftCut

'''
带备忘录的自顶向下方法：
核心思想在于Compute函数第一行
如果需要计算的问题已经在priceRecord里保存过了
就直接return
'''

def CutFromTop(price, length):
    priceRecord = []
    for i in range(length + 1):
        priceRecord.append(MINIMUMVALUE)
    return Compute(price, length, priceRecord)

def Compute(price, length, priceRecord):
    if priceRecord[length] >= 0:
        return priceRecord[length]
    if length == 0:
        maxPrice = 0
    else:
        maxPrice = MINIMUMVALUE
        for i in range(length):
            maxPrice = max(maxPrice, price[i] + Compute(price, length - i - 1, priceRecord))
    priceRecord[length] = maxPrice
    return maxPrice

if __name__ == '__main__':
    length = 10
    prices = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
    leftCut = CutFromBottom(prices, length)[1]
    print(leftCut)
    print(CutFromTop(prices, length))
    while length > 0:
        print(leftCut[length])
        length -= leftCut[length]
