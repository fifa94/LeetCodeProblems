#include <iostream>

class Pokus
{
private:
    Pokus(/* args */);
public:
    inline static int pocet = 0;
    static Pokus* of()
    {
        return new Pokus();
    }
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
    //Pokus* p = new Pokus();
    Pokus* p = Pokus::of();
    delete p;
    return 0;
}