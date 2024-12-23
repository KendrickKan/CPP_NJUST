#include <stdio.h>

void bubble_sort(int arr[], int len);
void insert_sort(int arr[], int len);
void select_sort(int arr[], int len);

int main()
{
    printf("第14次课\n");
    printf("排序算法\n");
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}; // 乱序数组
    // 数组的指针==数组的首地址==数组的第一个元素的地址==&arr[0]==arr
    // 通过传递数组的首地址，可以在函数内部修改数组的值
    // 排序算法：将乱序数组按照从小到大（从大到小）的顺序排列

    // 冒泡排序
    printf("冒泡排序\n");
    printf("排序前：");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // 调用冒泡排序函数
    // 冒泡排序的思想：两两比较，如果前面的数比后面的数大，就交换位置，多次循环，直到没有需要交换的位置
    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
    printf("排序后：");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // 插入排序
    int arr2[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}; // 乱序数组
    // 插入排序
    printf("插入排序\n");
    printf("排序前：");
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    // 调用插入排序函数
    insert_sort(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("排序后：");
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {
        printf("%d ", arr2[i]);
    }
    // 选择排序
    printf("\n");
    int arr3[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}; // 乱序数组
    // 选择排序
    printf("选择排序\n");
    printf("排序前：");
    for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    // 调用选择排序函数
    select_sort(arr3, sizeof(arr3) / sizeof(arr3[0]));
    printf("排序后：");
    for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
    {
        printf("%d ", arr3[i]);
    }
    return 0;
}

void bubble_sort(int arr[], int len)
{
    // 外层循环控制循环次数，一共需要找几次最大值，最大值就是数组的最后一个元素，len-1次
    // 为什么不能在这里的函数去计算len的值？
    // 因为数组是引用传递，数组的长度是在调用函数的时候传递进来的，编译器编译的时候，不知道数组的长度是多少
    for (int i = 0; i < len - 1; i++)
    {
        // 内层循环，两两比较，如果前面的数比后面的数大，就交换位置
        // 比较次数是逐渐减少的，第一次循环比较n-1次，第二次循环比较n-2次，第三次循环比较n-3次，以此类推
        // 第i次循环，比较次数是n-i次
        // len - 1 - i: 每次循环比较的次数
        for (int j = 0; j < len - 1 - i; j++)
        {
            // 有5个数需要排序
            // 比较从1-5的数，比较4次，第一次比较1和2，第二次比较2和3，第三次比较3和4，第四次比较4和5，比较完之后，最大的数就到了最后
            // 比较从1-4的数，比较3次，第一次比较1和2，第二次比较2和3，第三次比较3和4，比较完之后，第二大的数就到了倒数第二个位置
            // 比较从1-3的数，比较2次，第一次比较1和2，第二次比较2和3，比较完之后，第三大的数就到了倒数第三个位置
            // 比较从1-2的数，比较1次，第一次比较1和2，比较完之后，第四大的数就到了倒数第四个位置
            // 比较从1-1的数，比较0次，比较完之后，第五大的数就到了倒数第五个位置，这一步是没必要的
            // j 是从0开始的
            // 所以要比较的是arr[j]和arr[j+1]
            // arr[0] arr[1]
            // arr[1] arr[2]
            // arr[2] arr[3]
            // ...
            // arr[len-2-i] arr[len-1-i]
            // 从小到大排序
            // 如果前面的数比后面的数大，就交换位置
            if (arr[j] > arr[j + 1])
            {
                // 交换位置
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // 是否需要返回？
    // 不需要，因为数组是引用传递，函数内部对数组的修改会影响到函数外部
}

void insert_sort(int arr[], int len)
{
    // 插入排序核心思想：将数组分为两部分，一部分是有序的，一部分是无序的，每次从无序的部分取出一个元素，插入到有序的部分
    // 外层循环控制循环次数，控制的就是无序的部分
    for (int i = 0; i < len - 1; i++)
    {
        int temp = arr[i]; // 当前待插入的元素，就把第一个元素当需要插入的元素
        int j = i;         // 从i开始往前找
        // 内层循环，找到合适的位置插入
        while (j >= 0 && temp < arr[j - 1])
        {
            // 如果当前元素比前一个元素小，就把前一个元素往后移动一位
            arr[j] = arr[j - 1]; // 如果temp比arr[j-1]小，就把arr[j-1]往后移动一位，给temp腾位置
            j--;
        }
        // 找到合适的位置，插入元素
        arr[j] = temp;
    }
}

// 选择排序
void select_sort(int arr[], int len)
{
    // 选择排序核心思想：每次从无序的部分找到最小的元素，放到无序的部分的最前（从小到大）
    for (int i = 0; i < len - 1; i++)
    {
        int min_index = i; // min_index是最小元素的下标
        // 内层循环，找到未排序部分最小的元素
        for (int j = i; j < len - 1; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j; // 从前往后找，找到最小的元素的下标
            }
        }
        // 找到最小值的下标min_index，交换位置，把最小的元素放到未排序的部分的最前面
        // 未排序的部分的最前面的下标是i
        // 实现arr[min_index]和arr[i]的交换
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// 课上都是从小到大排序，如果想要从大到小排序，这三种算法应该怎么改？
// 快速排序
// 归并排序
// 堆排序
// 希尔排序
// 其他的排序算法