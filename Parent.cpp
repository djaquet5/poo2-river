//
// Created by christoph on 21.05.19.
//

#include "Parent.hpp"

Parent::Parent(const std::string& name, const std::list<Child*>& children) : Driver(name), children(children) {}

const std::list<Child*>& Parent::getChildren() {
    return children;
}