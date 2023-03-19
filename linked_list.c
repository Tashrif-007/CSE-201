#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*temp;

void insertbegin(int n)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data= n;
    link->next=head;
    head=link;
}
void insertlast(int n)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data= n;
    link->next= NULL;
    temp= head;
    while(temp->next!=NULL)
    temp= temp->next;

    temp->next= link;
}
void print()
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link= head;
    while(link!=NULL)
    {
        printf("%d ", link->data);
        link= link->next;
    }
}
void deletebegin()
{
    temp=head;
    head= head->next;
    free(temp);
}
void deletelast()
{
    struct node *prev;
    temp= head;
    while(temp->next!=NULL)
    {
        prev= temp;
        temp= temp->next;
    }
    if(temp==head)
    head=NULL;
    else
    prev->next= NULL;
    free(temp);
}
void delete_between(){
    struct node *link;
    temp=head;
    int pos,i=1;
    printf("\nEnter position to delete:");
    scanf("%d",&pos);

    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    link=temp->next;
    temp->next=link->next;

    free(link);
}

int len()
{
    temp=head;
    int i=0;
    while(temp!=NULL)
    {
        temp= temp->next;
        i++;
    }
    return i;
}
void insertbetween(int key, int n)
{
    int i=0;
    struct node *link=(struct node*)malloc(sizeof(struct node));
    temp=head;
    link->data= n;
    while(i<key)
    {
        temp= temp->next;
        i++;
    }
    link->next= temp->next;
    temp->next= link;
}
int main()
{
    int c,n;
    while(1){
    printf("Enter choice: \n1.Insertbegin, 2.insertend, 3.deletebegin, 4.printlist, 5.insert_between, 6.delete_last, 7.length, 8.delete_between: ");
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
    deletebegin();
    else if(c==4)
    print();
    else if(c==5)
    {
        printf("Enter value: ");
        scanf("%d", &n);
        printf("Enter position: ");
        scanf("%d", &c);
        insertbetween(c,n);
    }
    else if(c==6)
    deletelast();
    else if(c==7)
    printf("%d",len());
    else if(c==8)
    delete_between();
    else
    break;
    }
    return 0;
}
