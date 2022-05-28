#include <iostream>
#include <locale>
#include <stdlib.h>
using namespace std;

int main()
{
    float *pont;

    pont = (float *)malloc(sizeof(float));

    if (pont == NULL)
        cout << "Não foi possível alocar espaço requisitado \n";
    else
    {
        cout << "sizeof float: " << sizeof(float) << endl;
        cout << "digite o numero real: ";
        cin >> *pont;
        cout << "Apresentacao do dado armazenado na regiao = " << *pont;
        free(pont);
    }
    return 0;
}