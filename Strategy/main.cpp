#include <iostream>
#include <vector>
#include "duck.hpp"

int main() {

    // create various duck behaviours (strategies)
    SimpleFly simpleFly;
    JetFly jetFly;
    NoFly noFly;

    LoudQuack loudQuack;
    QuietQuack quietQuack;
    NoQuack noQuack;

    TextDisplay textDisplay;
    GraphicDisplay graphicDisplay;
    NoDisplay noDisplay;

    // create ducks with different sets of behaviours
    Duck duck1(std::make_unique<SimpleFly>(simpleFly), std::make_unique<LoudQuack>(loudQuack), std::make_unique<TextDisplay>(textDisplay));
    Duck duck2(std::make_unique<JetFly>(jetFly), std::make_unique<LoudQuack>(loudQuack), std::make_unique<GraphicDisplay>(graphicDisplay));
    Duck duck3(std::make_unique<NoFly>(noFly), std::make_unique<NoQuack>(noQuack), std::make_unique<NoDisplay>(noDisplay));

    std::vector<Duck> ducks = {duck1, duck2, duck3}; //FIXME


    return 0;
}
