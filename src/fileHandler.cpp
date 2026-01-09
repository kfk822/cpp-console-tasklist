#include "fileHandler.h"
#include "vector"
#include <iostream>
#include <fstream>

FILEHANDLER::FILEHANDLER()
{
    taskFile = std::fstream("task.json");
}
FILEHANDLER::~FILEHANDLER()
{
}

void FILEHANDLER::SaveFile(std::vector<struct Task> tasks)
{
}

std::vector<struct Task> FILEHANDLER::LoadFile()
{
}