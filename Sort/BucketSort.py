'''
桶排序思想：
将数据分为n个大小相同的子区间，称为桶，假设数据是均匀分布在某一区间内(本例设为[0, 1) )，
所以一般不会出现很多数据在同一个桶中的情况，对每个桶中的元素先进行排序，然后遍历每个桶，依次输出桶中的元素。
补充：只要满足桶大小的平方和与总元素呈线性关系，就可以在线性时间完成排序
'''

def bucket_sort(A):
    n = len(A)
    B = []
    for i in range(n):
        B.append([])
    for i in range(n):
        index = int(n * A[i])
        B[index].append(A[i])
    for i in range(n):
        B[i] = sorted(B[i])
    C = []
    for i in range(1, n):
        C.extend(B[i])
    return C


def main():
    A = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]
    A = bucket_sort(A)
    print(A)


if __name__ == '__main__':
    main()