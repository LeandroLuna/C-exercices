#include <iostream>
#include <locale>
#include <stdlib.h>
using namespace std;

struct livro
{
    char titulo[50], autor[30];
    float preco; // float tem 4 bytes
};
typedef struct livro TipoLivro;

int main()
{
    TipoLivro *pont;

    pont = (TipoLivro *)malloc(sizeof(TipoLivro));

    if (pont == NULL)
        cout << "Não foi possível alocar espaço requisitado \n";
    else
    {
        cout << "sizeof TipoLivro: " << sizeof(TipoLivro) << endl;
        cout << "digite o nome do livro: ";
        cin.getline(pont->titulo, 50);
        cout << "digite o nome do autor: ";
        cin.getline(pont->autor, 50);
        cout << "digite o preco do livro: ";
        cin >> pont->preco;

        cout << "\n\nApresentando informacoes do livro armazenado na regiao alocada dinamicamente..." << endl;
        cout << "Titulo do livro: " << pont->titulo << "\nAutor: " << pont->autor << "\nPreco: " << pont->preco;
    }
    free(pont);
    return 0;
}