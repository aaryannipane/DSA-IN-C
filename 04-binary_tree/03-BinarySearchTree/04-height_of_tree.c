#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>  // imp to include this file to use bool data type

// structure to store node
typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}BstNode;

// getnode function to create node in memory
BstNode *getNode(int);
// insert function to insert data in binary search tree
BstNode *insert(BstNode*, int);

void traverse(BstNode*);
void inorder(BstNode*);
void preorder(BstNode*);
void postorder(BstNode*);

bool search(BstNode*, int);
// to delete node in tree
BstNode* delete(BstNode*, int);

// function to m=find minimum value in tree
BstNode *findMin(BstNode*);

// function to find max number of 2
int max(int, int);
// function to find height of a tree
int findHeight(BstNode*);


int main(){

    // root pointer to first node (root node)
    BstNode *root = NULL;
    int data;
    int height;

    int choice;
    while (1)
    {
        printf("\n \t\t\t BINARY SEARCH TREE PROGRAM \n");
        printf("Choose any choice : \n");
        printf("1 -> insert\n");
        printf("2 -> traverse\n");
        printf("3 -> search\n");
        printf("4 -> delete\n");
        printf("5 -> Height of tree\n");
        printf("6 -> exit\n");
        printf("Your Choice : ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            fflush(stdin);
            root = insert(root, data);
            break;
        case 2:
            traverse(root);
            break;
        case 3:
            printf("Enter value to search in BST: ");
            scanf("%d", &data);
            bool found = search(root, data);
            if(found){
                printf("Data Found in BST\n");
            }
            else{
                printf("Data Not Found in BST\n");
            }

            break;
        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = delete(root, data);
            break;
        case 5:
            height = findHeight(root);
            printf("\n\n Height of Tree is %d \n\n", height);
            break;
        case 6:
            exit(1);
        default:
            printf("------> Enter correct choice\n");
            break;
        }
    }
    


    return 0;
}

// getnode defination
BstNode *getNode(int data){
    BstNode *newNode = (BstNode *)malloc(sizeof(BstNode));
    newNode->left = NULL;
    newNode->data = data;
    newNode->right = NULL;
    return newNode;
}

// insertion defination using BST properties
BstNode *insert(BstNode *root, int data){
    if(root == NULL){
        root = getNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
        printf("--> left\n");
    }
    else{
        root->right = insert(root->right, data);
        printf("--> right\n");
    }

    return root;
}

// traversal techniques
// inorder
void inorder(BstNode *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
    return;
}

// preorder
void preorder(BstNode *root){
    if(root == NULL){
        return;
    }
    printf("%d, ", root->data);
    inorder(root->left);
    inorder(root->right);
    return;
}

// postorder
void postorder(BstNode *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d, ", root->data);
    return;
}

void traverse(BstNode* root){

    if(root == NULL){
        printf("---> BST is Empty\n");
        return;
    }
    char choice;
    printf("Select which type of traversel you want :\n");;
    printf("\t a -> inorder\n");
    printf("\t b -> preorder\n");
    printf("\t c -> postorder\n");
    printf("\t You Choice : ");
    scanf("%c", &choice);

    switch(choice){
        case 'a':
            inorder(root);
            break;
        case 'b':
            preorder(root);
            break;
        case 'c':
            postorder(root);
            break;
        default:
            printf("\t Enter correct choice\n");
            break;
    }
}

bool search(BstNode* root, int data){
    if(root == NULL){
        return 0;
    }
    else if(root->data == data){
        return 1;
    }
    else if(data <= root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

BstNode* delete(BstNode* root, int data){
    if(root == NULL){
        printf("--> Tree is empty\n");
        return root;
    }
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else if(data < root->data){
        root->left = delete(root->left, data);
    }
    else{
        // case 1: No child
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
            return root;
        }
        // case 2: One Child
        else if(root->left == NULL){
            BstNode *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if(root->right == NULL){
            BstNode *temp = root;
            root = root->left;
            free(root);
            return root;
        }
        // case 3: Two Children
        else{
            BstNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            return root;
        }
    }

}

BstNode *findMin(BstNode *root){

    if(root->left == NULL){
        return root;
    }

    return findMin(root->left);
}

int max(int a, int b){
    return ((a > b)?a:b);
}

int findHeight(BstNode* root){
    if(root == NULL){
        return -1;
    }

    return max(findHeight(root->right), findHeight(root->left)) + 1;
}