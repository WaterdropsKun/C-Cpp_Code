#include <iostream>
using namespace std;

// ���ҵ�һ��ֵ���ڸ���ֵ��Ԫ��
int bsearch1(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = low + ((high - low) >> 1);

        if (a[mid] > value)
        {
            high = mid - 1;
        }
        else if (a[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            if ((mid == 0) || (a[mid - 1] != value))
                return mid;
            else
                high = mid - 1;
        }
    }

    return -1;
}

// �������һ��ֵ���ڸ���ֵ��Ԫ��
int bsearch2(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = low + ((high - low) >> 1);

        if (a[mid] > value)
        {
            high = mid - 1;
        }
        else if (a[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == n - 1 || a[mid + 1] != value)
                return mid;
            else
                low = mid + 1;
        }
    }
}

// ���ҵ�һ�����ڵ��ڸ���ֵ��Ԫ��
int bsearch3(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = low + ((high - low) >> 1);

        if (a[mid] >= value)
        {
            if (mid == 0 || a[mid - 1] < value)
                return mid;
            else
                high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

// �������һ��С�ڵ��ڸ���ֵ��Ԫ��
int bsearch4(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = low + ((high - low) >> 1);

        if (a[mid] <= value)
        {
            if (mid == n - 1 || a[mid + 1] > value)
                return mid;
            else
                low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}


// ��������
int Partition(int a[], int low, int high)
{
    // ������ȡ3���м�ֵ
    int mid = low + ((high - low) >> 1);
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
        // ���õ��������ǵݹ�ķ�������������ջ��ȣ��Ӷ��������������
        //QSort1(a, pivot + 1, high);
        low = pivot + 1;
    }
}

void QuickSort(int a[], int n)
{
    // �����������±��0��ʼ
    QSort1(a, 0, n - 1);
}


void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << endl;
}


int main_binary_search()
{
    int a[9] = { 50, 10, 90, 30, 70, 40, 80, 60, 30 };
    PrintArray(a, 9);

    QuickSort(a, 9);
    PrintArray(a, 9);

    int value = bsearch4(a, 9, 35);
    cout << value << endl;

    return 0;
}











