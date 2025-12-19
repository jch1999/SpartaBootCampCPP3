// Copyright 2025 <Sparta>
#pragma once

#include <string>

class ItemBase {
 public:
     ItemBase();
     explicit ItemBase(std::string name, int price);
     virtual ~ItemBase();

     virtual void PrintInfo() const;

     void SetName(std::string newName);
     std::string GetName() const;

     void SetPrice(int newPrice);
     int GetPrice() const;


 private:
    std::string name_;
    int price_;
};
