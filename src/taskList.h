#pragma once
#include <vector>
#include <string>

class TASKLIST
{
private:
    bool taskListShouldRun = true;
    std::vector<std::string> tasks;
    std::vector<bool> marked;
    int numOfTasks = 0;

public:
    TASKLIST();
    ~TASKLIST();

    void Run();
    bool ValidateInt(std::string num, int size);
};