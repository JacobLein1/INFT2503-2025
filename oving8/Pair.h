//
// Created by Jacob Lein on 17/10/2025.
//

#ifndef OVING8_PAIR_H
#define OVING8_PAIR_H

template <typename Type1, typename Type2>
class Pair {
public:
    Type1 first;
    Type2 second;

    Pair(Type1 a, Type2 b) : first(a), second(b){}

    bool operator>(const Pair &other);
    Pair<Type1,Type2> operator+(const Pair<Type1,Type2> &other) const {
        return Pair<Type1, Type2>(first + other.first, second + other.second);
    }
};

template<typename Type1, typename Type2>
bool Pair<Type1, Type2>::operator>(const Pair &other) {
    if (first>second) return true;
    else return false;
}


#endif //OVING8_PAIR_H
