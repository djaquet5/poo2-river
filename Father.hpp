//
// Created by christoph on 21.05.19.
//

#pragma once

#include <list>

#include "Parent.hpp"
#include "Mother.hpp"

class Father : public Parent {
private:
    Mother& wife;
public:
    Father(const std::string& name, const std::list<Child*>& children, Mother& wife);

    const std::list<Child*>& getChildren();
};
