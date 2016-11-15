//
// Created by john on 2016/11/13.
//

#ifndef TOUR_CARGUILD_H
#define TOUR_CARGUILD_H

#define MAXCAR 2 //最大停车数量
using namespace std;

typedef struct zanlind {
    int number; //汽车车号
    int ar_time;//汽车到达时间
    struct zanlind *next;
} zanInode;


typedef struct {
    zanInode *base;//停车场的堆栈底
    zanInode *top; //停车场的堆栈顶
    int stacksize_curren;
} stackhead;

void showMenu2();

void carGuild();

void createStack();

void createQueue();

void inCar();

void outCar();

#endif //TOUR_CARGUILD_H
