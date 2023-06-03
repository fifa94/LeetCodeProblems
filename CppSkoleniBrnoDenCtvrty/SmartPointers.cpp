class Dedecek
{
private:
    /* data */
public:
    Dedecek(/* args */);
    ~Dedecek();
    virtual void fn(){}
};

Dedecek::Dedecek(/* args */)
{
}

Dedecek::~Dedecek()
{
}

class Matka : public Dedecek
{
private:
    /* data */
public:
    Matka(/* args */);
    ~Matka();
};

Matka::Matka(/* args */)
{
}

Matka::~Matka()
{
}

class Potomek : Matka
{
private:
    /* data */
public:
    Potomek(/* args */);
    ~Potomek();
};

Potomek::Potomek(/* args */)
{
}

Potomek::~Potomek()
{
}

//Podomacku vytvoreny smart pointer
// funguje na principu RAII
template<typename T> class ChytryDedecek
{
private:
    T* dedecek;
public:
    ChytryDedecek(T* ptr): dedecek(ptr){}
    ~ChytryDedecek(){ delete dedecek; dedecek = nullptr;}
    T* operator->(){return dedecek;}
};

void create(){
    // Tohle neni. Po skonceni vykonani funkce se tento objekt zahodi
    //Dedecek d2;
    // Tohle je pametovy leak
    //Dedecek* d1 = new Dedecek;

    ChytryDedecek cd {new Dedecek};
    cd->fn();
}




int main()
{
    while (1)
    {
        create();
    }
    
}

/*
________________
+++Unique ptr+++
________________

Nejzakladnejsi chytry pointer.
V podstate to je chytry dedecek.
Na ten objekt muze odkazovat pouze jedna promenna.

________________
+++Shared ptr+++
________________

Umoznuje mit na stacku vice promennych, ktere miri na pointer v heapu. Je tam jakesi pocitadlo referenci.
V podstate jako v pythonu

________________
+++Weak ptr+++
________________
Nezveda pocitadlo jako shared ptr.
V praxi se moc nepouziva.

*/