#include<stdio.h>
#define MAX 5

int top = -1;
int arr[MAX];

void push(int data){
    
    if(top == MAX-1){
        printf("Stack is Full!\n");
        return;
    }

    arr[++top] = data;
}

void pop(){
    
    if(top == -1){
        printf("Stack is empty!\n");
        return;
    }

    printf("Popped: %d\n", arr[top]);
    top--;
}

int peek(){
    
    if(top == -1){
        printf("Stack is empty!\n");
        return -1;
    }

    return arr[top];
}

void display(){

    if(top == -1){
        printf("Stack is empty!\n");
        return;
    }

    int temp = top;

    while(temp != -1){
        printf("%d\n", arr[temp]);
        temp--;
    }
}

int main(){
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    pop();

    printf("Peek: %d\n", peek());
    
    display();

    return 0;
}