//
// Created by Zosia on 24.09.2022.
//

#include "weather.hpp"
#include <algorithm>
#include <iostream>

void WeatherStation::add_display(IDisplay &iDisplay) {
    displays_.push_back(&iDisplay);
}

void WeatherStation::remove_display(IDisplay &iDisplay) {
    displays_.erase(std::find(displays_.cbegin(), displays_.cend(), &iDisplay));
}

void WeatherStation::notify() {
    for (auto d : displays_){
        d->update();
    }
}

int WeatherStation::get_temperature() const {
    return temperature_;
}

void WeatherStation::set_temperature(int t) {
    temperature_ = t;
}

std::vector<IDisplay *> WeatherStation::get_displays() const {
    return displays_;
}

int WeatherStation::size() const {
    return displays_.size();
}

PhoneDisplay::PhoneDisplay(WeatherStation &station) : station_(station) {}

void PhoneDisplay::update() {
    temperature_ = station_.get_temperature();
    std::cout << "Updated value = " << temperature_ << std::endl;
}

int PhoneDisplay::get_temperature() const {
    return temperature_;
}
