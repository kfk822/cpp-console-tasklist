#include "IO.h"
#include <iostream>
#include <vector>
#include <string>

IO::IO()
{
}
IO::~IO()
{
}

std::string IO::Input()
{
    std::string input;
    std::cin >> input;
    return input;
}

void IO::NoTask()
{
    std::cout << "Task list is empty.\n";
}

void IO::ShowTasks(std::vector<std::string> tasks)
{
    std::cout << "Tasks:\n";
    for (int i = 0; i < tasks.size(); i++)
    {
        std::cout << tasks.at(i) << "\n";
    }
}

void IO::AddTask()
{
    std::cout << "Add task:\n";
}

void IO::ShowOptions()
{
    line();
    std::cout << "Commands (help | quit):\n";
}

void IO::ShowHelp()
{
    std::cout << "Availabe commands:\n";
    std::cout << "view\tView task list\n";
    std::cout << "add\tAdd new task\n";
}

void IO::InvalidInput()
{
    std::cout << "Invalid input!\n";
}

void IO::line()
{
    std::cout << "-----------------------\n";
}
