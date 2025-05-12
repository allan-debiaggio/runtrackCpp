#include <iostream>

bool isEven(int number);

int main(void)
{
    int number = 0;

    std::cout << "Enter a number : ";
    std::cin >> number;
    if(isEven(number))
    {
        std::cout << "This number is even.";
    }
    else
    {
        std::cout << "This number is odd.";
    }
}

bool isEven(int number)
{
    if(number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}