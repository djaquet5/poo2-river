

#include "utils.h"

#define LINE_LENGTH 60

std::string makeLine(char c) {
    std::string str = "";

    for(size_t i = 0; i < LINE_LENGTH; i++) {
        str += c;
    }

    return str;
}