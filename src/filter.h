#pragma once
#include "taskStruct.h"
#include <vector>

class FILTER
{
private:
public:
    FILTER();
    ~FILTER();

    std::vector<struct Task> FilterByMark(std::vector<struct Task> tasks, bool marked);
    std::vector<struct Task> FilterByPriority(std::vector<struct Task> tasks, int prioLevel);
};