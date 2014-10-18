# Orange Juice - ACM-ICPC Cheat Sheet

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
#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOWSHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOWSHOWSHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define REACH_HERE {cout << "REACH_HERE!" << endl;}

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

#### read one line

* get one line

```c++
string a;
getline(cin, a);
cout << a << endl;
```

Input
```
Hello World!!!
```

Output
```
Hello World!!!
```


#### Convert to char array

```c++
string cppstr = "this is a string";
char target[1024];
strcpy(target, cppstr.c_str());
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

However, using gets() is "unsafe", but we are not to discuss the details here.

#### Convert to C++ string
char arrstr[] = "this is a string";
string target = string(arr);


### Algorithm

```
include <algorithm>
```

#### Permutation

next_permutation

```
// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints,myints+3) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
```

Output

```
The 3! possible permutations with 3 elements:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
After loop: 1 2 3
```

#### Binary Search

```
bool binary_search (ForwardIterator first, ForwardIterator last,
                      const T& val);
bool binary_search (ForwardIterator first, ForwardIterator last,
                      const T& val, Compare comp);
```


```
// binary_search example
#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

int main () {
  int myints[] = {1,2,3,4,5,4,3,2,1};
  std::vector<int> v(myints,myints+9);                         // 1 2 3 4 5 4 3 2 1

  // using default comparison:
  std::sort (v.begin(), v.end());

  std::cout << "looking for a 3... ";
  if (std::binary_search (v.begin(), v.end(), 3))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  // using myfunction as comp:
  std::sort (v.begin(), v.end(), myfunction);

  std::cout << "looking for a 6... ";
  if (std::binary_search (v.begin(), v.end(), 6, myfunction))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  return 0;
}
```

### Standard Template Library

##### ``include <algorithm>``

####### ``next_permutation / pre_permutation``

####### ``binary_search``

####### ``swap / iter_swap``

####### ``make_heap / pop heap / push heap / sort_heap``

####### ``sort / stable_sort``



##### ``include <map>``

##### ``include <priority_queue>``

##### ``include <queue>``

##### ``include <stack>``

##### ``string``

##### ``T::iterator``

##### ``include <vector>``

##### ``pair<, >``



### Java BigInteger & BigDecimal




### String Related

##### KMP

##### Longest palindromic substring (Manacher's algorithm)

##### 后缀数组


### Tree Related

##### Tree Traversal

##### Trie

##### Segment Tree

##### Union-find Set 冰茶鸡

##### 。。。




### Graph Theory

##### Minimium Spanning Tree

####### Prime

####### Kruskal


##### Shortest Path

####### 任意两点

####### SPFA

####### Dijkstra


##### 二分图

##### 最大流

####### Dinic
``` C++
int graph[250][250];
int level[250];
int n_node, n_edge;

int mark_level() {
    memset(level, -1, sizeof(level));
    queue<int> to_visit;
    
    level[1] = 0;
    to_visit.push(1);
    while (!to_visit.empty()) {
        int cur = to_visit.front();
        to_visit.pop();
        for (int i = 1; i <= n_node; ++i) {
            if (graph[cur][i] != 0 && level[i] == -1) {
                level[i] = level[cur] + 1;
                to_visit.push(i);
            }
        }
    }

    if (level[n_node] == -1)
        return 0; // cannot reach the sink
    return 1; // can reach the sink
}

int augment_recursive(int cur, int min_flow) {
    if (cur == n_node)
        return min_flow;

    int augmented_flow = 0;
    for (int i = 1; i <= n_node; ++i) {
        if (level[i] == level[cur] + 1 && graph[cur][i] > 0 && (augmented_flow = augment_recursive(i, min(graph[cur][i], min_flow)))) {
            graph[cur][i] -= augmented_flow;
            graph[i][cur] += augmented_flow;
            return augmented_flow;
        }
    }
    return 0;
}

int dinic() {
    int ans = 0;
    int temp = 0;
    while (mark_level())
        while (temp = augment_recursive(1, INT_MAX))
            ans += temp;
    return ans;
}

int main() {
    cin >> n_edge >> n_node)
    memset(graph, 0, sizeof(graph));
    
    int start_node, end_node, flow;
    for (int i = 0; i < n_edge; ++i) {
        cin >> start_node >> end_node >> flow;
        graph[start_node][end_node] += flow; // use "+" to combine
    }
    cout << dinic() << endl;
}
```
 
##### 最小费用最大流 ?

##### 强连通分量 图的 割点, 桥, 双连通分支

##### 拓扑排序

##### Euler Cycle/Path, Hamilton Cycle/Path

##### 。。。




### Math

##### 欧拉函数 ?

##### 欧几里得的算法
```C++
int gcd();
```

##### 中国剩余定理

##### 最大公约数

##### 最小公倍数

##### 分解质因数

##### 因数个数

##### 素数判定

##### 进制转换

##### 。。。



### 博弈论

##### 。。。




### 计算几何

##### 向量点乘 叉乘

##### 直线公式

##### Convex Hull

####### Gift Wrapping

####### QuickHull

####### Graham scan
```C++
```



### Tricks / 分析方法

##### Dynamic Programming

####### 树上的

##### Divide and Conquer

####### Fast Exponention


##### 双向 BFS

##### Brute Force

####### 子集生成



### Userful Code Snippets

##### Fast Exponention
```C++
// NEED VERIFY
int power_modulo(int n, int p, int M) {  
    int result = 1;
    while (p > 0) {
        if (p % 2 == 1)
            result = (result*n) % M;
        p /= 2;
        n = (n*n) % M;
    }
    return result;

}
```

##### 刷质数表
