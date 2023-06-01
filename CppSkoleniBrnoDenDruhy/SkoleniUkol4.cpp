#include <iostream>
#include <array>

template <typename T, int MAX = 10>
class Stack
{
private:
    T *storage;
    void increment_cnt(void) { cnt++; }
    void decrement_cnt(void) { cnt--; }

public:
    inline static int cnt = 0;
    Stack() { storage = new T[MAX]; }
    // Predavam data pomoci konstannti reference
    void push(const T& value);
    void pop();
    T top();
    ~Stack() { delete[] storage; }
};

template <typename T, int MAX>
void Stack<T, MAX>::push(const T& value)
{
    std::cout << value << std::endl;

    if (cnt < MAX)
    {
        this->storage[cnt] = value;
        increment_cnt();
    }
}

template <typename T, int MAX>
void Stack<T, MAX>::pop()
{
    if (cnt > 0)
    {
        std::cout << "deleted val: " << this->storage[cnt - 1] << std::endl;
        storage[cnt - 1] = 0;
        decrement_cnt();
    }
}

template <typename T, int MAX>
T Stack<T, MAX>::top()
{
    return this->storage[cnt - 1];
}
int main()
{
    Stack<int, 4> lifo;
    lifo.push(5);
    lifo.push(10);
    lifo.push(15);
    std::cout << "top " << lifo.top() << std::endl;
    lifo.pop();
    lifo.pop();
    lifo.pop();

    return 0;
}