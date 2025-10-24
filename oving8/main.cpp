#include <iostream>
#include "equal.h"
#include <string>
#include <iostream>
#include "Pair.h"
using namespace std;

int main() {
    // check for strings
    string input1 = "Ja";
    string input2 = "Ja";

    string input3 = "Nei";

    cout << "Testing input1 and input2: " << equal(input1,input2) << endl;
    cout << "Testing input1 and input3: "<< equal(input3,input2) << endl;

    int test1 = 1;
    int test2 = 1;
    int test3 = 3;

    cout<< "Testing test1 and test2: " << equal(test1,test2) << endl;
    cout<< "Testing test1 and test3: " << equal(test1,test3) << endl;

    double input4= 1.5;
    double input5 = 1.5;
    double input6 = 3.3;

    cout<< "Testing input4 and input5: " << equal(input4,input5) << endl;
    cout<< "Testing input4 and input6: " << equal(input4,input6) << endl;

    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first<< ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second<< endl;
}