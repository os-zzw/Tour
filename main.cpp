#include <iostream>
#include <cstdlib>
#include "create.h"
#include "search.h"
#include "carGuild.h"


int isCreate(bool Is, int n);

void OutRoadPlan(ALGraph g, string basic_string);

int main() {

    bool createdG = true;//过滤
    int n;//输入
    ALGraph g, g1;//图

    bool IsDetail = false;

    //path用来存储经过的路径，D用来存储两个顶点之间的距离
    int path[MAXNODENUM][MAXNODENUM];
    double D[MAXNODENUM][MAXNODENUM];

    showMenu();//菜单

    while (true) {
        cout << endl << endl << endl;
        cout << "请输入您要选择的菜单项：";
        cin >> n;
        //判断是否已经创建了图
        n = isCreate(createdG, n);
        createdG = false;
        switch (n) {
            case 0:
                exit(0);
            case 1:
                CreateGraph(g);
                OutputGraph(g, false);//创建数组
                break;
            case 2:
                OutputGraph(g, true);//输出矩阵
                break;
            case 3:
                OutTheTour(g, g1);//输出导游路线图
                break;
            case 4:
                TopoSort(g1);//输出导游路中的回路
                break;
            case 5:
                MiniDistanse(g, path, D);//求最短路径
                break;
            case 6:
                OutRoadPlan(g, g.nodeList[0].name);//输出道路修建规划图
                break;
            case 7:
                inputTheDetail(g, IsDetail);//输入景点详细信息
                break;
            case 8:
                searchNode(g);//搜索某个景点的具体信息
                break;
            case 9:
                sortByPopular(g);//将景点进行排序
                break;
            case 10:
                carGuild();//停车场车辆进出记录信息
                break;
            default:
                exit(0);
        }
    }

}

void OutRoadPlan(ALGraph g, string basic_string) {
    Edge edge;
    int i = locateNode(g, basic_string);

}

int isCreate(bool Is, int n) {
    while (Is && !IsZeroOrOne(n)) {
        cout << "您还不能进行此操作，请先创建图。" << endl;
        cin >> n;
    }

    return n;
}













