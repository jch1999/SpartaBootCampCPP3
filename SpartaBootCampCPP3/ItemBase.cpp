// Copyright 2025 <Sparta>
#include <iostream>
#include <string>
#include "ItemBase.h"


ItemBase::ItemBase() : name_(""), price_(0) {
}

ItemBase::ItemBase(std::string name, int price)
    : name_(name), price_(price) {
}

ItemBase::~ItemBase() {
}

void ItemBase::PrintInfo() const {
    std::cout << "[이름: " << name_
        << ", 가격: " << price_ << "G]" << std::endl;
}

void ItemBase::setName(std::string newName) {
    this->name_ = newName;
}

std::string ItemBase::getName() {
    return name_;
}

void ItemBase::setPrice(int newPrice) {
    this->price_ = newPrice;
}

int ItemBase::getPrice() {
    return price_;
}
