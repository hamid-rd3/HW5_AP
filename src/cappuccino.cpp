#include "cappuccino.h"
Cappuccino::Cappuccino()
{
    ingredients.push_back(new Espresso { 2 });
    ingredients.push_back(new Milk { 2 });
    ingredients.push_back(new MilkFoam { 1 });
}