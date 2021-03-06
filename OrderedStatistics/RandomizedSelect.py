#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jul 12 20:33:16 2017

从数组中找出第order大的元素：
思路是借用快速排序的方法，不断找到分割点元素，比较该元素与order的大小，
如果小于order，则在[start，order-1]之间寻找第order大的数。
如果大于order，则在[order+1, finish]之间寻找第（order-分割点位置）大的元素。

这种算法的期望运行时间是O(n)
"""
import random


def random_partition(A, start, finish):
    i = random.randint(start, finish)
    temp = A[finish]
    A[finish] = A[i]
    A[i] = temp
    return partition(A, start, finish)


def partition(A, start, finish):
    main_num = A[finish]
    i = start - 1
    for j in range(start, finish):
        if A[j] <= main_num:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[finish] = A[finish], A[i+1]
    return i+1


def random_select(A, start, finish, order):
    if start == finish:
        return A[start]
    break_point = random_partition(A, start, finish)
    count = break_point - start + 1
    if order == count:
        return A[break_point]
    elif order < count:
        return random_select(A, start, break_point-1, order)
    else:
        return random_select(A, break_point+1, finish, order-count)


def main():
    A = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
    order = 3
    random_select(A, 0, len(A)-1, order)
    print(A)
    print(A[order])


if __name__ == '__main__':
    main()

