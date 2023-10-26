#include "queue.hpp"
#include "stack.hpp"

int main()
{
    Queue<int> queueObj;
    Stack<int> stackObj;

    if (queueObj.isEmpty())
    {
        queueObj.insertElement(1);
        queueObj.insertElement(2);
    }

    queueObj.popElement();
    queueObj.printAllElements();

    if (stackObj.isEmpty())
    {
        stackObj.insertElement(15);
        stackObj.insertElement(5);
        stackObj.insertElement(1);
    }
    
    stackObj.popElement();
    stackObj.printElements();

    return 0;
}