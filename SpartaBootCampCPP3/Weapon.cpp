// Copyright 2025 <Sparta>
#include <iostream>
#include <string>
#include "Weapon.h"

Weapon::Weapon() : ItemBase() {
    setName("Weapon");
}

Weapon::Weapon(std::string name_, int price_) : ItemBase(name_, price_) {
}

Weapon::~Weapon() {
}

void Weapon::PrintInfo() const {
    std::cout << "[무기] | ";
    ItemBase::PrintInfo();
}
