#pragma once

#include <vector>
#include <vector>
#include <functional>
#include <iostream>

#include "TaskManagerTask.hpp"

class TaskManager
{
private:
    std::vector<Task> TaskStorage;
public:
    TaskManager();
    ~TaskManager();
    bool addNewTask(std::string task, std::string taskDescription);
};

TaskManager::TaskManager()
{
    std::cout << "Vita te tvuj spravde ukolu" << std::endl;
}

TaskManager::~TaskManager()
{
    std::cout << "Task manager se vypina" << std::endl;
}

bool TaskManager::addNewTask(std::string task, std::string taskDescription){
    
    if ((task.empty()) || taskDescription.empty())
    {
        return 0;
    }
    return 0;
}
