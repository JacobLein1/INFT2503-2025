#include "Circle.cpp"
#include "Commodity.cpp"
#include <iostream>
#include <string>
using namespace std;

string read(const string &prompt) {
  cout << prompt << endl;
  string input;
  getline(cin, input);
  return input;
}

int main() {
  Circle circle(5);

  double area = circle.get_area();
  cout << "Arealet er lik " << area << endl;

  double circumference = circle.get_circumference();
  cout << "Omkretsen er lik " << circumference << endl;

  const double quantity = 2.5;
  Commodity commodity("Norvegia", 123, 73.50);

  cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id()
       << " Pris pr enhet: " << commodity.get_price() << endl;

  cout << "Kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
       << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
       << " med moms" << endl;

  commodity.set_price(79.60);
  cout << "Ny kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
       << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
       << " med moms" << endl
       << endl;

  cout << "Oppgave4: " << endl;

  string word1 = read("Skriv inn ord 1");
  string word2 = read("Skriv inn ord 2");
  string word3 = read("Skriv inn ord 3");

  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << sentence << endl;

  cout << "Lengden av ord 1: " << word1.length() << endl;
  cout << "Lengden av ord 2: " << word2.length() << endl;
  cout << "Lengden av ord 3: " << word3.length() << endl;
  cout << "Lengden av setning: " << sentence.length() << endl;

  string sentence2 = sentence;

  if (sentence.length() >= 12) {
    for (int i = 10; i < 12; i++) {
      sentence2[i] = 'x';
    }
  }
  cout << "Sentence 1: " << sentence << endl;
  cout << "Sentence 2: " << sentence2 << endl;

  string sentence_start = "";

  for (int i = 0; i < 5; i++) {
    sentence_start.push_back(sentence[i]);
  }

  if (sentence.find("hallo", 0) != string::npos) {
    cout << "Setningen inneholder hallo" << endl;
  }

  int occurences = 0;
  std::string::size_type pos = 0;
  string target = "er";
  while ((pos = sentence.find(target, pos)) != std::string::npos) {
    ++occurences;
    pos += target.length();
  }
  cout << "Antall repetisjoner av 'er' : " << occurences << endl;
}
