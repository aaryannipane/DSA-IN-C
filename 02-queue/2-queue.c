#include<stdio.h>
#include<stdlib.h>
#define maxSize 5

void insert(), delete(), display();
int front=-1;
int rear=-1;
int queue[maxSize];

int main(){

    int choice;
    while(1){
        printf("\n\nQueue menu\n");
        printf("select an option:- \n");
        printf("\n1-insert\n2-delete\n3-display\n4-exit\n");
        printf("Enter any choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                insert();
                printf("\nfront: %d, rear: %d", front, rear);
                break;
            case 2: 
                delete();
                printf("\nfront: %d, rear: %d", front, rear);
                break;
            case 3:
                display();
                printf("\nfront: %d, rear: %d", front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("\nEnter valid option");
        }
    }

    return 0;
}

void insert(){
    int ele;

    if(rear== maxSize-1){
        printf("queue is full or overflow");
    }
    else{
        if(front==-1&&rear==-1){
            front = 0;
            rear = 0;
        }
        else{
            rear++;
        }
        printf("Enter number element: ");
        scanf("%d", &ele);
        queue[rear] = ele;
        display();
    }
}

void delete(){
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue[front]);
        front = front + 1;
        if(front>rear){
            front=-1;
            rear=-1;
        }
    }
}

void display(){
    if(front==-1){
        printf("queue is empty");
    }
    else{
        for(int i = front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}