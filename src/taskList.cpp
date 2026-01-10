#include "taskList.h"

TASKLIST::TASKLIST()
{
    io = new IO();
    filehandler = new FILEHANDLER();
}

TASKLIST::~TASKLIST()
{
    delete io;
    delete filehandler;
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
        tasks.push_back({taskInput, false});
        SetPrio(static_cast<int>(tasks.size() - 1));
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
            io->ShowMarkedTask(tasks.at(i).taskName, i, tasks.at(i).Prio);
        }
        else
        {
            io->ShowUnMarkedTask(tasks.at(i).taskName, i, tasks.at(i).Prio);
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
    case 2:
    {
        std::string input = io->Input();
        if (input == "cancel" || input == "c")
        {
            return input;
        }
        if (input.at(0) >= '1' && input.at(0) <= '5' && input.length() == 1)
        {
            return input;
        }
        else
        {
            return "invalid";
        }
        return input;
    }

    default:
    {
        return io->Input();
    }
    }
}
void TASKLIST::SetPrio(int taskNum)
{
    io->PrioOptions();
    std::string prioLevel = GetValidInput(validePrio);
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