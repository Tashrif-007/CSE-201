#include<stdio.h>
#include<stdlib.h>

struct tree* create_tree();
void postorder(int size);

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root=NULL;

int main()
{
    int size;
    printf("Enter size of the tree:");
    scanf("%d",&size);
    root=create_tree();
    inorder(size);

    

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
