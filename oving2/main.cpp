#include <iostream>
#include <set>
#include <string>
using namespace std;

void oppgave1() {
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  cout << &i << " - " << i << endl;
  cout << &j << " - " << j << endl;
  cout << &p << " - " << p << endl;
  cout << &q << " - " << q << endl;

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;
  cout << *p << " " << *q << endl;
}

void oppgave2() {
  char *line = nullptr;
  strcpy(line, "Dette er en tekst");
}

void oppgave3() {

  char text[5];
  char *pointer = text;
  char search_for = 'e';
  cin >> text;
  while (*pointer != search_for) {
    *pointer = search_for;
    pointer++;
  }
}

void oppgave4() {
  /* kode med feil:
  int a = 5;
  int &b; // b er en referanse og blir initialisert men ingen verdi, i c++ er det ikke mulig å referere til ingenting
  int *c;
  c = &b;
  *a = *b + *c; // a er en int og kan ikke bli dereferencet
  &b = 2; // b er opprinnelig en referanse til a, og det er ikke mulig å sette en int for denne variabelen når det er en int*
  */

  // Riktig syntaks
  int a = 5;
  int &b = a;
  int *c;
  c = &b;
  a = b + *c;
}

void oppgave5() {
  double number;
  double *ptr = &number;
  double &ref = number;

  number = 10; // sette variabelen
  cout << number << endl;

  *ptr = 11; // endre variabelen ved å endre verdien til det ptr peker på (number)
  cout << number << endl;

  ref = 12; // endre referansen
  cout << number << endl;
}

int find_sum(const int *table, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += table[i];
  }
  return sum;
}

void oppgave6() {

  int table[20];
  for (int i = 0; i < 20; i++) {
    table[i] = i + 1;
  }

  int first10 = find_sum(table, 10);
  int next5 = find_sum(table + 10, 5);
  int last5 = find_sum(table + 15, 5);

  cout << first10 << endl;
  cout << next5 << endl;
  cout << last5 << endl;
}

int main() {

  // oppgave1();
  // oppgave4();
  // oppgave5();
  oppgave6();

  return 1;
}
