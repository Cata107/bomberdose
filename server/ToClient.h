#ifndef ToClient_h
#define ToClient_h
#include <iostream>
#include "../include/Macro.h"
struct ToClient
{
    std::string str;
    char plateau [ NB_CASE + 1];
    bool j1;
    uint16_t x1;
    uint16_t y1;
    bool j2;
    uint16_t x2;
    uint16_t y2;
    bool j3;
    uint16_t x3;
    uint16_t y3;
    bool j4;
    uint16_t x4;
    uint16_t y4;
};
#endif //ToClient_h
