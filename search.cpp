//
// Created by john on 2016/11/13.
//

void sortByPopular(ALGraph &g) {
    int a[MAX_VERTEX_NUM];
    for (int i = 0; i < g.vexnum; ++i) {
        a[i] = g.adjlist[i].popularValue;
    }
    quickSort(a, 0, 7);
    cout << a;
    cout << "最受欢迎的景点依次为:" << endl;
    for (int j = 0; j < g.vexnum; ++j) {
        for (int i = 0; i < g.vexnum; ++i) {
            if (g.adjlist[i].popularValue == a[j]) {
                cout << g.adjlist[i].name <<"  "<< g.adjlist[i].popularValue << endl;
            }
        }
    }
}

void quickSort(int s[], int l, int r) {
    if (l < r) {
        int i = l, j = r, x = s[l];
        while (i < j) {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
}


//查找
void searchNode(ALGraph &g) {
    cout << "请输入景点的名字";
    string name;
    cin >> name;
    for (int j = 0; j < g.vexnum; ++j) {
        bool exites = g.adjlist[j].name == name;
        if (exites) {
            cout << "景点的详细信息为:" << g.adjlist[j].desc << endl;
            cout << "景点的受欢迎程度为:" << g.adjlist[j].popularValue;
        }
    }
}

//输入详细景点信息
void inputTheDetail(ALGraph &g, bool isDetail) {
    cout << "请输入景点的名字 介绍 和受欢迎程度(用数字来表示,数字越大越受欢迎)";
    string name, desc;
    int popularValue;
    for (int i = 0; i < g.vexnum; ++i) {
        cin >> name >> desc >> popularValue;
        for (int j = 0; j < g.vexnum; ++j) {
            bool exites = g.adjlist[j].name == name;
            if (exites) {
                g.adjlist[j].desc = desc;
                g.adjlist[j].popularValue = popularValue;
            }
        }
    }
    for (int k = 0; k < g.vexnum; ++k) {
        cout << g.adjlist[k].name << "   " << g.adjlist[k].desc << "受欢迎程度为:"
             << g.adjlist[k].popularValue << endl;
    }
    isDetail = true;
}
