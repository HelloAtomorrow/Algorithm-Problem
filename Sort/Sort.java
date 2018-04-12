public class Sort {

    /**
     * 简单选择排序
     * 时间复杂度：最坏:O(n^2) 最好: O(n^2) 平均: O(n^2)
     * 空间复杂度：O(1)
     * 稳定性：不稳定
     */
    public static void selectSort(int[] array) {
        if (array == null) {
            return;
        }
        for (int i = 0; i < array.length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }

    /**
     * 冒泡排序:两种解法
     * 时间复杂度：最坏：O(n2) 最好: O(n) 平均: O(n2)
     * 空间复杂度：O(1)
     * 稳定性：稳定
     */
    public static void bubbleSort(int[] array) { 
        if (array == null) {
            return;
        }
        boolean flag;
        for (int i = 0; i < array.length - 1; i++) {
            flag = false;
//            最大数移到末尾
//            for (int j = 0; j < array.length - i - 1; j++) {
//                if (array[j] > array[j+1]) {
//                    int temp = array[j];
//                    array[j] = array[j+1];
//                    array[j+1] = temp;
//                    flag = true;
//                }
//            }
//            最小数移到开头
            for (int j = array.length - 1; j > i; j--) {
                if (array[j-1] > array[j]) {
                    int temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = temp;
                    flag = true;
                }
            }
            if (!flag) {
                return;
            }
        }
    }

    /**
     * 插入排序
     * 时间复杂度：O(n^2) O(n) O(n^2) （最坏 最好 平均）
     * 空间复杂度：O(1)
     * 稳定性： 稳定
     */
    public static void insertSort(int[] array) {
        if (array == null) {
            return;
        }
        for (int i = 1; i < array.length; i++) {
            int value = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > value) {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = value;
        }
    }

    /**
     * 希尔排序，插入排序的升级版。
     * 时间复杂度：O(n2) O(n) O(n1.5)
     * 空间复杂度：O(1)
     * 稳定性：不稳定
     */
    public static void sellSort(int[] array) {
        if (array == null) {
            return;
        }
        for (int gap = array.length / 2; gap > 0; gap = gap / 2) {
            for (int i = gap; i < array.length; ++i) {
                int value = array[i];
                int j = i - gap;
                while (j >= 0 && array[j] > value) {
                    array[j+gap] = array[j];
                    j -= gap;
                }
                array[j+gap] = value;
            }
        }
    }

    /**
     * 快速排序
     * 时间复杂度：最坏:O(n2) 最好: O(nlogn) 平均: O(nlogn)
     * 空间复杂度：O(nlogn)用于方法栈
     * 稳定性：不稳定
     * 扩展内容：三向快速排序
     */
    public static void quickSort(int[] array) {
        if (array == null || array.length <= 0) {
            return;
        }
        int start = 0;
        int end = array.length - 1;
        doQuickSort(start, end, array);
    }

    private static void doQuickSort(int start, int end, int[] array) {
        if (start < end) {
            int partitionLocation = partition(start, end, array);
            doQuickSort(start, partitionLocation - 1, array);
            doQuickSort(partitionLocation + 1, end, array);
        }
    }

    private static int partition(int start, int end, int[] array) {
        int mainNumber = array[end];
        int min = start;
        int max = start;
        while (max < end) {
            if (array[max] < mainNumber) {
                int temp = array[min];
                array[min] = array[max];
                array[max] = temp;
                min++;
            }
            max++;
        }
        int temp = array[min];
        array[min] = mainNumber;
        array[end] = temp;
        return min;
    }

    /**
     * 归并排序
     * 时间复杂度：最坏:O(nlog2n) 最好: O(nlog2n) 平均: O(nlog2n)
     * 空间复杂度：O(n)
     * 稳定性：稳定
     */
    public static void mergeSort(int[] array) {
        if (array == null || array.length <= 0) {
            return;
        }
        doMergeSort(0, array.length - 1, array);
    }

    private static void doMergeSort(int start, int end, int[] array) {
        if (start < end) {
            int middle = (start + end) >> 1;
            doMergeSort(start, middle, array);
            doMergeSort(middle + 1, end, array);
            merge(start, middle, end, array);
        }
    }

    private static void merge(int start, int middle, int end, int[] array) {
        int[] leftArray = new int[middle - start + 1];
        int[] rightArray = new int[end - middle];
        int leftIndex = 0;
        int rightIndex = 0;
        for (int i = start; i <= end; i++) {
            if (i <= middle) {
                leftArray[leftIndex] = array[i];
                leftIndex++;
            } else {
                rightArray[rightIndex] = array[i];
                rightIndex++;
            }
        }
        leftIndex = 0;
        rightIndex = 0;
        for (int i = start; i <= end; i++) {
            if (leftIndex >= leftArray.length) {
                array[i] = rightArray[rightIndex];
                rightIndex++;
            } else if (rightIndex >= rightArray.length) {
                array[i] = leftArray[leftIndex];
                leftIndex++;
            } else if (leftArray[leftIndex] <= rightArray[rightIndex]) {
                array[i] = leftArray[leftIndex];
                leftIndex++;
            } else {
                array[i] = rightArray[rightIndex];
                rightIndex++;
            }
        }
    }

    /**
     * 堆排序
     * 时间复杂度：最坏:O(nlog2n) 最好: O(nlog2n) 平均: O(nlog2n)
     * 空间复杂度：O(1)
     * 稳定性：不稳定
     */
    public static void heapSort(int[] array) {
        if (array == null || array.length <= 0) {
            return;
        }
        for (int i = array.length / 2 - 1; i >= 0; i--) {
            maxHeap(i, array.length, array);
        }
        for (int i = array.length - 1; i >= 0; i--) {
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;
            maxHeap(0, i, array);
        }
    }

    private static void maxHeap(int nodeIndex, int arrayLength, int[] array) {
        int largestIndex = nodeIndex;
        int leftIndex = 2 * nodeIndex + 1;
        int rightIndex = 2 * nodeIndex + 2;
        if (leftIndex < arrayLength && array[largestIndex] < array[leftIndex]) {
            largestIndex = leftIndex;
        }
        if (rightIndex < arrayLength && array[largestIndex] < array[rightIndex]) {
            largestIndex = rightIndex;
        }
        if (largestIndex != nodeIndex) {
            int temp = array[nodeIndex];
            array[nodeIndex] = array[largestIndex];
            array[largestIndex] = temp;
            maxHeap(largestIndex, arrayLength, array);
        }
    }


    public static void main(String[] args) {
        int[] array = {6, 5, 5, 4, 3, 7};
//        insertSort(array);
//        sellSort(array);
//        selectSort(array);
//        bubbleSort(array);
//        quickSort(array);
//        mergeSort(array);
        heapSort(array);
        for (int value : array) {
            System.out.printf("%d ", value);
        }
    }
}
