// minimum spanning tree
// prim
// if edge is almost n_node * n_node, then use graph[][] would be faster then vector<int> graph[]
// this kind of Prim: Time complexity = O(V^2)
// use another : O(E*log(V))

// Vijos P1190

// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>

#define GET_BIT(n, i) ((n) & (1 << ((i)-1)))
#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define REACH_HERE {cout << "REACH_HERE!" << endl;}

using namespace std;

void mst_prim() {
    int ans = 0;

    int n_node;
    int n_edge;
    ////////////////////////////////////////
    cin >> n_node >> n_edge; // read data
    ////////////////////////////////////////
    int graph[n_node][n_node];
    int min_dis[n_node];
    for (int i = 0; i < n_node; i++)
        min_dis[i] = INT_MAX; // initialize
    ////////////////////////////////////////
    memset(graph, -1, sizeof(graph));
    for (int i = 0; i < n_edge; i++) {
        int a, b, length;
        cin >> a >> b >> length;
        a--;
        b--;
        graph[a][b] = length;
        graph[b][a] = length;
    }
    for (int i = 0; i < n_node; i++)
        for (int j = 0; j < n_node; j++)
            if (graph[i][j] == -1)
                graph[i][j] = INT_MAX;
    ////////////////////////////////////////

    
    int cur = 0; // the node just added
    for (int i = 1; i < n_node; i++) { // total need pick n-1 edges
        min_dis[cur] = -1; // add cur
        for (int j = 0; j < n_node; j++) // for all node
            if (graph[cur][j] < min_dis[j]) // if can reach from new node and nearer
                min_dis[j] = graph[cur][j]; // update the distance
        int next = -1; // the node to add
        int cur_min_dis = INT_MAX; // current distance of nearest node
        for (int j = 0; j < n_node; j++) // check all node
            if (min_dis[j] >= 0 && min_dis[j] < cur_min_dis) { // if j node is nearer
                next = j; // record
                cur_min_dis = min_dis[j];
            }
        // add edge: cur->next
        cur = next; // next node to add
        ans = max(ans, cur_min_dis); // from the question
        // should directly maintain the min distance for each node to current tree
        // use heapfy...
    }

    cout << n_node - 1 << " " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);

    mst_prim();

    return 0;
}


// P1190繁忙的都市请登录后递交
// 标签：四川2005[显示标签]
// 描述
// 城市C是一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造。城市C的道路是这样分布的：城市中有n个交叉路口，有些交叉路口之间有道路相连，两个交叉路口之间最多有一条道路相连接。这些道路是双向的，且把所有的交叉路口直接或间接的连接起来了。每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要进行改造。但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：
// 1．改造的那些道路能够把所有的交叉路口直接或间接的连通起来。
// 2．在满足要求1的情况下，改造的道路尽量少。
// 3．在满足要求1、2的情况下，改造的那些道路中分值最大的道路分值尽量小。
// 任务：作为市规划局的你，应当作出最佳的决策，选择那些道路应当被修建。
// 格式
// 输入格式

// 第一行有两个整数n,m表示城市有n个交叉路口，m条道路。接下来m行是对每条道路的描述，u, v, c表示交叉路口u和v之间有道路相连，分值为c。(1≤n≤300，1≤c≤10000)
// 输出格式

// 两个整数s, max，表示你选出了几条道路，分值最大的那条道路的分值是多少。
// 样例1
// 样例输入1[复制]

// 4 5
// 1 2 3
// 1 4 5
// 2 4 7
// 2 3 6
// 3 4 8
// 样例输出1[复制]

// 3 6
// 限制
// 每个测试点1s