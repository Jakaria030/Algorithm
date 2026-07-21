#include<stdio.h>
#include<stdlib.h>

// Circular Singly Linked List Structure
typedef struct Node{
    int data;
    struct Node *next;
} Node;

// Create New Node
Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
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
        return newNode;
    }

    Node *temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    return head;
}

// Node Insert At Position (1-based indexing)
Node *insertAtPosition(Node *head, int data, int position){

    // Invalid position
    if(position < 1){
        printf("Invalid Position!\n");
        return head;
    }

    // Insert at beginning
    if(position == 1){
        return insertAtBeginning(head, data);
    }

    // Empty list but position > 1
    if(head == NULL){
        printf("Invalid Position!\n");
        return head;
    }

    Node *temp = head;
    int count = 1;

    // Move to the node before the desired position
    while(count < position - 1 && temp->next != head){
        temp = temp->next;
        count++;
    }

    // Position is beyond the list size
    if(count != position - 1){
        printf("Invalid Position!\n");
        return head;
    }

    Node *newNode = createNode(data);

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Node Insert At End
Node *insertAtEnd(Node *head, int data){
    Node *newNode = createNode(data);

    // Empty list
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// ========== Deletion ==========
// Node Delete From Beginning
Node *deleteFromBeginning(Node *head){

    // Empty list
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    // Only one node
    if(head->next == head){
        free(head);
        return NULL;
    }

    Node *temp = head;

    // Find the last node
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = head->next;

    Node *deleteNode = head;
    head = head->next;
    free(deleteNode);

    return head;
}

// Node Delete From Position (1-based indexing)
Node *deleteFromPosition(Node *head, int position){

    // Empty list
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    // Invalid position
    if(position < 1){
        printf("Invalid Position!\n");
        return head;
    }

    // Delete first node
    if(position == 1){
        return deleteFromBeginning(head);
    }

    Node *temp = head;
    int count = 1;

    // Move to the node before the desired position
    while(count < position - 1 && temp->next != head){
        temp = temp->next;
        count++;
    }

    // Position doesn't exist
    if(temp->next == head){
        printf("Invalid Position!\n");
        return head;
    }

    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);

    return head;
}

// Node Delete From End
Node *deleteFromEnd(Node *head){

    // Empty list
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    // Only one node
    if(head->next == head){
        free(head);
        return NULL;
    }

    Node *temp = head;

    // Move to the second last node
    while(temp->next->next != head){
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = head;
    free(deleteNode);

    return head;
}

// ========== Reverse Circular Linked List ==========
Node *reverse(Node *head){

    // Empty list or only one node
    if(head == NULL || head->next == head){
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    do{
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }while(curr != head);

    // Make the old head point to the last node
    head->next = prev;

    return prev;
}

// ========== Find Length ==========
int listSize(Node *head){

    // Empty list
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
    Node *temp = head;

    while(temp->next != head){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->NULL\n", temp->data);
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
    printf("Cicular Linked List Size: %d\n", listSize(head));

    return 0;
}