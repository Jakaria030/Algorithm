#include<stdio.h>
#define MAX 5

int arr[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
    return front == -1;
}

int isFull(){
    return (rear + 1) % MAX == front;
}

void enqueue(int data){
    
    if(isFull()){
        printf("Queue is full!\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
        arr[rear] = data;
        return;
    }

    rear = (rear + 1) % MAX;
    arr[rear] = data;
}

void dequeue(){

    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }

    if(front == rear){
        printf("Dequeue: %d\n", arr[front]);
        front = rear = -1;
        return;
    }

    printf("Dequeue: %d\n", arr[front]);
    front = (front + 1) % MAX;
}

int peek(){

    if(isEmpty()){
        return -1;
    }

    return arr[front];
}

void display(){
    
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }

    int i = front;
    while(i != rear){
        printf("%d ", arr[i]);
        i = (i + 1) % MAX;
    }
   
    printf("%d\n", arr[rear]);
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    display();

    dequeue();
    dequeue();

    display();

    printf("Peek: %d\n", peek());

    return 0;
}