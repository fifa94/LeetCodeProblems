#include<string>
#include<iostream>
#include <functional>
void pozdrav(const std::string& zprava)\
{
    std::cout << zprava << std::endl;
}
// vylozene zpais reference na r hodnotu. Nebude to fungovat s promennou 
int fn(int&& x)
{
    return x;
}

int main()
{
    auto korekce {10};

    std::string msg = "Hello";

    //pozdrav(msg);
    // Tohle je reference na r hodnotu
    // chybu lze vyresit pridanim const do atributu funkce. Nicmene nemuzu modifikovat zpravu
    pozdrav("hello");

    fn(10);

    // lambda funkce
    // lamda fce by mela byt state less
    // pokud si ji budu definovat v kodu, kdyz chci vystup do promenne
    std::function<int(int, int)> nasobek0 = [](int x, int y) {return x * y ;};
    auto nasobek1 = [](int x, int y) {return x * y;};
    // k cemu slouzi ta hranata zavorka
    // je to seznam promennych, ktere jsou pristupne ve funkci z globalniho seznamu mimo atributy
    auto nasobek2 = [korekce](int x, int y) {return x * y + korekce;};
    // parametrem v capture listu muzu ovlivnit, zda bude napr predana hodnota jako reference a dalsi komba
    int cnt = 0;
    std::string prefix = "Msg: ";

    return 0;
}