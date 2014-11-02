// maximum bipartite matching
// Hungarian algorithm


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
#define REACH_HERE {cout << "REACH_HERE! line: " << __LINE__ << endl;}

// const double E = 1e-8;
// const double PI = acos(-1);

using namespace std;

int n_cow, n_stall;

int n_node;
int graph[405][405];
int match[405];
int visited[405];

bool augment(int cur) {
    for (int i = 0; i < n_node; i++) { // for all node
        if (graph[cur][i] > 0 && visited[i] == 0) { // if have edge and not visited
            visited[i] = 1; // mark visited
            if (match[i] == -1 || augment(match[i])) { // if not matched, or its previous can find other match
                match[i] = cur; // match it
                return true;
            }
        }
    }
    return false; // cannot find any match
}

int solve() {
    while (cin >> n_cow >> n_stall) {
        memset(graph, 0, sizeof(graph));

        n_node = n_cow + n_stall;
        for (int i = 0; i < n_cow; i++) {
            int temp;
            cin >> temp;
            for (int j = 0; j < temp; j++) {
                int temptemp;
                cin >> temptemp;
                graph[i][--temptemp + n_cow] = 1;
            }
        }

        int n_match = 0;
        memset(match, -1, sizeof(match));
        for (int i = 0; i < n_node; i++) { // for each node, find an augmented path
            memset(visited, 0, sizeof(visited)); // each node only visit once
            if (augment(i)) // if found
                n_match++; // maximum matching ++
        }
        
        cout << n_match << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);

    solve();

    return 0;
}



// The Perfect Stall
// Time Limit: 1000MS      Memory Limit: 10000K
// Total Submissions: 18893        Accepted: 8585
// Description

// Farmer John completed his new barn just last week, complete with all the latest milking technology. Unfortunately, due to engineering problems, all the stalls in the new barn are different. For the first week, Farmer John randomly assigned cows to stalls, but it quickly became clear that any given cow was only willing to produce milk in certain stalls. For the last week, Farmer John has been collecting data on which cows are willing to produce milk in which stalls. A stall may be only assigned to one cow, and, of course, a cow may be only assigned to one stall. 
// Given the preferences of the cows, compute the maximum number of milk-producing assignments of cows to stalls that is possible. 
// Input

// The input includes several cases. For each case, the first line contains two integers, N (0 <= N <= 200) and M (0 <= M <= 200). N is the number of cows that Farmer John has and M is the number of stalls in the new barn. Each of the following N lines corresponds to a single cow. The first integer (Si) on the line is the number of stalls that the cow is willing to produce milk in (0 <= Si <= M). The subsequent Si integers on that line are the stalls in which that cow is willing to produce milk. The stall numbers will be integers in the range (1..M), and no stall will be listed twice for a given cow.
// Output

// For each case, output a single line with a single integer, the maximum number of milk-producing stall assignments that can be made.
// Sample Input

// 5 5
// 2 2 5
// 3 2 3 4
// 2 1 5
// 3 1 2 5
// 1 2 
// Sample Output

// 4