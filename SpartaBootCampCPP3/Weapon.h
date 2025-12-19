// Copyright 2025 <Sparta>
#pragma once
#include <string>
#include "ItemBase.h"

class Weapon : public ItemBase {
 public:
     Weapon();
     explicit Weapon(std::string name_, int price_);
     ~Weapon();

     void PrintInfo() const override;
};
