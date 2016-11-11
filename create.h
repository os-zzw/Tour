//
// Created by john on 2016/11/8.
//
#include <string>
#include <list>

using namespace std;
#ifndef TOUR_LIST_H
#define TOUR_LIST_H

#define MAX_VERTEX_NUM 20 //定义图的最大节点数
#define INFINITY 32767 //无穷远

extern double **a;//定义图的全局顶点矩阵

/**
 * 定义图
 */
//边表结点
typedef struct ArcNode {
    int adjvex;//数组中位置
    struct ArcNode *nextarc;//下一个节点
    double w;//顶点之间距离
} ArcNode;
//表结点
typedef struct VNode {
    string name;//名字
    ArcNode *firstarc;//所有的边
} VNode, AdjList[MAX_VERTEX_NUM];
//图邻接表
typedef struct {
    AdjList adjlist;
    int vexnum, arcnum;
} ALGraph;
//边
typedef struct edge {
    string vex;
    int lowcost;
} Edge[MAX_VERTEX_NUM];//定义辅助数组


/**
 * 创建图
 */
//菜单
void showMenu();

//过滤
bool IsZeroOrOne(int n);

void CreateGraph(ALGraph &g);

//定位结点
int locateNode(ALGraph g, string nodeName);

/**
 * 输出图
 */
void OutputGraph(ALGraph g);

/**
 * 导游路线图
 */
void DFS(ALGraph G, int v);//递归遍历

void DFSTraverse(ALGraph G);//图的深度遍历

bool IsEdge(ALGraph G, string v1, string v2);//判断要查的这两个顶点之间是否有直接相连的边

void CreateTourSortGraph(ALGraph G, ALGraph G1);

#endif //TOUR_LIST_H
