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
#include <cmath>

/*
 * n: number
 * i: LSB starting from 1
 */
#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define GET_BIT(n, i) (((n) & (1 << ((i)-1))) >> ((i)-1))
#define SHOW(x) {cout << #x << " = " << x << endl;}
#define ASSERT(x) { assert(x); cout << #x << endl; }
const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

struct HHH {
    int a;
    // bool operator==(HHH that) {
    //     return this->a == that.a;
    // }
    // bool operator==(const HHH that) {
    //     return this->a == that.a;
    // }
    bool operator==(HHH& that) {
        return this->a == that.a;
    }
    // bool operator==(const HHH& that) {
    //     return this->a == that.a;
    // }
};

int main() {
    ios::sync_with_stdio(false);

    HHH a = {1};
    HHH b = {2};
    if (a == b)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}