#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ""); // Set the location as the same as OS.
    float f, x;
    cout << "Enter the Farenheit value:";
    cin >> f;
    x = 5 / 9 * (f - 32);
    cout << "Value converted to Celsius: " << x;

    return 0;
}
