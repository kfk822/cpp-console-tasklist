#pragma once
#include "IO.h"
#include "fileHandler.h"
#include "taskStruct.h"
#include "filter.h"
#include <vector>
#include <string>

class TASKLIST
{
private:
    bool taskListShouldRun = true;
    IO *io;
    FILEHANDLER *filehandler;
    FILTER *filter;

    std::vector<struct Task> tasks;
    std::vector<struct Task> filteredTasks;

    int noValidation = 0;
    int validateInt = 1;
    int validatePrio = 2;
    int validateFilter = 3;

    int filterNumber = 8;

    void HandleList();
    void HandleAdd();
    void HandleRemove();
    void HandleMark();
    void HandleHelp();
    void HandlePrio();
    void HandleFilter();
    void HandleQuit();
    void HandleInvalidInput();

    void DisplayTasks();
    std::string GetValidInput(int option);
    bool ValidateInt(std::string num, int size);
    void SetPrio(int taskNum);
    void SetFilter(int filterNumber);
    void Save();
    void Load();

public:
    TASKLIST();
    ~TASKLIST();

    void Run();
};