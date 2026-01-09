#include "taskList.h"
#include "IO.h"
#include <vector>
#include <string>

TASKLIST::TASKLIST()
{
    io = new IO();
}

TASKLIST::~TASKLIST()
{
    delete io;
}

void TASKLIST::Run()
{
    while (taskListShouldRun)
    {
        io->ShowOptions();
        std::string input = GetValidInput(noValidation);

        if (input == "list" || input == "l")
        {
            HandleList();
        }
        else if (input == "add" || input == "a")
        {
            HandleAdd();
        }
        else if (input == "mark" || input == "m")
        {
            HandleMark();
        }
        else if (input == "help" || input == "h")
        {
            HandleHelp();
        }
        else if (input == "quit" || input == "q")
        {
            HandleQuit();
        }
        else
        {
            HandleInvalidInput();
        }
    }
}

void TASKLIST::HandleList()
{
    if (tasks.empty())
    {
        io->NoTask();
    }
    else
    {
        DisplayTasks();
    }
}
void TASKLIST::HandleAdd()
{
    io->AddTask();
    std::string taskInput = GetValidInput(noValidation);
    if (!(taskInput == "cancel" || taskInput == "c"))
    {
        tasks.push_back({false, taskInput});
    }
}
void TASKLIST::HandleMark()
{
    if (tasks.empty())
    {
        io->NoTask();
    }
    else
    {
        DisplayTasks();
        std::string markNumber = GetValidInput(validateInt);
        if (!(markNumber == "cancel" || markNumber == "c"))
        {
            if (markNumber != "invalid")
            {
                int taskNumber = std::stoi(markNumber) - 1;
                tasks.at(taskNumber).marked = !tasks.at(taskNumber).marked;
            }
            else
            {
                io->InvalidInput();
            }
        }
    }
}
void TASKLIST::HandleHelp()
{
    io->ShowHelp();
}
void TASKLIST::HandleQuit()
{
    taskListShouldRun = false;
}
void TASKLIST::HandleInvalidInput()
{
    io->InvalidInput();
}

void TASKLIST::DisplayTasks()
{
    io->Task();
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks.at(i).marked == true)
        {
            io->ShowMarkedTask(tasks.at(i).taskName, i);
        }
        else
        {
            io->ShowUnMarkedTask(tasks.at(i).taskName, i);
        }
    }
}
std::string TASKLIST::GetValidInput(int option)
{
    switch (option)
    {
    case 1:
    {
        std::string input = io->Input();
        if (input == "cancel" || input == "c")
        {
            return input;
        }
        if (input == "0")
        {
            return "invalid";
        }
        for (int i = 0; i < input.length(); i++)
        {
            if (!(input.at(i) >= '0' && input.at(i) <= '9'))
            {
                return "invalid";
            }
        }
        if (std::stoi(input) <= tasks.size())
        {
            return input;
        }
        else
        {
            return "invalid";
        }
    }

    default:
    {
        return io->Input();
    }
    }
}