#include <iostream>

template<typename T>
T FindMaximum (T num1, T num2){
    return (num1 > num2)? num1 : num2;
}

int main(){

    std::cout << "Maximum z cisel 5 a 2 je " << FindMaximum(5, 2);
    return 0;
}