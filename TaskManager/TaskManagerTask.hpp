#pragma once

#include <string>

class Task
{
private:
    std::string task;
    std::string taskDescription;
public:
    Task(std::string task, std::string taskDescription);
    ~Task();
    std::string getTask(void);
    bool updateTask(std::string newTask);
    bool updateTaskDescription(std::string newTaskDescription);
};

Task::Task(std::string task, std::string taskDescription): task{task}, taskDescription{taskDescription}
{
}

Task::~Task()
{
}

std::string Task::getTask(void)
{
    return this->task;
}

bool:: Task::updateTask(std::string newTask){
    this->task = newTask;
    return 1;
}

bool Task::updateTaskDescription(std::string newTaskDescription){
    this->taskDescription = newTaskDescription;
    return 1;
}



