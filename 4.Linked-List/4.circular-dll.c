#include <stdio.h>
#include <stdlib.h>

// Circular Doubly Linked List Structure
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

// Create New Node
Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// ========== Insertion ==========
// Node Insert At Beginning
Node *insertAtBeginning(Node *head, int data){
    Node *newNode = createNode(data);

    // Empty list
    if(head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    head = newNode;

    return head;
}

// Node Insert At Position (1-based indexing)
Node *insertAtPosition(Node *head, int data, int position){

    if(position < 1){
        printf("Invalid Position!\n");
        return head;
    }

    if(position == 1){
        return insertAtBeginning(head, data);
    }

    if(head == NULL){
        printf("Invalid Position!\n");
        return head;
    }

    Node *temp = head;
    int count = 1;

    while(count < position - 1 && temp->next != head){
        temp = temp->next;
        count++;
    }

    if(count != position - 1){
        printf("Invalid Position!\n");
        return head;
    }

    Node *newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Node Insert At End
Node *insertAtEnd(Node *head, int data){
    Node *newNode = createNode(data);

    // Empty list
    if(head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    return head;
}

// ========== Deletion ==========
// Node Delete From Beginning
Node *deleteFromBeginning(Node *head){

    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }

    Node *last = head->prev;
    Node *deleteNode = head;

    head = head->next;

    head->prev = last;
    last->next = head;

    free(deleteNode);

    return head;
}

// Node Delete from Position (1-based indexing)
Node *deleteFromPosition(Node *head, int position){

    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    if(position < 1){
        printf("Invalid Position!\n");
        return head;
    }

    if(position == 1){
        return deleteFromBeginning(head);
    }

    Node *temp = head;
    int count = 1;

    while(count < position && temp->next != head){
        temp = temp->next;
        count++;
    }

    if(count != position){
        printf("Invalid Position!\n");
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);

    return head;
}

// Node Delete From End
Node *deleteFromEnd(Node *head){

    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }

    Node *last = head->prev;
    Node *newLast = last->prev;

    newLast->next = head;
    head->prev = newLast;

    free(last);

    return head;
}

// ========== Reverse ==========
Node *reverse(Node *head){

    if(head == NULL || head->next == head){
        return head;
    }

    Node *curr = head;

    do{
        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    }while(curr != head);

    head = head->next;

    return head;
}

// ========== Find Length ==========
int listSize(Node *head){

    if(head == NULL){
        return 0;
    }

    int count = 0;
    Node *temp = head;

    do{
        count++;
        temp = temp->next;
    }while(temp != head);

    return count;
}

// ========== Traversal ==========
void display(Node *head){

    if(head == NULL){
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;

    do{
        printf("%d<->", temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("(Head)\n");
}

int main(){
    Node *head = NULL;

    // ========== Insert Function Call ==========
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 10);

    display(head);

    head = insertAtBeginning(head, 15);
    head = insertAtBeginning(head, 20);

    display(head);

    head = insertAtPosition(head, 50, 1);
    head = insertAtPosition(head, 40, 2);

    head = insertAtPosition(head, 99, 0);
    head = insertAtPosition(head, 99, 10);

    display(head);

    // ========== Delete Function Call ==========
    head = deleteFromBeginning(head);
    
    display(head);

    head = deleteFromPosition(head, 3);
    head = deleteFromPosition(head, 10);

    display(head);

    head = deleteFromEnd(head);
    
    display(head);

    // ========== Reverse Function Call ==========
    head = reverse(head);

    display(head);
    
    // ========== Find Length Function Call ==========
    printf("Circular Doubly Linked List Size: %d\n", listSize(head));

    return 0;
}