#include <iostream>
using namespace std;


int Partition(int a[], int low, int high)
{
    // 左右中取3数中间值
    int mid = low + (high - low) / 2;
    if (a[low] > a[high])
    {
        swap(a[low], a[high]);
    }
    if (a[mid] > a[high])
    {
        swap(a[mid], a[high]);
    }
    if (a[mid] > a[low])
    {
        swap(a[mid], a[low]);
    }
    int pivotkey;
    pivotkey = a[low];

    while (low < high)
    {
        while (low < high && a[high] >= pivotkey)
        {
            high--;
        }
        a[low] = a[high];

        while (low < high && a[low] <= pivotkey)
        {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = pivotkey;
    return low;
}

void QSort1(int a[], int low, int high)
{
    int pivot;
    //if (low < high)
    while (low < high)
    {
        pivot = Partition(a, low, high);

        QSort1(a, low, pivot - 1);
        // 采用迭代而不是递归的方法可以缩减堆栈深度，从而提高了整体性能
        //QSort1(a, pivot + 1, high);
        low = pivot + 1;
    }
}

/*
* 快速排序
*
* 参数说明：
*     a -- 待排序的数组
*     l -- 数组的左边界(例如，从起始位置开始排序，则l=0)
*     r -- 数组的右边界(例如，排序截至到数组末尾，则r=a.length-1)
*/
void QSort2(int a[], int low, int high)
{
    //if (low < high)
    while (low < high)
    {
        int lowTmp, highTmp;
        lowTmp = low;
        highTmp = high;

        // 左右中取3数中间值
        int mid = lowTmp + (highTmp - lowTmp) / 2;
        if (a[lowTmp] > a[highTmp])
        {
            swap(a[lowTmp], a[highTmp]);
        }
        if (a[mid] > a[highTmp])
        {
            swap(a[mid], a[highTmp]);
        }
        if (a[mid] > a[lowTmp])
        {
            swap(a[mid], a[lowTmp]);
        }
        int pivotkey;
        pivotkey = a[lowTmp];

        while (lowTmp < highTmp)
        {
            while (lowTmp < highTmp && a[highTmp] >= pivotkey)
            {
                highTmp--;
            }
            //if (i < j)
            //{
            //    a[i++] = a[j];
            //}
            a[lowTmp] = a[highTmp];

            while (lowTmp < highTmp && a[lowTmp] <= pivotkey)
            {
                lowTmp++;
            }
            //if (i < j)
            //{
            //    a[j--] = a[i];
            //}
            a[highTmp] = a[lowTmp];
        }
        a[lowTmp] = pivotkey;

        QSort2(a, low, lowTmp - 1);
        //QSort2(a, lowTmp + 1, high);
        low = lowTmp + 1;
    }
}

void QuickSort(int a[], int n)
{
    // 多个函数调用，下标从0开始
    //QSort1(a, 0, n - 1);

    // 单个函数，下标从0开始
    QSort2(a, 0, n - 1);
}


void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}


//int main_quick_sort()
int main()
{
    int a[9] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };
    PrintArray(a, 9);

    QuickSort(a, 9);
    PrintArray(a, 9);
}