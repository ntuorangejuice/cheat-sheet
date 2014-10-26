// Matrix
// ...
// http://www.matrix67.com/blog/archives/276
// ...

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

#define GET_BIT(n, i) (((n) & (1 << ((i)-1))) >> ((i)-1))
#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define REACH_HERE {cout << "REACH_HERE!" << endl;}


const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

int n;
int k;
int m;

struct Matrix {
    // int height;
    // int width;

    long long value[32][32];

    Matrix operator* (const Matrix& that);
    Matrix operator+ (const Matrix& that);
    Matrix mirror();
    void show() {
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << this->value[i][j] << " ";
            cout << endl;
        }
    }
};

void mod_it(Matrix& temp) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp.value[i][j] %= m;
}

Matrix Matrix::operator* (const Matrix& that) {
    Matrix temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.value[i][j] = 0;
            for (int k = 0; k < n; k++)
                temp.value[i][j] += this->value[i][k] * that.value[k][j];
        }
    }
    mod_it(temp);
    return temp;
}

Matrix Matrix::operator+ (const Matrix& that) {
    Matrix temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp.value[i][j] = this->value[i][j] + that.value[i][j];
    mod_it(temp);
    return temp;
}

Matrix Matrix::mirror() {
    Matrix temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp.value[i][j] = this->value[i][j];
    return temp;
}

Matrix a;
Matrix one;

Matrix get_single(int the_k) {
    if (the_k == 0)
        REACH_HERE;
    if (the_k == 1)
        return a.mirror();

    if (the_k % 2 == 0) {
        Matrix temp = get_single(the_k / 2);
        return temp * temp;
    }
    else
        return get_single(the_k - 1) * get_single(1);
}

Matrix get(int the_k) {
    if (the_k == 0)
        REACH_HERE;
    if (the_k == 1)
        return a.mirror();

    if (the_k % 2 == 0) {
        Matrix sum = get(the_k / 2);
        Matrix second = get_single(the_k / 2);
        return sum + (sum * second);
    }
    else
        return get(the_k - 1) + get_single(the_k);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a.value[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            one.value[i][j] = i == j ? 1 : 0;

    Matrix ans = get(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans.value[i][j] << " ";
        cout << endl;
    }

    return 0;
}


// D - Matrix Power Series
// Time Limit:3000MS     Memory Limit:131072KB     64bit IO Format:%I64d & %I64u
// Submit
 
// Status
// Description
// Given a n × n matrix A and a positive integer k, find the sum S = A + A^2 + A^3 + … + A^k.

// Input
// The input contains exactly one test case. The first line of input contains three positive integers n (n ≤ 30), k (k ≤ 109) and m (m < 104). Then follow n lines each containing n nonnegative integers below 32,768, giving A’s elements in row-major order.

// Output
// Output the elements of S modulo m in the same way as A is given.

// Sample Input
// 2 2 4
// 0 1
// 1 1
// Sample Output
// 1 2
// 2 3
