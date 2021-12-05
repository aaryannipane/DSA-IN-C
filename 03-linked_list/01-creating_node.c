#include<stdio.h>
#include<stdlib.h>


typedef struct nd{
    int data;
    struct nd *next;
}node;     // given another name to struct nd as node

node *getnode(void);

int main(){

    node *first = getnode();
    first->data = 10;
    first->next = NULL;

    printf("data inside node is %d\nnext value inside node is %d\n", first->data, first->next);

    return 0;
}

node *getnode(){
    // creating memory for node
    node *new = (node *) malloc(sizeof(node));
    printf("value of pointer is %d\n", new->next);
    return new;
}