//
// Created by Zosia on 24.09.2022.
//

#ifndef OBSERVER_WEATHER_HPP
#define OBSERVER_WEATHER_HPP

#include <vector>


//observer interface
class IDisplay {
public:
    virtual void update() = 0;
};

//observable interface
class IWeatherStation {
public:
    virtual void add_display(IDisplay& iDisplay) = 0;
    virtual void remove_display(IDisplay& iDisplay) = 0;
    virtual void notify() = 0;
};

// concrete class of the observable
class WeatherStation : public IWeatherStation {
public:
    WeatherStation() = default;
    void add_display(IDisplay &iDisplay) override;
    void remove_display(IDisplay &iDisplay) override;
    void notify() override;
    int get_temperature() const;
    void set_temperature(int t);
    std::vector<IDisplay*> get_displays() const;
    int size() const;
    ~WeatherStation() = default;

private:
    int temperature_ = 0;
    std::vector<IDisplay*> displays_;
};

//concrete class of the observer
class PhoneDisplay : public IDisplay {
public:
    PhoneDisplay(WeatherStation &station);
    void update() override;
    int get_temperature() const;
    ~PhoneDisplay() = default;

private:
     WeatherStation& station_;
     int temperature_ = 0;
};

#endif //OBSERVER_WEATHER_HPP
