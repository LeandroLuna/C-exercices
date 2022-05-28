#include <iostream>
#include <cstring>
#define N 15
using namespace std;

int main()
{
    char str1[N], str2[N];
    cout << "Informe um nome: ";
    cin.getline(str1, N);
    cout << "Informe o segundo nome: ";
    cin.getline(str2, N);
    if (strcmp(str1, str2) == 0)
    {
        cout << "\nString sao iguais."; // Compara as 'strings'. Se "str1" for igual a "str2" o valor retorna 0.
    }
    else
    {
        if (strcmp(str1, str2) > 0) // Se "str1" for maior que "str2", o valor retornado será maior que 0.
        {
            cout << "\nOrdem alfabetica: \n\t" << str2 << "\n\t" << str1;
        }
        else // Se "str2" for maior que "str1", o valor retornado será menor que 0.
        {
            cout << "\nOrdem alfabetica: \n\t" << str1 << "\n\t" << str2;
        }
    }
    return 0;
}
