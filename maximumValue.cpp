#include <iostream>
#include "midterm.h"

int main()
{
    midterm midterm;
	int myArray[] = { 0,1,2,3,4,5,6,7,8,9 };
	std::cout << midterm.maximumValue(myArray, 10) << std::endl;
}