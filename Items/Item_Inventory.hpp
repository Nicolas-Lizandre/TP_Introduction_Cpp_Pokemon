//
// Created by nicol on 23/09/2026.
//

#ifndef ITEM_INVENTORY_HPP
#define ITEM_INVENTORY_HPP
#include <vector>

#include "Item.hpp"

class Item_Inventory { //Propriété d'une PartyPokemon
    private :
    std::vector<Item*> items_types;
    std::vector<int> respective_items_quantity;

    public:
    //Constructeur
    Item_Inventory()= default;
    Item_Inventory(std::vector<Item*> items_types, std::vector<int> respective_items_quantity);
    ~Item_Inventory()=default;

    //Méthodes
    [[nodiscard]] bool isNameInItems_Types(std::string name) const;
    [[nodiscard]] bool isItemAvailable(std::string name) const;
    void setRespectiveItemsQuantity(std::string name, int quantity);
    void displayInventory() const;

    //Fts internes
    void decreaseRespectiveQuantityOfOne(std::string name);
    Item * getItemWithName(std::string name);


};
#endif //ITEM_INVENTORY_HPP
