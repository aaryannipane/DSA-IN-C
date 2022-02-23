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
        printf("1 - Insert (AT END)\n");
        printf("2 - Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            exit(1);
            break;
        default:
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
    int ele;
    printf("Enter data : ");
    scanf("%d", &ele);

    node *new = getnode();
    new->data = ele;
    new->next = NULL;

    if(head == NULL){
        head = new;
        printf("\nData Inserted\n\n");
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
        printf("\nData Inserted\n\n");
    }
}