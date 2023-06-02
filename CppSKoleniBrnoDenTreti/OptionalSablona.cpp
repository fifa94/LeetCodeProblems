#include <iostream>
#include <optional>

std::optional<int> fn (int parameter){
    if (parameter < 0)
        return std::nullopt;
    
    return std::optional(parameter);
}

int main()
{
    fn(100); //OK
    fn(-1); // Error

    // funguje to jako v drahe restauraci, kdy ucet vraci v knizce. Muze tam byt ucet a take nemusi. Tady to je akorat vysledek
    std::optional<int> result { fn (100)};

    if (result.has_value())
    {
        std::cout << *result;
    }
    
}