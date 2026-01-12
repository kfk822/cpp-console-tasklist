#include "taskList.h"

TASKLIST::TASKLIST()
{
    io = new IO();
    filehandler = new FILEHANDLER();
    filter = new FILTER();
    filterNumber = 8;
}

TASKLIST::~TASKLIST()
{
    delete io;
    delete filehandler;
    delete filter;
}

void TASKLIST::Run()
{
    Load();
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
        else if (input == "remove" || input == "r")
        {
            HandleRemove();
        }
        else if (input == "mark" || input == "m")
        {
            HandleMark();
        }
        else if (input == "help" || input == "h")
        {
            HandleHelp();
        }
        else if (input == "prio" || input == "p")
        {
            HandlePrio();
        }
        else if (input == "filter" || input == "f")
        {
            HandleFilter();
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
    if (taskInput == "invalid")
    {
        io->InvalidInput();
    }
    else if (!(taskInput == "cancel" || taskInput == "c"))
    {
        tasks.push_back({taskInput, false});
        SetPrio(int(tasks.size() - 1));
        Save();
    }
}
void TASKLIST::HandleRemove()
{
    io->RemoveTask();
    DisplayTasks();
    std::string taskNum = GetValidInput(validateInt);
    if (!(taskNum == "cancel" || taskNum == "c"))
    {
        if (taskNum == "invalid")
        {
            io->InvalidInput();
        }
        else
        {
            tasks.erase(tasks.begin() + (std::stoi(taskNum) - 1));
            Save();
        }
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
                Save();
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
void TASKLIST::HandlePrio()
{
    if (tasks.empty())
    {
        io->NoTask();
    }
    else
    {
        io->WritePrio();
        DisplayTasks();
        std::string prioTask = GetValidInput(validateInt);
        if (!(prioTask == "cancel" || prioTask == "c"))
        {
            if (prioTask == "invalid")
            {
                io->InvalidInput();
            }
            else
            {
                SetPrio(std::stoi(prioTask) - 1);
            }
        }
    }
}
void TASKLIST::HandleFilter()
{
    io->FilterOptions();
    std::string input = GetValidInput(validateFilter);
    if (!(input == "cancel" || input == "c"))
    {
        if (input == "invalid")
        {
            io->InvalidInput();
        }
        else
        {
            filterNumber = std::stoi(input);
        }
    }
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
    SetFilter(filterNumber);
    for (int i = 0; i < filteredTasks.size(); i++)
    {
        if (filteredTasks.at(i).marked == true)
        {
            io->ShowMarkedTask(filteredTasks.at(i).taskName, i, filteredTasks.at(i).Prio);
        }
        else
        {
            io->ShowUnMarkedTask(filteredTasks.at(i).taskName, i, filteredTasks.at(i).Prio);
        }
    }
}
std::string TASKLIST::GetValidInput(int option)
{
    std::string input = io->Input();
    switch (option)
    {
    case 1:
    {

        if (input == "cancel" || input == "c")
        {
            return input;
        }
        else if (input == "0")
        {
            return "invalid";
        }
        else if (input.empty())
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
        if (std::stoi(input) <= filteredTasks.size())
        {
            return input;
        }
        else
        {
            return "invalid";
        }
    }
    case 2:
    {
        if (input == "cancel" || input == "c")
        {
            return input;
        }
        else if (input.empty())
        {
            return "invalid";
        }
        else if (input.at(0) >= '1' && input.at(0) <= '5' && input.length() == 1)
        {
            return input;
        }
        else
        {
            return "invalid";
        }
        return input;
    }
    case 3:
    {
        if (input == "cancel" || input == "c")
        {
            return input;
        }
        else if (input.empty())
        {
            return "invalid";
        }
        else if (input.at(0) >= '1' && input.at(0) <= '8' && input.length() == 1)
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
        if (input.empty())
        {
            return "invalid";
        }
        else
        {
            return input;
        }
    }
    }
}
void TASKLIST::SetPrio(int taskNum)
{
    io->PrioOptions();
    std::string prioLevel = GetValidInput(validatePrio);
    if (!(prioLevel == "c" || prioLevel == "cancel"))
    {
        if (prioLevel == "invalid")
        {
            io->InvalidInput();
        }
        else
        {

            switch (std::stoi(prioLevel))
            {
            case 1:
            {
                tasks.at(taskNum).Prio = "Urgent";
                tasks.at(taskNum).Priolevel = 1;
                break;
            }
            case 2:

            {
                tasks.at(taskNum).Prio = "High";
                tasks.at(taskNum).Priolevel = 2;
                break;
            }
            case 3:
            {
                tasks.at(taskNum).Prio = "Medium";
                tasks.at(taskNum).Priolevel = 3;
                break;
            }
            case 4:
            {
                tasks.at(taskNum).Prio = "Low";
                tasks.at(taskNum).Priolevel = 4;
                break;
            }
            case 5:
            {
                tasks.at(taskNum).Prio = "Optional";
                tasks.at(taskNum).Priolevel = 5;
                break;
            }
            default:
                break;
            }
        }
    }
}
void TASKLIST::SetFilter(int filterNumber)
{
    filteredTasks.clear();
    if (filterNumber <= 2)
    {
        for (auto element : tasks)
        {
            if (int(element.marked) == (filterNumber - 1))
            {
                filteredTasks.push_back(element);
            }
        }
    }
    else if (filterNumber <= 7)
    {
        for (auto element : tasks)
        {
            if (element.Priolevel == (filterNumber - 2))
            {
                filteredTasks.push_back(element);
            }
        }
    }
    else
    {
        filteredTasks = tasks;
    }
}
void TASKLIST::Save()
{
    if (!filehandler->SaveFile(tasks))
    {
        io->SaveUnsuccesful();
    }
}
void TASKLIST::Load()
{
    if (filehandler->LoadFile(tasks))
    {
        io->LoadSuccesful();
    }
    else
    {
        io->LoadUnsuccesful();
    }
}