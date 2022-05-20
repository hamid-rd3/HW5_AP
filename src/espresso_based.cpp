#include "espresso_based.h"
#include<iostream>
EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
    // std::cout <<"espressobase destructor called "<<std::endl;
}
