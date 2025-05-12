#include <iostream>

int multiply(int num1, int num2);

int main(void)
{
    int num1 = 0;
    int num2 = 0;

    std::cout << "Give me the first number : ";
    std::cin >> num1;
    std::cout << "Give me the second number : ";
    std::cin >> num2;
    std::cout << multiply(num1, num2);
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}