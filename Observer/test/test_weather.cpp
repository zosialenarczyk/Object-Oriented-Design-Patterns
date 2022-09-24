//
// Created by Zosia on 24.09.2022.
//

#include "gtest/gtest.h"
#include "weather.hpp"

TEST(weatherTests, addDisplayTest){

    WeatherStation station;
    PhoneDisplay phoneA(station);
    PhoneDisplay phoneB(station);
    PhoneDisplay phoneC(station);

    station.add_display(phoneA);
    station.add_display(phoneB);
    station.add_display(phoneC);

    EXPECT_EQ(3, station.size());
}

TEST(weatherTests, removeDisplayTest){

    WeatherStation station;
    PhoneDisplay phoneA(station);
    PhoneDisplay phoneB(station);
    PhoneDisplay phoneC(station);

    station.add_display(phoneA);
    station.add_display(phoneB);
    station.add_display(phoneC);

    station.remove_display(phoneB);

    EXPECT_EQ(2, station.size());
}

TEST(weatherTests, notifyTest){

    WeatherStation station;
    PhoneDisplay phoneA(station);

    station.add_display(phoneA);

    int temp = 10;

    station.set_temperature(temp);
    station.notify();

    EXPECT_EQ(temp, phoneA.get_temperature());
}