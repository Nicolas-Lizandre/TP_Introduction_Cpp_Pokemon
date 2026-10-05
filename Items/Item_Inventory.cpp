//
// Created by nicol on 23/09/2026.
//
#include "Item_Inventory.hpp"

#include <iostream>
#include <ostream>

Item_Inventory::Item_Inventory(std::vector<Item*> items_types, std::vector<int> respective_items_quantity)
: items_types(items_types), respective_items_quantity(respective_items_quantity) {
    std::cout << "Item_Inventory created" << std::endl;
}

//Méthodes
bool Item_Inventory::isNameInItems_Types(std::string name) const {//
    for(int i = 0; i < items_types.size(); i++) {
        if(items_types.at(i)->getName() == name) {
            return true;
        }
    }
    return false;
}


bool Item_Inventory::isItemAvailable(std::string name) const {
    for(int i = 0; i < items_types.size(); i++) {
        if(items_types.at(i)->getName() == name) {
            if(respective_items_quantity.at(i) > 0) {
                return true;
            }
            return false;
        }
    }
    return false;
}

void Item_Inventory::setRespectiveItemsQuantity(std::string name, int quantity) {
    for(int i = 0; i < items_types.size(); i++) {
        if(items_types.at(i)->getName() == name) {
            respective_items_quantity.at(i) = quantity;
        }
    }
}

void Item_Inventory::displayInventory() const {
    for(int i = 0; i < items_types.size(); i++) {
        std::cout << "Item type : " << items_types.at(i)->getName() << std::endl;
        std::cout << "Quantity : " << respective_items_quantity.at(i) << std::endl;
        std::cout << "Description : " << items_types.at(i)->getDescription() << std::endl;
    }

}


//Fts internes
void Item_Inventory::decreaseRespectiveQuantityOfOne(std::string name) {
    for(int i = 0; i < items_types.size(); i++) {
        if(items_types.at(i)->getName() == name) {
            respective_items_quantity.at(i) -= 1;
        }
    }
}

Item * Item_Inventory::getItemWithName(std::string name) {
    for(int i = 0; i < items_types.size(); i++) {
        if(items_types.at(i)->getName() == name) {
            return items_types.at(i);
        }
    }
    return nullptr; //Devrait ne jamais arriver
}