//
// Created by Jacob Lein on 16/10/2025.
//
#ifndef OVING8_EQUAL_H
#define OVING8_EQUAL_H
#include <cmath>

template <typename Type>
    bool equal(Type a, Type b) {
        return a == b;;
    }

    template<>
    bool equal<double>(double a, double b) {
        const double allowed_Margin = 0.00001;
        return std::fabs(a-b) < allowed_Margin;
    }

#endif //OVING8_EQUAL_H
