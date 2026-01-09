#include "fileHandler.h"

FILEHANDLER::FILEHANDLER()
{
}
FILEHANDLER::~FILEHANDLER()
{
}

bool FILEHANDLER::SaveFile(std::vector<struct Task> tasks)
{
    taskOutput = std::ofstream("task.json");
    if (taskOutput.is_open())
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            std::string taskNumber = "Task" + std::to_string(i + 1);
            outputJSON[taskNumber] = {
                {"Task", tasks.at(i).taskName},
                {"Completed", tasks.at(i).marked}};

            taskOutput << outputJSON.dump(4);
        }
        taskOutput.close();
        return true;
    }
    else
    {
        return false;
    }
}

void FILEHANDLER::LoadFile(std::vector<struct Task> &tasks)
{
}