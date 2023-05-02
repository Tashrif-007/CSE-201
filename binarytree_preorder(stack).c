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
    else if(data>root->data)
    root->right= insert(root->right, data);
    return root;
}
void preorder(struct node* root)
{
    if(root==NULL)
    return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
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
    preorder(root);
    return 0;
}
