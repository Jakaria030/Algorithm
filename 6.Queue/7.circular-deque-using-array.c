#include <stdio.h>

#define MAX 5

int arr[MAX];
int front = -1, rear = -1;

int isEmpty(){
    return front == -1;
}

int isFull(){
    return (rear + 1) % MAX == front;
}

void insertFront(int data){

    if(isFull()){
        printf("Deque is full!\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }else{
        front = (front - 1 + MAX) % MAX;
    }

    arr[front] = data;
}

void insertRear(int data){

    if(isFull()){
        printf("Deque is full!\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }else{
        rear = (rear + 1) % MAX;
    }

    arr[rear] = data;
}

void deleteFront(){

    if(isEmpty()){
        printf("Deque is empty!\n");
        return;
    }

    printf("Delete Front: %d\n", arr[front]);

    if(front == rear){
        front = rear = -1;
    }else{
        front = (front + 1) % MAX;
    }
}

void deleteRear(){

    if(isEmpty()){
        printf("Deque is empty!\n");
        return;
    }

    printf("Delete Rear: %d\n", arr[rear]);

    if(front == rear){
        front = rear = -1;
    }else{
        rear = (rear - 1 + MAX) % MAX;
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

    int i = front;

    while(i != rear){
        printf("%d ", arr[i]);
        i = (i + 1) % MAX;
    }

    printf("%d\n", arr[rear]);
}

int main(){

    insertRear(10);
    insertRear(20);
    insertRear(30);

    insertFront(5);
    insertFront(1);

    display();

    deleteFront();
    deleteRear();

    display();

    printf("Front: %d\n", peekFront());
    printf("Rear : %d\n", peekRear());

    return 0;
}