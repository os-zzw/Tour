#include <iostream>
#include <cstdlib>
#include "create.h"



int main() {

    bool Is = true;//过滤
    int n;//输入
    ALGraph G,G1;//图

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
                break;
            case 2:
                OutputGraph(G);
                break;
            case 3:
                CreateTourSortGraph(G, G1);
                break;
//            case 4:
//                TopoSort(G1);
//                break;
//            case 5:
//                MiniDistanse(G, path, D);
//                break;
//            case 6:
//                MiniSpanTree(G, G.adjlist[0].name);
//                break;
            default:
                exit(0);
        }
    }

}










