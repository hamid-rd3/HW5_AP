#include "cappuccino.h"
#include <numeric>
#include <iostream>
Cappuccino::Cappuccino()
{
    ingredients.push_back(new Espresso { 2 });
    ingredients.push_back(new Milk { 2 });
    ingredients.push_back(new MilkFoam { 1 });
}
void Cappuccino::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

double Cappuccino::price() const
{
    double sum {};
    for (auto v : ingredients) {
        sum += v->price();
    }
    for (auto v : side_items) {
        sum += v->price();
    }
    return sum;
}

Cappuccino::~Cappuccino()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
        // std::cout <<"adas"<<std::endl;

}