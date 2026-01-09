#pragma once
#include "taskStruct.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann\json.hpp>

class FILEHANDLER
{
private:
    std::ifstream taskInput;
    std::ofstream taskOutput;
    nlohmann::json outputJSON;
    std::vector<struct Task> inputTasks;

public:
    FILEHANDLER();
    ~FILEHANDLER();

    bool SaveFile(std::vector<struct Task> tasks);
    void LoadFile(std::vector<struct Task> &tasks);
};
