#include <fstream>
#include <iostream>
using namespace std;

vector<double> read_temperatures(double temperatures[], int length) {
  ifstream file;
  file.open("tallfil.txt");
  if (!file) {
    cout << "Noe gikk feil" << endl;
    exit(EXIT_FAILURE);
  }
  int i = 0;
  double number;
  while (i < length && file >> number) {

    temperatures[i] = number;
    cout << "Leste inn: " << temperatures[i] << endl;
  }
  file.close();
}
