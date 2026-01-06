#pragma once

class TASKLIST
{
private:
    bool taskListShouldRun = true;

public:
    TASKLIST();
    ~TASKLIST();

    void Run();
};