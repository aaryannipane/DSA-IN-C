#include<stdio.h>
#include<stdlib.h>

typedef struct nd{
    int data;
    struct nd *next;
}node;

node *getnode(void);
void insert(void);

node *head = NULL;

int main(){

    int choice;
    while (1)
    {
        printf("\n\t\tSingly Linked List\n\n");
        printf("Linked List menu\n");
        printf("1 - Insert (AFTER SOME NODE)\n");
        printf("2 - Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("Wrong Choice inserted");
            break;
        }
    }
    
    
}

node *getnode(){
    // creating memory for node
    node *newNode = (node *) malloc(sizeof(node));
    return newNode;
}


void insert(){
    int ele, key;
    printf("Enter position : ");
    scanf("%d", &key);

    fflush(stdin);

    printf("Enter data : ");
    scanf("%d", &ele);

    node *new = getnode();
    new->data = ele;
    new->next = NULL;

    if(key == 1){
        new->next = head;
        head = new;
    }
    else{
        node *prev = head;
        int count = 1;
        while(count < key - 1){
            prev = prev->next;
            count++;
        }
        new->next = prev->next;
        prev->next = new;
    }
}

// void insert(){
//     int ele;
//     printf("Enter data : ");
//     scanf("%d", &ele);
//     // fflush(stdin);

//     node *new = getnode();
//     new->data = ele;
//     new->next = NULL;

//     if(head == NULL){
//         head = new;
//         printf("First Node Inserted\n");
//     }
//     else{
//         int key;
//         node *prev = head;
//         node *temp = head->next; 
//         printf("Enter Key : ");
//         scanf("%d", &key);
//         while(prev->data != key){
//             prev = temp;
//             temp = temp->next;
//         }

//         prev->next = new;
//         new->next = temp;

//         printf("Node Inserted Succesfully\n");
//     }
    
// }