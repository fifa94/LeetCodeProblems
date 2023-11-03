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
    void printAllTasks(void);
    bool deleteTask(int index);
};

TaskManager::TaskManager()
{
    std::cout << "Vita te tvuj spravce ukolu" << std::endl;
}

TaskManager::~TaskManager()
{
    std::cout << "Task manager se vypina" << std::endl;
}

bool TaskManager::addNewTask(std::string task, std::string taskDescription)
{

    if ((task.empty()) || taskDescription.empty())
    {
        return 0;
    }

    Task newTask(task, taskDescription);

    this->TaskStorage.push_back(newTask);

    return 1;
}

void TaskManager::printAllTasks(void)
{
    if (!this->TaskStorage.empty())
    {
        int index = 0;
        for (auto i = this->TaskStorage.begin(); i != this->TaskStorage.end(); i++)
        {
            std::cout << "Index: " << index << " ukol: " << i->getTask() << " popis ukolu: " << i->getTaskDescription() << std::endl;
            index++;
        }
    }
    else
    {
        std::cout << "Ukolnicek je prazdny" << std::endl;
    }
}

bool TaskManager::deleteTask(int index)
{
    if ((index < this->TaskStorage.size()) && (!this->TaskStorage.empty()) && (index >= 0))
    {
        std::cout << "Smazan ukol " << this->TaskStorage[index].getTask() << std::endl;
        this->TaskStorage.erase(this->TaskStorage.begin() + index);
        return 1;
    }
    return 0;
}