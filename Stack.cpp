//
// Created by john on 2016/11/14.
//

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;


void push(Stack *stack, StackNode *node, int &count) {
    //入队处理
//    if (count >= MAXCAR) {
//        cout << "当前车库已经存满,请您排队等候";
//        QueueNode *queueNode = new QueueNode;
//        queueNode->data = node->data;
//        delete (node);
//        enQueue(queue, queueNode);
//        return;
//    }
    count++;
    node->link = stack->top;
    stack->top = node;
}


StackNode *pop(Stack *stack, int &count) {
    count--;
    stack->top = stack->top->link;
//    if (queue->front->data->number) {
//        QueueNode *pNode = deQueue(queue);
//        StackNode *node = new StackNode;
//        node->data = pNode->data;
//        delete (pNode);
//        push(stack, node, count);
//        if (count <= 5) {
//            cout << "车牌号为" << node->data->number << "的车已经被停在了" << count << "号车道" << endl;
//        }
//    }
    return stack->top;
}


void push2(Stack *stack, StackNode *node, int &count) {
    node->link = stack->top;
    stack->top = node;
}

StackNode *pop2(Stack *stack, int &count) {
    stack->top = stack->top->link;
    return stack->top;
}
