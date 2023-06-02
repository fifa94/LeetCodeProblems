/*
1)Kontejnery
2)Algoritmy
3)Funkcni objekty
4)Funkcni adaptery - umoznuje adaptaci funkce napr.
5)Pomocne sablony
*/

/*
Array
Nahrada poli z C
Staticke pole s pevnum poctem prvku
*/

/*
Vector
Pole s dynamickou delkou
*/

/*
Deque
dynamicka fronta
Elementy nejsou za sebou v pameti
Vhodne pro datove struktury s rychlym vkladanim a odebiranim prvku
*/

/*
Set
Unikatni prvky, ktere nejsou za sebou v pameti. Automaticky se radi
std::set<int, greater<int>> data
*/

/*
map
Asociativni slovnik
Jako v pythonu mam klid a hodnotu
Klic je unikatni
Rychly pristup k datum pomoci klice
*/

/*Funktory
Preddefinovane funkcni objekty
pouziti
std::greater<int> gt;
gt(1,3)
std::sort(v.begin(), v.end(), std::greater<int>());
*/

/*Funkcni adaptery
Umoznuje snizit, zvysit pocet argumentu funkce, prehozeni parametru popr zmenit logicke navratove hodnoty
V podstate to vyrobi novou funkci, kterou adaptoval na pro misto pouziti

int add (int a, int b, int c){
    return a+b+c;
}

auto add2 { bind(add, placeholders::1, placeholders::2, 100)};
potom volam add2(1,2); --- toto odpovida volani funkce add(1,2,100)

===
negator
neguje vysledek
*/
#include <iostream>
#include <vector>
#include <algorithm>

bool je_zaporny(int cislo)
{
    return cislo < 0;
}

class JeZaporny
{
private:
    int limit;

public:
    JeZaporny(int limit) : limit(limit) {}
    bool operator()(int cislo) { return cislo < limit; }
};

int main()
{
    std::vector<int> data{1, 2, -4, 3, 5};

    // 1 funkce
    auto vysledek1 = std::find_if(data.begin(), data.end(), je_zaporny);
    // 2 lamda
    auto vysledek2 = std::find_if(data.begin(), data.end(), [](int cislo)
                                  { return cislo < 0; });
    // 3 functor
    auto vysledek3 = std::find_if(data.begin(), data.end(), JeZaporny(0));

    if (vysledek1 != data.end())
        std::cout << "prvni zaporne cislo je: " << *vysledek1 << std::endl;

    if (vysledek2 != data.end())
        std::cout << "prvni zaporne cislo je: " << *vysledek2 << std::endl;

    if (vysledek3 != data.end())
        std::cout << "prvni zaporne cislo je: " << *vysledek3 << std::endl;
}