#include <iostream>
#include <cstring>

using namespace std;

#define NC 30

#include "PilhaChar.h"

int main()
{
    setlocale(LC_ALL, "");
    int i;
    TipoPilha pilha;

    char word[NC], compara[NC];
    cout << "Digite uma palavra: ";
    cin >> word;

    init(&pilha);

    for (i = 0; i < strlen(word); i++)
        push(&pilha, word[i]);

    i = 0;
    while (!isEmpty(pilha))
    {
        pop(&pilha, &compara[i]);
        i++;
    }
    compara[i] = '\0';

    cout << compara << endl;

    if (strcmp(word, compara) == 0)
        cout << "� pal�ndromo" << endl;
    else
        cout << "N�O � pal�ndromo" << endl;
    return 0;
}
