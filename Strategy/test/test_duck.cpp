//
// Created by Zosia on 17.09.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "duck.hpp"


TEST(DuckTest, getTest) {

    SimpleFly simpleFly;
    LoudQuack loudQuack;
    TextDisplay textDisplay;

    Duck duck(std::make_unique<SimpleFly>(simpleFly), std::make_unique<LoudQuack>(loudQuack), std::make_unique<TextDisplay>(textDisplay));

    std::string s = duck.display();
    EXPECT_EQ(s, "TextDisplay");

}