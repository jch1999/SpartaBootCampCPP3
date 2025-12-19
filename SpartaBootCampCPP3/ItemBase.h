// Copyright 2025 <Sparta>
#pragma once

#include <string>

class ItemBase {
 public:
     ItemBase();
     explicit ItemBase(std::string name, int price);
     virtual ~ItemBase();

     virtual void PrintInfo() const;

     void setName(std::string newName);
     std::string getName();

     void setPrice(int newPrice);
     int getPrice();


 private:
    std::string name_;
    int price_;
};
