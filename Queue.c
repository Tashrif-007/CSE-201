#include<stdio.h>
#define size 10
int queue[size];
int front=-1,rear=-1;

void enqueue(int n)
{
    if(rear == size-1){
        printf("Overflow");
        return;}
    if(front==-1)
    front=0;
    rear++;
    queue[rear]=n;
}
void dequeue()
{
    if(front==-1 || front>rear){
        printf("Underflow");
        return;
    }
    printf("Dequeued element is: %d\n", queue[front]);
    front++;
}
void print()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty");
        return;
    }
    for(int i=front; i<=rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    print();
    dequeue();
    print();
    return 0;
}
