//
// Created by Zosia on 08.09.2022.
//

#include "duck.hpp"
#include <memory>

Duck::Duck(std::unique_ptr<IFlyBehaviour> fb, std::unique_ptr<IQuackBehaviour> qb, std::unique_ptr<IDisplayBehaviour> db)
: fb_(std::move(fb)), qb_(std::move(qb)), db_(std::move(db)) {}

// virtual copy constructor
Duck::Duck(const Duck &duck) :
fb_(duck.fb_ ? duck.fb_->clone() : nullptr), // if duck.fb_ exists then clone it, if not return nullptr?
qb_(duck.qb_ ? duck.qb_->clone() : nullptr),
db_(duck.db_ ? duck.db_->clone() : nullptr) {}

