#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

void insert();
void delete();
void display();

int mpQueue[MAX];
int front=-1, rear=-1;
int itemcount = 0;

int main(){

    int choice;
    printf("\n\t\t<--MINIMUM PRIORITY QUEUE-->\n");
    while(1){
        printf("\nEnter any one choice:-\n1 - insert\n2 - delete\n3 - display\n4 - exit\n");
        printf("choice -> ");
        scanf("%d", &choice);
        switch(choice){
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
                exit(1);
            default:
                printf("--> Select correct option\n");
        }
    }

    return 0;
}

void insert(){
    if(rear==MAX-1){
        printf("--> MIN PROPRITY QUEUE IS FULL (overflow)\n");
        return;
    }
    else{
        int item;
        printf("Enter number : ");
        scanf("%d", &item);

        if(front==-1 && rear==-1){
            front=0;
            rear=0;
            mpQueue[rear]=item;
            itemcount = itemcount + 1;
            display();
        }
        else{
            int i = itemcount - 1;
            while(i>=0){
                // ascending order sorting from back of array
                if(item < mpQueue[i]){
                    mpQueue[i+1] = mpQueue[i];
                }
                else{
                    break;
                }
                i--;
            }

            mpQueue[i+1] = item;
            printf("--> %d item inserted succesfully\n", item);
            itemcount++;
            rear++;
            display();
        }
    }
}

void delete(){
    if(front==-1 && rear==-1){
        printf("--> QUEUE IS EMPTY (underflow)\n");
    }
    else{
        int ele = mpQueue[front];
        itemcount--;
        printf("--> %d deleted succesfully\n", ele);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        display();
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("--> QUEUE IS EMPTY (underflow)\n");
    }
    else{
        printf("--> MIN PRIORITY QUEUE [");
        for(int j=front; j<=rear; j++){
            printf("%d  ", mpQueue[j]);
        }
        printf("]\n");
    }
}