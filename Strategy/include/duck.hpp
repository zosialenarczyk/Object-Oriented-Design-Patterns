//
// Created by Zosia on 08.09.2022.
//

#ifndef STRATEGY_DUCK_HPP
#define STRATEGY_DUCK_HPP

#include <cstdlib>
#include <memory>
#include <iostream>


// ---------- STRATEGIES (INTERFACES) ---------------------

class IFlyBehaviour {
public:
    virtual void fly() const = 0;
};

class IQuackBehaviour {
public:
    virtual void quack() const = 0;
};

class IDisplayBehaviour {
public:
    virtual void display() const = 0;
};

// ------------- CONCRETE CLASSES ---------------

// IFlyBehaviour implementations ----------------

class SimpleFly : public IFlyBehaviour {
public:
    void fly() const override { std::cout << 'SimpleFly' << std::endl; }
};

class JetFly : public IFlyBehaviour {
public:
    void fly() const override { std::cout << 'JetFly' << std::endl; }
};

class NoFly : public IFlyBehaviour {
public:
    void fly() const override { std::cout << 'NoFly' << std::endl; }
};

// IQuackBehaviour implementations ---------------

class LoudQuack : public IQuackBehaviour {
public:
    void quack() const override { std::cout << 'LoudQuack' << std::endl; }
};

class QuietQuack : public IQuackBehaviour {
public:
    void quack() const override { std::cout << 'QuietQuack' << std::endl; }
};

class NoQuack : public IQuackBehaviour {
public:
    void quack() const override { std::cout << 'NoQuack' << std::endl; }
};

// IDisplayBehaviour implementations ---------------

class TextDisplay : public IDisplayBehaviour {
public:
    void display() const override { std::cout << 'TextDisplay' << std::endl; }
};

class GraphicDisplay : public IDisplayBehaviour {
public:
    void display() const override { std::cout << 'GRaphicDisplay' << std::endl; }
};

class NoDisplay : public IDisplayBehaviour {
public:
    void display() const override { std::cout << 'NoDisplay' << std::endl; }
};

// ------------ CONTEXT CLASS -----------------

class Duck {
public:

    Duck() = default; // default constructor created with word "defualt" because compiler
                    // will not create default constructor by itself when class has an user-implemented constructor
    Duck(std::unique_ptr<IFlyBehaviour> fb, std::unique_ptr<IQuackBehaviour> qb, std::unique_ptr<IDisplayBehaviour> db); // default constructor

    // setters
    void set_fly(std::unique_ptr<IFlyBehaviour> fb) { fb_ = std::move(fb); }
    void set_quack(std::unique_ptr<IQuackBehaviour> qb) { qb_ = std::move(qb); }
    void set_display(std::unique_ptr<IDisplayBehaviour> db) { db_ = std::move(db); }

    void fly() { fb_->fly(); }
    void quack() { qb_->quack(); }
    void display() { db_->display(); }

    ~Duck(){}

private:
    std::unique_ptr<IFlyBehaviour> fb_;
    std::unique_ptr<IQuackBehaviour> qb_;
    std::unique_ptr<IDisplayBehaviour> db_;
};



#endif //STRATEGY_DUCK_HPP
