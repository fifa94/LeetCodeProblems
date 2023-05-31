#include<iostream>
//refactoring.guru

class Pokus
{
private:
    
public:
    inline static int pocet = 0;
    Pokus(/* args */);
    ~Pokus();
};

Pokus::Pokus(/* args */)
{
    pocet++;
}

Pokus::~Pokus()
{
    pocet--;
}



int main ()
{
    
    std::cout << "pocet objektu " << Pokus::pocet << std::endl;
    Pokus p;
    std::cout << "pocet objektu " << Pokus::pocet << std::endl;
    return 0;
}