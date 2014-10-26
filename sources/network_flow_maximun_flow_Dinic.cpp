// network flow
// maximun flow
// Dinic

#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <climits>

#define min(x, y) (((x) < (y) ? (x) : (y)))

using namespace std;

int graph[250][250];
int level[250];
int n_node, n_edge;

int mark_level() {
    memset(level, -1, sizeof(level));
    queue<int> to_visit;
    
    level[1] = 0;
    to_visit.push(1);
    while (!to_visit.empty()) {
        int cur = to_visit.front();
        to_visit.pop();
        for (int i = 1; i <= n_node; ++i) {
            if (graph[cur][i] != 0 && level[i] == -1) {
                level[i] = level[cur] + 1;
                to_visit.push(i);
            }
        }
    }

    if (level[n_node] == -1)
        return 0; // cannot reach the sink
    return 1; // can reach the sink
}

//int augment() {
//    //
//    // // not tested
//    //
//    int pre_node[n_node + 1];
//    memset(pre_node, -1, sizeof(pre_node));
//
//    stack<int> to_visit;
//    to_visit.push(1);
//    while (!to_visit.empty()) {
//        int cur = to_visit.top();
//        to_visit.pop();
//        for (int i = 1; i <= n_node; ++i) {
//            if (level[cur] + 1 == level[i]) {
//                pre_node[cur] = i;
//                to_visit.push(i);  
//                if (i == n_node) {
//                    pre_node[n_node] = i;
//                    goto FOUND_THE_PATH;
//                }
//            }
//        }
//    }
//
//    // found an augmented path
//    FOUND_THE_PATH:
//    int min_flow = LONG_MAX;
//    int cur = n_node;
//    int pre = pre_node[cur];
//    while (pre != pre_node[cur]) {
//        if (graph[pre][cur] < min_flow)
//            min_flow = graph[pre][cur];
//    }
//    cur = n_node;
//    pre = pre_node[cur];
//    while (pre != pre_node[cur]) {
//        graph[pre][cur] -= min_flow;
//        graph[cur][pre] += min_flow;
//    }
//    return min_flow;
//}

int augment_recursive(int cur, int min_flow) {
    if (cur == n_node)
        return min_flow;

    int augmented_flow = 0;
    for (int i = 1; i <= n_node; ++i) {
        if (level[i] == level[cur] + 1 && graph[cur][i] > 0 && (augmented_flow = augment_recursive(i, min(graph[cur][i], min_flow)))) {
            graph[cur][i] -= augmented_flow;
            graph[i][cur] += augmented_flow;
            return augmented_flow;
        }
    }
    return 0;
}

int dinic() {
    int ans = 0;
    int temp = 0;
    while (mark_level())
        while (temp = augment_recursive(1, INT_MAX))
            ans += temp;
    return ans;
}

int main() {
    while (cin >> n_edge >> n_node) {
        memset(graph, 0, sizeof(graph));
        
        int start_node, end_node, flow;
        for (int i = 0; i < n_edge; ++i) {
            cin >> start_node >> end_node >> flow;
            graph[start_node][end_node] += flow; // use "+" to combine !!
        }
        int ans = dinic();
        cout << ans << endl;
    }
}

// Drainage Ditches
// Time Limit: 1000MS      Memory Limit: 10000K
// Total Submissions: 56697        Accepted: 21784
// Description

// Every time it rains on Farmer John's fields, a pond forms over Bessie's favorite clover patch. This means that the clover is covered by water for awhile and takes quite a long time to regrow. Thus, Farmer John has built a set of drainage ditches so that Bessie's clover patch is never covered in water. Instead, the water is drained to a nearby stream. Being an ace engineer, Farmer John has also installed regulators at the beginning of each ditch, so he can control at what rate water flows into that ditch. 
// Farmer John knows not only how many gallons of water each ditch can transport per minute but also the exact layout of the ditches, which feed out of the pond and into each other and stream in a potentially complex network. 
// Given all this information, determine the maximum rate at which water can be transported out of the pond and into the stream. For any given ditch, water flows in only one direction, but there might be a way that water can flow in a circle. 
// Input

// The input includes several cases. For each case, the first line contains two space-separated integers, N (0 <= N <= 200) and M (2 <= M <= 200). N is the number of ditches that Farmer John has dug. M is the number of intersections points for those ditches. Intersection 1 is the pond. Intersection point M is the stream. Each of the following N lines contains three integers, Si, Ei, and Ci. Si and Ei (1 <= Si, Ei <= M) designate the intersections between which this ditch flows. Water will flow through this ditch from Si to Ei. Ci (0 <= Ci <= 10,000,000) is the maximum rate at which water will flow through the ditch.
// Output

// For each case, output a single integer, the maximum rate at which water may emptied from the pond.
// Sample Input

// 5 4
// 1 2 40
// 1 4 20
// 2 4 20
// 2 3 30
// 3 4 10
// Sample Output

// 50