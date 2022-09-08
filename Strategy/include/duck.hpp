//
// Created by Zosia on 08.09.2022.
//

#ifndef STRATEGY_DUCK_HPP
#define STRATEGY_DUCK_HPP

class IFlyBehaviour {
public:
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

class Duck {
public:

    Duck(IFlyBehaviour fb, IQuackBehaviour qb, IDisplayBehaviour db) : fb_(fb), qb_(qb), db_(db) {}

    bool fly() { fb_.fly(); }
    bool quack() { qb_.quack(); }
    bool display() { db_.display(); }

    ~Duck(){}

private:
    IFlyBehaviour fb_;
    IQuackBehaviour qb_;
    IDisplayBehaviour db_;
};



#endif //STRATEGY_DUCK_HPP
