//
// Created by Jacob Lein on 14/10/2025.
//
#include <vector>
#pragma once


class Set{
    std::vector<int> data;
    void add_unique(int value);

public:
    Set() = default;

    Set operator+(const Set &other)const; // A+B -> left is set returns new set => member
    Set operator+(int value) const; // Both members because they have
    Set& operator+=(int value);     // left element as set and they have to know how to
    Set& operator=(const Set& other); // Has to be member as it changes the set
    friend std::ostream& operator<<(std::ostream& os, const Set& s); // Friend function because
    // the left operandum isnt Set, but it needs access to the data
};



