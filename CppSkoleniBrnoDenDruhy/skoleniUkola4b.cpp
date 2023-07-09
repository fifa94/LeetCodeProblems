#include <vector>
#include <iostream>

template <typename T>
class Stack
{
private:
    std::vector<T> stack;

public:
 
    Stack() {}
    ~Stack() {}
    void pop();
    void push(T value);
    T top () {return this->stack.back();}
};

template <typename T>
void Stack<T>::push(T value)
{
    std::cout << value << std::endl;
    this->stack.push_back(value);
}

template<typename T>
void Stack<T>::pop()
{
    std::cout << "poped value " << this->stack.back() << std::endl;
    this->stack.pop_back();
}



int main()
{
    Stack<int> lifo;

    lifo.push(5);
    lifo.push(10);
    lifo.push(15);
    std::cout << "top " << lifo.top() << std::endl;
    lifo.pop();
    lifo.pop();
    lifo.pop();

    return 0;
}