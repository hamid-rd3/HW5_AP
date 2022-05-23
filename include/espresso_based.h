#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H
#include "ingredient.h"
#include "sub_ingredients.h"
#include <chrono> // for operator""s, chrono_literals
#include <ftxui/dom/elements.hpp> // for text, gauge, operator|, flex, hbox, Element
#include <ftxui/screen/screen.hpp> // for Screen
#include <iostream>
#include <iostream> // for cout, endl, ostream
#include <string> // for allocator, operator+, char_traits, operator<<, string, to_string, basic_string
#include <thread> // for sleep_for

#include "ftxui/dom/node.hpp" // for Render
#include "ftxui/screen/color.hpp" // for ftxui

class EspressoBased {
public:
    virtual std::string get_name() const = 0;
    virtual double price() const = 0;

    void brew();
    std::vector<Ingredient*>& get_ingredients() { return ingredients; };

    virtual ~EspressoBased();

protected:
     EspressoBased()=default;
     EspressoBased(const EspressoBased& esp);
     void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name{};
};
#endif // ESPRESSO_BASED_H