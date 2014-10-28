// minimum spanning tree
// prim
// if edge is almost n_node * n_node, then use graph[][] would be faster then vector<int> graph[]
// POJ2485 (AC with graph[][], TLE with vector<int> graph[])

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

// const double E = 1e-8;
// const double PI = acos(-1);

using namespace std;

struct Edge {
    int from;
    int to;
    int length;
};

struct compare {
public:
    bool operator() (Edge a, Edge b) {
        return a.length > b.length;
    }
};

void mst() {
    int ans = 0;

    int n_node;
    int n_edge;
    ////////////////////////////////////////
    cin >> n_node;
    ////////////////////////////////////////
    vector<Edge> graph[n_node];
    ////////////////////////////////////////
    for (int i = 0; i < n_node; i++) {
        for (int j = 0; j < n_node; j++) {
            int length;
            cin >> length;
            Edge temp = {i, j, length};
            Edge pmet = {j, i, length};
            graph[i].push_back(temp);
            graph[j].push_back(pmet);
        }
    }
    ////////////////////////////////////////

    priority_queue<Edge, vector<Edge>, compare> discovered;
    int added[n_node];
    memset(added, 0, sizeof(added));

    int to_add = n_node;
    Edge temp = {0, 0, 0};
    discovered.push(temp); // 0 is first node
    while (to_add--) {
        Edge cur = discovered.top();
        discovered.pop();
        while (added[cur.to] == 1) {
            cur = discovered.top();
            discovered.pop();
        }
        int from = cur.from, to = cur.to, length = cur.length;

        ans = max(ans, length);

        added[to] = 1;
        for (int i = 0; i < graph[to].size(); i++)
            if (to != graph[to][i].to && added[graph[to][i].to] == 0)
                discovered.push(graph[to][i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
        mst();

    return 0;
}


// Highways
// Time Limit: 1000MS      Memory Limit: 65536K
// Total Submissions: 22952        Accepted: 10566
// Description

// The island nation of Flatopia is perfectly flat. Unfortunately, Flatopia has no public highways. So the traffic is difficult in Flatopia. The Flatopian government is aware of this problem. They're planning to build some highways so that it will be possible to drive between any pair of towns without leaving the highway system. 

// Flatopian towns are numbered from 1 to N. Each highway connects exactly two towns. All highways follow straight lines. All highways can be used in both directions. Highways can freely cross each other, but a driver can only switch between highways at a town that is located at the end of both highways. 

// The Flatopian government wants to minimize the length of the longest highway to be built. However, they want to guarantee that every town is highway-reachable from every other town.
// Input

// The first line of input is an integer T, which tells how many test cases followed. 
// The first line of each case is an integer N (3 <= N <= 500), which is the number of villages. Then come N lines, the i-th of which contains N integers, and the j-th of these N integers is the distance (the distance should be an integer within [1, 65536]) between village i and village j. There is an empty line after each test case.
// Output

// For each test case, you should output a line contains an integer, which is the length of the longest road to be built such that all the villages are connected, and this value is minimum.
// Sample Input

// 1

// 3
// 0 990 692
// 990 0 179
// 692 179 0
// Sample Output

// 692
// Hint

// Huge input,scanf is recommended.