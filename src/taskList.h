#pragma once
#include "io.h"
#include <vector>
#include <string>

class TASKLIST
{
private:
    bool taskListShouldRun = true;
    IO *io;

    struct Task
    {
        bool marked;
        std::string taskName;
    };
    std::vector<struct Task> tasks;

    int noValidation = 0;
    int validateInt = 1;

    void HandleList();
    void HandleAdd();
    void HandleMark();
    void HandleHelp();
    void HandleQuit();
    void HandleInvalidInput();

    void DisplayTasks();
    std::string GetValidInput(int option);
    bool ValidateInt(std::string num, int size);

public:
    TASKLIST();
    ~TASKLIST();

    void Run();
};