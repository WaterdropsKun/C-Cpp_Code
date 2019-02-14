#include <iostream>
using namespace std;

void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}
void PrintArray(char* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}


int* getNexts(char b[], int m)
{
    int* next = new int[m];
    next[0] = -1;
    int k = -1;
    for (int i = 1; i < m; ++i)
    {
        while (k != -1 && b[k + 1] != b[i])
        {
            k = next[k];
        }

        if (b[k + 1] == b[i])
        {
            ++k;
        }

        next[i] = k;
    }

    return next;
}

int kmp(char a[], int n, char b[], int m)
{
    // DebugMK
    PrintArray(b, m);

    int* next = getNexts(b, m);

    // DebugMK
    PrintArray(next, m);

    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j > 0 && a[i] != b[j])
        {
            j = next[j - 1] + 1;
        }
        if (a[i] == b[j])
        {
            ++j;
        }
        if (j == m)
        {
            return i - m + 1;
        }
    }

    return -1;
}

int main_kmp()
//int main()
{
    char a[100] = "bababacdababacdababacdeabac";
    char b[7] = { 'a', 'b' , 'a' , 'b' , 'a' , 'c' , 'd' };

    int ret = kmp(a, 100, b, 7);
    cout << ret << endl;

    return 0;
}







