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

##### Input string

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

##### Convert to char array

```c++
string cppstr = "this is a string";
char target[1024];
strcpy(target, cppstr.c_str());
```


### C String (Character Array)

##### Input C String

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

##### Convert to C++ string
char arrstr[] = "this is a string";
string target = string(arr);



## Standard Template Library ##

##### ``include <algorithm>`` #####

next_permutation
adjacent_find / binary_search / copy / copy_backward / count
/ count_if / equal / equal_range / fill / fill_n / find /
find_end / find_first_of / find_if / for_each / generate /
generate_n / includes / inplace_merge / iter_swap /
lexicographical_compare / lower_bound / make_heap / max /
max_element / merge / min / min_element / mismatch /
next_permutation / nth_element / partial_sort /
partial_sort_copy / partition / pop_heap / prev_permutation
/ push_heap / random_shuffle / remove / remove_copy /
remove_copy_if / remove_if / replace / replace_copy /
replace_copy_if / replace_if / reverse / reverse_copy /
rotate / rotate_copy / search / search_n / set_difference /
set_intersection / set_symmetric_difference / set_union /
sort / sort_heap / stable_partition / stable_sort / swap /
swap_ranges / transform / unique / unique_copy / upper_bound

##### ``include <map>`` #####

##### ``include <priority_queue>`` #####

##### ``include <queue>`` #####

##### ``include <stack>`` #####

##### string #####

##### T::iterator #####

##### ``include <vector>`` #####

##### pair\<, \> #####
