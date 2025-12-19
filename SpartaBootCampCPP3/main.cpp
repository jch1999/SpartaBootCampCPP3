// Copyright 2025 <Sparta>
#include <iostream>
#include "Inventory.h"
#include "Weapon.h"

int main() {
    Inventory<Weapon> weaponInventory;

    // 처음 생성되었으 때의 상태
    std::cout << "WeaonInventory | capcity : " << weaponInventory.GetCapcity()
        << ", size : " << weaponInventory.GetSize() << "\n";

    weaponInventory.AddItem(Weapon("Sword", 10));
    weaponInventory.AddItem(Weapon("Shield", 15));
    weaponInventory.AddItem(Weapon("Spear", 8));

    weaponInventory.PrintAllItems();

    for (int i = 0; i <= 7; i++) {
        weaponInventory.AddItem(Weapon("Sword", 10));
    }

    for (int i = 0; i < 5; i++) {
        weaponInventory.RemoveLastItem();
    }
    weaponInventory.PrintAllItems();

    for (int i = 0; i < 5; i++) {
        weaponInventory.RemoveLastItem();
    }
    return 0;
}
