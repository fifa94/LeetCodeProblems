#include <iostream>

class GrafickyObjekt
{
private:
    /* data */
public:
    virtual double obsah () = 0;
};


class Obdelnik : public GrafickyObjekt
{
private:
    int delka, sirka;
public:
    Obdelnik(int delka, int sirka): delka(delka), sirka(sirka){};
    ~Obdelnik();
    double obsah () override {return delka * sirka;}
};


Obdelnik::~Obdelnik()
{
}

class Kruh : public GrafickyObjekt
{
private:
    int polomer;
public:
    Kruh(int polomer): polomer(polomer) {};
    ~Kruh();
    double obsah () override {return 3.14 * polomer * polomer;}
};


Kruh::~Kruh()
{
}

double vypocitej_obsah (GrafickyObjekt & obj)
{
    return obj.obsah();
}

class Rodic
{
private:
    /* data */
public:
    Rodic(/* args */);
    // Pokud by tady nebylo virtual, tak se nezavola tenhle destruktor
    virtual ~Rodic();
};

Rodic::Rodic(/* args */)
{
    std::cout << "Konstruktor Rodic" << std::endl;
}

Rodic::~Rodic()
{
    std::cout << "Destruktor Rodic" << std::endl;
}

class Potomek : public Rodic
{
private:
    /* data */
public:
    Potomek(/* args */);
    ~Potomek();
};

Potomek::Potomek(/* args */)
{
    std::cout << "Konstruktor Potomek" << std::endl;
}

Potomek::~Potomek()
{
    std::cout << "Destruktor Potomek" << std::endl;
}


int main()
{
    Obdelnik o (12,22);
    Kruh k (15);

    std::cout << vypocitej_obsah(o) << std::endl;
    std::cout << vypocitej_obsah(k) << std::endl;

    Rodic* r = new Potomek();

    delete r;

    return 0;
}