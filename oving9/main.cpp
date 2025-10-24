#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    // Binærsøk. Funksjonen binary_search() sier om et element
    // er i en vektor, men ikke hvor. Bruker lower_bound()
    // (ev. upper_bound()) til å fortelle oss det.
    if (binary_search(v1.begin(), v1.end(), 17)) {
        cout << "17 fins i v1\n";
    } else
        cout << "17 fins ikke i v1\n";

    // Verdien 17 er i v1, men på hvilken indeks?
    auto pos = lower_bound(v1.begin(), v1.end(), 17);
    cout << "17 er på indeks " << (pos - v1.begin()) << endl;

    // 25 er ikke i v2. Lager en kopi av v2, skal sette inn 25 der.
    auto v3 = v2;
    pos = lower_bound(v3.begin(), v3.end(), 25);
    cout << "25 skal inn på posisjon " << (pos - v3.begin()) << endl;
    v3.insert(pos, 25);
    cout << "V3 er lik v2 med 25 satt inn: " << v3 << endl;

    // Includes
    if (includes(v1.begin(), v1.end(), v2.begin() + 1, v2.begin() + 3))
        cout << "Er med!\n";
    else
        cout << "Er ikke med!\n";

    // Fletting
    vector<int> result;
    result.resize(v1.size() + v2.size()); // eksakt riktig størrelse
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    cout << "V1 og V2 flettet: " << result << endl;

    // Fjerner dubletter i result
    auto end = unique(result.begin(), result.end());
    result.erase(end, result.end()); // reduserer størrelsen
    cout << "V1 og V2 flettet, uten dubletter: " << result << endl;

    // Mengdeoperasjoner
    result.resize(v1.size() + v2.size()); // minst stort nok
    end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    result.erase(end, result.end()); // reduserer størrelsen
    cout << "V1 union V2: " << result << endl;

    result.resize(v1.size() + v2.size()); // minst stort nok
    end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    result.erase(end, result.end());
    cout << "V1 snitt V2: " << result << endl;

    // OPPGAVE A - Skal finne første element som er større enn 15 i v1
    auto itFindIf = find_if(v1.begin(), v1.end(), [](int val) { return val > 15;});
    cout << "The first value larger than 15 is " << *itFindIf << '\n';

    // OPPGAVE B - Skal finne ut om intervallene er omtrent lik
    bool areEqualA = equal(v1.begin(), v1.begin()+5, v2.begin(), [](int a, int b){
        return abs(a-b)<=2;
    });

    bool areEqualB = equal(v1.begin(), v1.begin()+4, v2.begin(), [](int a, int b){
        return abs(a-b)<=2;
    });
    cout << "Are the first 5 values of v1 'equal' to v2? " << areEqualA << endl;
    cout << "Are the first 4 values of v1 'equal' to v2? " << areEqualB << endl;

    // OPPGAVE C - Erstatt alle oddetall i v1 med 100
    // Kan ikke erstatte elementer i samme man itererer gjennom, så må lage midlertidig lager
    std::vector<int> tmp(v1.size());

    replace_copy_if(v1.begin(), v1.end(), tmp.begin() , [](int val){ return val % 2 != 0; }, 100);
    // Bytter midlertidig med v1
    v1.swap(tmp);
    cout << "Resultat av oddetall bytte:" << endl;
    cout << v1 << endl;
}