//
// Created by Zosia on 08.09.2022.
//

#include "duck.hpp"
#include <memory>

Duck::Duck(std::unique_ptr<IFlyBehaviour> fb, std::unique_ptr<IQuackBehaviour> qb, std::unique_ptr<IDisplayBehaviour> db) {
    fb_ = std::move(fb);
    qb_ = std::move(qb);
    db_ = std::move(db);
}