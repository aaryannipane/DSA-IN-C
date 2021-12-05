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
        printf("1 - Insert (AT BEGINNING)\n");
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
    int ele;
    printf("Enter data : ");
    scanf("%d", &ele);
    fflush(stdin);

    node *new = getnode();
    new->data = ele;
    new->next = NULL;

    if(head == NULL){
        head = new;
        printf("\nFirst Node Inserted\n");
    }
    else{
        node *temp = head;
        head = new;
        new->next = temp;
        printf("\nNode Inserted\n");
    }

}