// Convex Hull problem
// Graham's Scan

#include <iostream>
#include <algorithm>
#include <cmath>
#define TESTING false
using namespace std;

class Point {
public:
    long __x__;
    long __y__;
    
    Point();
    Point(long, long);
    ~Point();

    bool at_right_of(Point& that, Point& base);
    long operator* (Point& that);
    double distance_to(Point& that);
    double length();
    void show();
};

Point::Point(long x, long y): __x__(x), __y__(y) {};
Point::Point() {};
Point::~Point() {};
void Point::show() {
    cout << "(" << this->__x__ << ", " << this->__y__ << ")";
}
bool Point::at_right_of(Point& that, Point& base) {
    Point vec_self(this->__x__ - base.__x__, this->__y__ - base.__y__);
    Point vec_that(that.__x__ - base.__x__, that.__y__ - base.__y__);

    long product = vec_self * vec_that;
    if (product > 0) {
        if (TESTING) {
            this->show();
            cout << " at right of ";
            that.show();
            cout << endl;           
        }

        return true;
    }
    if (product == 0 && vec_self.length() > vec_that.length()) {
        if (TESTING) {
            this->show();
            cout << " at right of ";
            that.show();
            cout << endl;
        }
        return true;
    }
    
    if (TESTING) {
        this->show();
        cout << " not at right of ";
        that.show();
        cout << endl;
    }
    return false;
};
double Point::length() {
    return sqrt(pow((double)this->__x__, 2) + pow((double)this->__y__, 2));
}
long Point::operator* (Point& that) {
    return this->__x__ * that.__y__ - this->__y__ * that.__x__;
};
double Point::distance_to(Point& that) {
    double temp = pow((double)this->__x__ - that.__x__, 2) + pow((double)this->__y__ - that.__y__, 2);
    return sqrt(temp);
};

Point* p;
int* stack;
int n, l, stack_top = -1;

bool compare(Point p1, Point p2) {
    Point vec_self(p1.__x__ - p[0].__x__, p1.__y__ - p[0].__y__);
    Point vec_that(p2.__x__ - p[0].__x__, p2.__y__ - p[0].__y__);

    long product = vec_self * vec_that;
    if (product > 0)
        return true;
    if (product == 0 && vec_self.length() > vec_that.length())
        return true;
    return false;
}

void show() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        p[i].show();
        cout << endl;
    }
    cout << endl;
}
void show_stack() {
    cout << "stack: " << stack_top  + 1 << endl;
    for (int i = stack_top; i >= 0; i--) {
        p[stack[i]].show();
        cout << endl;
    }
    cout << "__________" << endl;
}

void push(int index) {
    stack[++stack_top] = index;
    
    if (TESTING) {
    cout << "\n-- push -- ";
    p[stack[stack_top]].show();
    cout << endl;
    show_stack();
    }
}
int pop() {
    int temp = stack[stack_top--];
    if (TESTING) {
        cout << "\n-- pop -- ";
        p[temp].show();
        cout << endl;
        show_stack();
    }
    return temp;
}

void scan() {
    push(0);
    push(1);

    int pre;
    int prepre;
    for (int i = 2; i < n; i++) {
        pre = stack_top;
        prepre = stack_top - 1;
        while (p[i].at_right_of(p[stack[pre]], p[stack[prepre]])) {
            pop();
            if (stack_top == 0)
                break;
            pre = stack_top;
            prepre = stack_top - 1;
        }
        push(i);
    }

    int last = stack_top;
    if (p[0].at_right_of(p[stack[last]], p[stack[pre]]))
        pop();
}

int main(int argc, char const *argv[]) {
    cin >> n >> l;
    p = new Point[n];
    stack = new int[n];
    
    int minimun = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        Point temp(x, y);
        p[i] = temp;

        if ((p[i].__y__ < p[minimun].__y__) || (p[i].__y__ == p[minimun].__y__ && p[i].__x__ < p[minimun].__x__))
            minimun = i;
    }
        
    Point temp(p[minimun].__x__, p[minimun].__y__);
    p[minimun] = p[0];
    p[0] = temp;

    if (TESTING) {
        show();
    }
    
    sort(p + 1, p + n, compare);
    
    if (TESTING) {
        show();
    }
    scan();
    
    if (TESTING) {
        cout << "\n--- final ---" << endl;
        show_stack();        
    }

    double ans = 0;
    for (int i = 0; i < stack_top; i++) {
        ans += p[stack[i]].distance_to(p[stack[i + 1]]);
    }
    ans += p[stack[0]].distance_to(p[stack[stack_top]]);

    cout << (long)(ans + 2 * 3.1415926 * l + 0.5) << endl;
}


// Wall
// Time Limit: 1000MS      Memory Limit: 10000K
// Total Submissions: 29880        Accepted: 10035
// Description

// Once upon a time there was a greedy King who ordered his chief Architect to build a wall around the King's castle. The King was so greedy, that he would not listen to his Architect's proposals to build a beautiful brick wall with a perfect shape and nice tall towers. Instead, he ordered to build the wall around the whole castle using the least amount of stone and labor, but demanded that the wall should not come closer to the castle than a certain distance. If the King finds that the Architect has used more resources to build the wall than it was absolutely necessary to satisfy those requirements, then the Architect will loose his head. Moreover, he demanded Architect to introduce at once a plan of the wall listing the exact amount of resources that are needed to build the wall. 


// Your task is to help poor Architect to save his head, by writing a program that will find the minimum possible length of the wall that he could build around the castle to satisfy King's requirements. 

// The task is somewhat simplified by the fact, that the King's castle has a polygonal shape and is situated on a flat ground. The Architect has already established a Cartesian coordinate system and has precisely measured the coordinates of all castle's vertices in feet.
// Input

// The first line of the input file contains two integer numbers N and L separated by a space. N (3 <= N <= 1000) is the number of vertices in the King's castle, and L (1 <= L <= 1000) is the minimal number of feet that King allows for the wall to come close to the castle. 

// Next N lines describe coordinates of castle's vertices in a clockwise order. Each line contains two integer numbers Xi and Yi separated by a space (-10000 <= Xi, Yi <= 10000) that represent the coordinates of ith vertex. All vertices are different and the sides of the castle do not intersect anywhere except for vertices.
// Output

// Write to the output file the single number that represents the minimal possible length of the wall in feet that could be built around the castle to satisfy King's requirements. You must present the integer number of feet to the King, because the floating numbers are not invented yet. However, you must round the result in such a way, that it is accurate to 8 inches (1 foot is equal to 12 inches), since the King will not tolerate larger error in the estimates.
// Sample Input

// 9 100
// 200 400
// 300 400
// 300 300
// 400 300
// 400 400
// 500 400
// 500 200
// 350 200
// 200 200
// Sample Output

// 1628