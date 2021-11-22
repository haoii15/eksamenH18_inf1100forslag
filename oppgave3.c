#include <stdlib.h>
#include <stdio.h>

void random_array(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 2;
    }
}

int forekommer(int *A, int n, int k)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == k)
        {
            count++;
        }
    }

    return count;
}

void sorter(int *A, int n)
{
    int temp;
    int sorted = 0;

    while (!sorted)
    {
        sorted = 1;

        for (int i = 0; i < n; i++)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                sorted = 0;
            }
        }
    }
}

int majoritetselement(int *A, int n)
{
    sorter(A, n);

    int midten = A[n/2];

    int antall_midten = forekommer(A, n, midten);

    if (antall_midten > n/2)
        return 1;
    
    else 
        return 0;
}

int main()
{
    int n = 1000;
    int k = 17;
    int *A = malloc(sizeof(int) * n);

    random_array(A, n);

    printf("majoritetselement: %d\n", majoritetselement(A, n));
}