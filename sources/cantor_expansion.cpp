// Cantor expansion
// reverse Cantor expansion

#include <iostream>
#include <iterator>
#include <cstring>
using namespace std;

long long factorial(int n) {
    if (n == 0)
        return 1;

    long long ans = n;
    for (int i = 1; i < n; i++)
        ans = ans * i;
    return ans;
}

long long cantor_expansion(int permutation[], int n) {
    int used[n + 1];
    memset(used, n, sizeof(used));

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        used[permutation[i]] = 1;
        for (int j = 1; j < permutation[i]; j++)
            if (used[j] != 1)
                temp += 1;
        ans += factorial(n - 1 - i) * temp;
    }

    return ans + 1;
}

void reverse_cantor_expansion(int n, long long m) {
    int ans[n + 1], used[n + 1];
    memset(ans, -1, sizeof (ans));
    memset(used, 0, sizeof (used));

    m = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        long long fac = factorial(i);
        int temp = m / fac + 1;
        m = m - (temp - 1) * fac;
        for (int j = 1; j <= temp; j++)
            if (used[j] == 1)
                temp++;

        ans[n - i] = temp;
        used[temp] = 1;
    }

    for (int i = 1; i < n + 1; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main(int argc, char const *argv[]) {
    int n;
    long long m;
    cin >> n >> m;

    reverse_cantor_expansion(n, m);
}



// 描述
// 输入两个自然数m,n 1<=n<=20，1<=m<=n!
// 输出n个数的第m种全排列。
// 如 ：
// 输入 3 1
// 输出 1 2 3
// 格式
// 输入格式

// 在一行中输入n m
// 输出格式

// 一个数列,既n个数的第m种排列
// 每两个数之间空1格
// 样例1
// 样例输入1[复制]

// 3 2
// 样例输出1[复制]

// 1 3 2