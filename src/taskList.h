#pragma once
#include <vector>
#include <string>

class TASKLIST
{
private:
    bool taskListShouldRun = true;
    std::vector<std::string> tasks;

public:
    TASKLIST();
    ~TASKLIST();

    void Run();
};