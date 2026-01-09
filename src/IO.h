#pragma once
#include <string>
#include <vector>

class IO
{
private:
    void line();

public:
    IO();
    ~IO();

    std::string Input();
    void NoTask();
    void Task();
    void ShowMarkedTask(std::string task, int taskNum);
    void ShowUnMarkedTask(std::string task, int taskNum);
    void AddTask();
    void ShowOptions();
    void ShowHelp();
    void InvalidInput();
    void SaveUnsuccesful();
    void LoadSuccesful();
    void LoadUnsuccesful();
};