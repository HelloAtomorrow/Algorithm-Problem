'''
快速排序算法：最坏情况时间复杂度为O(n^2),期望时间复杂度为O(nlgn),在实际应用中平均性能很好。
算法思想：算法运用分治法的思想，将待排序数组分为 ≤主元 和 >主元 两部分。
函数partition用于寻找主元分割点，循环变量i，j将数组从左到右分为三个部分：
≤main_num, >main_num, 和没有限制(没有循环到那里)。
'''


def quick_sort(A, start, finish):
    if start < finish:
        break_point = partition(A, start, finish)
        quick_sort(A, start, break_point-1)
        quick_sort(A, break_point+1, finish)


def partition(A, start, finish):
    main_num = A[finish]
    i = start - 1
    for j in range(start, finish):
        if A[j] <= main_num:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[finish] = A[finish], A[i+1]
    return i+1


def main():
    A = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
    quick_sort(A, 0, len(A)-1)
    print(A)


if __name__ == '__main__':
    main()
