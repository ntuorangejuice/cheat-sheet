#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vt;
    vt.push_back(1);
    vt.push_back(2);
    vt.push_back(3);
    vt.push_back(4);

    for (vector<int>::iterator it = vt.begin(); it != vt.end(); it++) {
        cout << *it << endl;
    }

    cout << vt[2] << endl;

    return 0;
}