//
// Created by john on 2016/11/8.
//
#include <string>
#include <list>

using namespace std;
#ifndef TOUR_LIST_H
#define TOUR_LIST_H

#define MAXNODENUM 20 //定义图的最大节点数
#define INFINITY 32767 //无穷远

extern double **a;//定义图的全局顶点矩阵

/**
 * 定义图
 */
//边表结点
typedef struct ENode {
    int location;//数组中位置
    struct ENode *nextENode;//下一个节点
    double w;//顶点之间距离
} ENode;
//表结点
typedef struct VNode {
    string name;//景点名字
    string desc;//景点的详细介绍
    int popularValue;//受欢迎程度
    ENode *firstNode;//所有的边
} VNode, NodeList[MAXNODENUM];

//图邻接表
typedef struct {
    NodeList nodeList;
    int vNodeNum, eNodeNum;
} ALGraph;

//边
typedef struct edge {
    string vNodeName;
    int lowcost;
} Edge[MAXNODENUM];//定义辅助数组


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
void OutputGraph(ALGraph g, bool isprint);
void insert(ALGraph &g, int w, int index1, int index2);
/**
 * 导游路线图
 */
//递归遍历
void DFS(ALGraph G, int v);

//图的深度遍历
void DFSTraverse(ALGraph G);

//判断要查的这两个顶点之间是否有直接相连的边
bool IsEdge(ALGraph G, string v1, string v2);

//输出路线
void OutTheTour(ALGraph g, ALGraph &g1);

//创建导游路线图
void createGraph2(const ALGraph &g, ALGraph &g1, int i, int j, int n);

/**
 * 找回路
 */
int TopoSort(ALGraph G1);//拓扑排序

void getInDegree(ALGraph g1, int *indegree);//计算每个顶点的入度，存储在indegree数组中
/**
 * 求两个景点之间的最短路径,和最短距离
 */
void ShortestPath(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM]);//计算最短路径

void OutPutShortestPath(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM], int i,
                        int j);//求最短路径
void MiniDistanse(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM]);//输出最短路径
/**
 *输出道路修建规划图
 */


#endif //TOUR_LIST_H
