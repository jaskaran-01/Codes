#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top; 
    top = newNode; 
}
int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next; 
    free(temp); 
    return poppedValue;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* current = top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(2000);
    display();
    
    printf("Popped element is %d\n", pop()); 
    
    display();
    
    return 0;
}

