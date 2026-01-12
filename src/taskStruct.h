#pragma once
#include <string>

struct Task
{
    std::string taskName;
    bool marked;
    std::string Prio = "Optional";
    int Priolevel = 5;
};
