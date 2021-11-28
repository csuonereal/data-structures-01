#include <iostream>

int main()
{
    int var;
    int *ptr;
    int **pptr;

    var = 3000;

    //take the address of var
    ptr = &var;
    //take the address of ptr using address of operator &
    pptr = &ptr;

    std::cout << "Value of var:" << var << std::endl;
    std::cout << "Value available at *ptr:" << *ptr << std::endl;
    std::cout << "Value available at **ptr:" << **pptr << std::endl;
}