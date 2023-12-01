#include <string>
#include <iostream>
#include <vector>
#include <cstring>

class TextAnalyzer
{
public:
    TextAnalyzer(std::string Text);
    ~TextAnalyzer();
    int countWords(void) const;
    double averageWordLength(void) const;
    int totalNumberOfChars(void) const {return this->numberOfChar;}

private:
    /* data types */

    struct WordsStackType
    {
        std::vector<std::string> data;
        int top;
    };

    /* variables */
    std::string _Text;
    std::string _auxString;
    int numberOfChar;
    WordsStackType Stack;
    /* methods */
    void initializeStack(void);
    bool addNewElementToStack(std::string Text);
};

TextAnalyzer::TextAnalyzer(std::string Text)
{
    /* save text input */
    this->_Text = Text;
    /* initialize stack */
    initializeStack();
    this->numberOfChar = 0;

    for (int i = 0; i < this->_Text.size(); i++)
    {
        if ((this->_Text[i] != '!') && (this->_Text[i] != ',') 
        && (this->_Text[i] != '.') && (this->_Text[i] != '?'))
        {
            this->_auxString.append(1, this->_Text[i]);
            this->numberOfChar++;
        }
        

        if ((this->_Text[i] == ' ') || (i == this->_Text.size() - 1))
        {
            addNewElementToStack(this->_auxString);
            this->_auxString.clear();
        }
    }
}

TextAnalyzer::~TextAnalyzer()
{
    initializeStack();
}

int TextAnalyzer::countWords(void) const
{
    return (this->Stack.top == -1) ? 0 : this->Stack.top + 1;
}

double TextAnalyzer::averageWordLength(void) const
{
    return (static_cast<double>(this->numberOfChar) / (static_cast<double>(this->Stack.top + 1)));
}

void TextAnalyzer::initializeStack(void)
{
    Stack.top = -1;
    Stack.data.clear();
}

bool TextAnalyzer::addNewElementToStack(std::string Text)
{
    if (Text.size() > 0)
    {
        this->Stack.data.push_back(Text);
        this->Stack.top++;
    }
    return 0;
}

int main()
{
    std::string text = "Vítejte v programu pro objektově orientovanou analýzu textu!";
    TextAnalyzer TextAnalyzerObj(text);
    std::cout << "Pocet slov: " <<TextAnalyzerObj.countWords()<< std::endl;
    std::cout << "Pocet pismen: " << TextAnalyzerObj.totalNumberOfChars() << std::endl;
    std::cout << "Prumerna velikost slova: " << TextAnalyzerObj.averageWordLength() << std::endl;

    return 0;
}