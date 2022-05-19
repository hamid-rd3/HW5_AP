#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H
#include "ingredient.h"
#define DEFCLASS(nameofclass, price_unit)                              \
    class nameofclass : public Ingredient {                            \
    public:                                                            \
        nameofclass(size_t units)                                      \
            : Ingredient(price_unit, units)                            \
        {                                                              \
            this->name = #nameofclass;                                 \
        }                                                              \
        virtual std::string get_name() override { return this->name; } \
    };
DEFCLASS(Cinnamon, 5);
DEFCLASS(Chocolate, 5);
DEFCLASS(Sugar, 1);
DEFCLASS(Cookie, 10);
DEFCLASS(Espresso, 15);
DEFCLASS(Milk, 10);
DEFCLASS(MilkFoam, 5);
DEFCLASS(Water, 1);
#endif // SUB_INGREDIENTS_H