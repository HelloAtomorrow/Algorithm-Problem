'''
插入排序法，思想在于：被选中的insertNum左侧的数组为已经排好序的数组，
而后通过比较insertNum的值与左侧数组的值，将其插入到相应位置
'''
#升序插入排序
def InsertionSort(sortList):
    for i in range(1, len(sortList)):
        insertNum = sortList[i]
        j = i - 1
        while j >= 0 and sortList[j] > insertNum:
            sortList[j+1] = sortList[j]
            j -= 1
        sortList[j+1] = insertNum
        print(sortList)

#降序插入排序
def DownInsertionSort(sortList):
    for i in range(1, len(sortList)):
        insertNum = sortList[i]
        j = i - 1
        while j >= 0 and sortList[j] < insertNum:
            sortList[j+1] = sortList[j]
            j -= 1
        sortList[j+1] = insertNum
        print(sortList)

if __name__ == '__main__':
    sortList = [5, 4, 7, 3, 5, 2, 1]
    InsertionSort(sortList)
    print('result:', sortList)
    DownInsertionSort(sortList)
    print('result:', sortList)
