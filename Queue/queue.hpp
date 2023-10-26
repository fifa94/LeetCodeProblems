#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Queue
{
private:
    std::vector<T> data;
    int cnt;
    enum QueueEnum {EMPTY = -1};
public:
    Queue();
    ~Queue();
    bool insertElement(T data);
    void printAllElements(void);
    bool popElement(void);
    int getNumberOfElements(void) { return this->cnt + 1; }
    bool isEmpty(void) { return this->cnt == EMPTY; }
};

/* constructor */
template <typename T>
Queue<T>::Queue()
{
    /* reset of counter */
    this->cnt = EMPTY;
}

/* destructor */
template <typename T>
Queue<T>::~Queue()
{
}

template <typename T>
bool Queue<T>::insertElement(T data)
{
    this->data.push_back(data);
    this->cnt++;
    return 1;
}

template <typename T>
void Queue<T>::printAllElements(void)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << "Index " << i << " value " << this->data[i] << std::endl;
    }
    std::cout << "Number of elements: " << getNumberOfElements() << std::endl;
}

template <typename T>
bool Queue<T>::popElement(void)
{
    this->data.erase(this->data.begin());
    this->cnt--;
    return 1;
}