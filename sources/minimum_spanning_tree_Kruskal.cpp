// minimum spanning tree
// kruskal
// union-find set
// poj 1861

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


const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

struct Edge {
    int from;
    int to;
    int length;

    bool operator< (Edge b) const {
        return this->length < b.length;
    }
};

int get_father(int father[], int a) {
    if (father[a] != a)
        return father[a] = get_father(father, father[a]);
    return a;
}

void show(Edge a) {
    cout << a.from << "-" << a.to << ": " << a.length << endl;
}


void solve() {
    int ans_max_len = 0;
    vector<Edge> ans_cable;

    int n_node, n_edge;
    vector<Edge> e;

    cin >> n_node >> n_edge;
    for (int i = 0; i < n_edge; i++) {
        int from, to, length;
        cin >> from >> to >> length;
        Edge temp = {--from, --to, length};
        e.push_back(temp);
    }

    int added[n_node];
    memset(added, 0, sizeof(added));
    int father[n_node];
    for (int i = 0; i < n_node; i++)
        father[i] = i;

    sort(e.begin(), e.end());

    int to_add = n_node - 1;
    for (int cur = 0; to_add; cur++) {
        int fromSfather = get_father(father, e[cur].from);
        int toSfather = get_father(father, e[cur].to);
        if (fromSfather != toSfather) {
            father[fromSfather] = toSfather;
            to_add--;

            ans_cable.push_back(e[cur]);
            ans_max_len = max(ans_max_len, e[cur].length);
        }
    }

    cout << ans_max_len << endl << n_node - 1 << endl;
    for (int i = 0; i < ans_cable.size(); i++)
        cout << (ans_cable[i].from + 1) << " " << (ans_cable[i].to + 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);

    solve();

    return 0;
}


// Network
// Time Limit: 1000MS      Memory Limit: 30000K
// Total Submissions: 13832        Accepted: 5397      Special Judge

// Description
// Andrew is working as system administrator and is planning to establish a new network in his company. There will be N hubs in the company, they can be connected to each other using cables. Since each worker of the company must have access to the whole network, each hub must be accessible by cables from any other hub (with possibly some intermediate hubs).
// Since cables of different types are available and shorter ones are cheaper, it is necessary to make such a plan of hub connection, that the maximum length of a single cable is minimal. There is another problem — not each hub can be connected to any other one because of compatibility problems and building geometry limitations. Of course, Andrew will provide you all necessary information about possible hub connections.
// You are to help Andrew to find the way to connect hubs so that all above conditions are satisfied.

// Input
// The first line of the input contains two integer numbers: N - the number of hubs in the network (2 <= N <= 1000) and M - the number of possible hub connections (1 <= M <= 15000). All hubs are numbered from 1 to N. The following M lines contain information about possible connections - the numbers of two hubs, which can be connected and the cable length required to connect them. Length is a positive integer number that does not exceed 106. There will be no more than one way to connect two hubs. A hub cannot be connected to itself. There will always be at least one way to connect all hubs.

// Output
// Output first the maximum length of a single cable in your hub connection plan (the value you should minimize). Then output your plan: first output P - the number of cables used, then output P pairs of integer numbers - numbers of hubs connected by the corresponding cable. Separate numbers by spaces and/or line breaks.

// Sample Input

// 4 6
// 1 2 1
// 1 3 1
// 1 4 2
// 2 3 1
// 3 4 1
// 2 4 1

// Sample Output

// 1
// 4
// 1 2
// 1 3
// 2 3
// 3 4
