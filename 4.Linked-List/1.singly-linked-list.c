#include<stdio.h>
#include<stdlib.h>

// Singly Linked List Structure
typedef struct Node{
    int data;
    struct Node *next;
} Node;

// New Node Create
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

    newNode->next = head;
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

    Node *newNode = createNode(data);
    Node *temp = head;
    int count = 1;

    // Move to the node before the desired position
    while(count < position - 1 && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(temp == NULL){
        printf("Invalid Position!\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Node Insert At End
Node *insertAtEnd(Node *head, int data){
    Node *newNode = createNode(data);

    // If the list is empty
    if(head == NULL){
        return newNode;
    }

    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

// ========== Deletion ==========
// Node Delete From Beginning
Node *deleteFromBeginning(Node *head){
    
    // If list is empty
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    free(temp);

    return head;    
}

// Node Delete From Position (1-based indexing)
Node *deleteFromPosition(Node *head, int position){
    
    // If list is empty
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    // Invalid position
    if(position < 1){
        printf("Invalid Position!\n");
        return head;
    }

    // If position is 1
    if(position == 1){
        return deleteFromBeginning(head);
    }

    Node *temp = head;
    int count = 1;

    while(count < position - 1 && temp->next != NULL){
        temp = temp->next;
        count++;
    }

    // If position not exist
    if(temp->next == NULL){
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
    
    // If list is empty
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }

    // If there is only one node
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    Node *temp = head;
    
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = NULL;
    free(deleteNode);

    return head;
}

// ========== Reverse Linked List ==========
Node *reverse(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// ========== Find Length ==========
int listSize(Node *head){
    int count = 0;

    while(head != NULL){
        head = head->next;
        count++;
    }

    return count;
}

// ========== Traversal ==========
// Display Linked List
void display(Node *head){
    while(head != NULL){
        printf("%d->", head->data);
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
    printf("Linked List Size: %d\n", listSize(head));
    return 0;
}