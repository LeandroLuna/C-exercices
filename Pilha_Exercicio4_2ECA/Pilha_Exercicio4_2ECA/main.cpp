#include <iostream>
#include <locale>

using namespace std;

#include "PilhaInt.h"

int main()
{
    setlocale(LC_ALL,"");
    TipoPilha topo;
    init(&topo);

    int decimal, resto;
    cout << "Informe valor em decimal: " ;
    cin >> decimal;
    while (decimal>0){
        resto = decimal % 2;
        push(&topo, resto);
        decimal = decimal / 2;
    }
    cout << " Valor em binário: ";
    while (!isEmpty(topo)){
        pop(&topo, &resto);
        cout << resto << " ";
    }
    cout << endl;
    return 0;
}
