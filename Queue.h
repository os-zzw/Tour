//
// Created by john on 2016/11/15.
//

#ifndef TEST2_QUEUE_H
#define TEST2_QUEUE_H

#include <iostream>
#include "QueueNode.h"


using namespace std;

class Queue {
public:
    QueueNode *rear = NULL;
    QueueNode *front = NULL;
};


QueueNode *deQueue(Queue *queue);

void enQueue(Queue *queue, QueueNode *node);

#endif //TEST2_QUEUE_H
