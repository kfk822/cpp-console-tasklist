#pragma once
#include "IO.h"
#include "fileHandler.h"
#include "taskStruct.h"
#include <vector>
#include <string>

class TASKLIST
{
private:
    bool taskListShouldRun = true;
    IO *io;
    FILEHANDLER *filehandler;

    std::vector<struct Task> tasks;

    int noValidation = 0;
    int validateInt = 1;
    int validePrio = 2;

    void HandleList();
    void HandleAdd();
    void HandleMark();
    void HandleHelp();
    void HandlePrio();
    void HandleQuit();
    void HandleInvalidInput();

    void DisplayTasks();
    std::string GetValidInput(int option);
    bool ValidateInt(std::string num, int size);
    void SetPrio(int taskNum);
    void Save();
    void Load();

public:
    TASKLIST();
    ~TASKLIST();

    void Run();
};