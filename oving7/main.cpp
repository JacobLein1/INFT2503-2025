//
// fraction/main.cpp
//
#include "fraction.hpp"
#include <iostream>
#include <string>
#include "Set.hpp"

using namespace std;

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    b += a;
    ++c;
    d *= d;

    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    c = a + b - d * a;
    c = -c;

    print("c = ", c);

    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);

    Fraction result1 = b-3;
    print("result1 = ",result1);
    Fraction result2 = 3-b;
    print("result2 = ",result2);

    Fraction fraction1(1,2);
    Fraction fraction2(1,4);
    Fraction result3 = 5 - 3 - fraction1 - 7 - fraction2;
    print("result3 = ",result3);

    // Måten result 3 tolkes (venstre assosiativ):
    // 5 - 3 - fraction1 - 7 - fraction2
    // (5 - 3) - fraction1 - 7 - fraction2 -> innebygd int funksjon
    // (2 - fraction1) - 7 - fraction2 -> kaller ikke-medlemsfunksjon (Fraction operator-(int integer, const Fraction &other))
    // Resultat blir en Fraction (kaller den fraction3 her)
    // (fraction3 - 7) - fraction2 -> bruker medlemsfunksjon kaller resultat fraction4
    // fraction4 - fraction2 bruker medlemsfunksjon (Fraction::operator-(const Fraction&))
    // Resultatet blir en Fraction -> result3

    Set A;
    A += 3;
    A += 5;

    Set B;
    B += 3;
    B += 8;
    B += 10;
    B += 3;

    std::cout << "Mengden A er: " << A << std::endl;
    std::cout << "Mengden B er: " << B << std::endl;

    Set C = A + B;
    Set D = C;
    std::cout << "Mengden C er: " << C << std::endl;
    std::cout << "Mengden D er: " << D << std::endl;

}