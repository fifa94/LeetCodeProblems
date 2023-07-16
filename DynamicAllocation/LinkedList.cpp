// Includes
#include <string.h>
#include <iostream>

// Declaration of enum
enum Search
{
    FAILED = 0,
    SUCCESSFUL = 1
};

// Declaration of node struct
typedef struct Node
{
    int value;
    Node *next;
} NODE;

// Declaration of class which will be used as a linked list interface
class LinkedList
{
private:
    typedef struct
    {
        NODE *head;
        NODE *tail;
    } INFO;

    INFO info;
    inline static int cnt = 0;

public:
    LinkedList(/* args */);
    ~LinkedList();
    bool IsEmpty(void)
    {
        return (info.head == NULL);
    };
    bool InsertAtEnd(int x);
    bool RemoveItem(int x);
    void CntUp()
    {
        cnt++;
    };
    void CntDown()
    {
        cnt--;
    }
    int GetNumberOfElements(void)
    {
        return cnt;
    };
    bool DeleteLastElement(void);
    void UpdateTail(NODE *next, NODE *head)
    {

        if (next == NULL)
        {
            info.tail = head;
        }
    };
    bool InsertInAscendingOrder(int insertedValue);
    bool InsertAtFirstPosition(int insertedValue);
    void PrintLinkedList(void);
    bool FindElementInList(int num);
};

LinkedList::LinkedList(/* args */)
{
    info.head = NULL;
    info.tail = NULL;
}

LinkedList::~LinkedList()
{
    while (!IsEmpty())
    {
        DeleteLastElement();
        std::cout << "deleted element by destructor" << std::endl;
    }
}

bool LinkedList::InsertAtEnd(int x)
{

    NODE *New_node = new NODE;

    if (New_node == NULL)
        return 0;

    New_node->value = x;
    New_node->next = NULL;

    if (this->IsEmpty())
    {
        this->info.head = New_node;
        this->info.tail = New_node;
    }
    else
    {
        (info.tail)->next = New_node;
        info.tail = New_node;
    }

    CntUp();
    return 1;
}

bool LinkedList::RemoveItem(int x)
{

    if (info.head == NULL)
        return 0;

    // if actual head is equal to x value
    if (info.head->value == x)
    {
        NODE *temp = info.head;

        info.head = info.head->next;

        this->UpdateTail(info.head->next, info.head);

        delete temp;
        temp = nullptr;

        if (temp == NULL)
        {
            this->CntDown();
            return 1;
        }
    }

    // find value in linked list and delete node. Just first occurence will be deleted
    NODE *current = info.head;

    while (!(current->next == NULL))
    {
        if (current->next->value == x)
        {
            NODE *temp = current->next;

            current->next = current->next->next;
            this->UpdateTail(current->next, current);

            delete temp;
            temp = nullptr;

            if (temp == NULL)
            {
                this->CntDown();
                return 1;
            }
        }
        current = current->next;
    }
    return 0;
}

bool LinkedList::DeleteLastElement(void)
{
    if (info.head == NULL)
        return 0;

    NODE *current = info.head;
    NODE *last = info.head;

    while (!(current->next == nullptr))
    {
        last = current;
        current = current->next;
    }

    if (last->next == nullptr)
    {
        delete last;
        info.tail = nullptr;
        info.head = nullptr;
        last = nullptr;
    }
    else
    {
        info.tail = last;
        delete last->next;
        last->next = nullptr;
    }

    this->CntDown();

    return 1;
}

bool LinkedList::InsertInAscendingOrder(int insertedValue)
{
    NODE *NewNode = new NODE;

    if (NewNode == NULL)
        return 0;

    NewNode->value = insertedValue;
    NODE *current = info.head;
    NODE *position = info.head;

    if (insertedValue > this->info.tail->value)
    {
        this->InsertAtEnd(insertedValue);
        return 1;
    }
    else if (insertedValue < this->info.head->value)
    {
        this->InsertAtFirstPosition(insertedValue);
        return 1;
    }

    do
    {
        position = current;
        current = current->next;
    } while (!(current->value > insertedValue));

    position->next = NewNode;
    NewNode->next = current;

    return 1;
}

bool LinkedList::InsertAtFirstPosition(int insertedValue)
{
    if (info.head == NULL)
    {
        this->InsertAtEnd(insertedValue);
        return 1;
    }

    NODE *NewNode = new NODE;

    if (NewNode == nullptr)
    {
        return 0;
    }

    NewNode->value = info.head->value;
    info.head->value = insertedValue;

    if (info.head->next == nullptr)
    {
        this->info.head->next = NewNode;
        this->info.tail = NewNode;
    }
    else
    {
        NewNode->next = info.head->next;
        info.head->next = NewNode;
    }

    this->CntUp();
    return 1;
}

void LinkedList::PrintLinkedList(void)
{

    NODE *temp_list = info.head;

    while (!(temp_list == nullptr))
    {
        std::cout << "Hodnota nodu: " << std::to_string(temp_list->value) << std::endl;
        temp_list = temp_list->next;
    }
}

bool LinkedList::FindElementInList(int num)
{

    NODE *temp = info.head;

    while (!(temp->next == nullptr))
    {
        if (temp->value == num)
        {
            return SUCCESSFUL;
        }
        temp = temp->next;
    }

    return FAILED;
}

// Main function
int main()
{
    LinkedList LinkedListObj;

    LinkedListObj.InsertAtEnd(3);
    LinkedListObj.InsertAtFirstPosition(2);
    LinkedListObj.InsertAtFirstPosition(4);

    LinkedListObj.InsertAtEnd(5);
    LinkedListObj.InsertAtEnd(6);
    LinkedListObj.InsertAtEnd(7);
    LinkedListObj.InsertAtEnd(9);

    LinkedListObj.InsertInAscendingOrder(8);
    LinkedListObj.InsertInAscendingOrder(2);
    LinkedListObj.InsertInAscendingOrder(10);

    LinkedListObj.PrintLinkedList();

    if (LinkedListObj.FindElementInList(5))
    {
        std::cout << "found element in linked list" << std::endl;
    }
    else
    {
        std::cout << "didnt find element in linked list" << std::endl;
    }
    
    std::cout << "Number of elemets: " << std::to_string(LinkedListObj.GetNumberOfElements()) << std::endl;
    LinkedListObj.RemoveItem(4);
    LinkedListObj.RemoveItem(7);
    std::cout << "Number of elemets: " << std::to_string(LinkedListObj.GetNumberOfElements()) << std::endl;

    LinkedListObj.DeleteLastElement();

    std::cout << "Number of elemets: " << std::to_string(LinkedListObj.GetNumberOfElements()) << std::endl;

    if (LinkedListObj.IsEmpty())
    {
        std::cout << "linked list is empty" << std::endl;
    }

    return 0;
}
