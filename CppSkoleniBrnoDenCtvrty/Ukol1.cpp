/*
1) naplnit vektor od 28 ... 100 increment 3
2) kolik cisel je v intervalu 30 - 75, lambda
3) prvni cislo delitelne 4 a vetsi jak 30. Functor nebo lambda
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using Predicate = std::function<bool(int)>;

void fill_array(int N, std::vector<int> &data)
{
    if (N == 100)
    {
        data.push_back(100);
        return;
    }
    data.push_back(N);
    fill_array(N + 3, data);
}

void print_value(int data)
{
    std::cout << "cislo: " << data << std::endl;
}

class Functor
{
public:
    bool operator()(int cislo) { return (cislo % 4 == 0) && (cislo > 30); }
};

/*od pana seveldy*/
class Selector
{
    private:
        Predicate predicate;
    public:
        Selector(Predicate predicate): predicate(predicate){}
        bool operator () (int cislo) { return predicate(cislo);}
};

int main()
{
    std::vector<int> data;

    fill_array(28, data);
    /*
        for(auto& element : data)
            std::cout<< "Cislo: " << element << std::endl;

    */
    std::for_each(data.begin(), data.end(), print_value);

    auto vysledek = std::count_if(data.begin(), data.end(), [](int data)
                                  { return (data > 30) && (data < 75); });

    std::cout << "data > 30 && data < 75: " <<vysledek << std::endl;

    auto vysledek1 = std::find_if(data.begin(), data.end(), Functor());
    //auto vysledek1 = std::find_if(data.begin(), data.end(), Selector());

    if (vysledek1 != data.end())
        std::cout << "vysledek data % 4 and data > 30: "<< *vysledek1 << std::endl;


    return 0;
}


