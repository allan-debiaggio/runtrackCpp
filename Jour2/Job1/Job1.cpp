// Rendre le programme lisible
// do {} while (cout << "donnez un nombre > 0 ", cin >> n, n <= 0);

#include <iostream>

using namespace std;

int main(void)
{
    int n = 0;

    do
    {
        cout << "donnez un nombre > 0 : ";
        cin >> n;
    }
    while(n <= 0);

    return 0;
}