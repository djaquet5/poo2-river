//
// Created by jostoph on 5/7/19.
//

#ifndef POO2_RIVER_CONTAINER_HPP
#define POO2_RIVER_CONTAINER_HPP

#include <string>
#include <list>

#include "Person.hpp"


class Container {
private:
    std::string name;
    std::list<Person&> people;

public:
    Container(std::string name);

    virtual bool add(Person& person);

    bool remove(Person& person);

    bool contains(Person& person) const;

    std::string getName() const;
};


#endif //POO2_RIVER_CONTAINER_HPP
