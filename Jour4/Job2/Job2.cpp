#include <iostream>

using namespace std;

int main(void)
{
    int num1 = 42;
    int num2 = 12;
    int num3 = 0;

    cout << "Number 1 : " <<  num1 << endl;
    cout << "Number 2 : " << num2 << endl;

    int* ptr_num1 = &num1;
    int* ptr_num2 = &num2;
    int* ptr_num3 = &num3;

    num3 = *ptr_num1;
    num1 = *ptr_num2;
    num2 = *ptr_num3;


    cout << "Number 1 : " << num1 << endl;
    cout << "Number 2 : " << num2 << endl;

}