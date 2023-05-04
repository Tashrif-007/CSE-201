#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root=NULL;


struct tree* create_tree(){
    struct tree *newtree;
    newtree=(struct tree*)malloc(sizeof(struct tree));
    int value;
    printf("Enter data:(-1 for no node):");
    scanf("%d",&value);

    if(value==-1) return 0;
    newtree->data=value;
    printf("\nEnter left child of %d :\n",value);
    newtree->left=create_tree();

    printf("\nEnter right child of %d :\n",value);
    newtree->right=create_tree();


    return newtree;

}

void preorder(int size)
{
    struct tree *stack[size];
    int top=-1;
    if(root==NULL)
    return;

    stack[++top]= root;
    while(top>=0)
    {
        struct tree *temp = stack[top--];
        printf("%d ", temp->data);
        if(temp->right!=NULL)
        stack[++top]=temp->right;
        if(temp->left!=NULL)
        stack[++top]=temp->left;
    }
}
void level_order(int size)
{
    struct tree *queue[size];
    int front=0,rear=0,level=1;
    if(root==NULL)
    return;
    queue[rear++]=root;

    while(front<rear)
    {
        struct tree *temp = queue[front++];
        printf("%d ", temp->data);
        level--;

        if(temp->left!=NULL)
        queue[rear++]=temp->left;
        if(temp->right!=NULL)
        queue[rear++]=temp->right;
        if(level==0){
        printf("\n");
        level = rear-front;
        }
    }
}
void inorder(int size)
{
    struct tree *stack[size];
    int top=-1;
    struct tree *temp = root;
    while(temp!=NULL || top!=-1)
    {
        while(temp!=NULL)
        {
            stack[++top]= temp;
            temp= temp->left;
        }
        temp = stack[top--];
        printf("%d ", temp->data);
        temp= temp->right;
    }
}
void postorder(int size){
    struct tree *stack[size],*current, *lastvisited,*peek;
    int top=-1;
    current=root;
    lastvisited=NULL;


    while(current!=NULL || top!=-1){
        while(current!=NULL){
            stack[++top]=current;
            current=current->left;

        }
        peek=stack[top];
        if(peek->right==NULL || peek->right==lastvisited){
            printf("%d ",peek->data);
            lastvisited=peek;
            top--;
        }else{
            current=peek->right;
        }

    }
}
int main() {
    int size;
    printf("Enter size of the tree:");
    scanf("%d",&size);
    root=create_tree();
    inorder(size);

    return 0;
}
