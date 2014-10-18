# Orange Juice - ACM-ICPC Cheat Sheet

## Basic

### C++ Solution Template

```c++
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

/*
 * n: number
 * i: LSB starting from 1
 */
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

Output

```
looking for a 3... found!
looking for a 6... not found.
```

### Standard Template Library

##### ``include <algorithm>``

####### ``next_permutation / pre_permutation``

```C++
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last); // use operator<
// return true if now is larger than previous, false if now is initial permutation
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);
```

```C++
int n = 3; int a[3] = {1,2,3};
// cout ...
while (next_permutation(a, a + n))
    // cout ...
cout << "return false: (go back)" << endl;
// cout ...

// output:
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
// return false: (go back)
// 1 2 3
```

####### ``binary_search``

```C++
// first...last should be sorted using operator< or comp
bool binary_search (ForwardIterator first, ForwardIterator last, const T& val);
// return true if found, false if not
bool binary_search (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
```

####### ``swap / iter_swap``



####### ``make_heap / pop heap / push heap / sort_heap``
```C++
// use priority_queue
```

####### ``sort / stable_sort``



##### ``include <map>``

##### ``include <list>`` double linked list

```C++

```


##### ``include <dequeue>``

##### ``include <queue>``

####### ``queue``

```C++
// constructor
queue<int> my_queue;
queue<int, list<int> > my_queue (my_list); // use list<int> as container, copy my_list into my_queue

void queue::push(const value_type& val);
void queue::pop();
bool queue::empty() const;
size_type queue::size() const;
const_reference& queue::front() const;
```

####### ``priority_queue``

```C++
// constructor
priority_queue<int> my_priority_queue;
priority_queue<int, vector<int>, greater<int> > two_priority_queue; // if use greater<int>, must have vector<int>
priority_queue<My_type, vector<My_type>, Comparator_class> my_priority_queue (my_data.begin(), my_data.end()); // use Comparator_class as comparator, use vector<My_type> as container, copy my_data into my_priority_queue

bool priority_queue::empty() const; // return true if empty, false if not
size_type priority_queue::size() const; // return size of queue
const_reference priority_queue::top() const; // returns a constant reference to the top element
void priority_queue::push(const value_type& val); // inserts a new element, initialize to val
void priority_queue::pop(); // removes the element on top
```
```C++
struct My_type {
    int weight;
    int other;
};

struct My_class_for_compare {
    public:
        bool operator() (My_type a, My_type b) {
            return a.weight < b.weight;
        }
};

vector<My_type> my_vector = {(My_type){2, 789}, (My_type){1, 127}, (My_type){3, 456}};

priority_queue<My_type, vector<My_type>, My_class_for_compare> one_priority_queue (my_vector.begin(), my_vector.end());
one_priority_queue.push((My_type){4, 483});
while (one_priority_queue.size() != 0) {
    My_type temp = one_priority_queue.top();
    one_priority_queue.pop();
    SHOW_B(temp.weight, temp.other);
}

vector<int> my_int = {2, 3, 1};

priority_queue<int, vector<int>, greater<int> > two_priority_queue (my_int.begin(), my_int.end());
while (two_priority_queue.size() != 0) {
    SHOW_A(two_priority_queue.top());
    two_priority_queue.pop();
}

priority_queue<int> three_priority_queue (my_int.begin(), my_int.end());
while (three_priority_queue.size() != 0) {
    SHOW_A(three_priority_queue.top());
    three_priority_queue.pop();
}


// output
// temp.weight = 4, temp.other = 483
// temp.weight = 3, temp.other = 456
// temp.weight = 2, temp.other = 789
// temp.weight = 1, temp.other = 127
// two_priority_queue.top() = 1
// two_priority_queue.top() = 2
// two_priority_queue.top() = 3
// three_priority_queue.top() = 3
// three_priority_queue.top() = 2
// three_priority_queue.top() = 1
```



##### ``include <stack>``

```C++
// constructor, use vector<int> as container, copy my_data into my_stack
stack<int, vector<int> > my_stack (my_data);

bool stack::empty() const;
size_type stack::size() const;
const_reference& stack::top() const;
void stack::push (const value_type& val);
void stack::pop();
```

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

```
for ()
    for ()
        for ()
```

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

##### 强连通分量 图的 割点, 桥, 双连通分支 ``https://www.byvoid.com/blog/biconnect``

##### 拓扑排序

##### Euler Cycle/Path, Hamilton Cycle/Path

##### 。。。




### Math

##### 欧拉函数 ?

##### 欧几里得算法

```C++
int gcd();
```

##### 扩展欧几里得算法 ``http://www.cnblogs.com/frog112111/archive/2012/08/19/2646012.html``

> 对于不完全为 0 的非负整数 a, b, 必然存在整数对 (x, y), 使得 gcd(a, b) = ax + by

> suppose: a > b, we want to get (x1, y1)

> (i) if b == 0, then gcd(a, b) = a = ax + 0, then x1 = 1, y1 = 0

> (ii) if b != 0:

>   (1): a * x1 + b * y1 = gcd(a, b)

>   (2): b * x2 + (a % b) * y2 = gcd(b, a % b)
    
>   (1) == (2)

>   so: a * x1 + b * y1 = b * x2 + (a % b) * y2
    
>   so: a * x1 + b * y1 = b * x2 + (a - (int)(a / b) * b) * y2
    
>   so: a * x1 + b * y1 = a * y2 + b * (x2 - (int)(a / b) * y2)
    
>   so: x1 = y2, y1 = x2 - (int)(a / b) * y2, can get (x1, y1) from (x2, y2)

>   next:

>       (1): b * x2 + (a % b) * y2 = gcd(b, a % b)
        
>       (2): (a % b) * x3 + b % (a % b) * y3 = gcd(a % b, b % (a % b))
        
>       so: can get (x2, y2) from (x3, y3)
        
>       next: ... until in gcd(a, b), b == 0, then xi = 1, yi = 0, go back ...

```C++
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
    long long a, b, c;
    cin >> a >> b >> c;

    ansx = 0;
    ansy = 0;
    ansd = 0;
    euclidean(a, b);

    // now (ansx, ansy) is the answer (x, y) for a * x1 + b * y1 = gcd(a, b)
    // ansd is the a when b == 0, which is just gcd(a, b)
}
```

####### 求解不定方程

> for: p * a + q * b = c

> if c % gcd(a, b) == 0, then 有整数解 (p, q), else NO


> if we get (p0, q0) for p0 * a + q0 * b = gcd(a, b)

> then: for p * a + q * b = gcd(a, b) (k is any integer)

> p = p0 + b / gcd(a, b) * k

> q = q0 - a / gcd(a, b) * k


> then: for p * a + q * b = c = c / gcd(a, b) * gcd(a, b) (k is any integer)

> p = (p0 + b / gcd(a, b) * k) * c / gcd(a, b)

> q = (q0 - a / gcd(a, b) * k) * c / gcd(a, b)

```C++
// after get ansx, ansy, ansd
// test if c % ansd == 0
// ansx = (ansx + b / gcd(a, b) * k) * c / gcd(a, b)
// ansy = (ansy - a / gcd(a, b) * k) * c / gcd(a, b)
// smallest: ansx % (b / gcd(a, b) + b / gcd(a, b)) % (b / gcd(a, b))
```

####### 求解模线性方程（线性同余方程）

> (a * x) % n = b % n, x = ?

> same as: a * x + n * y= b

> so: one answer for a * x + n * y= b is: x * b / gcd(a, n)

> so: one answer for (a * x) % n = b % n is: x0 = (x * b / gcd(a, n)) % n

> other answer xi = (x0 + i * (n / gcd(a, n))) % n, i = 0...gcd(a, n)-1

> smallest answer is x0 % (n / gcd(a, n) + gcd(a, n)) % gcd(a, n)

```C++
```

####### 求解模的逆元

(a * x) % n = 1, x = ?
if gcd(a, n) != 1, then NO answer
else:
same as: a * x + n * y = 1
can get only one answer x

```C++
// after get ansx, ansy, ansd
// if ansd != 1, then NO answer
// smallest ansx = (ansx % (n / gcd(a, n)) + (n / gcd(a, n))) % (n / gcd(a, n))
```

##### 中国剩余定理



##### 最大公约数

##### 最小公倍数

##### 分解质因数

```C++
long long x;
cin >> x;
for (long long factor = 2; x != 1; factor++) {
    if (x % factor == 0)
        cout << factor << " is a prime factor" << endl;
    while (x % factor == 0)
        x = x / factor;
}
```

##### 因数个数

##### 素数判定

```
// 大于 3 的质数可以被表示为 6n - 1 或 6n + 1
```
```
bool is_prime(int n) {
    if (n == 1 || n % 2 == 0)
        return false;  
    int t = sqrt(n);
    for (int i = 3; i <= t; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
```

##### 进制转换

##### 。。。



### 博弈论

##### 。。。




### 计算几何

##### template class for Point?

```C++

```

##### 向量点乘 叉乘

> 点乘意义 点乘公式

> 叉乘意义 叉乘公式

##### 直线公式

##### Convex Hull

####### Gift Wrapping

####### QuickHull

####### Graham scan
```C++
struct Point {
    long x;
    long y;

    bool at_right_of(Point& that, Point& base) {
        Point vec_self = {this->x - base.x, this->y - base.y};
        Point vec_that = {that.x - base.x, that.y - base.y};

        long product = vec_self * vec_that;
        if (product > 0)
            return true; // "this" is at right of "that"
        if (product == 0 && vec_self.length() > vec_that.length())
            return true; // "this" is at right of "that"
        return false; // "this" is NOT at right of "that"
    };
    long operator* (Point& that) {
        return this->x * that.y - this->y * that.x;
    };
    double distance_to(Point& that) {
        long x_diff = this->x - that.x;
        long y_diff = this->y - that.y;
        return sqrt(x_diff * x_diff + y_diff * y_diff);
    };
    double length() {
        return sqrt(this->x * this->x + this->y * this->y);
    }
};

Point p[1005];
int my_stack[1005];
int n, l, my_stack_top = -1;

bool compare(Point p1, Point p2) {
    return p1.at_right_of(p2, p[0]);
}

void push(int index) {
    my_stack[++my_stack_top] = index;
}
int pop() {
    int temp = my_stack[my_stack_top--];
    return temp;
}

void graham_scan() {
    push(0);
    push(1);

    int pre;
    int prepre;
    for (int i = 2; i < n; i++) {
        pre = my_stack_top;
        prepre = my_stack_top - 1;
        while (p[i].at_right_of(p[my_stack[pre]], p[my_stack[prepre]])) {
            pop();
            if (my_stack_top == 0)
                break;
            pre = my_stack_top;
            prepre = my_stack_top - 1;
        }
        push(i);
    }

    int last = my_stack_top;
    if (p[0].at_right_of(p[my_stack[last]], p[my_stack[pre]]))
        pop();
}

int main(int argc, char const *argv[]) {
    cin >> n >> l;
    
    int minimun = 0;
    for (int i = 0; i < n; ++i) {
        int temp_x, temp_y;
        cin >> temp_x >> temp_y;
        p[i] = {temp_x, temp_y};

        if ((p[i].y < p[minimun].y) || (p[i].y == p[minimun].y && p[i].x < p[minimun].x))
            minimun = i;
    }

    Point temp = {p[minimun].x, p[minimun].y}; // swap lowest and most left point to p[0]
    p[minimun] = p[0];
    p[0] = temp;

    sort(p + 1, p + n, compare); // use p[0] as base, sort according to polar angle
    graham_scan();
    // now all points in the stack is on Convex Hull // size of stack = 1 + stack_top

    for (int i = 0; i <= my_stack_top; i++)
        cout << "point " << my_stack[i] << " is on Convex Hull" << endl;
}
```



### Tricks / 分析方法

##### Dynamic Programming

####### 树上的

##### Divide and Conquer

##### 迭代加深搜索 (+ binary increase/decrease)

##### 双向 BFS

##### 从终点开始搜

##### Brute Force

####### 子集生成



### Userful Code Snippets

##### ``cantor_expansion / reverse_cantor_expansion``

```C++
long long factorial(int n) {
    if (n == 0)
        return 1;

    long long ans = n;
    for (int i = 1; i < n; i++)
        ans = ans * i;
    return ans;
}

long long cantor_expansion(int permutation[], int n) {
    // input: (m-th permutation of n numbers, n)
    // return: m
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
    // m-th permutation of n numbers
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
```

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

##### 质数表

```C++
int is_prime[UP_LIMIT + 1];
for (int i = 1; i <= UP_LIMIT; i++) // init to 1
    is_prime[i] = 1;
for (int i = 4; i <= UP_LIMIT; i += 2) // even number is not
    is_prime[i] = 0;
for (int k = 3; k*k <= UP_LIMIT; k++) // start from 9, end at sqrt
    if (is_prime[k])
        for(int i = k*k; i <= UP_LIMIT; i += 2*k) // every two is not 
            is_prime[i] = 0;
```

