#include "sort.h"

SORT::SORT()
{
}

SORT::~SORT()
{
}

std::vector<struct Task> SORT::SortByMark(std::vector<struct Task> tasks, int order)
{
    if (order == 0)
    {
        std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
                  { return a.marked < b.marked; });
    }
    else
    {
        std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
                  { return a.marked > b.marked; });
    }
    return tasks;
}
std::vector<struct Task> SORT::SortByPriority(std::vector<struct Task> tasks, int order)
{
    if (order == 0)
    {
        std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
                  { return a.Priolevel < b.Priolevel; });
    }
    else
    {
        std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
                  { return a.Priolevel > b.Priolevel; });
    }
    return tasks;
}
std::vector<struct Task> SORT::SortByName(std::vector<struct Task> tasks, int order)
{
    if (order == 0)
    {
        std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
                  { return a.taskName < b.taskName; });
    }
    else
    {
        std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
                  { return a.taskName > b.taskName; });
    }
    return tasks;
}