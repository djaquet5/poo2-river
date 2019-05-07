//
// Created by jostoph on 5/7/19.
//

#ifndef POO2_RIVER_PERSON_HPP
#define POO2_RIVER_PERSON_HPP

#include <string>

class Person {
private:
    const std::string name; // const ?

public:
    Person(std::string& name); // ref or value ?

    const std::string& getName() const; // const string ?

    virtual bool canDrive() const = 0;

};


#endif //POO2_RIVER_PERSON_HPP
