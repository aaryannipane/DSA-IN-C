#include<stdio.h>
#include<stdlib.h>

void push(), pop(), display();
int top = -1, stack[5];

int main(){

    int choice;
    while(1){
        printf("\n\nStack menu\n");
        printf("1 - PUSH\n");
        printf("2 - POP\n");
        printf("3 - DISPLAY\n");
        printf("4 - EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong choice..\n");
            break;
        }
    }

    return 0;
}

// to insert element in stack
void push(){
    int num;
    if(top <= 4){
        printf("Enter number element: ");
        scanf("%d", &num);
        top = top + 1;
        stack[top] = num;
    }
    else{
        printf("\nstack is overflowed\n");
    }
    display();
}

// to remove element from the stack
void pop(){
    int item;
    if(top > -1){
        item = stack[top];
        printf("Element removed is %d\n", item);
        top--;
    }
    else{
        printf("\nStack is underflowed\n");
    }
    display();
}

// to display elements in stack
void display(){
    int head = top;
    if(top>-1){
        while(head != -1){
            printf("%d\n", stack[head]);
            head--;
        }
    }
    else{
        printf("\nStack is empty\n");
    }
}