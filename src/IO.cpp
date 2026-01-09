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

void IO::Task()
{
    std::cout << "Tasks([ ] == unfinished, [X] == finished):\n";
}

void IO::ShowMarkedTask(std::string task, int taskNum)
{
    std::cout << taskNum + 1 << ".) [X] " << task << "\n";
}

void IO::ShowUnMarkedTask(std::string task, int taskNum)
{
    std::cout << taskNum + 1 << ".) [ ] " << task << "\n";
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
    std::cout << "list\t(l)\tList tasks\n";
    std::cout << "add\t(a)\tAdd new task\n";
    std::cout << "mark\t(m)\tMark task as finished\n";
    std::cout << "cancel\t(c)\tCancel current action\n";
}

void IO::InvalidInput()
{
    std::cout << "Invalid input!\n";
}

void IO::SaveUnsuccesful()
{
    std::cout << "Failed to save file!!";
}

void IO::line()
{
    std::cout << "-----------------------\n";
}
