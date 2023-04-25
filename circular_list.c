#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL,*temp;

int len()
{
    int i=0;
    temp = head;
    do{
        temp = temp->next;
        i++;
    }while(temp!=head);
    return i;
}
void insert_first(int n)
{
    struct node *link  = (struct node*)malloc(sizeof(struct node));
    link->data = n;
    if(head==NULL)
    {
        head = link;
        tail = link;
        link->next = head;
    }
    else
    {
        link->next = head;
        head = link;
        tail->next = head;
    }
}
void insert_place(int n, int key)
{
    if(key==1)
    insert_first(n);
    else
    {
        int i=1;
        struct node *link=(struct node*)malloc(sizeof(struct node)),*prev;
        temp=head;
        link->data= n;
        while(i<key)
        {
            prev = temp;
            temp= temp->next;
            i++;
        }
        link->next= temp;
        prev->next= link;
    }
}
void insert_last(int n)
{
    struct node *link  = (struct node*)malloc(sizeof(struct node));
    link->data = n;
    if(head==NULL)
    {
        head = link;
        tail = link;
        link->next = head;
    }
    else
    {
        tail->next = link;
        tail = link;
        tail->next = head;
    }
}
void delete_first()
{
    temp = head;
    if(head==NULL)
    printf("List already empty");
    else if(head==tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        tail->next = head;
        free(temp);
    }
}
void delete_place(int key)
{
    if(key==1)
    delete_first();
    else if(key==len())
    delete_last();
    else
    {
        int i=1;
        temp = head;
        struct node *prev;
        while(i<key)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        free(temp);
    }
}
void delete_last()
{
    if(head==NULL)
    printf("List already empty");
    else if(head==tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = tail;
        do{
            temp = temp->next;
        }while(temp->next!=tail);
        temp->next=head;
        tail=temp;
    }
}
void print()
{
    temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp!=head);
}
int main() {
    insert_last(1);
    insert_last(2);
    insert_first(3);
    insert_first(4);
    delete_place(2);
    print();
    return 0;
}
