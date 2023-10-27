#include <string>
#include <iostream>
#include <vector>

class Solution
{

private:
    struct ValidParenthesesStackType
    {
        std::vector<char> data;
        int top;
    };

    ValidParenthesesStackType Stack;
    ValidParenthesesStackType MemStack;

    enum SolutionEnum
    {
        EMPTY = -1
    };

public:
    bool isValid(std::string s)
    {
        if ((s.size() < 2) || (s.size() % 2 != 0))
            return 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            pushNewElement(&this->Stack, s[i]);
        }

        do
        {
            if ((this->Stack.data[this->Stack.top] == '(') || (this->Stack.data[this->Stack.top] == '[') || (this->Stack.data[this->Stack.top] == '{'))
            {
                pushNewElement(&this->MemStack, this->Stack.data[this->Stack.top]);
                popElement(&this->Stack);
            }

            if (!isEmpty(&this->MemStack))
            {
                switch (this->Stack.data[this->Stack.top])
                {

                case ')':

                    if (this->MemStack.data[this->MemStack.top] == '(')
                    {
                        popElement(&this->MemStack);
                        popElement(&this->Stack);
                    }

                    else
                    {
                        return 0;
                    }
                    break;

                case ']':

                    if (this->MemStack.data[this->MemStack.top] == '[')
                    {
                        popElement(&this->MemStack);
                        popElement(&this->Stack);
                    }

                    else
                    {
                        return 0;
                    }
                    break;

                case '}':

                    if (this->MemStack.data[this->MemStack.top] == '{')
                    {
                        popElement(&this->MemStack);
                        popElement(&this->Stack);
                    }

                    else
                    {
                        return 0;
                    }
                    break;
                }
            }
            else
            {
                return 0;
            }

        }while (!isEmpty(&this->Stack));

        return ((isEmpty(&this->Stack)) && (isEmpty(&this->MemStack)));
    }

    Solution();
    bool isEmpty(ValidParenthesesStackType *stack) { return stack->top == EMPTY; }
    bool pushNewElement(ValidParenthesesStackType *stack, char data);
    bool popElement(ValidParenthesesStackType *stack);
};

Solution::Solution()
{
    Stack.top = -1;
    MemStack.top = -1;
}

bool Solution::pushNewElement(ValidParenthesesStackType *stack, char data)
{
    stack->data.push_back(data);
    stack->top++;
    return 1;
}

bool Solution::popElement(ValidParenthesesStackType *stack)
{
    if (!isEmpty(stack))
    {
        stack->data.pop_back();
        stack->top--;
        return 1;
    }
    return 0;
}

int main()
{
    // std::string s = "([)]";
    // std::string s = "()[]{}";
    std::string s = "((";
    // std::string s = "([{}])()([{}])()([{}])()([{}])()";
    // std::string s = "(()])";

    Solution SolutionObj;
    std::cout << "result: " << SolutionObj.isValid(s);

    return 0;
}