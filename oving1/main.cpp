#include <iostream>

using namespace std;
void opgA();
void read_temperatures(double temperatures[], int length);

int main() {
  opgA();
  cout << "\nBegynner oppgave B" << endl;

  int length = 5;
  double temps[5];
  read_temperatures(temps, length);
}
