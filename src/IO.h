#pragma once
#include <string>

class IO
{
public:
    IO();
    ~IO();

    std::string Input();
    void ShowTasks();
    void ShowOptions();
    void ShowHelp();
};