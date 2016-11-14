//
// Created by john on 2016/11/8.
//
#include <iostream>
#include "create.h"

/**
 * 创建图
 */
void showMenu() {
    cout << "                  ";
    cout << "=====================" << endl;
    cout << "                        ";
    cout << "欢迎使用景区旅游信息管理系统" << endl;
    cout << "                        ";
    cout << "  **请选择菜单**" << endl;
    cout << "                  ";
    cout << "=====================" << endl;
    cout << "                  ";
    cout << "0、退出系统。" << endl;
    cout << "                  ";
    cout << "1、创建景区景点分布图。" << endl;
    cout << "                  ";
    cout << "2、输出景区景点分布图。" << endl;
    cout << "                  ";
    cout << "3、输出导游线路图。" << endl;
    cout << "                  ";
    cout << "4、输出导游线路图中的回路。" << endl;
    cout << "                  ";
    cout << "5、求两个景点间的最短路径和最短距离。" << endl;
    cout << "                  ";
    cout << "6、输出道路修建规划图。" << endl;
    cout << "                  ";
    cout << "7、输入景点详细信息。" << endl;
    cout << "                  ";
    cout << "8、搜索某个景点的具体信息。" << endl;
    cout << "                  ";
    cout << "9、把景点按照受欢迎程度进行排序。" << endl;
    cout << "                  ";
    cout << "10、停车场车辆进出记录信息。" << endl;
    cout << "                  ";
}

bool IsZeroOrOne(int n) {
    if (n == 0 || n == 1)
        return true;
    return false;
}

void CreateGraph(ALGraph &g) {
    cout << "请输入顶点数和边数：";
    cin >> g.vexnum >> g.arcnum;
    cout << endl << "                " << "\"请输入各顶点的信息\"" << endl << endl;
    cout << "请输入各顶点的名字：";

    for (int i = 0; i < g.vexnum; ++i) {
        cin >> g.adjlist[i].name;
        g.adjlist[i].firstarc = NULL;
    }
    //定义两个
    string v1, v2;//两个顶点名
    int w;//顶点之间的距离
    cout << "请输入顶点 以及权值";
    for (int j = 0; j < g.arcnum; ++j) {
//        cout << "请输入第" << j + 1 << "条边的两个顶点以及该边的权值：";
        cin >> v1 >> v2 >> w;
        //得到两个节点的位置
        int index1 = locateNode(g, v1);
        int index2 = locateNode(g, v2);
        if (index1 == -1 || index2 == -1) {
            cout << "没有该地址,请重新输入";
            j--;
        }
        ArcNode *node1 = new ArcNode;
        ArcNode *node2 = new ArcNode;
        //设置第一个节点

        node1->w = w;
        node1->adjvex = index2;//他的相邻节点
        node1->nextarc = g.adjlist[index1].firstarc;
        g.adjlist[index1].firstarc = node1;
        //设置第二个节点
        node2->w = w;
        node2->adjvex = index1;
        node2->nextarc = g.adjlist[index2].firstarc;
        g.adjlist[index2].firstarc = node2;

    }
}

int locateNode(ALGraph g, string nodeName) {
    for (int i = 0; i < g.vexnum; ++i) {
        if (nodeName == g.adjlist[i].name) {
            return i;
        }
    }
    return -1;//定位失败
}

/**
 * 输出为矩阵图
 */

double **a;

void OutputGraph(ALGraph g, bool isprint) {
    int i, j;
    //对邻接矩阵数组分配空间
    a = new double *[g.vexnum];
    for (i = 0; i < g.vexnum; i++)
        a[i] = new double[g.vexnum];

    //初始化数组数据
    for (int k = 0; k < g.vexnum; k++)
        for (int l = 0; l < g.vexnum; l++)
            if (k == l)
                a[k][l] = 0;
            else
                a[k][l] = INFINITY;

    //遍历链表进行赋值
    ArcNode *node = new ArcNode;
    for (int m = 0; m < g.vexnum; m++) {
        for (node = g.adjlist[m].firstarc; node; node = node->nextarc) {
            int i = node->adjvex;
            a[m][i] = node->w;
        }
    }
    if (isprint) {
        //遍历数组并输出
        for (i = 0; i < g.vexnum; i++)
            cout << "\t" << g.adjlist[i].name;
        cout << endl;
        for (i = 0; i < g.vexnum; i++) {
            cout << g.adjlist[i].name << "\t";
            for (j = 0; j < g.vexnum; j++)
                cout << a[i][j] << "\t";
            cout << endl;
        }
    }
    delete[]node;
}

/**
 * 导游路线图
 */
bool visited[MAX_VERTEX_NUM];//定义一个数组保存图的节点是否遍历过
string vex[MAX_VERTEX_NUM];//深度优先序列
int k;
ArcNode *p = new ArcNode;

void DFS(ALGraph G, int v) {
    visited[v] = true;
    vex[k++] = G.adjlist[v].name;

    for (p = G.adjlist[v].firstarc; p; p = p->nextarc)
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex);
            p = G.adjlist[v].firstarc;
        }
}

void DFSTraverse(ALGraph G) {
    int v;
    for (v = 0; v < G.vexnum; v++)
        visited[v] = false;//初始化遍历顶点为没有被访问
    for (v = 0; v < G.vexnum; v++)
        if (!visited[v])//如果没有被访问就对其进行深度优先遍历
            DFS(G, v);
}

bool IsEdge(ALGraph G, string v1, string v2)//判断两个顶点之间是否有边
{
    int i = locateNode(G, v1);
    int j = locateNode(G, v2);
    if (a[i][j] < INFINITY)//如果这两个顶点之间有边就返回为真，否则返回假
        return true;
    return false;
}

string vex1[2 * MAX_VERTEX_NUM];//存储导游线路图的顶点遍历序列
void CreateTourSortGraph(ALGraph G, ALGraph G1) {
    DFSTraverse(G);
    cout << endl;
    int i, j, n = 0;
    bool Is;
    for (i = 0; i < G.vexnum - 1; i++) {
        k = 0;
        Is = true;
        while (Is) {
            vex1[n++] = vex[i + k];
            if (IsEdge(G, vex[i + k], vex[i + 1]))//如果他们之间有边就直接连接上这条边
                Is = false;
            else
                k--;//如果没有就回溯，直到找到和vex[i+1]有边的
        }
    }
    vex1[n] = vex[i];//将最后一个顶点放进vex数组中
    for (i = 0; i <= n; i++)
        visited[i] = false;
    for (i = 0; i < G.vexnum; i++)//初始化导游图
    {
        G1.adjlist[i].name = G.adjlist[i].name;
        G1.adjlist[i].firstarc = NULL;
    }

    int arcnum = 0;//记录导游线路图中的边的个数
    for (k = 0; k < n; k++) {
        i = locateNode(G, vex1[k]);
        j = locateNode(G, vex1[k + 1]);
        if (visited[j])//如果该点已经在导游线路图中，就寻找它是否与已经在导游线路图中的点形成回路
        {
            int m = k + 2;//跳过他的直接前驱
            if (m <= n)//判断是否超出存储导游线路图的数组
            {
                while (visited[locateNode(G, vex1[m])])//直到出现新的节点为止
                {
                    /*判断这两个点在原来的景区分布图中是否有边，如果有就连接上这条边，否者继续向后找*/
                    if (IsEdge(G, vex1[k], vex1[m])) {
                        j = locateNode(G, vex1[m]);
                        ArcNode *P = new ArcNode;
                        ArcNode *Q = new ArcNode;
                        P->adjvex = j;
                        P->w = a[i][j];

                        Q = G1.adjlist[i].firstarc;
                        G1.adjlist[i].firstarc = P;
                        P->nextarc = Q;

                        arcnum++;
                    }
                    if (++m >= n)//如果在查找的过程中到了数组末尾就强行退出
                        break;
                }
            }
        } else//如果没有在导游线路图中就连接上它
        {
            visited[i] = visited[j] = true;

            ArcNode *P = new ArcNode;
            ArcNode *Q = new ArcNode;
            P->adjvex = j;
            P->w = a[i][j];

            Q = G1.adjlist[i].firstarc;
            G1.adjlist[i].firstarc = P;
            P->nextarc = Q;

            arcnum++;
        }

    }
    G1.vexnum = G.vexnum;//赋值导游线路图中顶点的个数
    G1.arcnum = arcnum;//赋值导游线路图中边的个数
    cout << "导游路线为：";
    for (i = 0; i <= n; i++)
        cout << vex1[i] << "->";//输出导游线路图
    cout << endl;
}

/**
 * 找回路
 */


/**
 * 求两个景点之间的最短路径,和最短距离
 */
void ShortestPath(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM])//求最短路径
{
    int u, v, w;
    for (v = 0; v < G.vexnum; v++)
        for (w = 0; w < G.vexnum; w++) {
            D[v][w] = a[v][w];//对最短距离初始化为任意两点之间的权值
            if (a[v][w] < INFINITY)
                path[v][w] = v;//对最短路径初始化为自身的前一个结点的序号
        }
    for (u = 0; u < G.vexnum; u++)
        for (v = 0; v < G.vexnum; v++)
            for (w = 0; w < G.vexnum; w++)
                if (D[v][u] + D[u][w] < D[v][w])//如果新加入的结点导致最短路径变短了，就更改他，同时记录增加的路径的编号
                {
                    D[v][w] = D[v][u] + D[u][w];
                    path[v][w] = u;
                }
}

void MiniDistanse(ALGraph G1, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM])//输出最短路径
{
    ShortestPath(G1, path, D);
    string A, B;
    cout << "请输入要查询距离的两个景点的名称：";
    cin >> A >> B;
    int i = locateNode(G1, A);
    int j = locateNode(G1, B);
    cout << "最短路径为：";
    OutPutShortestPath(G1, path, D, i, j);
    cout << "最短距离为：" << D[i][j] << endl;
}

void OutPutShortestPath(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM], int i,
                        int j) {
    if (path[i][j] == i)
        cout << G.adjlist[i].name << "--" << G.adjlist[j].name << endl;//输出经过的最短路径上的边的两端顶点
    else {
        OutPutShortestPath(G, path, D, i, path[i][j]);//依次找经过的中间路径
        OutPutShortestPath(G, path, D, path[i][j], j);
    }
}
