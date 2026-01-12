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
    void ShowMarkedTask(std::string task, int taskNum, std::string Prio);
    void ShowUnMarkedTask(std::string task, int taskNum, std::string Prio);
    void AddTask();
    void WritePrio();
    void PrioOptions();
    void ShowOptions();
    void RemoveTask();
    void FilterOptions();
    void ShowHelp();
    void InvalidInput();
    void SaveUnsuccesful();
    void LoadSuccesful();
    void LoadUnsuccesful();
};