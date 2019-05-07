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
    const std::string name;
    std::list<Person*> people;

public:
    Container(const std::string& name);

    virtual bool add(Person* person);

    void remove(Person* person);

    bool contains(Person* person) const;

    const std::string& getName() const;

    std::list<Person*>& getPeople();
};


#endif //POO2_RIVER_CONTAINER_HPP
