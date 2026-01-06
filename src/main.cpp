#include "taskList.h"

int main()
{

    TASKLIST *taskList = new TASKLIST();

    taskList->Run();
    delete taskList;

    return 0;
}