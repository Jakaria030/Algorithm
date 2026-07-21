#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Structure
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

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

    if(head != NULL){
        head->prev = newNode;
    }

    newNode->next = head;

    return newNode;
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

    Node *temp = head;
    int count = 1;

    while(count < position - 1 && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(temp == NULL){
        printf("Invalid Position!\n");
        return head;
    }

    Node *newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return head;
}

// Node Insert At End
Node *insertAtEnd(Node *head, int data){
    Node *newNode = createNode(data);

    if(head == NULL){
        return newNode;
    }

    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// ========== Deletion ==========
// Node Delete From Beginning
Node *deleteFromBeginning(Node *head){

    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    Node *temp = head;
    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }

    free(temp);

    return head;
}


// Node Delete From Position (1-based indexing)
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

    while(count < position && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(temp == NULL){
        printf("Invalid Position!\n");
        return head;
    }

    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    temp->prev->next = temp->next;

    free(temp);

    return head;
}

// Node Delete From End
Node *deleteFromEnd(Node *head){

    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    if(head->next == NULL){
        free(head);
        return NULL;
    }

    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;

    free(temp);

    return head;
}

// ========== Reverse ==========
Node *reverse(Node *head){
    Node *temp = NULL;
    Node *curr = head;

    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if(temp != NULL){
        head = temp->prev;
    }

    return head;
}

// ========== Find Length ==========
int listSize(Node *head){
    int count = 0;

    while(head != NULL){
        count++;
        head = head->next;
    }

    return count;
}

// ========== Traversal ==========
void display(Node *head){
    while(head != NULL){
        printf("%d<->", head->data);
        head = head->next;
    }
    printf("NULL\n");
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
    printf("Doubly Linked List Size: %d\n", listSize(head));

    return 0;
}