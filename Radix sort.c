#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Max(int num[], int n)
{
    int max = num[0];
    for (int i = 1; i < n; i++)
        if (num[i] > max)
            max = num[i];
    return max;
}

void countSort(int num[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(num[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (i = n - 1; i >= 0; i--) {
        output[count[(num[i] / exp) % 10] - 1] = num[i];
        count[(num[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        num[i] = output[i];
}


void radixsort(int num[], int n)
{

    int m = Max(num, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(num, n, exp);
}

int main()
{
    clock_t s,e;
    s= clock();
    int n=10;
    int num[n];
    for(int i=0; i<n; i++)
    {
        num[i]=rand();
    }
    radixsort(num, n);
    for(int i=0; i<n; i++)
    printf("%d ", num[i]);
    e= clock();
    printf("\ntime: %f", (double)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
