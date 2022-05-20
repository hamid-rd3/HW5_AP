#include "cappuccino.h"
#include "espresso_based.h"
#include "ingredient.h"
#include "mocha.h"
#include "sub_ingredients.h"
// #include <QApplication>
// #include <QLabel>
// #include <QWidget>
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        // QApplication app(argc, argv);
        // QLabel hola("<center>Ejemplo Qt para Ubunlog</center>");
        // hola.setWindowTitle("Mi primer programa Qt");
        // hola.resize(600, 400);
        // hola.show();
        // return app.exec();

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