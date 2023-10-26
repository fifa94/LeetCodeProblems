#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> data;
    int top;
    enum StackEnum {EMPTY = -1};
public:
    Stack();
    ~Stack();
    bool isEmpty (void){return this->top == EMPTY; }
    bool insertElement(T data);
    bool popElement(void);
    void printElements();
    int getNumberOfElements (void){return this->top + 1; }
};   

/* constructor */
template <typename T>
Stack<T>::Stack(){
    this->top = EMPTY;
}

/* destructor */
template <typename T>
Stack<T>::~Stack(){
    this->top = EMPTY;
}

template <typename T>
bool Stack<T>::insertElement(T data){
    this->data.push_back(data);
    this->top++;
    return 1;
}

template <typename T>
bool Stack<T>::popElement(void){
    this->data.pop_back();
    this->top--;
    return 1;
}

template <typename T>
void Stack<T>::printElements(void){
     for (int i = 0; i < data.size(); i++)
    {
        std::cout << "Index " << i << " value " << this->data[i] << std::endl;
    }
    std::cout << "Number of elements: " << getNumberOfElements() << std::endl;
}
