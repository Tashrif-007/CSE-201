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
    if(head==NULL)
    {
        head= link;
        temp= link;
    }
    else
    {
        temp->next= link;
        temp=link;
    }
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
    temp=head;
    int i=0;
    int j= len();
    while(i<j-2)
    {
        temp= temp->next;
        i++;
    }
    temp->next=NULL;
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
    printf("Enter choice: \n1.Insertbegin, 2.insertend, 3.deletebegin, 4.printlist: ");
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
    else
    break;
    }
    return 0;
}
