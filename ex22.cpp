#include <iostream>
#include <locale>
#include <stdlib.h>
using namespace std;

int main()
{
    char *pontChar; // *pontChar (conteúdo apontado pelo ponteiro pontChar) é um caracter

    pontChar = (char *)malloc(sizeof(char)); //A função malloc é usada para alocar memória para qualquer tipo de dado, assim retorna um ponteiro genérico. O casting "(char*)" converte o ponteiro genérico retornado no tipo ponteiro para char.

    if (pontChar == NULL) // ''NULL'' é um valor de ponteiro reservado que não aponta para nenhum objeto de dado valido.
        cout << "Não foi possível alocar espaço requisitado \n";
    else
    {
        cout << "sizeof char: " << sizeof(char) << endl;
        cout << "digite caracter: ";
        cin >> *pontChar; // A variável ''pontChar'' contém o endereço de memória onde o valor lido sera armazenado
        cout << "Apresentação do dado armazenado na região = " << *pontChar;
        free(pontChar);
    }
    return 0;
}