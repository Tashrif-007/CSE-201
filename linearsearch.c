#include<stdio.h>
#include<time.h>
void linsearch(int num[], int size, int target)
{
    int i=0;
    while(i<size)
    {
        if(num[i]==target)
        {
            printf("Found");
            break;
        }
        i++;
    }
    if(i==size)
    printf("Not found");
}
int main()
{
    clock_t s,e;
    s= clock();
    int num[100000],target;
    for(int i=0; i<100000; i++)
    num[i]= rand();
    target= num[0];
    linsearch(num, 100000,target);
    e= clock();
    printf("\nTime: %f", (double)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
