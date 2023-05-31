#include <iostream>

void swappp(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{   
    // new vola automaticky konstruktor tridy
    int* x = new int;

    int* x_arr = new int [4];
    // Musi tady byt hranata zavorka, aby doslo ke kompletnimu odstraneni alokovane pameti. pokud bych zavolal pouze delete x_arr, tak odstanim prvni prvek v poli
    // delete vola automaticky destruktor
    delete [] x_arr; 
    x_arr = nullptr;
    
    delete x;
    // devalidace pointru x
    x = nullptr;

    int y= 100;

    int &z = y;

    std::cout << z << ", " << y;

    return 0;
}