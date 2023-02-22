#include <stdio.h>

void merge(int num[], int temp[], int left, int mid, int right)
{
    int leftend= mid-1,tmpos= left;
    int element= right-left+1;
    while(left<=leftend && mid<=right)
    {
        if(num[left]<=num[mid])
        {
            temp[tmpos++]= num[left++];
        }
        else
        temp[tmpos++]= num[mid++];
    }
    while(left<=leftend)
    temp[tmpos++]= num[left++];
    while(mid<=right)
    temp[tmpos++]= num[mid++];
    for(int i=0; i<element; i++){
    num[right]= temp[right];
    right--;}
}
void mergesort(int num[], int temp[], int left, int right)
{
    if(left<right)
    {
        int mid= (left+right)/2;
        mergesort(num, temp, left, mid);
        mergesort(num, temp, mid+1, right);
        merge(num, temp, left, mid+1, right);
    }
}
int main() {
    int num[]= {23,12,2,45,67},temp[5];
    mergesort(num, temp, 0, 4);
    for(int i=0; i<5; i++)
    printf("%d ", num[i]);
    return 0;
}
