#include <iostream>
#include <locale>
using namespace std;

void classifica (int l1, int l2, int l3, char *t)
{
    if (l1==l2 && l1==l3)
        *t = 'E';
    else if (l1==l2 || l1==l3 || l2==l3)
        *t = 'I';
    else
        *t = 'S';
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

    classifica(a,b,c,&tipo);
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
