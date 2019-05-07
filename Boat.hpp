//
// Created by jostoph on 5/7/19.
//

#ifndef POO2_RIVER_BOAT_HPP
#define POO2_RIVER_BOAT_HPP

#include "Container.hpp"
#include "Bank.hpp"

class Boat : public Container {
private:
    Bank* currentBank;
public:
    Boat(Bank* currentBank);

    bool add(Person* person) override;

    Bank* getBank() const; // const ??

    void move(Bank* bank);
};


#endif //POO2_RIVER_BOAT_HPP
