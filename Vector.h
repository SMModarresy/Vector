//
// Created by XamarinDev on 12/31/2022.
//
#include<algorithm>
#include<stdexcept>

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

using namespace std;

typedef unsigned int uint;

template<typename T>
class Vector {
public:
    Vector();
    Vector(const size_t sz);
    Vector(const size_t sz, const T& default_value);
    Vector(const Vector& v);
    Vector(Vector&& v);

    Vector<T>& operator=(const Vector<T>& v);
    void push_back(const T item);
    void pop_back();
    void resize(const size_t new_size);
    void resize(const size_t new_size, const T& default_value);
    T& operator[](const uint i);
    const T& operator[](const uint i) const;
    size_t size() const;
private:
    T* items;
    size_t array_size;
    size_t real_size;
};

#include "VectorImpl.h"

#endif //VECTOR_VECTOR_H
