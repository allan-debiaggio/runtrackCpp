#include <iostream>

int sum(int num1, int num2);

int main(void)
{
    int num1;
    int num2;
    std::cout << "Enter the first number : ";
    std::cin >> num1;
    std::cout << "Enter the second number : ";
    std::cin >> num2;

    std::cout << sum(num1, num2);

    return 0;
}

int sum(int num1, int num2)
{
    return num1 + num2;
}