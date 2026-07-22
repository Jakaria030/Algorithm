#include <stdio.h>

#define MAX 5

int arr[MAX];
int front = -1, rear = -1;

int isEmpty(){
    return front == -1;
}

int isFull(){
    return rear == MAX - 1;
}

void enqueueFront(int data){

    if(isFull()){
        printf("Deque is full!\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
        arr[front] = data;
        return;
    }

    if(front == 0){
        printf("Cannot insert at front!\n");
        return;
    }

    arr[--front] = data;
}

void enqueueRear(int data){

    if(isFull()){
        printf("Deque is full!\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }else{
        rear++;
    }

    arr[rear] = data;
}

void dequeueFront(){

    if(isEmpty()){
        printf("Deque is empty!\n");
        return;
    }

    printf("Dequeue Front: %d\n", arr[front]);

    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
}

void dequeueRear(){

    if(isEmpty()){
        printf("Deque is empty!\n");
        return;
    }

    printf("Dequeue Rear: %d\n", arr[rear]);

    if(front == rear){
        front = rear = -1;
    }else{
        rear--;
    }
}

int peekFront(){

    if(isEmpty()){
        return -1;
    }

    return arr[front];
}

int peekRear(){

    if(isEmpty()){
        return -1;
    }

    return arr[rear];
}

void display(){

    if(isEmpty()){
        printf("Deque is empty!\n");
        return;
    }

    for(int i = front; i <= rear; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){

    enqueueFront(10);
    enqueueFront(20);
    enqueueFront(30);

    display();

    enqueueRear(100);
    enqueueRear(200);
    enqueueRear(300);

    display();

    dequeueFront();

    display();

    dequeueRear();

    display();

    printf("Front: %d\n", peekFront());
    printf("Rear : %d\n", peekRear());

    return 0;
}