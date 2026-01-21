#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> ll;
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
        ll.push_back(i);

        cout<<"Resulting list is as follows : \n";
    for (list<int>::iterator li = ll.begin(); li != ll.end(); li++) {
        cout << *li << endl;
    }

    return 0;
}
