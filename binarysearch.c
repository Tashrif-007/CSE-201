#include<stdio.h>
#include<time.h>
int binsearch(int num[], int low, int high, int target)
{
    if(low<=high)
    {
        int mid= (low+high)/2;
        if(num[mid]==target)
        return mid;

        else if(num[mid]>target)
        return binsearch(num, low, mid-1, target);

        else if(num[mid]<target)
        return binsearch(num, mid+1, high, target);
    }
    return -1;
}
int main()
{
    clock_t start, end;
    start= clock();
    int num[10000],target;
    for(int i=0; i<10000; i++)
    num[i]= i+1;
    target= num[(0+9999)/2];
    int res= binsearch(num, 0, 9999, target);
    if(res==-1)
    printf("Not found");
    else
    printf("Found at %d", res);
    end= clock();
    printf("\nTime: %f", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
