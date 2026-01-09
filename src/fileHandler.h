#pragma once
#include "taskList.h"
#include <vector>
#include <iostream>
#include <fstream>

class FILEHANDLER
{
private:
    std::fstream taskFile;

public:
    FILEHANDLER();
    ~FILEHANDLER();

    void SaveFile(std::vector<struct Task> tasks);
    std::vector<struct Task> LoadFile();
};
