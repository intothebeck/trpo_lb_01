#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for new node\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Stack pointer is NULL\n");
        return;
    }
    stack->top = NULL;
}

void destroyStack(Stack* stack) {
    if (stack == NULL) return;

    Node* current = stack->top;
    while (current != NULL) {
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
    stack->top = NULL;
}

bool push(Stack* stack, int data) {
    if (stack == NULL) return false;

    Node* newNode = createNode(data);
    if (newNode == NULL) return false;

    newNode->next = stack->top;
    stack->top = newNode;
    return true;
}

bool pop(Stack* stack, int* data) {
    if (stack == NULL || stack->top == NULL) return false;

    Node* temp = stack->top;
    if (data != NULL) {
        *data = temp->data;
    }
    stack->top = stack->top->next;
    free(temp);
    return true;
}

Node* searchByValue(Stack* stack, int value) {
    if (stack == NULL) return NULL;

    Node* current = stack->top;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* searchByIndex(Stack* stack, int index) {
    if (stack == NULL || index < 0) return NULL;

    Node* current = stack->top;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

Node* getTop(Stack* stack) {
    if (stack == NULL) return NULL;
    return stack->top;
}

void traverseStack(Stack* stack) {
    if (stack == NULL) {
        printf("Stack is NULL\n");
        return;
    }

    Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool isEmpty(Stack* stack) {
    if (stack == NULL) return true;
    return stack->top == NULL;
}