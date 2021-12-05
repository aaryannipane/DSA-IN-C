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


int main(){

    //assigning first node in root pointer
    root = createNode(10);

    // assigning new node to roots left 
    root->left = createNode(5);

    // assigning new node to roots right
    root->right = createNode(15);

    root->right->left = createNode(12);

    /* 
                       root
                        |
                        10
                      /    \
                    5       15
                           /
                         12

    */

    // print root value
    printf("root: %d\n", root->data);
    // print left node of root
    printf("left child: %d\n", root->left->data);
    // print right node of root
    printf("right child: %d\n", root->right->data);

    return 0;
}

BTNode *createNode(int x){
    BTNode *temp = (BTNode *)malloc(sizeof(BTNode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}