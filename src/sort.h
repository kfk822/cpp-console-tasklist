#pragma once
#include "taskStruct.h"
#include <vector>
#include <algorithm>

class SORT
{
private:
public:
    SORT();
    ~SORT();

    std::vector<struct Task> SortByMark(std::vector<struct Task> tasks, int order);
    std::vector<struct Task> SortByPriority(std::vector<struct Task> tasks, int order);
    std::vector<struct Task> SortByName(std::vector<struct Task> tasks, int order);
};