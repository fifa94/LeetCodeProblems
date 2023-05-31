#include<iostream>
#include<string>

void string_cpy (std::string source, std::string &temp, int index=0)
{
    if (source.length() != 0)
    {
        temp.push_back(source[source.length() - 1 -index]);
        source.pop_back();
        string_cpy(source, temp, index++);
    }
    return;
}

int main ()
{
    std::string destionation_string;
    string_cpy("Hello world", destionation_string);
    return 0;
}