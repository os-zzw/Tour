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
    cin >> g.vNodeNum >> g.eNodeNum;
    cout << endl << "                " << "\"请输入各顶点的信息\"" << endl << endl;
    cout << "请输入各顶点的名字：";

    for (int i = 0; i < g.vNodeNum; ++i) {
        cin >> g.nodeList[i].name;
        g.nodeList[i].firstNode = NULL;
    }
    //定义两个
    string v1, v2;//两个顶点名
    int w;//顶点之间的距离
    cout << "请输入顶点 以及权值";
    for (int j = 0; j < g.eNodeNum; ++j) {
//        cout << "请输入第" << j + 1 << "条边的两个顶点以及该边的权值：";
        cin >> v1 >> v2 >> w;
        //得到两个节点的位置
        int index1 = locateNode(g, v1);
        int index2 = locateNode(g, v2);
        if (index1 == -1 || index2 == -1) {
            cout << "没有该地址,请重新输入";
            j--;
        }
        //将边结点插入
        insert(g, w, index1, index2);
    }
}

void insert(ALGraph &g, int w, int index1, int index2) {
    ENode *node1 = new ENode;
    ENode *node2 = new ENode;
    //设置第一个节点
    node1->w = w;
    node1->location = index2;//他的相邻节点
    node1->nextENode = g.nodeList[index1].firstNode;
    g.nodeList[index1].firstNode = node1;
    //设置第二个节点
    node2->w = w;
    node2->location = index1;
    node2->nextENode = g.nodeList[index2].firstNode;
    g.nodeList[index2].firstNode = node2;
}

int locateNode(ALGraph g, string nodeName) {
    for (int i = 0; i < g.vNodeNum; ++i) {
        if (nodeName == g.nodeList[i].name) {
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
    a = new double *[g.vNodeNum];
    for (i = 0; i < g.vNodeNum; i++)
        a[i] = new double[g.vNodeNum];

    //初始化数组数据
    for (int k = 0; k < g.vNodeNum; k++)
        for (int l = 0; l < g.vNodeNum; l++)
            if (k == l)
                a[k][l] = 0;
            else
                a[k][l] = INFINITY;

    //遍历链表进行赋值
    ENode *node = new ENode;
    for (int m = 0; m < g.vNodeNum; m++) {
        for (node = g.nodeList[m].firstNode; node; node = node->nextENode) {
            int i = node->location;
            a[m][i] = node->w;
        }
    }
    if (isprint) {
        //遍历数组并输出
        for (i = 0; i < g.vNodeNum; i++)
            cout << "\t" << g.nodeList[i].name;
        cout << endl;

        for (i = 0; i < g.vNodeNum; i++) {
            cout << g.nodeList[i].name << "\t";
            for (j = 0; j < g.vNodeNum; j++)
                cout << a[i][j] << "\t";
            cout << endl;
        }
    }
    delete[]node;
}

/**
 * 导游路线图
 */
bool visited[MAXNODENUM];//定义一个数组保存图的节点是否遍历过
string node1List[MAXNODENUM];//深度优先序列
int k;
ENode *p = new ENode;

void DFS(ALGraph G, int v) {
    visited[v] = true;
    node1List[k++] = G.nodeList[v].name;

    for (p = G.nodeList[v].firstNode; p; p = p->nextENode)
        if (!visited[p->location]) {
            DFS(G, p->location);
            p = G.nodeList[v].firstNode;
        }
}

void DFSTraverse(ALGraph G) {
    int v;
    for (v = 0; v < G.vNodeNum; v++)
        visited[v] = false;//初始化遍历顶点为没有被访问
    for (v = 0; v < G.vNodeNum; v++)
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

string node2List[2 * MAXNODENUM];//存储导游线路图的顶点遍历序列

void OutTheTour(ALGraph g, ALGraph &g1) {
    DFSTraverse(g);
    cout << endl;
    int i, j, n = 0;
    bool Is;
    for (i = 0; i < g.vNodeNum - 1; i++) {
        k = 0;
        Is = true;
        while (Is) {
            node2List[n++] = node1List[i + k];
            if (IsEdge(g, node1List[i + k], node1List[i + 1]))//如果他们之间有边就直接连接上这条边
                Is = false;
            else
                k--;//如果没有就回溯，直到找到和vex[i+1]有边的
        }
    }
    node2List[n] = node1List[i];//将最后一个顶点放进vex数组中
    //生成路线图
    for (i = 0; i <= n; i++)
        visited[i] = false;
    for (i = 0; i < g.vNodeNum; i++)//初始化导游图
    {
        g1.nodeList[i].name = g.nodeList[i].name;
        g1.nodeList[i].firstNode = NULL;
    }
    g1.vNodeNum = g.vNodeNum;
    g1.eNodeNum = n;
    for (int l = 0; l < n - 1; l++) {
        cout << node2List[l];
        int i = l;
        ENode *node = new ENode;
        int eNodeLocation = locateNode(g1, node2List[i + 1]);
        node->location = eNodeLocation;
        node->w = 5;
        int vNodeLocation = locateNode(g1, node2List[i]);
        node->nextENode = g1.nodeList[vNodeLocation].firstNode;
        g1.nodeList[vNodeLocation].firstNode = node;
    }
//    createGraph2(g, g1, i, j, n);
    cout << "导游路线为：";
    for (i = 0; i <= n; i++)
        cout << node2List[i] << "->";//输出导游线路图
    cout << endl;
}

//void createGraph2(const ALGraph &g, ALGraph &g1, int i, int j, int n) {
//    for (i = 0; i <= n; i++)
//        visited[i] = false;
//    for (i = 0; i < g.vNodeNum; i++)//初始化导游图
//    {
//        g1.nodeList[i].name = g.nodeList[i].name;
//        g1.nodeList[i].firstNode = NULL;
//    }
//
//    int edgeNum = 0;//记录导游线路图中的边的个数
//    for (k = 0; k < n; k++) {
//        i = locateNode(g, node2List[k]);
//        j = locateNode(g, node2List[k + 1]);
//        if (visited[j])//如果该点已经在导游线路图中，就寻找它是否与已经在导游线路图中的点形成回路
//        {
//            int m = k + 2;//跳过他的直接前驱
//            if (m <= n)//判断是否超出存储导游线路图的数组
//            {
//                while (visited[locateNode(g, node2List[m])])//直到出现新的节点为止
//                {
//                    /*判断这两个点在原来的景区分布图中是否有边，如果有就连接上这条边，否者继续向后找*/
//                    if (IsEdge(g, node2List[k], node2List[m])) {
//                        j = locateNode(g, node2List[m]);
//                        ENode *P = new ENode;
//                        ENode *Q = new ENode;
//                        P->location = j;
//                        P->w = a[i][j];
//
//                        Q = g1.nodeList[i].firstNode;
//                        g1.nodeList[i].firstNode = P;
//                        P->nextENode = Q;
//
//                        edgeNum++;
//                    }
//                    if (++m >= n)//如果在查找的过程中到了数组末尾就强行退出
//                        break;
//                }
//            }
//        } else//如果没有在导游线路图中就连接上它
//        {
//            visited[i] = visited[j] = true;
//
//            ENode *P = new ENode;
//            ENode *Q = new ENode;
//            P->location = j;
//            P->w = a[i][j];
//
//            Q = g1.nodeList[i].firstNode;
//            g1.nodeList[i].firstNode = P;
//            P->nextENode = Q;
//
//            edgeNum++;
//        }
//
//    }
//    g1.vNodeNum = g.vNodeNum;//赋值导游线路图中顶点的个数
//    g1.eNodeNum = edgeNum;//赋值导游线路图中边的个数
//}
void createGraph2(const ALGraph &g, ALGraph &g1, int i, int j, int n) {

}

/**
 * 找回路
 */
int TopoSort(ALGraph G1) {
    string *a = new string[G1.vNodeNum];//将不在回路中的顶点暂存在字符数组a中
    int *indegree = new int[G1.vNodeNum];//为顶点入度数组开辟空间
    int top = 0, base = 0;
    int *S = new int[G1.vNodeNum];//为顶点栈开辟空间
    int i = 0;
    for (; i < G1.vNodeNum; i++)//初始化顶点入读数组
        indegree[i] = 0;
    getInDegree(G1, indegree);//调用求入度函数求出各个顶点的入度
    for (i = 0; i < G1.vNodeNum; i++)
        if (!indegree[i])//将入度减为0的顶点入栈
            S[top++] = i;
    int count = 0;//记录已经进入拓扑序列的顶点的个数
    int k;
    ENode *p = new ENode;
    while (top != base)//当栈不空是继续循环
    {
        k = S[--top];
        a[count++] = G1.nodeList[k].name;
        for (p = G1.nodeList[k].firstNode; p; p = p->nextENode)
            if (!(--indegree[p->location]))//如果入度减为0，则入栈
                S[top++] = p->location;
    }
    if (count < G1.vNodeNum) {
        cout << endl << "图中有回路,回路为：" << endl;
        for (i = 0; i < G1.vNodeNum; i++) {
            for (k = 0; k < count; k++)
                if (G1.nodeList[i].name == a[k])//如果顶点与数组a中的顶点相同就跳出循环，说明不在循环中
                    break;
            if (k >= count)
                cout << G1.nodeList[i].name;
        }
        delete[]a;
        delete[]indegree;
        delete[]S;
        return false;
    } else {
        cout << "图中没有回路" << endl;
        delete[]a;
        delete[]indegree;
        delete[]S;
        return true;
    }

}

void getInDegree(ALGraph g1, int indegree[])//求各个顶点的入度
{
    ENode *p = new ENode;
    for (int i = 0; i < g1.vNodeNum; i++)
        for (p = g1.nodeList[i].firstNode; p; p = p->nextENode)//搜索完所有的边
            indegree[p->location]++;
    delete p;
}

/**
 * 求两个景点之间的最短路径,和最短距离
 */
void ShortestPath(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM])//求最短路径
{
    int u, v, w;
    for (v = 0; v < G.vNodeNum; v++)
        for (w = 0; w < G.vNodeNum; w++) {
            D[v][w] = a[v][w];//对最短距离初始化为任意两点之间的权值
            if (a[v][w] < INFINITY)
                path[v][w] = v;//对最短路径初始化为自身的前一个结点的序号
        }
    for (u = 0; u < G.vNodeNum; u++)
        for (v = 0; v < G.vNodeNum; v++)
            for (w = 0; w < G.vNodeNum; w++)
                if (D[v][u] + D[u][w] < D[v][w])//如果新加入的结点导致最短路径变短了，就更改他，同时记录增加的路径的编号
                {
                    D[v][w] = D[v][u] + D[u][w];
                    path[v][w] = u;
                }
}

void MiniDistanse(ALGraph G1, int path[][MAXNODENUM], double D[][MAXNODENUM])//输出最短路径
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

void OutPutShortestPath(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM], int i,
                        int j) {
    if (path[i][j] == i)
        cout << G.nodeList[i].name << "--" << G.nodeList[j].name << endl;//输出经过的最短路径上的边的两端顶点
    else {
        OutPutShortestPath(G, path, D, i, path[i][j]);//依次找经过的中间路径
        OutPutShortestPath(G, path, D, path[i][j], j);
    }
}

/**
 *输出道路修建规划图
 */
