// Copyright 2025 <Sparta>
#pragma once
#include <iostream>
#include "Vector.h"


template <typename T>
Vector<T>::Vector() : datas(nullptr), capacity(0), size(0) {
}

template<typename T>
Vector<T>::Vector(int initCapacity) : capacity(initCapacity), size(0) {
    datas = new T[initCapacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] datas;  // 메모리 해제
}

template <typename T>
void Vector<T>::push_back(T value) {
    resizeDatas();
    datas[size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size == 0) throw std::underflow_error("Vector size is zero.");

    resizeDatas();
    size--;
}

template <typename T>
const int& Vector<T>::getCapcity() const {
    return capacity;
}

template <typename T>
const int& Vector<T>::getSize() const {
    return size;
}

template <typename T>
T* Vector<T>::begin() {
    return datas;
}

template <typename T>
T* Vector<T>::end() {
    return datas + size;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index >= capacity) {
        throw std::out_of_range("index over Vector size!");
    } else if (index < 0) {
        throw std::underflow_error("index below zero!");
    }

    return datas[index];
}

template <typename T>
void Vector<T>::resizeDatas() {
    if (size == capacity) {  // datas가 꽉차면 2배 영역 배정
        if (capacity == 0) capacity = 1;

        T* temp = new T[capacity * 2];

        for (int i = 0; i < size; i++) {
            temp[i] = datas[i];
        }

        if (datas != nullptr) delete[] datas;

        datas = temp;
        capacity <<= 1;
    } else if (size < capacity / 2 && size != 0) {
        T* temp = new T[size / 2];

        for (int i = 0; i < capacity; i++) {
            temp[i] = datas[i];
        }

        delete[] datas;

        datas = temp;
        capacity >>= 1;
    }
}
