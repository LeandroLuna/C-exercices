#include <iostream>
#include <locale>
using namespace std;

char classifica (int l1, int l2, int l3)
{
    if (l1==l2 && l1==l3)
        return 'E';
    else if (l1==l2 || l1==l3 || l2==l3)
       return 'I';
    else
        return 'S';
}

int main()  {
    setlocale(LC_ALL,"");
    int a,b,c;
    char tipo;
    cout << "digite os valores dos 3 lados do triangulo \n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    tipo = classifica(a,b,c);
    switch(tipo){
            case 'E': cout << "Equilátero\n";
                      break;
            case 'I': cout << "Isósceles\n";
                      break;
            case 'S': cout << "Escaleno\n";
                      break;
            }
    return 0;
}

