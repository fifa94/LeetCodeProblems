#include <iostream>

class Cislo
{
private:
    int cislo;

public:
    Cislo(int cislo) : cislo(cislo) {}
    Cislo() = default;
    // copy constructor = copu ctor
    // Zakazani copy cotur
    Cislo (Cislo& obj) = delete;
    void increment() { cislo++; }
    int get() const { return this->cislo; }
    Cislo& operator=(Cislo& dalsi_cislo) = delete;
    ~Cislo();
};


Cislo::~Cislo()
{
}

int main()
{
    int data[]{1, 2, 3, 4};
    // pri tomto zapisu se cisla stale kopiruji do stacku. Muze to zpusobit problemy s vykonem.
    for (auto cislo : data)
        cislo++;
    // for(auto cislo : data) std::cout << cislo << std::endl;
    //  ted se to nebude kopirovat. Upravena data mi zustanou a bude to rychlejsi. Muzu klidne pouzit misto int i auto s referenci.
    for (int &cislo : data)
        cislo++;
    // for(int cislo : data) std::cout << cislo << std::endl;

    Cislo *cisla[2] { new Cislo(10), new Cislo(5)};

    for(const auto c : cisla)
        c->increment();

    for(const auto c : cisla)
        std::cout << c->get() << std::endl;


    Cislo c(10);
    Cislo x;


    //Cislo y = c; Cislo y(c); Tohlej je jeden z moznych zapisu na copy constructor, ktery jsem zakazal
    // deletem to tohle zakazu
    //c = x; // prepisuje na c.operator=

    return 0;
}