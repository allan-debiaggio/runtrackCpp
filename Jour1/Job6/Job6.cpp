#include <format>
#include <iostream>

void table(int number);

int main(void)
{
    int number = 0;
    std::cout << "Enter a number : ";
    std::cin >> number; 
    table(number);
}

void table(int number)
{
    for(int i = 1; i < 11; i++)
    {
        int result = number * i;
        std::cout << result << std::endl;
    }
}