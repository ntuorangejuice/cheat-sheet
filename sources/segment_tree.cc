// Problem http://poj.org/problem?id=2777

// Count Color
// Time Limit: 1000MS      Memory Limit: 65536K
// Total Submissions: 36259        Accepted: 10943
// Description

// Chosen Problem Solving and Program design as an optional course, you are required to solve all kinds of problems. Here, we get a new problem. 

// There is a very long board with length L centimeter, L is a positive integer, so we can evenly divide the board into L segments, and they are labeled by 1, 2, ... L from left to right, each is 1 centimeter long. Now we have to color the board - one segment with only one color. We can do following two operations on the board: 

// 1. "C A B C" Color the board from segment A to segment B with color C. 
// 2. "P A B" Output the number of different colors painted between segment A and segment B (including). 

// In our daily life, we have very few words to describe a color (red, green, blue, yellow…), so you may assume that the total number of different colors T is very small. To make it simple, we express the names of colors as color 1, color 2, ... color T. At the beginning, the board was painted in color 1. Now the rest of problem is left to your. 
// Input

// First line of input contains L (1 <= L <= 100000), T (1 <= T <= 30) and O (1 <= O <= 100000). Here O denotes the number of operations. Following O lines, each contains "C A B C" or "P A B" (here A, B, C are integers, and A may be larger than B) as an operation defined previously.
// Output

// Ouput results of the output operation in order, each line contains a number.
// Sample Input

// 2 2 4
// C 1 1 2
// P 1 2
// C 2 2 2
// P 1 2
// Sample Output

// 2
// 1


#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define GET_BIT(n, i) (((n) & (1 << ((i)-1))) >> ((i)-1))
#define SHOW(x) {cout << #x << " = " << x << endl;}

using namespace std;

// mainly copied from http://blog.sina.com.cn/s/blog_6635898a0100kzph.html

const int MAX = 100000;

struct node {
    int left, right;
    int color;
    bool cover;
};

node nodes[3*MAX];

void build_tree(int left, int right, int u) {
    nodes[u].left = left;
    nodes[u].right = right;
    nodes[u].color = 1;
    nodes[u].cover = true;
    if (left == right) return;
    int mid = (left + right)/2;
    build_tree(left, mid, 2*u);
    build_tree(mid+1, right, 2*u + 1);
}

void get_down(int u) {
    int value = nodes[u].color;
    nodes[u].cover = false;
    nodes[2*u].color = value;
    nodes[2*u].cover = true;
    nodes[2*u + 1].color = value;
    nodes[2*u + 1].cover = true;
}

void update(int left, int right, int value, int u) {
    if (left <= nodes[u].left && nodes[u].right <= right) {
        nodes[u].color = value;
        nodes[u].cover = true;
        return;
    }
    if (nodes[u].color == value) return;  // optimize purpose
    //SHOW(u);
    if (nodes[u].cover) get_down(u);
    if (left <= nodes[2*u].right) {
        update(left, right, value, 2*u);
    }
    if (right >= nodes[2*u+1].left) {
        update(left, right, value, 2*u + 1);
    }
    nodes[u].color = nodes[2*u].color | nodes[2*u+1].color;
}

void query(int left, int right, int &sum, int u) {
    if (nodes[u].cover) {
        sum |= nodes[u].color;
        return;
    }
    if (left <= nodes[u].left && nodes[u].right <= right) {
        sum |= nodes[u].color;
        return;
    }
    if (left <= nodes[2*u].right) {
        query(left, right, sum, 2*u);
    }
    if (right >= nodes[2*u+1].left) {
        query(left, right, sum, 2*u + 1);
    }
}

int bit_count(int sum) {
    int ans = 0;
    while (sum) {
        if (sum%2) ans++;
        sum = sum >> 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int L, T, O;
    cin >> L >> T >> O;
    build_tree(1, L, 1);
    while (O--) {
        char op;
        int a, b, c;
        cin >> op;
        if (op == 'C') {
            cin >> a >> b >> c;
            if (a > b) swap(a, b);
            update(a, b, 1<<(c-1), 1);
        } else {
            cin >> a >> b;
            if (a > b) swap(a, b);
            int sum = 0;
            query(a, b, sum, 1);
            cout << bit_count(sum) << endl;
        }
    }

    return 0;
}
