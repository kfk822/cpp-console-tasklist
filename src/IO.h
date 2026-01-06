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
    void ShowTasks(std::vector<std::string> tasks);
    void AddTask();
    void ShowOptions();
    void ShowHelp();
    void InvalidInput();
};