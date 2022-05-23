#include "cappuccino.h"
#include "espresso_based.h"
#include "ingredient.h"
#include "mocha.h"
#include "sub_ingredients.h"
#include <chrono> // for operator""s, chrono_literals
#include <ftxui/dom/elements.hpp> // for text, gauge, operator|, flex, hbox, Element
#include <ftxui/screen/screen.hpp> // for Screen
#include <iostream> // for cout, endl, ostream
#include <string> // for allocator, operator+, char_traits, operator<<, string, to_string, basic_string
#include <thread> // for sleep_for

#include "ftxui/dom/node.hpp" // for Render
#include "ftxui/screen/color.hpp" // for ftxui

#include <gtest/gtest.h>
#include <iostream>
int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        using namespace ftxui;
        using namespace std::chrono_literals;

        std::string reset_position;
        for (float percentage = 0.0f; percentage <= 1.01f; percentage += 0.002f) {
            std::string coffeebrewd = std::to_string(int(percentage * 100)) + "%";
            std::shared_ptr<ftxui::Node> document {};
            std::string msg {};

            if (percentage < 0.3f) {
                document = hbox({
                    text("brewing Cappuccino :") | color(Color::Blue) | bgcolor(Color::White),
                    gauge(percentage) | flex,
                    text(" " + coffeebrewd),
                });
            } else if (percentage < 0.5f) {
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
            } else if (percentage < 0.9f) {
                document = hbox({
                    text("adding foam :") | color(Color::Red) | bgcolor(Color::Black),
                    gauge(percentage) | flex,
                    text(" " + coffeebrewd),
                });
            } else {
                document = hbox({
                    text("waiting ... :") | color(Color::Blue) | bgcolor(Color::Black),
                    gauge(percentage) | flex,
                    text(" " + coffeebrewd),
                });
            }
            auto screen = Screen(100, 1);
            Render(screen, document);
            std::cout << reset_position;
            screen.Print();
            reset_position = screen.ResetPosition();
            std::this_thread::sleep_for(0.02s);
        }
        std::cout << std::endl;

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}