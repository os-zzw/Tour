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

void push(Stack *stack, StackNode *node);

StackNode * pop(Stack *stack);

#endif //TOUR_STACK_H
