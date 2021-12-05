#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    
    // pointer to left node
    struct node *left;
    // data in node
    int data;
    // pointer to right node
    struct node *right;

}BTNode;

// pointer to root node
BTNode *root = NULL;

// function to create node
BTNode *createNode(int);

void inorder(BTNode *);
void preorder(BTNode *);
void postorder(BTNode *);


int main(){

    //assigning first node in root pointer
    root = createNode(10);

    // assigning new node to roots left 
    root->left = createNode(5);

    // assigning new node to roots right
    root->right = createNode(15);

    root->right->left = createNode(12);

    root->left->left = createNode(2);

    /* 
                       root
                        |
                        10
                      /    \
                    5       15
                   /        /
                  2       12

    inorder : 2, 5, 10, 12, 15,
    preorder : 10, 2, 5, 12, 15,
    postorder : 2, 5, 12, 15, 10,
    */

    printf("inorder : ");
    inorder(root);

    printf("\n");

    printf("preorder : ");
    preorder(root);

    printf("\n");

    printf("postorder : ");
    postorder(root);

    printf("\n");

    return 0;
}

BTNode *createNode(int x){
    BTNode *temp = (BTNode *)malloc(sizeof(BTNode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// inorder
void inorder(BTNode *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
    return;
}

// preorder
void preorder(BTNode *root){
    if(root == NULL){
        return;
    }
    printf("%d, ", root->data);
    inorder(root->left);
    inorder(root->right);
    return;
}

// postorder
void postorder(BTNode *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d, ", root->data);
    return;
}