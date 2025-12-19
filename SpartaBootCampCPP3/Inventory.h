// Copyright 2025 <Sparta>
#pragma once
#include <iostream>
#include <algorithm>
#include "ItemBase.h"

// 아이템 가격 비교 함수
bool compareItemByPrice(const ItemBase& a, const ItemBase& b) {
    return a.GetPrice() < b.GetPrice();
}

template <typename T>
class Inventory {
 public:
     Inventory<T>(int capacity = 10);
     Inventory(const Inventory<T>& other);
     ~Inventory();

     void Assign(const Inventory<T>& other);
     void AddItem(const T& item);
     void RemoveLastItem();

     void SortItems();

     int GetSize() const;
     int GetCapcity() const;

     void PrintAllItems() const;
     const T* GetItems() const;

     void Resize(int newCacpcity);
 private:
     T* pItems_;
     int capacity_;
     int size_;
};

// 일반 생성자
template <typename T>
Inventory<T>::Inventory(int capacity) : pItems_(nullptr),
capacity_(0), size_(0) {
    if (capacity < 0) capacity = 1;
    capacity_ = capacity;

    pItems_ = new T[capacity_];
}

// 대입 생성자
template<typename T>
inline Inventory<T>::Inventory(const Inventory<T>& other) {
    capacity_ = other.GetCapcity();
    size_ = other.GetSize();
    pItems_ = new T[capacity_];

    const T* otherItems = other.GetItems();
    for (int i = 0; i < capacity_; i++) {
        pItems_[i] = otherItems[i];
    }
}

// 소멸자
template <typename T>
Inventory<T>::~Inventory() {
    delete[] pItems_;
    pItems_ = nullptr;
}

// 대입 함수
template<typename T>
inline void Inventory<T>::Assign(const Inventory<T>& other) {
    capacity_ = other.GetCapcity();
    size_ = other.GetSize();
    Resize(capacity_);

    const T* otherItems = other.GetItems();
    for (int i = 0; i < size_; i++) {
        pItems_[i] = otherItems[i];
    }
}

// 아이템 추가
template <typename T>
void Inventory<T>::AddItem(const T& item) {
    if (size_ == capacity_) {
        // std::cout << "인벤토리가 꽉 찼습니다.\n";
        // return;
        capacity_ <<= 1;
        Resize(capacity_);
    }
    pItems_[size_++] = item;
}

// 아이템 제거
template <typename T>
void Inventory<T>::RemoveLastItem() {
    if (size_ == 0) {
        std::cout << "인벤토리가 비어있습니다.\n";
        return;
    }

    size_--;
}

// 아이템 가격 순 정렬
template<typename T>
inline void Inventory<T>::SortItems() {
    ItemBase* item = dynamic_cast<ItemBase*>(&pItems_[0]);
    if (item != nullptr) {
        std::sort(pItems_, pItems_ + size_, compareItemByPrice);
    }
}

// 인벤토리 사이즈 반환
template <typename T>
int Inventory<T>::GetSize() const {
    return size_;
}

// 인벤토리 최대 용량 반환
template <typename T>
int Inventory<T>::GetCapcity() const {
    return capacity_;
}

// 소지중인 아이템 정보 일괄 출력
template <typename T>
void Inventory<T>::PrintAllItems() const {
    if (size_ == 0) {
        std::cout << "인벤토리가 텅 비어있습니다.\n";
        return;
    }

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

// 아이템 목록 포인터 반환
template<typename T>
inline const T* Inventory<T>::GetItems() const {
    return pItems_;
}

// 아이템 목록 크기 변환
template<typename T>
inline void Inventory<T>::Resize(int newCacpcity) {
    capacity_ = newCacpcity;
    if (size_ > capacity_) {
        size_ = capacity_;
    }

    if (pItems_ == nullptr) {
        pItems_ = new T[capacity_];
        return;
    }

    T* temp = new T[capacity_];  // 변경할 메모리 생성
    for (int i = 0; i < size_; i++) {
        temp[i] = pItems_[i];  // 데이터 복사
    }

    delete[] pItems_;  // 기존 메모리 해제
    pItems_ = temp;  // 메모리 변경
    temp = nullptr;  // 임시 메모리 연결 끊기
}
