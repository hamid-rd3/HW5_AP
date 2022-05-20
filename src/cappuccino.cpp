#include "cappuccino.h"
#include <numeric>
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