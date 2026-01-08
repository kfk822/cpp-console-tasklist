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

void IO::ShowMarkedTask(std::string task)
{
    std::cout << "[X]" << task << "\n";
}

void IO::ShowUnMarkedTask(std::string task)
{
    std::cout << "[ ]" << task << "\n";
}

void IO::Numbering(int i)
{
    std::cout << i + 1 << ".)\t";
}

void IO::AddTask()
{
    std::cout << "Add task:\n";
}

void IO::MarkTask()
{
    std::cout << "Wich task do you want to mark or unmark?([ ] == unfinished, [X] == finished)\n";
}

void IO::ShowOptions()
{
    line();
    std::cout << "Commands (help | quit):\n";
}

void IO::ShowHelp()
{
    std::cout << "Availabe commands:\n";
    std::cout << "list (l)\tlist tasks\n";
    std::cout << "add (a)\tAdd new task\n";
    std::cout << "mark (m)\tMark task as finished\n";
    std::cout << "cancel (c)\tCancel current action\n";
}

void IO::InvalidInput()
{
    std::cout << "Invalid input!\n";
}

void IO::line()
{
    std::cout << "-----------------------\n";
}
