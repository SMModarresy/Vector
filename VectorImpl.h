//
// Created by XamarinDev on 01/03/2023.
//

#ifndef VECTOR_VECTORIMPL_H
#define VECTOR_VECTORIMPL_H

#include "Vector.h"

template<typename T>
Vector<T>::Vector() : real_size(0), array_size(0), items(new T[0]) {}

template<typename T>
Vector<T>::Vector(const size_t sz) : real_size(sz), array_size(sz), items(new T[sz]) {}

template<typename T>
Vector<T>::Vector(const size_t sz, const T& default_value) : real_size(sz), array_size(sz), items(new T[sz]) {
    fill(items, items + real_size, default_value);
}

template<typename T>
Vector<T>::Vector(const Vector& v) : real_size(v.real_size), array_size(v.array_size) {
    items = new T[array_size];
    copy(v.items, v.items + real_size, items);
}

template<typename T>
Vector<T>::Vector(Vector&& v) : real_size(v.real_size), array_size(v.array_size), items(v.items) {
    v.real_size = 0;
    v.array_size = 0;
    v.items = new T[0];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    real_size = v.real_size;
    array_size = v.array_size;
    items = new T[array_size];
    copy(v.items, v.items + real_size, items);
    return *this;
}

template<typename T>
void Vector<T>::push_back(const T item) {
    if (array_size <= real_size) {
        size_t new_array_size = max(array_size, (size_t)1) * 2;
        T* new_items = new T[new_array_size];
        copy(items, items + real_size, new_items);
        delete[] items;
        items = new_items;
        array_size = new_array_size;
    }
    items[real_size] = item;
    real_size++;
}

template<typename T>
void Vector<T>::pop_back() {
    if (real_size == 0) {
        return;
    }
    real_size--;
    if (real_size <= array_size / 2) {
        size_t new_array_size = array_size / 2;
        T* new_items = new T[new_array_size];
        copy(items, items + real_size, new_items);
        delete[] items;
        items = new_items;
        array_size = new_array_size;
    }
}

template<typename T>
void Vector<T>::resize(const size_t new_size) {
    if (new_size > (1 << 27)) {
        throw bad_alloc();
    }
    size_t new_array_size = max(array_size, (size_t)1);
    while (new_array_size < new_size) {
        new_array_size *= 2;
    }
    while (new_array_size / 2 >= new_size) {
        new_array_size /= 2;
    }
    T* new_items = new T[new_array_size];
    copy(items, items + min(real_size, new_size), new_items);
    delete[] items;
    items = new_items;
    array_size = new_array_size;
    real_size = new_size;
}

template<typename T>
void Vector<T>::resize(const size_t new_size, const T& default_value) {
    size_t old_size = real_size;
    resize(new_size);
    if (old_size < new_size) {
        fill(items + old_size, items + new_size, default_value);
    }
}

template<typename T>
T& Vector<T>::operator[](const uint i) {
    if (i >= real_size) {
        throw out_of_range("index");
    }
    return items[i];
}

template<typename T>
const T& Vector<T>::operator[](const uint i) const {
    if (i >= real_size) {
        throw out_of_range("index");
    }
    return items[i];
}

template<typename T>
size_t Vector<T>::size() const {
    return real_size;
}

#endif //VECTOR_VECTORIMPL_H
