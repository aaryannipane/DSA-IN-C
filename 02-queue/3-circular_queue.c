#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int cqueue[MAX];
int front=-1, rear=-1;

void insert();
void delete();
void display();

int main(){

    int choice;
    while(1){
        printf("\n\t\t--WELCOME TO CIRCULAR QUEUE--\t\t\n");
        printf("\nEnter any one choice\n1 - INSERT\n2 - DELETE\n3 - DISPLAY\n4 - EXIT\n\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        
        default:
            printf("-> OPTION NOT AVAILABLE\n");
            break;
        }
    }
    
    return 0;
}

void insert(){
    if((rear==MAX-1 && front==0) || (front==rear+1)){
        printf("\n-> Circular Queue is FULL\n");
    }
    else{
        int item;
        if(front==-1 && rear==-1){
            front = 0;
            rear = 0;
        }
        else if(rear==MAX-1 && front!=0){
            rear = 0;
        }
        else{
            rear++;
        }
        printf("Enter element: ");
        scanf("%d", &item);
        cqueue[rear] = item;
        display();
        printf("\n-> ELEMENT ENTERED SUCCESFULY\n");
    }
}

void delete(){
    if(front==-1&&rear==-1){
        printf("-> Queue has no data (QUEUE UNDERFLOW)\n");
    }
    else{
        int item;
        item = cqueue[front];
        printf("-> %d ITEM REMOVED SUCCESFULLY front=%d rear=%d\n", item, front, rear);
        
        if(front==rear){
            front = -1;
            rear = -1;
        }
        else if(front==MAX-1){
            front = 0;
        }
        else{
            front = front + 1;
        }
        
        display();
    }
}

void display(){
    if(front==-1 && rear == -1){
        printf("-> QUEUE IS EMPTY\n");
    }
    else{
        if(front<=rear){
            printf("ELEMENTS ARE --> ");
            for(int i=front; i<=rear; i++){
                printf("%d  ", cqueue[i]);
            }
        }
        else if(front>rear){
            printf("ELEMENTS ARE --> ");
            for(int i=front; i<=MAX-1;i++){
                printf("%d  ", cqueue[i]);
            }

            for(int i=0; i<=rear; i++){
                printf("%d  ", cqueue[i]);
            }
        }
    }
    
}