#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int data)
{
    struct node *root= (struct node*)malloc(sizeof(struct node));
    root->data= data;
    root->left= NULL;
    root->right= NULL;
    return root;
}
struct node* insert(struct node* root, int data)
{
    if(root==NULL)
    return create(data);
    if(data<root->data)
    root->left=insert(root->left, data);
    else
    root->right= insert(root->right, data);
    return root;
}
void preorder(struct node* root, int size)
{
    struct node *stack[size];
    int top=-1;
    if(root==NULL)
    return;
    
    stack[++top]= root;
    while(top>=0)
    {
        struct node *temp = stack[top--];
        printf("%d ", temp->data);
        if(temp->right!=NULL)
        stack[++top]=temp->right;
        if(temp->left!=NULL)
        stack[++top]=temp->left;
    }
}

int main() {
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root=NULL;
    root=insert(root, 25);
    insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    preorder(root, 6);
    return 0;
}
