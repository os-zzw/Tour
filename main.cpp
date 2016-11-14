#include <iostream>
#include <cstdlib>
#include "create.h"
#include "search.h"
#include "carGuild.h"


int main() {

    bool Is = true;//过滤
    int n;//输入
    ALGraph G, G1;//图

    bool IsDetail = false;

    //path用来存储经过的路径，D用来存储两个顶点之间的距离
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    double D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

    showMenu();//菜单

    while (true) {
        cout << endl << endl << endl;
        cout << "请输入您要选择的菜单项：";
        cin >> n;

        while (Is && !IsZeroOrOne(n)) {
            cout << "您还不能进行此操作，请先创建图。" << endl;
            cin >> n;
        }
        Is = false;

        switch (n) {
            case 0:
                exit(0);
            case 1:
                CreateGraph(G);
                OutputGraph(G, false);//创建数组
                break;
            case 2:
                OutputGraph(G, true);//输出内容
                break;
            case 3:
                CreateTourSortGraph(G, G1);
                break;
//            case 4:
//                TopoSort(G1);
//                break;
            case 5:
                MiniDistanse(G, path, D);
                break;
//            case 6:
//                MiniSpanTree(G, G.adjlist[0].name);
//                break;
            case 7:
                inputTheDetail(G, IsDetail);
                break;
            case 8:
                searchNode(G);
                break;
            case 9:
                sortByPopular(G);
                break;
            case 10:
                carGuild();
                break;
            default:
                exit(0);
        }
    }

}













