#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H
#include "ingredient.h"
#include "sub_ingredients.h"
class EspressoBased {
public:
    virtual std::string get_name() const = 0;
    virtual double price() const = 0;

    // void brew();
    std::vector<Ingredient*>& get_ingredients() { return ingredients; };

    virtual ~EspressoBased();

protected:
    // EspressoBased();
    // EspressoBased(const EspressoBased& esp);
    // void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;
};
#endif // ESPRESSO_BASED_H