//
// Created by Zosia on 08.09.2022.
//

#ifndef STRATEGY_DUCK_HPP
#define STRATEGY_DUCK_HPP

#include <cstdlib>
#include <memory>
#include <iostream>
#include <string>


// ---------- STRATEGIES (INTERFACES) ---------------------

class IFlyBehaviour {
public:
    virtual IFlyBehaviour* clone() const = 0; // method for "virtual copy constructor"
    virtual IFlyBehaviour* create() const = 0; // method for "virtual default constructor"
    virtual void fly() const = 0;
    virtual ~IFlyBehaviour() = default;
};

class IQuackBehaviour {
public:
    virtual IQuackBehaviour* clone() const = 0;
    virtual IQuackBehaviour* create() const = 0;
    virtual void quack() const = 0;
    virtual ~IQuackBehaviour() = default;
};

class IDisplayBehaviour {
public:
    virtual IDisplayBehaviour* clone() const = 0;
    virtual IDisplayBehaviour* create() const = 0;
    virtual std::string display() const = 0;
    virtual ~IDisplayBehaviour() = default;
};

// ------------- CONCRETE CLASSES ---------------

// IFlyBehaviour implementations ----------------

class SimpleFly : public IFlyBehaviour {
public:
    SimpleFly* clone() const override { return new SimpleFly(*this); }
    SimpleFly* create() const override { return new SimpleFly(); }
    void fly() const override { std::cout << "SimpleFly" << std::endl; }
    ~SimpleFly() override = default;
};

class JetFly : public IFlyBehaviour {
public:
    JetFly* clone() const override { return new JetFly(*this); }
    JetFly* create() const override { return new JetFly(); }
    void fly() const override { std::cout << "JetFly" << std::endl; }
    ~JetFly() override = default;
};

class NoFly : public IFlyBehaviour {
public:
    NoFly* clone() const override { return new NoFly(*this); }
    NoFly* create() const override { return new NoFly(); }
    void fly() const override { std::cout << "NoFly" << std::endl; }
    ~NoFly() override = default;
};

// IQuackBehaviour implementations ---------------

class LoudQuack : public IQuackBehaviour {
public:
    LoudQuack* clone() const override { return new LoudQuack(*this); }
    LoudQuack* create() const override { return new LoudQuack();}
    void quack() const override { std::cout << "LoudQuack" << std::endl; }
    ~LoudQuack() override = default;
};

class QuietQuack : public IQuackBehaviour {
public:
    QuietQuack* clone() const override { return new QuietQuack(*this); }
    QuietQuack* create() const override { return new QuietQuack();}
    void quack() const override { std::cout << "QuietQuack" << std::endl; }
    ~QuietQuack() override = default;
};

class NoQuack : public IQuackBehaviour {
public:
    NoQuack* clone() const override { return new NoQuack(*this); }
    NoQuack* create() const override { return new NoQuack();}
    void quack() const override { std::cout << "NoQuack" << std::endl; }
    ~NoQuack() override = default;
};

// IDisplayBehaviour implementations ---------------

class TextDisplay : public IDisplayBehaviour {
public:
    TextDisplay* clone() const override { return new TextDisplay(*this); }
    TextDisplay* create() const override { return new TextDisplay(); }
    std::string display() const override { return "TextDisplay"; }
    ~TextDisplay() override = default;
};

class GraphicDisplay : public IDisplayBehaviour {
public:
    GraphicDisplay* clone() const override { return new GraphicDisplay(*this); }
    GraphicDisplay* create() const override { return new GraphicDisplay(); }
    std::string display() const override { return "GraphicDisplay"; }
    ~GraphicDisplay() override = default;
};

class NoDisplay : public IDisplayBehaviour {
public:
    NoDisplay* clone() const override { return new NoDisplay(*this); }
    NoDisplay* create() const override { return new NoDisplay(); }
    std::string display() const override { return "NoDisplay"; }
    ~NoDisplay() override = default;
};

// ------------ CONTEXT CLASS -----------------

class Duck {
public:

    Duck();  // default constructor created with word "defualt" because compiler will not create
                    // default constructor by itself when class has at least one user-implemented constructor

    Duck(std::unique_ptr<IFlyBehaviour> fb, std::unique_ptr<IQuackBehaviour> qb, std::unique_ptr<IDisplayBehaviour> db);
    Duck(const Duck& duck);

    ~Duck() = default;

    // setters
    void set_fly(std::unique_ptr<IFlyBehaviour> fb) { fb_ = std::move(fb); }
    void set_quack(std::unique_ptr<IQuackBehaviour> qb) { qb_ = std::move(qb); }
    void set_display(std::unique_ptr<IDisplayBehaviour> db) { db_ = std::move(db); }

    //getters
    IFlyBehaviour* get_flyBehaviour() { return fb_->clone(); }
    IQuackBehaviour* get_quackBehaviour() { return qb_->clone(); }
    IDisplayBehaviour* get_displayBehaviour() { return db_->clone(); }

    void fly() { fb_->fly(); }
    void quack() { qb_->quack(); }
    std::string display() { db_->display(); }

private:
    std::unique_ptr<IFlyBehaviour> fb_;
    std::unique_ptr<IQuackBehaviour> qb_;
    std::unique_ptr<IDisplayBehaviour> db_;
};

#endif //STRATEGY_DUCK_HPP
