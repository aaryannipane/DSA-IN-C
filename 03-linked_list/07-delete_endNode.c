// PERFECT CODE FOR DELETION

#include<stdio.h>
#include<stdlib.h>

typedef struct nd{
    int data;
    struct nd *next;
}node;

node *getnode(void);
void insert(void);
void display(void);
void delete(void);

node *head = NULL;

int main(){

    int choice;
    while (1)
    {
        printf("\n\t\tSingly Linked List\n\n");
        printf("Linked List menu\n");
        printf("1 - Insert (AT END)\n");
        printf("2 - Display\n");
        printf("3 - Delete (FROM END)\n");
        printf("4 - Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 4:
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

    node *new = getnode();
    new->data = ele;
    new->next = NULL;

    if(head == NULL){
        head = new;
        printf("\nData Inserted\n\n");
        display();
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new;
        printf("\nData Inserted\n\n");
        display();
    }

}

void display(){
    if(head == NULL){
        printf("--> Linked list is empty\n");
    }
    else{
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }    
    }
}

void delete(){
    
    if(head == NULL){
        printf("Linked List is Empty\n");
    }
    else{

        if(head->next == NULL){
            printf("data removed is %d\n", head->data);
            free(head);
            head = NULL;
        }
        else{
            node *temp = head;
            node *prev;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            printf("data removed is %d\n", temp->data);
            free(temp);
        }

    }
    display();

}