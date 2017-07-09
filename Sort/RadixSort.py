'''
基数排序思想：
给定n个d位数，将数组中的数按不同位划分，然后先排序最低位，然后不断排序高位。最后完成排序过程。
这个排序算法有点绕，需要先将需要排序的数按位取出，需要一点技巧。
然后不能直接用计数排序，需要对其进行一些修改，主要改动在于输出的时候，将原数组元素放置在相应的位置，而不是某一位的数组元素。
'''


def radix_sort(A, d):
    for i in range(1, d+1):
        A_temp = []#A_temp作为临时变量，存放A[]当前位的值，用于输入计数排序
        for k in range(len(A)):
            number = int((A[k] - (int(A[k] / (10 ** i)) * (10 ** i))) / (10 ** (i - 1)))
            #number这一行的目的是取出A[k]的当前位
            A_temp.append(number)
        A = counting_sort(A_temp, A, 9)
    return A

def counting_sort(A_temp, A_origin, k=9):
    '''
    将计数排序的程序稍作改动，构建辅助数组C的时候用的A_temp，输出数组B的时候将原数组A_origin对应的值放到B中
    :param A_temp: 数组A当前需要排序的那一位
    :param A_origin: 数组A
    :param k: 进制数，10进制就是0~9，k就设为9
    :return: 按当前位排好序的数组A
    '''
    C = []
    for i in range(0, k+1):
        C.append(0)
    B = []
    for j in range(0, len(A_temp)):
        B.append(0)
    for j in range(0, len(A_temp)):
        C[A_temp[j]] += 1
    for i in range(1, k+1):
        C[i] = C[i-1] + C[i]
    for j in range(len(A_temp)-1, -1, -1):#这一行是从len(A)到0，降序遍历。
                                     #目的是为了保证排序前后相同大小的值相对次序不变，即计数排序是稳定的。
        B[C[A_temp[j]]-1] = A_origin[j]
        C[A_temp[j]] -= 1
    return B


def main():
    A = [329, 457, 657, 839, 436, 720, 355]
    d = 3
    A = radix_sort(A, d)
    print(A)


if __name__ == '__main__':
    main()