#include <iostream>
using namespace std;

void CountingSort(int a[], int n)
{
    if (n <= 1)
    {
        return;
    }

    // 查找数组中数据的范围
    int nMax = a[0];
    for (int i = 1; i < n; i++)
    {
        if (nMax < a[i])
        {
            nMax = a[i];
        }
    }

    // 申请一个计数数组anCount，下标大小[0, nMax]
    int *anCount = new int[nMax + 1];
    for (int i = 0; i < nMax + 1; i++)
    {
        anCount[i] = 0;
    }

    // 计算每个元素的个数，放进anCount中
    for (int i = 0; i < n; i++)
    {
        anCount[a[i]]++;
    }
    // 依次累加
    for (int i = 1; i < nMax + 1; i++)
    {
        anCount[i] = anCount[i - 1] + anCount[i];
    }

    // 临时数组anTmp，存储排序后的结果
    int *anTmp = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int nIndex = anCount[a[i]] - 1;   // 数组下标从0开始

        anTmp[nIndex] = a[i];
        anCount[a[i]]--;
    }

    // 临时数组anTmp拷贝到a
    for (int i = 0; i < n; i++)
    {
        a[i] = anTmp[i];
    }
}

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << endl;
}

int main_counting_sort()
{
    int a[9] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };
    PrintArray(a, 9);

    CountingSort(a, 9);
    PrintArray(a, 9);
}

































