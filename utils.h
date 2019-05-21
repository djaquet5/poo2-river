//
// Created by David on 21.05.2019.
//

#pragma once

#include <iostream>

void displayLine(char c, size_t nb) {
    for(size_t i = 0; i < nb; i++) {
        std::cout << c;
    }

    std::cout << std::endl;
}
