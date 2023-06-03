int main()
{
/*
* static_cas, const_cast, dynamic_cast, reinterpret_cast
*/
    int x = 100;
    (double)x;
    static_cast<double>(x);

    // dynamic cast pouziti na ukolu 2
    // zohlednuje dynamicke vazby
    //dynamic_cast<memoryStorage<User>>(stor)->fn();
    
    return 0;
}