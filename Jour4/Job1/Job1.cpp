#include <iostream>

using namespace std;

int main(void)
{
    int number = 2019;
    int* ptr = &number;

    cout << "Address of variable : " << &number << endl;
    cout << "Printing variable with dereferenced pointer : " << *ptr << endl;

}