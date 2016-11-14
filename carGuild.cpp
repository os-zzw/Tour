//
// Created by john on 2016/11/13.
//
#include <iostream>
#include "carGuild.h"
#include "Stack.h"


using namespace std;

void carGuild() {
    showMenu2();
    createStack();
    createQueue();
}

void createQueue() {

}

void createStack() {

}

Stack *stack = new Stack;

void showMenu2() {
    cout << "       *** 停车场管理程序 ***   " << endl;
    cout << "================================" << endl;
    cout << "**                               " << endl;
    cout << "**   1--- 汽车进车场 2--- 汽车出车场                            " << endl;
    cout << "**                               " << endl;
    cout << "**     3 --- 退出 程序                          " << endl;
    cout << "**                               " << endl;
    cout << "================================" << endl;
    cout << " 请选择 <1 2 3 > : " << endl;
    int in;
    cin >> in;
    switch (in) {
        case 1:
            inCar();
            break;
        case 2:
            outCar();
        default:
            break;
    }

}

void outCar() {
    int card;
    cout << "车牌为:";
    cin >> card;
    int out_time;
    cin >> out_time;

}

void inCar() {
    int card;
    cout << "车牌为:";
    cin >> card;
    int in_time;
    cout << "进场的时间为:";
    cin >> in_time;
    zanInode *inode = new zanInode;
    inode->ar_time = in_time;
    StackNode *node = new StackNode;
    push(stack, node);
}