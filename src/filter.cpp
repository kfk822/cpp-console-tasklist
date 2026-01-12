#include "filter.h"

FILTER::FILTER()
{
}

FILTER::~FILTER()
{
}

std::vector<struct Task> FILTER::FilterByMark(std::vector<struct Task> tasks, bool marked)
{
    std::vector<struct Task> filteredTasks;

    for (auto task : tasks)
    {
        if (task.marked == marked)
        {
            filteredTasks.push_back(task);
        }
    }

    return filteredTasks;
}
std::vector<struct Task> FILTER::FilterByPriority(std::vector<struct Task> tasks, int prioLevel)
{
    std::vector<struct Task> filteredTasks;

    for (auto task : tasks)
    {
        if (task.Priolevel == prioLevel)
        {
            filteredTasks.push_back(task);
        }
    }

    return filteredTasks;
}