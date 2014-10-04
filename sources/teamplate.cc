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

/*
 * n: number
 * i: LSB starting from 1
 */
#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define GET_BIT(n, i) (((n) & (1 << ((i)-1))) >> ((i)-1))
#define SHOW(x) {cout << #x << " = " << x << endl;}
const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    /*
     * Begin test cases.
     */
    // Bit operation shortcut.
    int x = 0;
    cout << "X = " << x << endl;
    cout << "SET_BIT " << (x = SET_BIT(x, 3)) << endl;
    cout << "CLR_BIT " << (x = CLR_BIT(x, 3)) << endl;
    /*
     * End test cases.
     */

    return 0;
}