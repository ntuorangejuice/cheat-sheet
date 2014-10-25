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
const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

const int BASE_LENGTH = 2;
const int BASE = (int) pow(10, BASE_LENGTH);
const int MAX_LENGTH = 500;


string int_to_string(int i, int width, bool zero) {
    string res = "";
    while (width--) {
        if (!zero && i == 0) return res;
        res = (char)(i%10 + '0') + res;
        i /= 10;
    }
    return res;
}

struct bigint {
    int len, s[MAX_LENGTH];  
    bigint() {  
        memset(s, 0, sizeof(s));  
        len = 1;  
    }

    bigint(int num) {
        len = 0;
        while (num >= BASE) {
            s[len] = num % BASE;
            num /= BASE;
            len ++;
        }
        s[len++] = num;
    }

    bigint(const char* num) {
        int l = strlen(num);
        len = l/BASE_LENGTH;
        if (l % BASE_LENGTH) len++;
        int index = 0;
        for (int i = l - 1; i >= 0; i -= BASE_LENGTH) {
            int tmp = 0;
            int k = i - BASE_LENGTH + 1;
            if (k < 0) k = 0;
            for (int j = k; j <= i; j++) {
                tmp = tmp*10 + num[j] - '0';
            }
            s[index++] = tmp;
        }
    }

    void clean() {  
        while(len > 1 && !s[len-1]) len--;  
    }

    string str() const {
        string ret = "";
        if (len == 1 && !s[0]) return "0";
        for(int i = 0; i < len; i++) {
            if (i == 0) {
                ret += int_to_string(s[len - i - 1], BASE_LENGTH, false);
            } else {
                ret += int_to_string(s[len - i - 1], BASE_LENGTH, true);
            }
        }
        return ret;
    }

    bigint operator + (const bigint& b) {
        bigint ret = b;
        while (ret.len < len) ret.s[ret.len++] = 0;
        ret.s[ret.len++] = 0;
        bool r = false;
        for (int i = 0; i < len || r; i++) {
            if (i<len) ret.s[i] += s[i] + r;
            else ret.s[i] += r;
            r = ret.s[i] >= BASE;
            if (r) ret.s[i] %= BASE;
        }
        ret.clean();
        return ret;
    } 

    bigint operator * (const bigint& b) {  
        bigint c;
        c.len = len + b.len;  
        for(int i = 0; i < len; i++)  
            for(int j = 0; j < b.len; j++)  
                c.s[i+j] += s[i] * b.s[j];  
        for(int i = 0; i < c.len-1; i++){  
            c.s[i+1] += c.s[i] / BASE;  
            c.s[i] %= BASE;  
        }  
        c.clean();  
        return c;  
    }

    bigint operator / (const int b) {
        bigint ret;
        int down = 0;
        for (int i = len - 1; i >= 0; i--) {
            ret.s[i] = (s[i] + down * BASE) / b;
            down = s[i] + down * BASE - ret.s[i] * b;
        }
        ret.len = len;
        ret.clean();
        return ret;
    }

    bool operator == (bigint b) {
        if (len != b.len) return false;
        for (int i = 0; i < len; i++) 
            if (s[i]!=b.s[i]) return false;
        return true;
    }
};


int test = 0, pass = 0;

void assert(string desc, bool result) {
    test++; pass+=result;
    cout << (result ? "PASS: " : "FAIL: ")
         << desc << endl;
}


int main() {
    bigint a = 2;
    bigint b = 9999;
    assert("2+9999", (a+b).str()=="10001");
    assert("2+9999", (a+b)==bigint(10001));
    cout << "Total test: " << test << endl;
    cout << "Passed: " << 100.0*pass/test << "%%" << endl;
}