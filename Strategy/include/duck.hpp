//
// Created by Zosia on 08.09.2022.
//

#ifndef STRATEGY_DUCK_HPP
#define STRATEGY_DUCK_HPP

#include <cstdlib>
#include <memory>


// ---------- STRATEGIES (INTERFACES) ---------------------

class IFlyBehaviour {
public:
    IFlyBehaviour() = default;
    virtual bool fly() const = 0;
};

class IQuackBehaviour {
public:
    virtual bool quack() const = 0;
};

class IDisplayBehaviour {
public:
    virtual bool display() const = 0;
};

// ------------- CONCRETE CLASSES ---------------

// IFlyBehaviour implementations ----------------

class SimpleFly : public IFlyBehaviour {
public:
    bool fly() const override { return true; }
};

class JetFly : public IFlyBehaviour {
public:
    bool fly() const override { return true; }
};

class NoFly : public IFlyBehaviour {
public:
    bool fly() const override { return false; }
};

// IQuackBehaviour implementations ---------------

class LoudQuack : public IQuackBehaviour {
public:
    bool quack() const override { return true; }
};

class QuietQuack : public IQuackBehaviour {
public:
    bool quack() const override { return true; }
};

class NoQuack : public IQuackBehaviour {
public:
    bool quack() const override { return false; }
};

// IDisplayBehaviour implementations ---------------

class TextDisplay : public IDisplayBehaviour {
public:
    bool display() const override { return true; }
};

class GraphicDisplay : public IDisplayBehaviour {
public:
    bool display() const override { return true; }
};

class NoDisplay : public IDisplayBehaviour {
public:
    bool display() const override { return false; }
};

// ------------ CONTEXT CLASS -----------------

class Duck {
public:

    Duck(IFlyBehaviour fb, IQuackBehaviour qb, IDisplayBehaviour db){}
//    : fb_(std::move(fb), qb_(std::move(qb), db_(std::move(db))) ){}

    bool fly() { fb_->fly(); }
    bool quack() { qb_->quack(); }
    bool display() { db_->display(); }

    ~Duck(){}

private:
    std::unique_ptr<IFlyBehaviour> fb_;
    std::unique_ptr<IQuackBehaviour> qb_;
    std::unique_ptr<IDisplayBehaviour> db_;
};



#endif //STRATEGY_DUCK_HPP
