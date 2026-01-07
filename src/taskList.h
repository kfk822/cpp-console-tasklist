#pragma once
#include <vector>
#include <string>

class TASKLIST
{
private:
    bool taskListShouldRun = true;
    std::vector<std::string> tasks;
    std::vector<bool> marked;

public:
    TASKLIST();
    ~TASKLIST();

    void Run();
    bool ValidateInt(std::string num, int size);
};