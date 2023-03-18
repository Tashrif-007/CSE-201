#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*temp;
void insertlast(int n)
{
    struct node *link= (struct node*)malloc(sizeof(struct node));
    link->data= n;
    link->next= NULL;
    if(head==NULL)
    {
        head= link;
        temp= link;
    }
    else
    {
        temp->next= link;
        temp= link;
    }
}
void insertbegin(int n)
{
    struct node *link= (struct node*)malloc(sizeof(struct node));
    link->data= n;
    link->next= head;
    head= link;
}
void print()
{
    struct node *link= (struct node*)malloc(sizeof(struct node));
    link= head;
    while(link!=NULL)
    {
        printf("%d ", link->data);
        link= link->next;
    }
}
void deletebegin()
{
    temp= head;
    head= head->next;
    free(temp);
}
int main() {
    while(1)
    {
        int c,n;
        printf("\nEnter choice:\n1.insertbegin, 2.insertlast, 3.printlist: ");
        scanf("%d", &c);
        if(c==1)
        {
            printf("Enter value: ");
            scanf("%d", &n);
            insertbegin(n);
        }
        else if(c==2)
        {
            printf("Enter value: ");
            scanf("%d", &n);
            insertlast(n);
        }
        else if(c==3)
        {
            print();
        }
        else if(c==0)
        break;
    }
    return 0;
}
