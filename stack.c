#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL, *temp;

void push(int n)
{
    struct node *link = (struct node*)malloc(sizeof(struct node));
    link->data = n;
    link->next = top;
    top = link;
}
void pop()
{
    temp = top;
    if(temp==NULL)
    printf("Underflow");
    else{
    top = top->next;
    free(temp);
    }
}
void print()
{
    temp = top;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    push(3);
    push(4);
    push(5);
    print();
    pop();
    printf("\n");
    print();
    return 0;
}
