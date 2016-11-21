//
// Created by john on 2016/11/13.
//
#include <iostream>
#include <cstdlib>
#include "carGuild.h"
#include "Stack.h"
#include "Queue.h"


using namespace std;

void carGuild() {
    showMenu2();
}


Stack *stack = new Stack;
Stack *stack2 = new Stack;
Queue *queue = new Queue;
int count = 0;
int count2 = 0;

void showMenu2() {
    cout << "       *** 停车场管理程序 ***   " << endl;
    cout << "================================" << endl;
    cout << "**                               " << endl;
    cout << "**   1--- 汽车进车场 2--- 汽车出车场  " << endl;
    cout << "**                               " << endl;
    cout << "**     3 --- 退出 程序            " << endl;
    cout << "**                                " << endl;
    cout << "================================  " << endl;

    while (true) {
        cout << " 请选择 <1 2 3 > : " << endl;
        int in;
        cin >> in;
        switch (in) {
            case 1:
                inCar();
                break;
            case 2:
                outCar();
                break;
            case 3:
                exit(0);
            default:
                exit(0);
        }
    }
}

void outCar() {
    int card;
    int out_time;
    cout << "请输入车牌和" << "汽车离去的时间";
    cin >> card >> out_time;
    //出栈处理
    StackNode *node;
    for (int i = 0; i < MAXCAR; i++) {
        node = stack->top;
        pop(stack, count);
        push2(stack2, node, count2);
        if (node->data->number == card) {
            int i = out_time - node->data->ar_time;
            cout << "您应该上交的钱数是(每小时1块钱):" << i << endl;
            pop2(stack2, count2);
            for (int i = 0; i < count2; i++) {
                push(stack, node, count);
            }
            //出队处理
            if (queue->front != NULL) {
                QueueNode *pNode = deQueue(queue);
                node->data = pNode->data;
                push(stack, node, count);
                cout << "排队中第一辆车,车牌号为" << node->data->number << "的车进入停车场" << endl;
            }
            delete[]node;
            return;
        }
    }

}

void inCar() {
    int card;
    int in_time;
    cout << "请输入车牌和" << "进场的时间为:";
    cin >> card >> in_time;
    //入栈处理
    zanInode *inode = new zanInode;
    inode->ar_time = in_time;
    inode->number = card;
    if (count < MAXCAR) {
        StackNode *node = new StackNode;
        node->data = inode;
        push(stack, node, count);
        if (count <= MAXCAR) {
            cout << "您的车已经被停在了" << count << "号车道" << endl;
        }
    } else {
        //入队处理
        QueueNode *node = new QueueNode;
        node->data = inode;
        enQueue(queue, node);
        cout << "车队已经满了,请排队等候" << endl;
    }
    return;
}