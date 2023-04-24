#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL,*temp;

void insert_begin(int n)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data=n;
    if(head==NULL)
    {
        head=link;
        tail=link;
        link->next=head;
    }
    else
    {
        link->next=head;
        head=link;
        temp=head;
        tail->next=head;
    }
}
void insert_end(int n)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data=n;
    if(head==NULL)
    {
        head=link;
        tail=link;
        link->next=head;
    }
    else
    {
        tail->next=link;
        tail=link;
        tail->next=head;
    }
}
void print()
{
    temp=head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp!=head);
}
int main()
{
    insert_end(325);
    insert_end(51);
    insert_begin(555);
    insert_end(53);
    print();
    return 0;
}
