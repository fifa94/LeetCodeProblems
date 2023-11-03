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
    bool updateTask(std::string newTask);
    bool updateTaskDescription(std::string newTaskDescription);
    std::string getTask (void){return this->task;}
    std::string getTaskDescription (void){return this->taskDescription;}
};

Task::Task(std::string task, std::string taskDescription): task{task}, taskDescription{taskDescription}
{
}

Task::~Task()
{
}

bool:: Task::updateTask(std::string newTask){
    this->task = newTask;
    return 1;
}

bool Task::updateTaskDescription(std::string newTaskDescription){
    this->taskDescription = newTaskDescription;
    return 1;
}



