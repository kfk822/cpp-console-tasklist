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
    void ShowMarkedTask(std::string task);
    void ShowUnMarkedTask(std::string task);
    void Numbering(int i);
    void AddTask();
    void MarkTask();
    void ShowOptions();
    void ShowHelp();
    void InvalidInput();
};