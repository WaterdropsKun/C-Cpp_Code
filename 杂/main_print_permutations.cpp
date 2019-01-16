#include <iostream>

void PrintPermutations(int a[], int n, int k)
{
    if (k == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < k; ++i)
    {
        int tmp = a[i];
        a[i] = a[k - 1];
        a[k - 1] = tmp;

        PrintPermutations(a, n, k - 1);
        
        tmp = a[i];
        a[i] = a[k - 1];
        a[k - 1] = tmp;
    }
}

int main_print_permutations()
//int main()
{
    int a[] = { 1, 2, 3, 4 };

    PrintPermutations(a, 4, 4);
}



















