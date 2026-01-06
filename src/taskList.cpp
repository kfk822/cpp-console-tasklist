#include "taskList.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <string>

TASKLIST::TASKLIST()
{
}

TASKLIST::~TASKLIST()
{
}

void TASKLIST::Run()
{
    IO *io = new IO();

    while (taskListShouldRun)
    {
        io->ShowOptions();
        std::string input = io->Input();

        if (input == "view" || input == "v")
        {
            if (tasks.empty())
            {
                io->NoTask();
            }
            else
            {
                io->ShowTasks(tasks);
            }
        }
        else if (input == "add" || input == "a")
        {
            io->AddTask();
            tasks.push_back(io->Input());
        }
        else if (input == "help" || input == "h")
        {
            io->ShowHelp();
        }
        else if (input == "quit" || input == "q")
        {
            taskListShouldRun = false;
        }
        else
        {
            io->InvalidInput();
        }
    }

    delete io;
}