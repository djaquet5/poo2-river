//
// Created by jostoph on 5/7/19.
//

#ifndef POO2_RIVER_PERSON_HPP
#define POO2_RIVER_PERSON_HPP

#include <string>

class Person {
private:
    std::string name;

public:
    Person(std::string name);

    std::string getName() const;

    virtual bool canDrive() const = 0;

};


#endif //POO2_RIVER_PERSON_HPP
