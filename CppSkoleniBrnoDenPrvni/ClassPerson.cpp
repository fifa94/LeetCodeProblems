#include <iostream>
#include <string>
#include <functional>

// get_age -- snake case
// getAge -- camel case

class Person
{
private:
    int age;
    
public:
    Person(int a); // Constructor
    int getAge() const; // getter
    void setAge(int age) {this->age = age;}
    ~Person();  // destructor
    // operator overloading
    Person& operator+(int);
};

Person& Person::operator+ (int plus_value)
{
    setAge(getAge() + plus_value);
    return *this;
}

/*
Person::Person(int a) : age(a)
{
    std::cout << "vytvarim novy objekt" << std::endl;
}

tohle s hodi napriklad v momente, jako je tenhle.
Prvne vznikne objekt, ktery by obsahoval prazdnou referenci.

class Pokus
{
private:
    int& cislo;
public:
    Pokus (int);
};

Pokus::Pokus (int value) : cislo(value)
{

}

*/

Person::Person(int age)
{
    if (age < 0)
    {
       std::cout << "sorry" << std::endl;
       // This je ukazatel sam na sebe. V pythonu jako self.
       this->age = 0;
       return;
    }
    
    this->age = age;
    std::cout << "vytvarim novy objekt" << std::endl;
}

Person::~Person()
{
    std::cout << "mazu objekt" << std::endl;
}

int Person::getAge () const
{
    return this->age;
}

bool zpracuj (int data, std::function<bool(int)> kod)
{
    return kod(data);
}

class Point
{
private:
    /* data */
    int x;
public:
    Point(int _x) : x(_x) {}
    ~Point();
};

Point::~Point()
{
}

class Point2D : public Point
{
private:
    /* data */
    int y;
public:
    Point2D(int _x, int _y) : Point(_x), y(_y) {}
    ~Point2D();
};

Point2D::~Point2D()
{
}

class Point3D : public Point2D
{
private:
    int z;
    /* data */
public:
    Point3D(int _x, int _y, int _z) : Point2D(_x, _y), z(_z) {}
    ~Point3D();
};

Point3D::~Point3D()
{
}



int main()
{
    // vytvori se na stacku
    Person franta(24);
    // vytvoreni v heapu
    Person* jirka = new Person(25);
    //franta.setAge(27);

    franta = franta + 8;

    std::cout << franta.getAge() << std::endl;
    std::cout << jirka->getAge() << std::endl; // nic jineho nez (*jirka).getAge();

    delete jirka;

    std::cout << zpracuj(100, [] (int n) {return n == 100;}) << std::endl;
    std::cout << zpracuj(100, [] (int n) {return n == 58;}) << std::endl;

    return 0;
}