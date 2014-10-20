#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    for (list<int>::iterator li = ll.begin(); li != ll.end(); li++) {
        cout << *li << endl;
    }

    return 0;
}