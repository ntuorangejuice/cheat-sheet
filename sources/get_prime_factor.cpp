// get prime factor
// :::: for prime number, if n >= 5, prime number = 6n+1 or 6n-1 ::::

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long p;
    cin >> p;

    long long ans = 1;
    while (p != 1) {
        ans++;
        while (p % ans == 0) {
            p = p / ans;
        }
    }
    cout << ans;
}


// 描述
// 已知正整数n是两个不同的质数的乘积试求出较大的那个质数。
// 格式
// 输入格式

// 输入只有一行包含一个正整数n。
// 输出格式

// 输出只有一行包含一个正整数p, 即较大的那个质数。
// 样例1
// 样例输入1[复制]

// 21
// 样例输出1[复制]

// 7
// 限制
// 1S