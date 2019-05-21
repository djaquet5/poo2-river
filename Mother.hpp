//
// Created by christoph on 21.05.19.
//

#pragma once

#include "Parent.hpp"
#include "Father.hpp"

class Mother : public Parent {
private:
    Father& husband;
public:
    Mother(const std::string& name, const std::list<Child*>& children, Father& husband);
};
