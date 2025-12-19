// Copyright 2025 <Sparta>
#pragma once
#include <iostream>
#include "Vector.h"

template <typename T>
class Vector {
 public:
    Vector<T>();
    Vector<T>(int size, std::initializer_list<T> list);

    ~Vector();

    void push_back(T value);
    void pop_back();
    const int& getCapcity() const;
    const int& getSize() const;

    T* begin();
    T* end();
    T& operator[](int index);
 private:
    void resizeDatas();

 private:
    T* datas;
    int capacity;  // 최대로 가질 수 있는 값이 수
    int size;  // 현재 가진 값의 수
};

template <typename T>
Vector<T>::Vector() : datas(nullptr), capacity(0), size(0) {
}

template<typename T>
Vector<T>::Vector(int initCapacity,
    std::initializer_list<T> list) : capacity(initCapacity), size(0) {
    datas = new T[initCapacity];

    for (auto& data : list) {
        datas[size++] = data;
    }
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
    if (index >= size) {
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
        T* temp = new T[capacity / 2];

        for (int i = 0; i < size; i++) {
            temp[i] = datas[i];
        }

        delete[] datas;
        datas = nullptr;

        datas = temp;
        capacity >>= 1;
    }
}
