// Copyright 2025 <Sparta>
#pragma once
#include <iostream>
#include "ItemBase.h"

template <typename T>
class Inventory {
 public:
     Inventory<T>(int capacity = 10);
     ~Inventory();

     void AddItem(const T& item);
     void RemoveLastItem();

     int GetSize() const;
     int GetCapcity() const;

     void PrintAllItems() const;

 private:
     T* pItems_;
     int capacity_;
     int size_;
};

template <typename T>
Inventory<T>::Inventory(int capacity) : pItems_(nullptr),
capacity_(0), size_(0) {
    if (capacity < 0) capacity = 1;
    capacity_ = capacity;

    pItems_ = new T[capacity_];
}

template <typename T>
Inventory<T>::~Inventory() {
    delete[] pItems_;
    pItems_ = nullptr;
}

template <typename T>
void Inventory<T>::AddItem(const T& item) {
    if (size_ == capacity_) {
        std::cout << "인벤토리가 꽉 찼습니다.\n";
        return;
    }
    pItems_[size_++] = item;
}

template <typename T>
void Inventory<T>::RemoveLastItem() {
    if (size_ == 0) {
        std::cout << "인벤토리가 비어있습니다.\n";
        return;
    }

    size_--;
}

template <typename T>
int Inventory<T>::GetSize() const {
    return size_;
}

template <typename T>
int Inventory<T>::GetCapcity() const {
    return capacity_;
}

template <typename T>
void Inventory<T>::PrintAllItems() const {
    for (int i = 0; i < size_; i++) {
        try {
            ItemBase* item = dynamic_cast<ItemBase*>(&pItems_[i]);
            if (item != nullptr) {
                item->PrintInfo();
            }
        } catch(std::exception& e) {
            std::cout << "아이템 정보 출력 중 오류발생!\n";
        }
    }
}
