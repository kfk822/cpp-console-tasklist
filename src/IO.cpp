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
    std::getline(std::cin, input);
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

void IO::ShowMarkedTask(std::string task, int taskNum, std::string Prio)
{
    std::cout << taskNum + 1 << ".) [X] " << Prio << " " << task << "\n";
}

void IO::ShowUnMarkedTask(std::string task, int taskNum, std::string Prio)
{
    std::cout << taskNum + 1 << ".) [ ] " << Prio << " " << task << "\n";
}

void IO::AddTask()
{
    std::cout << "Add task:\n";
}

void IO::RemoveTask()
{
    std::cout << "Select task to remove:";
}

void IO::WritePrio()
{
    std::cout << "Choose task:\n";
}

void IO::PrioOptions()
{
    line();
    std::cout << "Priority level options:\n";
    std::cout << "1.) Urgent\n";
    std::cout << "2.) High\n";
    std::cout << "3.) Medium\n";
    std::cout << "4.) Low\n";
    std::cout << "5.) Optional\n";
}

void IO::ShowOptions()
{
    line();
    std::cout << "Commands (help | quit):\n";
}

void IO::FilterOptions()
{
    std::cout << "Filter Options:\n";
    std::cout << "1.) Show unmarked tasks\n";
    std::cout << "2.) Show marked tasks\n";
    std::cout << "3.) Show urgent tasks\n";
    std::cout << "4.) Show high priority tasks\n";
    std::cout << "5.) Show medium priority tasks\n";
    std::cout << "6.) Show low priority tasks\n";
    std::cout << "7.) Show optional tasks\n";
    std::cout << "8.) Show all tasks\n";
}

void IO::SortOptions()
{
    std::cout << "Sort oprions:\n";
    std::cout << "1.) Sort by name (ASC)\n";
    std::cout << "2.) Sort by name (DESC)\n";
    std::cout << "3.) Sort by mark (unfinished first) [default]\n";
    std::cout << "4.) Sort by mark (finished first)\n";
    std::cout << "5.) Sort by priority (urgent first)\n";
    std::cout << "6.) Sort by priority (optional first)\n";
}

void IO::ShowHelp()
{
    std::cout << "Availabe commands:\n";
    std::cout << "list\t(l)\tList tasks\n";
    std::cout << "add\t(a)\tAdd new task\n";
    std::cout << "mark\t(m)\tMark task as finished\n";
    std::cout << "prio\t(p)\tSet task priority\n";
    std::cout << "remove\t(r)\tRemove task";
    std::cout << "filter\t(f)\tFilter tasks";
    std::cout << "sort\t(s)\tSort tasks\n";
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

void IO::LoadSuccesful()
{
    std::cout << "Task from task.json succesfully loaded!\n";
}

void IO::LoadUnsuccesful()
{
    std::cout << "task.json not found!\n";
}

void IO::line()
{
    std::cout << "-----------------------\n";
}