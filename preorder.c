#include <stdio.h>
#include <stdlib.h>

void preorder(int size);
struct tree* create_tree();

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root=NULL;

int main() {
    int size;
    printf("Enter size of the tree:");
    scanf("%d",&size);
    root=create_tree();
    preorder(size);

    return 0;
}

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
