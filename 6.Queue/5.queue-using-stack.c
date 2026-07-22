#include<stdio.h>

#define MAX 5

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack operations
int isFull(int top){
    return top == MAX - 1;
}

int isEmpty(int top){
    return top == -1;
}

void push1(int data){
    if(isFull(top1)){
        printf("Stack 1 is full!\n");
        return;
    }
    stack1[++top1] = data;
}

void push2(int data){
    if(isFull(top2)){
        printf("Stack 2 is full!\n");
        return;
    }
    stack2[++top2] = data;
}

int pop1(){
    if(isEmpty(top1)){
        return -1;
    }

    return stack1[top1--];
}

int pop2(){
    if(isEmpty(top2)){
        return -1;
    }

    return stack2[top2--];
}

void transerToStack1(){
    while(!isEmpty(top2)){
        push1(pop2());
    }
}

void transerToStack2(){
    while(!isEmpty(top1)){
        push2(pop1());
    }
}

// Queue operations
void enqueue(int data){
    push1(data);
}

void dequeue(){
    transerToStack2();

    if(isEmpty(top2)){
        printf("Queue is empty!\n");
        return;
    }

    printf("Dequeue: %d\n", pop2());

    transerToStack1();
}

int peek(){
    transerToStack2();

    if(isEmpty(top2)){
        return -1;
    }

    int value = stack2[top2];

    transerToStack1();

    return value;
}

// Display queue elements
void display(){
    if(isEmpty(top1)){
        printf("Queue is empty!\n");
        return;
    }

    for(int i = 0; i <= top1; i++){
        printf("%d ", stack1[i]);
    }

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

    enqueue(50);
    enqueue(60);

    display();

    printf("Peek: %d\n", peek());

    return 0;
}