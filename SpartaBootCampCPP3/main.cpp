// Copyright 2025 <Sparta>
#include <iostream>
#include "Inventory.h"
#include "Weapon.h"

int main() {
    // 생성
    Inventory<Weapon> weaponInventory(3);
    weaponInventory.AddItem(Weapon("StoneSpear", 3));
    weaponInventory.AddItem(Weapon("IronSpear", 5));
    weaponInventory.AddItem(Weapon("WoodenSpear", 1));
    // 출력
    weaponInventory.PrintAllItems();
    std::cout << "WeaponInventory capcity: " << weaponInventory.GetCapcity()
        << ", size: " << weaponInventory.GetSize() << "\n\n";

    // capacity up!
    weaponInventory.AddItem(Weapon("StoneHamer", 4));
    weaponInventory.AddItem(Weapon("IronHamer", 6));
    weaponInventory.AddItem(Weapon("woodenHamer", 2));
    // 출력
    weaponInventory.PrintAllItems();
    std::cout << "WeaponInventory capcity: " << weaponInventory.GetCapcity()
        << ", size: " << weaponInventory.GetSize() << "\n\n";

    // 정렬
    weaponInventory.SortItems();
    weaponInventory.PrintAllItems();
    std::cout << "WeaponInventory capcity: " << weaponInventory.GetCapcity()
        << ", size: " << weaponInventory.GetSize() << "\n\n";

    // 복사
    Inventory<Weapon> newWeaponInventory(weaponInventory);
    // 출력
    newWeaponInventory.PrintAllItems();
    std::cout << "WeaponInventory capcity: " << newWeaponInventory.GetCapcity()
        << ", size: " << newWeaponInventory.GetSize() << "\n\n";

    for (int i = 0; i < 7; i++) {
        newWeaponInventory.RemoveLastItem();
    }

    // 대입
    weaponInventory.Assign(newWeaponInventory);
    // 출력
    weaponInventory.PrintAllItems();
    std::cout << "WeaponInventory capcity: " << weaponInventory.GetCapcity()
        << ", size: " << weaponInventory.GetSize() << "\n\n";

    return 0;
}
