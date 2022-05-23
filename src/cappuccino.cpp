#include "cappuccino.h"
#include <iostream>
#include <numeric>
Cappuccino::Cappuccino()
{
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    name = "Cappuccino";
}

Cappuccino::Cappuccino(const Cappuccino& cap)
    : EspressoBased(cap)
{
    name = cap.get_name();
    for (const auto& v : cap.side_items) {
        std::string namesub { v->get_name() };
        auto unitsub { v->get_units() };
        if (namesub == "Cinnamon")
            side_items.push_back(new Cinnamon { unitsub });
        else if (namesub == "Chocolate")
            side_items.push_back(new Chocolate { unitsub });
        else if (namesub == "Sugar")
            side_items.push_back(new Sugar { unitsub });
        else if (namesub == "Espresso")
            side_items.push_back(new Espresso { unitsub });
        else if (namesub == "Milk")
            side_items.push_back(new Milk { unitsub });
        else if (namesub == "MilkFoam")
            side_items.push_back(new MilkFoam { unitsub });
        else // water
            side_items.push_back(new Water { unitsub });
    }
}

void Cappuccino::operator=(const Cappuccino& cap)
{
    if (this == &cap)
        return;

    for (const auto& i : side_items)
        delete i;
    side_items.clear();
    // no need for initilize name
    // no need for initilize ingredinets
    for (const auto& v : cap.side_items) {
        std::string nameside { v->get_name() };
        auto unitside { v->get_units() };
        if (nameside == "Cinnamon")
            side_items.push_back(new Cinnamon { unitside });
        else if (nameside == "Chocolate")
            side_items.push_back(new Chocolate { unitside });
        else if (nameside == "Sugar")
            side_items.push_back(new Sugar { unitside });
        else if (nameside == "Espresso")
            side_items.push_back(new Espresso { unitside });
        else if (nameside == "Milk")
            side_items.push_back(new Milk { unitside });
        else if (nameside == "MilkFoam")
            side_items.push_back(new MilkFoam { unitside });
        else // water
            side_items.push_back(new Water { unitside });
    }
}

void Cappuccino::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

double Cappuccino::price() const
{
    double sum {};
    for (auto& v : ingredients) {
        sum += v->price();
        // std::cout << v->get_name() << std::endl;
    }
    for (auto& v : side_items) {
        sum += v->price();
        // std::cout << v->get_name() << std::endl;
    }
    return sum;
}

Cappuccino::~Cappuccino()
{
    for (const auto& i : side_items)
        delete i;
    side_items.clear();
    // std::cout <<"adas"<<std::endl;
}