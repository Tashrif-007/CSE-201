#include <bits/stdc++.h>
using namespace std;

void heapify(int num[], int size, int i)
{
    int l=2*i +1;
    int r=2*i +2;
    int largest;
    if(l<size && num[l]>num[i])
    largest = l;
    else
    largest=i;
    if(r<size && num[r]>num[largest])
    largest=r;
    if(largest!=i){
    swap(num[i],num[largest]);
    heapify(num,size,largest);}
}
void create(int num[], int size)
{
    for(int i=size/2 -1; i>=0; i--)
    heapify(num, size, i);
}

void heapsort(int num[], int size)
{
    create(num,size);
    for(int i=size-1; i>0; i--)
    {
        swap(num[0], num[i]);
        heapify(num,i,0);
    }
}

void insert(int num[], int *size, int n)
{
    *size = *size +1;
    num[*size-1]=n;
    int i=*size-1;
    
    while(i>0)
    {
        int parent = (i-1)/2;
        if(num[parent]<num[i]){
        swap(num[parent], num[i]);
        i = parent;
        }
        else
        return;
    }
}
int extractMax(int num[], int &size)
{
    if (size <= 0) {
        cout << "Heap is empty!" << endl;
        return -1; 
    }
    int maxElement = num[0];
    num[0] = num[size - 1]; 
    size--;
    heapify(num, size, 0); 

    return maxElement;
}

int main() {
    int num[]={2,34,1,45,64},n=5;
    cout<<"Original Array: ";
    for(int i=0; i<5; i++)
    cout<<num[i]<<" ";
    create(num,n);
    cout<<"\n"<<"Heapified Array: ";
    for(int i=0; i<5; i++)
    cout<<num[i]<<" ";
    cout<<"\nMax extracted: "<<extractMax(num,n)<<endl;
    for(int i=0; i<4; i++)
    cout<<num[i]<<" ";
    cout<<endl;
    heapsort(num,n);
    cout<<"Heapsorted: ";
    for(int i=0; i<4; i++)
    cout<<num[i]<<" ";
    return 0;
}
