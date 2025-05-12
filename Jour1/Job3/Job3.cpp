#include <iostream>

int main(void)
{
    int number;

    std::cout << "Type a number : ";
    std::cin >> number;
    // std::cout << number;

    if(number > 0)
    {
        while(number > 0)
        {
            std::cout << "Hello World !\n";
            number -= 1;
        }
    }
}