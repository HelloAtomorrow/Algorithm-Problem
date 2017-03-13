'''
分治法递归切割钢条问题，思想是：
从钢条左端切下长度为i的一段，只对剩下长度为lenth - i的一段继续切割，左侧不再切割
'''
def CutSteel(prices, length):
    if length == 0:
        return 0
    maxPrice = 0
    for i in range(1, length + 1):
        nowPrice = prices[i-1] + CutSteel(prices, length - i)
        if nowPrice > maxPrice:            
            maxPrice = nowPrice
    return maxPrice

if __name__ == '__main__':
    length = 10
    prices = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
    print(CutSteel(prices, length))
