#include<stdio.h>

int binsearch(int num[], int left, int right, int target)
{
    if(left<=right)
    {
        int mid= (left+right)/2;
        if(num[mid]==target)
            return mid;
        if(num[mid]>target)
            return binsearch(num, left, mid-1, target);
        else
            return binsearch(num, mid+1, right, target);
    }
    return -1;
}
int main()
{
    int num[]= {12,34,56,78,90},f,t;
    printf("Enter value you want to search: ");
    scanf("%d", &t);
    f= binsearch(num, 0, 4, t);
    if(f==-1)
        printf("Not found");
    else
        printf("Value found at index %d", f);
    return 0;
}
