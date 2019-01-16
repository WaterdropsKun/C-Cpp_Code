#include <iostream>
using namespace std;

void CountingSort(int a[], int n)
{
    if (n <= 1)
    {
        return;
    }

    // �������������ݵķ�Χ
    int nMax = a[0];
    for (int i = 1; i < n; i++)
    {
        if (nMax < a[i])
        {
            nMax = a[i];
        }
    }

    // ����һ����������anCount���±��С[0, nMax]
    int *anCount = new int[nMax + 1];
    for (int i = 0; i < nMax + 1; i++)
    {
        anCount[i] = 0;
    }

    // ����ÿ��Ԫ�صĸ������Ž�anCount��
    for (int i = 0; i < n; i++)
    {
        anCount[a[i]]++;
    }
    // �����ۼ�
    for (int i = 1; i < nMax + 1; i++)
    {
        anCount[i] = anCount[i - 1] + anCount[i];
    }

    // ��ʱ����anTmp���洢�����Ľ��
    int *anTmp = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int nIndex = anCount[a[i]] - 1;   // �����±��0��ʼ

        anTmp[nIndex] = a[i];
        anCount[a[i]]--;
    }

    // ��ʱ����anTmp������a
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

































