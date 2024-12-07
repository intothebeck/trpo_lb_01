#pragma once

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

#ifdef __cplusplus
extern "C" {
#endif

Node* createNode(int data);

void initStack(Stack* stack);

void destroyStack(Stack *stack);

void push(Stack* stack, int data);

void pop(Stack* stack);

Node* searchByValue(Stack* stack, int value);

Node* searchByIndex(Stack* stack, int index);

Node* getTop(Stack* stack);

void traverseStack(Stack* stack);

bool isEmpty(Stack* stack);

#ifdef __cplusplus
}
#endif
