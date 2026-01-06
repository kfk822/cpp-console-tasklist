#include "taskList.h"
#include <iostream>

TASKLIST::TASKLIST()
{
}

TASKLIST::~TASKLIST()
{
}

void TASKLIST::Run()
{

    while (taskListShouldRun)
    {
        std::cout << "Task list is running." << std::endl;
        std::cout << "\nPress q to exit" << std::endl;
        char in;
        std::cin >> in;
        if (in == 'q')
            taskListShouldRun = false;
    }
}