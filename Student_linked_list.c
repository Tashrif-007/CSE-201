#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int marks, roll;
    struct student *next;
};

struct student *head=NULL,*temp;

void insert(int m, int r){
    struct student *link= (struct student*)malloc(sizeof(struct student));
    link->marks= m;
    link->roll= r;
    link->next= NULL;
    temp= head;
    if(temp==NULL)
    head = link;
    else
    {
    while(temp->next!=NULL)
    temp= temp->next;

    temp->next= link;
    }
}
void print()
{
    struct student *link=(struct student*)malloc(sizeof(struct student));
    link= head;
    printf("\n");
    while(link!=NULL)
    {
        printf("%d %d\n", link->marks, link->roll);
        link= link->next;
    }

}
void insertbetween(int key, int m, int r)
{
    int i=0;
    struct student *link=(struct student*)malloc(sizeof(struct student));
    temp=head;
    link->marks= m;
    link->roll=r;
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
    int marks[100],roll[100],t,temp_marks[100], temp_roll[100], m,r,pos,i;
    char ch[10];
    for(i=0; i<5; i++)
    {
        scanf("%d %d", &marks[i], &roll[i]);
        temp_marks[i]= marks[i];
        temp_roll[i] = roll[i];
    }
    for(i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(temp_marks[i]<temp_marks[j])
            {
                t= temp_marks[i];
                temp_marks[i]= temp_marks[j];
                temp_marks[j]= t;
                t= temp_roll[i];
                temp_roll[i]= temp_roll[j];
                temp_roll[j]= t;
            }
        }
    }

    for(i=0; i<5; i++)
    insert(temp_marks[i], temp_roll[i]);

    print();

    printf("Do you want to insert more marks?: ");
    scanf("%s", ch);
    if(!strcmp(ch, "yes"))
    {
        printf("Enter marks and roll: ");
        scanf("%d %d", &m, &r);
        marks[i]= m;
        roll[i]= r;
        printf("Enter position: ");
        scanf("%d", &pos);
        insertbetween(pos, m, r);
        print();
    }

    return 0;
}
