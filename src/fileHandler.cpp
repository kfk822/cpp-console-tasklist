#include "fileHandler.h"

FILEHANDLER::FILEHANDLER()
{
}
FILEHANDLER::~FILEHANDLER()
{
}

bool FILEHANDLER::SaveFile(std::vector<struct Task> tasks)
{
    taskOutput = std::ofstream("task.json", std::ios::out | std::ios::trunc);
    if (taskOutput.is_open())
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            std::string taskNumber = "Task" + std::to_string(i + 1);
            outputJSON[taskNumber] = {
                {"Task", tasks.at(i).taskName},
                {"Completed", tasks.at(i).marked},
                {"Priority", tasks.at(i).Prio},
                {"Priority Level", tasks.at(i).Priolevel}};
        }
        taskOutput << outputJSON.dump(4);
        taskOutput.close();
        return true;
    }
    else
    {
        return false;
    }
}

bool FILEHANDLER::LoadFile(std::vector<struct Task> &tasks)
{
    taskInput = std::ifstream("task.json");
    nlohmann::json taskList;
    if (taskInput.is_open())
    {
        taskInput >> taskList;

        for (auto &element : taskList.items())
        {
            tasks.push_back(
                {element.value()["Task"],
                 element.value()["Completed"],
                 element.value()["Priority"],
                 element.value()["Priority Level"]});
        }
        taskInput.close();

        return true;
    }
    else
    {
        return false;
    }
}
