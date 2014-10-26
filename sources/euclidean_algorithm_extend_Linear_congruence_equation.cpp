// extend-euclidean algorithm
// 1. gcd(a, b)
// 2. ax mod n = b mod n ......-> ax + ny = gcd(a, n) * (b / gcd(a, n))
// 3. ax mod n = 1       ......-> ax + ny = gcd(a, n) * (1 / gcd(a, n))

#include <iostream>
using namespace std;

long long ansx, ansy, ansd;

void euclidean(long long a, long long b) {
    if (b == 0) {
        ansx = 1;
        ansy = 0;
        ansd = a;
    } else {
        euclidean(b, a % b);
        long long temp = ansx;
        ansx = ansy;
        ansy = temp - a / b * ansy;
    }
}

int main(int argc, char const *argv[]) {
    long long a, b;
    cin >> a >> b;

    ansx = 0;
    ansy = 0;
    ansd = 0;
    euclidean(a, b);

    if (ansd != 1) {
        cout << "bad!";
    }
    else {
        ansx = (ansx % b + b) % b;
        cout << ansx;    
    }
}

// 描述
// 求关于x的同余方程ax ≡ 1 (mod b)的最小正整数解。
// 格式
// 输入格式

// 输入只有一行，包含两个正整数a, b，用一个空格隔开。
// 输出格式

// 输出只有一行，包含一个正整数x0，即最小正整数解。输入数据保证一定有解。
// 样例1
// 样例输入1[复制]

// 3 10
// 样例输出1[复制]

// 7