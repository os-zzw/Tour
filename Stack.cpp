//
// Created by john on 2016/11/14.
//

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;


void push(Stack *stack, StackNode *node, int &count) {
    count++;
    node->link = stack->top;
    stack->top = node;
}


StackNode *pop(Stack *stack, int &count) {
    count--;
    stack->top = stack->top->link;
    return stack->top;
}


void push2(Stack *stack, StackNode *node, int &count) {
    count++;
    node->link = stack->top;
    stack->top = node;
}

StackNode *pop2(Stack *stack, int &count) {
    count--;
    stack->top = stack->top->link;
    return stack->top;
}
