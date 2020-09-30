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
#include <ext/hash_map>
#include<bits/stdc++.h>
/*
 * n: number
 * i: LSB starting from 1
 */
#define GET_BIT(n, i) (((n) & (1 << ((i)-1))) >> ((i)-1))
#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define REACH_HERE {cout << "REACH_HERE!" << endl;}
#define ASSERT(x) { assert(x); cout << #x << endl; }

const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

int test = 0, pass = 0;

int checks(bool result) {
    test++; pass+=result;
    cout << (result ? "PASS " : "FAIL ")<<"\n";

    return 0;
}


int main() {
    ios::sync_with_stdio(false);

    map<string, int> months;

    months["January"] = 31;
    months["February"] = 28;
    months["March"] = 31;
    months["April"] = 30;
    months["May"] = 31;
    months["June"] = 30;
    months["July"] = 31;
    months["August"] = 31;
    months["September"] = 30;
    months["October"] = 31;
    months["November"] = 30;
    months["December"] = 31;

    checks(months["September"]==30);
    checks(months["August"]==31);

    cout << "Passed: " << pass << " (" << 100.0*pass/test << "%%)" << endl;

    return 0;
}
