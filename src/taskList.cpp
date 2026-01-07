#include "taskList.h"
#include "IO.h"
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
                io->Task();
                for (int i = 0; i < tasks.size(); i++)
                {
                    if (marked.at(i) == true)
                    {
                        io->ShowMarkedTask(tasks.at(i));
                    }
                    else
                    {
                        io->ShowUnMarkedTask(tasks.at(i));
                    }
                }
            }
        }
        else if (input == "add" || input == "a")
        {
            io->AddTask();
            tasks.push_back(io->Input());
            marked.push_back(false);
        }
        else if (input == "mark" || input == "m")
        {
            if (tasks.empty())
            {
                io->NoTask();
            }
            else
            {
                io->MarkTask();
                for (int i = 0; i < tasks.size(); i++)
                {
                    io->Numbering(i);
                    if (marked.at(i) == true)
                    {
                        io->ShowMarkedTask(tasks.at(i));
                    }
                    else
                    {
                        io->ShowUnMarkedTask(tasks.at(i));
                    }
                }
                std::string markNumber = io->Input();
                if (ValidateInt(markNumber, tasks.size()))
                {
                    marked.at(std::stoi(markNumber) - 1) = !marked.at(std::stoi(markNumber) - 1);
                }
                else
                {
                    io->InvalidInput();
                }
            }
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

bool TASKLIST::ValidateInt(std::string num, int size)
{
    for (int i = 0; i < num.length(); i++)
    {
        if (!(num.at(i) >= '1' && num.at(i) <= '9'))
        {
            return false;
        }
    }
    if (std::stoi(num) <= size)
    {

        return true;
    }
    else
    {
        return false;
    }
}