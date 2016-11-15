//
// Created by john on 2016/11/14.
//

#ifndef TOUR_STACK_H
#define TOUR_STACK_H


#include "StackNode.h"

class Stack {
public:
    StackNode *top;
};

void push(Stack *stack, StackNode *node, int &count);

StackNode *pop(Stack *stack, int &count);

void push2(Stack *stack, StackNode *node, int &count);

StackNode *pop2(Stack *stack, int &count);

#endif //TOUR_STACK_H
