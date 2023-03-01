#include<stdio.h>

void swap(int *a, int *b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}
int part(int num[], int low, int high)
{
    int piv= num[high];
    int j=low-1;
    for(int i=low; i<=high-1; i++)
    {
        if(num[i]<piv)
        {
            j++;
            swap(&num[i], &num[j]);
        }
    }
    swap(&num[j+1], &num[high]);
    return j+1;
}
void quicksort(int num[], int low, int high)
{
    if(low<high)
    {
        int p= part(num, low,high);
        quicksort(num, low, p-1);
        quicksort(num, p+1,high);
    }
}
int main(){
    int num[]= {45,32,1,34,51};
    quicksort(num, 0,4);
    for(int i=0; i<5; i++)
    printf("%d ", num[i]);
    return 0;
}
