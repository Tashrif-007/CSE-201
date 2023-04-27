#include<stdio.h>
#define size 10
int stack[size];
int top=-1;

void push(int n)
{
    if(top==size-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=n;
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[top]);
    top--;
}
void peek()
{
    if(top==-1)
    {
        printf("Stack empty");
        return;
    }
    printf("%d\n", stack[top]);
}
void print()
{
    if(top==-1)
    {
        printf("Stack empty\n");
        return;
    }
    for(int i=top; i>=0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}
int main()
{
    push(1);
    push(2);
    push(3);
    print();
    pop();
    peek();
    print();
    return 0;
}
