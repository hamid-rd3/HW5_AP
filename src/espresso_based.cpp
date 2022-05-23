#include "espresso_based.h"
#include <iostream>

EspressoBased::EspressoBased(const EspressoBased& esp)
{
    for (const auto& v : esp.ingredients) {
        std::string namesub { v->get_name() };
        auto unitsub { v->get_units() };
        if (namesub == "Cinnamon")
            ingredients.push_back(new Cinnamon { unitsub });
        else if (namesub == "Chocolate")
            ingredients.push_back(new Chocolate { unitsub });
        else if (namesub == "Sugar")
            ingredients.push_back(new Sugar { unitsub });
        else if (namesub == "Espresso")
            ingredients.push_back(new Espresso { unitsub });
        else if (namesub == "Milk")
            ingredients.push_back(new Milk { unitsub });
        else if (namesub == "MilkFoam")
            ingredients.push_back(new MilkFoam { unitsub });
        else // water
            ingredients.push_back(new Water { unitsub });
    }
}



void EspressoBased::operator=(const EspressoBased& esp)
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
    for (const auto& v : esp.ingredients) {
        std::string namesub { v->get_name() };
        auto unitsub { v->get_units() };
        if (namesub == "Cinnamon")
            ingredients.push_back(new Cinnamon { unitsub });
        else if (namesub == "Chocolate")
            ingredients.push_back(new Chocolate { unitsub });
        else if (namesub == "Sugar")
            ingredients.push_back(new Sugar { unitsub });
        else if (namesub == "Espresso")
            ingredients.push_back(new Espresso { unitsub });
        else if (namesub == "Milk")
            ingredients.push_back(new Milk { unitsub });
        else if (namesub == "MilkFoam")
            ingredients.push_back(new MilkFoam { unitsub });
        else // water
            ingredients.push_back(new Water { unitsub });
    }
}
EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
    // std::cout <<"espressobase destructor called "<<std::endl;
}
