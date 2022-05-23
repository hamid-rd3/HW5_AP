#include "espresso_based.h"
#include "sub_ingredients.h"

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
}

void EspressoBased::brew()
{
    using namespace ftxui;
    using namespace std::chrono_literals;

    std::string reset_position;
    for (float percentage = 0.0f; percentage <= 1.01f; percentage += 0.002f) {
        std::string coffeebrewd = std::to_string(int(percentage * 100)) + "%";
        std::shared_ptr<ftxui::Node> document {};
        std::string msg {};

        if (percentage < 0.2f) {
            if (name == "Cappuccino") {
                document = hbox({
                    text("brewing Cappuccino :") | color(Color::Blue) | bgcolor(Color::DeepPink3),
                    gauge(percentage) | flex,
                    text(" " + coffeebrewd),
                });
            } else { // Mocha
                document = hbox({
                    text("brewing Mocha :") | color(Color::Blue) | bgcolor(Color::White),
                    gauge(percentage) | flex,
                    text(" " + coffeebrewd),
                });
            }
        } else if (percentage < 0.45f) {
            document = hbox({
                text("adding Espresso :") | color(Color::RosyBrown) | bgcolor(Color::DarkOrange),
                gauge(percentage) | flex,
                text(" " + coffeebrewd),
            });
        } else if (percentage < 0.7f) {
            document = hbox({
                text("adding milk :") | color(Color::White) | bgcolor(Color::GrayDark),
                gauge(percentage) | flex,
                text(" " + coffeebrewd),
            });
        } else if (percentage < 0.8f) {
            document = hbox({
                text("adding foam :") | color(Color::Red) | bgcolor(Color::Black),
                gauge(percentage) | flex,
                text(" " + coffeebrewd),
            });
        } else if (percentage < 0.9f && name == "Mocha") {
            document = hbox({
                text("adding Chocklate :") | color(Color::SandyBrown) | bgcolor(Color::White),
                gauge(percentage) | flex,
                text(" " + coffeebrewd),
            });
        } else if (percentage < 0.98f) {
            document = hbox({
                text("waiting ... :") | color(Color::Blue) | bgcolor(Color::Black),
                gauge(percentage) | flex,
                text(" " + coffeebrewd),
            });
        } else {
            document = hbox({
                text("Ready to drink ! :") | color(Color::DarkSeaGreen) | bgcolor(Color::Black),
                gauge(percentage) | flex,
                text(" " + coffeebrewd),
            });
        }
        auto screen = Screen(100, 1);
        Render(screen, document);
        std::cout << reset_position;
        screen.Print();
        reset_position = screen.ResetPosition();
        if (name == "Cappuccino")
            std::this_thread::sleep_for(0.035s);
        else
            std::this_thread::sleep_for(0.05s);
    }
    std::cout << std::endl;
}