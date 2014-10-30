#include <bits/stdc++.h>

#define GET_BIT(n, i) (((n) & (1 << ((i)-1))) >> ((i)-1)) // i start from 1
#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define REACH_HERE {cout << "REACH_HERE! line: " << __LINE__ << endl;}
#define ASSERT(x) { _assert(x); cout << #x << endl; }

const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

int test = 0, pass = 0;

void _assert(bool result) {
    test++; pass+=result;
    cout << (result ? "PASS: " : "FAIL: ");
}

struct point {
    int x, y;

    double length() {
        return sqrt(x*x + y*y);
    }

    long operator* (const point& b) {
        return x*b.y - y*b.x;
    }

    bool at_right_of(const point& that, const point& base) {
        point vec_self = {x - base.x, y - base.y};
        point vec_that = {that.x - base.x, that.y - base.y};
        long product = vec_self * vec_that;
        if (product>0) return true;
        if (product==0 && vec_self.length()>vec_that.length()) return true;
        return false;
    }

    double distance_to(const point& b) {
        return sqrt(pow(x-b.x,2) + pow(y-b.y,2));
    }
};

int main() {
    ios::sync_with_stdio(false);

    point a = {1, 1};
    point b = {2, 2};
    ASSERT(abs(a.distance_to(b) - sqrt(2)) < E);
    ASSERT(a.at_right_of(b, (point){0,0}) == false)
    ASSERT(a.at_right_of((point){1,2}, (point){0,0}) == true)

    cout << "Passed: " << pass << " (" << 100.0*pass/test << "%%)" << endl;

    return 0;
}