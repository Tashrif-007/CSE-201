#include<stdio.h>

void insertion_sort(int num[], int n)
{
    int i,j,temp;
    for(i=1; i<n; i++)
    {
        temp= num[i];
        j=i-1;
        while(j>=0 && num[j]>temp)
        {
            num[j+1]= num[j];
            j--;
        }
        num[j+1]= temp;
    }
}
int main()
{
    int num[]={45,32,1,55,76};
    insertion_sort(num, 5);
    for(int i=0; i<5; i++)
    printf("%d ", num[i]);
    return 0;
}
