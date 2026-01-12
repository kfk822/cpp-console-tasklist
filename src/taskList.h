#pragma once
#include "IO.h"
#include "fileHandler.h"
#include "taskStruct.h"
#include "filter.h"
#include "sort.h"
#include <vector>
#include <string>

class TASKLIST
{
private:
    bool taskListShouldRun = true;
    IO *io;
    FILEHANDLER *filehandler;
    FILTER *filter;
    SORT *sort;

    std::vector<struct Task> tasks;
    std::vector<struct Task> filteredTasks;

    int noValidation = 0;
    int validateInt = 1;
    int validatePrio = 2;
    int validateFilter = 3;
    int validateSort = 4;

    int filterNumber = 8;
    int sortNumber = 3;
    int ASC = 0;
    int DESC = 1;

    void HandleList();
    void HandleAdd();
    void HandleRemove();
    void HandleMark();
    void HandleHelp();
    void HandlePrio();
    void HandleFilter();
    void HandleSort();
    void HandleQuit();
    void HandleInvalidInput();

    void DisplayTasks();
    std::string GetValidInput(int option);
    bool ValidateInt(std::string num, int size);
    void SetPrio(int taskNum);
    void SetFilter(int filterNumber);
    void SetSort(int sortNumber);
    void Save();
    void Load();

public:
    TASKLIST();
    ~TASKLIST();

    void Run();
};