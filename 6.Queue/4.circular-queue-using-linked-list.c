#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int isEmpty(){
    return head == NULL;
}

void enqueue(int data){
    Node *newNode = createNode(data);

    if(isEmpty()){
        head = tail = newNode;
        tail->next = newNode;
        return;
    }

    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

void dequeue(){

    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    
    Node *deletedNode = head;
    
    if(head == tail){
        head = tail = NULL;
        printf("Dequeue: %d\n", deletedNode->data);
        free(deletedNode);
        return;
    }

    head = head->next;
    tail->next = head;
    printf("Dequeue: %d\n", deletedNode->data);
    free(deletedNode);
}

int peek(){

    if(isEmpty()){
        return -1;
    }

    return head->data;
}

void display(){

    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }

    Node *temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    
    printf("\n");
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();

    dequeue();
    dequeue();

    display();

    printf("Peek: %d\n", peek());

    return 0;
}