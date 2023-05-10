#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* create(int data)
{
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

struct node* insert(struct node* root,  int data)
{
    if(root==NULL)
    return create(data);
    if(data<=root->data)
    root->left = insert(root->left, data);
    else
    root->right = insert(root->right, data);
    return root;
}
void inorder(struct node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int minimum(struct node *root)
{
    if(root->left==NULL)
    return root->data;
    minimum(root->left);
}
int maximum(struct node* root)
{
    if(root->right==NULL)
    return root->data;
    maximum(root->right);
}
struct node* search(struct node* root, int target)
{
    if(root==NULL || root->data==target)
    return root;
    else if(target<=root->data)
    return search(root->left, target);
    else
    return search(root->right, target);
}
struct node* successor(struct node* root, int target) 
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = search(root, target);
    if (temp->right != NULL)
        return search(root, minimum(temp->right));
    struct node* successor = NULL;
    while (root != NULL) {
        if (temp->data < root->data) {
            successor = root;
            root = root->left;
        } else if (temp->data > root->data) 
            root = root->right;
         else 
            break;
    }
}
int main()
{
    int n,val;
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter nodes: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    inorder(root);
    cout<<endl;
    cout<<minimum(root)<<endl;
    cout<<maximum(root)<<endl;
    cout<<"Enter target: ";
    cin>>val;
    cout<<successor(root, val)->data;
    return 0;
}
