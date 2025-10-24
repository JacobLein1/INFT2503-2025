//
// Created by Jacob Lein on 14/10/2025.
//
#include "Set.hpp"
#include <iostream>
using namespace std;

void Set::add_unique(int value){
    if (std::find(data.begin(), data.end(), value) == data.end()){
        data.push_back(value);
    }
}
Set& Set::operator=(const Set& other) {
    if(this != &other ){
        data = other.data;
    }
    return *this;
}

Set Set::operator+(const Set& other) const {
    Set result = *this;
    for (int val : other.data) {
        result.add_unique(val);
    }
    return result;
}

Set Set::operator+(int value) const {
    Set result = *this;
    result.add_unique(value);
    return result;
}
Set& Set::operator+=(int value) {
    add_unique(value);
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Set& s) {
    os << "{";
    for (size_t i = 0; i < s.data.size(); ++i) {
        os << s.data[i];
        if (i + 1 < s.data.size())
            os << ", ";
    }
    os << "}";
    return os;
}

