//
// Created by john on 2016/11/14.
//

#include "Stack.h"


void push(Stack *stack, StackNode *node) {
    node->link = stack->top;
    stack->top = node;
}

StackNode *pop(Stack *stack) {
    return stack->top;
}
