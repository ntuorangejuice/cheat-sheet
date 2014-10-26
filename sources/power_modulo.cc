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
int test = 0, pass = 0;

void assert(bool result) {
    test++; pass+=result;
    cout << (result ? "PASS: " : "FAIL: ");
}

int power_modulo(int n, int p, int M) { // n ^ p % M
    int result = 1;
    while (p > 0) {
        if (p % 2 == 1)
            result = (result*n) % M;
        p /= 2;
        n = (n*n) % M;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);

    ASSERT(power_modulo(2, 0, 10) == 1)
    ASSERT(power_modulo(2, 1, 10) == 2)
    ASSERT(power_modulo(2, 2, 10) == 4)
    ASSERT(power_modulo(2, 3, 10) == 8)
    ASSERT(power_modulo(2, 4, 10) == 6)

    cout << "Total test: " << test << endl;
    cout << "Passed: " << pass << " (" << 100.0*pass/test << "%%)" << endl;
}