#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void push(int data){
    Node *newNode = createNode(data);

    newNode->next = top;

    top = newNode;
}

void pop(){

    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }

    printf("Pop: %d\n", top->data);
    
    Node *deleteNode = top;
    top = top->next;

    free(deleteNode);
}

int peek(){
    
    if(top == NULL){
        printf("Stack is empty!\n");
        return -1;
    }

    return top->data;
}

void display(){
    Node *temp = top;

    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();

    printf("Peek: %d\n", peek());
    
    display();

    return 0;
}