#define SIZE 5
#define ROW 5
#define COLUMN 4

#include<iostream>
#include <array>

int main()
{
    
    int *pole = new int [SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        pole[i] = i;
        std::cout << "element:" << pole[i]<< std::endl;
    }

    float *array = new float[ROW];
    for (int i = 0; i < ROW; i++)
    {
        array = new float [COLUMN];
    }
    

    delete [] pole;

    for (int i = 0; i < ROW; i++)
    {
        delete [] array[i];
    }
    
    delete [] array;
    return 0;
}