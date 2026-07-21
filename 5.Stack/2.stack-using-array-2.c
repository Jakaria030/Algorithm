#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int *arr;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity){
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(capacity * sizeof(int));

    if(stack->arr == NULL){
        printf("Memory allocation failed!\n");
        free(stack);
        exit(1);
    }

    return stack;
}

void push(Stack *stack, int data){
    
    if(stack->top == stack->capacity-1){
        printf("Stack is full!\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = data;
}

void pop(Stack *stack){

    if(stack->top == -1){
        printf("Stack is empty!\n");
        return;
    }

    printf("Pop: %d\n", stack->arr[stack->top]);
    stack->top--;
}

int peek(Stack *stack){

    if(stack->top == -1){
        printf("Stack is empty!\n");
        return -1;
    }

    return stack->arr[stack->top];    
}

void display(Stack *stack){

    if(stack->top == -1){
        printf("Stack is empty!\n");
        return;
    }

    while(stack->top != -1){
        printf("%d\n", stack->arr[stack->top]);
        stack->top--;
    }
}

int main(){
    Stack *stack = createStack(5);

    pop(stack);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
    pop(stack);
    
    printf("Peek: %d\n", peek(stack));

    display(stack);

    return 0;
}