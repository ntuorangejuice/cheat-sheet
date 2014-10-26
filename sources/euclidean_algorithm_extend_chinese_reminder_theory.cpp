// Chinese Reminder Theory
// solution to   x mod A = a; x mode B = b; ...

#include <iostream>
using namespace std;

int ansx, ansy, ansd;

void extend_euclidean(int a, int b) {
    if (b == 0) {
        ansx = 1;
        ansy = 0;
        ansd = a;
    } else {
        extend_euclidean(b, a % b);
        int temp = ansx;
        ansx = ansy;
        ansy = temp - a / b * ansy;
    }
}

int main(int argc, char const *argv[]) {
    const int P = 23;
    const int E = 28;
    const int I = 33;
    const int PEI = P * E * I;
    extend_euclidean(P, E);
    const int lcmPE = P * E / ansd;
    extend_euclidean(P, I);
    const int lcmPI = P * I / ansd;
    extend_euclidean(E, I);
    const int lcmEI = E * I / ansd;

    int noc = 1;
    while (true) {
        int p, e, i, now, xp, xe, xi;
        cin >> p >> e >> i >> now;
        if (p == -1)
            break;
        
        extend_euclidean(lcmPE, I);
        xi = (ansx % I + I) % I * lcmPE;
        extend_euclidean(lcmPI, E);
        xe = (ansx % E + E) % E * lcmPI;
        extend_euclidean(lcmEI, P);
        xp = (ansx % P + P) % P * lcmEI;
        
        int x = ((xi * i + xe * e + xp * p) % PEI + PEI) % PEI;
        int ans = (x - now + PEI) % PEI;
        if (ans == 0)
            ans = PEI;
        cout << "Case " << noc++ << ": the next triple peak occurs in " << ans << " days.\n";
    }
}



// Biorhythms
// Time Limit: 1000MS      Memory Limit: 10000K
// Total Submissions: 111704       Accepted: 34800
// Description

// Some people believe that there are three cycles in a person's life that start the day he or she is born. These three cycles are the physical, emotional, and intellectual cycles, and they have periods of lengths 23, 28, and 33 days, respectively. There is one peak in each period of a cycle. At the peak of a cycle, a person performs at his or her best in the corresponding field (physical, emotional or mental). For example, if it is the mental curve, thought processes will be sharper and concentration will be easier. 
// Since the three cycles have different periods, the peaks of the three cycles generally occur at different times. We would like to determine when a triple peak occurs (the peaks of all three cycles occur in the same day) for any person. For each cycle, you will be given the number of days from the beginning of the current year at which one of its peaks (not necessarily the first) occurs. You will also be given a date expressed as the number of days from the beginning of the current year. You task is to determine the number of days from the given date to the next triple peak. The given date is not counted. For example, if the given date is 10 and the next triple peak occurs on day 12, the answer is 2, not 3. If a triple peak occurs on the given date, you should give the number of days to the next occurrence of a triple peak. 
// Input

// You will be given a number of cases. The input for each case consists of one line of four integers p, e, i, and d. The values p, e, and i are the number of days from the beginning of the current year at which the physical, emotional, and intellectual cycles peak, respectively. The value d is the given date and may be smaller than any of p, e, or i. All values are non-negative and at most 365, and you may assume that a triple peak will occur within 21252 days of the given date. The end of input is indicated by a line in which p = e = i = d = -1.
// Output

// For each test case, print the case number followed by a message indicating the number of days to the next triple peak, in the form: 

// Case 1: the next triple peak occurs in 1234 days. 

// Use the plural form ``days'' even if the answer is 1.
// Sample Input

// 0 0 0 0
// 0 0 0 100
// 5 20 34 325
// 4 5 6 7
// 283 102 23 320
// 203 301 203 40
// -1 -1 -1 -1
// Sample Output

// Case 1: the next triple peak occurs in 21252 days.
// Case 2: the next triple peak occurs in 21152 days.
// Case 3: the next triple peak occurs in 19575 days.
// Case 4: the next triple peak occurs in 16994 days.
// Case 5: the next triple peak occurs in 8910 days.
// Case 6: the next triple peak occurs in 10789 days.