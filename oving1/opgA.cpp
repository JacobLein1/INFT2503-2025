#include <iostream>

using namespace std;

void opgA() {

  int numberLow = 0;
  int numberMedium = 0;
  int numberHigh = 0;

  for (int i = 1; i <= 5; i++) {
    int temp = 0;
    cout << "Type temperature number " << i << ": " << endl;
    cin >> temp;
    if (temp < 10) {
      numberLow++;
    } else {
      if (temp <= 20) {
        numberMedium++;
      } else {
        numberHigh++;
      }
    }
  }
  cout << "Antall under 10: " << numberLow << endl;
  cout << "Antall mellom 10 og 20: " << numberMedium << endl;
  cout << "Antall over 20: " << numberHigh << endl;
}
