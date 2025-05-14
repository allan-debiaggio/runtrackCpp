#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string sentence = "vive la plateforme !\n";
    cout << sentence;
    for(int i = 0; i < sentence.length(); i ++)
        sentence[i] = toupper(sentence[i]);
    cout << sentence;

    return 0;
}