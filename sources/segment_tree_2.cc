#include <bits/stdc++.h>

#define GET_BIT(n, i) (((n) & (1 << ((i)-1))) >> ((i)-1)) // i start from 1
#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define SHOW_D(x, y, z, m) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #m << " = " << m << endl;}
#define REACH_HERE {cout << "REACH_HERE! line: " << __LINE__ << endl;}

const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

const int MAX = 30005;

struct node {
    int left, right;
    long long sum;
    int lazy;
    bool dirty;
};

node nodes[4*MAX];

void build_tree(int left, int right, int u) {
    nodes[u].left = left;
    nodes[u].right = right;
    nodes[u].sum = 0;
    nodes[u].lazy = 0;
    nodes[u].dirty = false;
    if (left == right) return;
    int mid = (left + right)/2;
    build_tree(left, mid, 2*u);
    build_tree(mid+1, right, 2*u + 1);
}

void get_down(int u) {
    if (!nodes[u].dirty) return;
    // SHOW_B(nodes[2*u].right, nodes[2*u].left)
    // SHOW_B(nodes[2*u+1].right, nodes[2*u+1].left)
    nodes[2*u].sum = (long long) nodes[u].lazy * (nodes[2*u].right - nodes[2*u].left + 1);
    nodes[2*u].lazy = nodes[u].lazy;
    nodes[2*u].dirty = true;
    nodes[2*u + 1].sum = (long long) nodes[u].lazy * (nodes[2*u + 1].right - nodes[2*u + 1].left + 1);
    nodes[2*u + 1].lazy = nodes[u].lazy;
    nodes[2*u + 1].dirty = true;
    nodes[u].dirty = false;
}

void update(int left, int right, int value, int u) {
    if (left <= nodes[u].left && nodes[u].right <= right) {
        // cout << "UPDATE ";
        // SHOW_D(value, u, nodes[u].left, nodes[u].right)
        nodes[u].sum = (long long)value * (nodes[u].right - nodes[u].left + 1);
        nodes[u].lazy = value;
        nodes[u].dirty = true;
        return;
    }
    //SHOW(u);
    get_down(u);
    if (left <= nodes[2*u].right) {
        update(left, right, value, 2*u);
    }
    if (right >= nodes[2*u+1].left) {
        update(left, right, value, 2*u + 1);
    }
    nodes[u].sum = nodes[2*u].sum + nodes[2*u+1].sum;
    // SHOW_A(u)
    // SHOW_C(nodes[2*u].sum, nodes[2*u].left, nodes[2*u].right)
    // SHOW_C(nodes[2*u+1].sum, nodes[2*u+1].left, nodes[2*u+1].right)
    // SHOW_D(nodes[u].sum, u, nodes[u].left, nodes[u].right)
}

void query(int left, int right, long long &sum, int u) {
    if (left <= nodes[u].left && nodes[u].right <= right) {
        sum += nodes[u].sum;
        // cout << "QUERY " ;
        // SHOW_D(left, right, sum, u)
        // SHOW_B(nodes[u].left, nodes[u].right)
        return;
    }
    get_down(u);
    if (left <= nodes[2*u].right) {
        query(left, right, sum, 2*u);
    }
    if (right >= nodes[2*u+1].left) {
        query(left, right, sum, 2*u + 1);
    }
}

long long round_down(long long a, int b) {
    if (a%b) {
        if (a > 0) return a/b;
        return a/b - 1;
    } else {
        return a/b;
    }
}

long long round_up(long long a, long long b) {
    if (a%b) {
        if (a > 0) return a/b + 1;
        return a/b;
    } else {
        return a/b;
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;

    while (cin >> n >> m) {
        long long ori_sum = 0;

        build_tree(1, n, 1);

        int v;

        for (int i = 0; i < n; i++) {
            cin >> v;
            ori_sum += v;
            update(i+1, i+1, v, 1);
        }

        int a, b;

        for (int i = 0; i < m; i++) {
            cin >> a >> b;

            if (a > b) swap(a, b);

            long long sum = 0;
            long long whole_sume = 0;

            query(a, b, sum, 1);
            query(1, n, whole_sume, 1);

            // SHOW_C(a, b, sum);

            if (whole_sume > ori_sum) {
                // round down
                // cout << "down" << endl;
                // SHOW_A(sum / (b - a + 1))
                update(a, b, round_down(sum, (b - a + 1)), 1);
            } else {
                // cout << "up" << endl;
                // round up
                update(a, b, round_up(sum, (b - a + 1)), 1);
            }
        }

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            query(i+1, i+1, sum, 1);
            cout << sum;
            if (i != n-1) cout << " ";
        }

        cout << endl;
        cout << endl;
    }

    return 0;
}