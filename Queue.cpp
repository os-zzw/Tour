//
// Created by john on 2016/11/15.
//

#include "Queue.h"
#include "QueueNode.h"

using namespace std;

void enQueue(Queue *queue, QueueNode *node) {
    if (queue->front == NULL) {
        queue->front = queue->rear = node;
    } else {
        queue->rear = node;
        queue->rear = queue->rear->link;
    }
}

QueueNode *deQueue(Queue *queue) {
    QueueNode *node = queue->front;
    queue->front = queue->front->link;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return node;
}