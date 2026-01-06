#include "IO.h"
#include <iostream>
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

void IO::ShowTasks()
{
    std::cout << "\nTask1" << std::endl;
    std::cout << "Task2" << std::endl;
    std::cout << "Task3" << std::endl;
    std::cout << "Task4" << std::endl;
}

void IO::ShowOptions()
{
    std::cout << "\nCommands (help | quit):" << std::endl;
}

void IO::ShowHelp()
{
    std::cout << "\nAvailabe commands:" << std::endl;
    std::cout << "view\tView task list" << std::endl;
}
