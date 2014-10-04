# The Orange Juice ACM-ICPC Cheat Sheet

## Basic

### C++ Solution Template

```c++
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
     * Main program.
     */
    return 0;
}
```

### C++ String

#### Input string

* get one string with no space and new-line.

```c++
string a;
cin >> a;
cout << "[C++] You have input \"" << a << "\", "
     << ", whose length is " << a.length() << endl;
```

Input
```
hello world
new line
```

Output
```
[C++] You have input "hello", , whose length is 5
```

### C String (Character Array)

#### Input C String

* gets

Reads characters from the standard input (stdin) and stores them as a C string into str until a newline character or the end-of-file is reached.

```c++
char b[10];
gets(b);
cout << "[C++] You have input \"" << b << "\", "
     << ", whose length is " << strlen(b) << endl;
```

Input
```
 world
new line
```

Output
```
[C] You have input " world", , whose length is 6
```

Note: There is a space in front of "world", which will be part of the string.

However, using gets() is "unsafe".