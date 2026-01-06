#include "taskList.h"
#include "IO.h"
#include <iostream>

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
            io->ShowTasks();
        }
        else if (input == "help" || input == "h")
        {
            io->ShowHelp();
        }
        else if (input == "quit" || input == "q")
        {
            taskListShouldRun = false;
        }
    }

    delete io;
}