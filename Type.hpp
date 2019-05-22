//
// Created by christoph on 22.05.19.
//

#pragma once

class Type {
public:
    Type(const Type&) = delete;
    Type& operator = (const Type&) = delete;

    static const Type thief, son, girl, policeman, father, mother;

private:
    Type(const char *name) : name(name){};

    const char *name;
};

const Type Type::thief("Thief");
const Type Type::son("Son");
const Type Type::girl("Girl");
const Type Type::policeman("Policeman");
const Type Type::father("Father");
const Type Type::mother("Mother");