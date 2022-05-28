#include <iostream>
#include <cstring>
using namespace std;

#define NC 50
#define NL 3000

struct livro
{
    char titulo[NC], genero[NC];
    float preco;
};
typedef struct livro TipoLivro;

int main()
{
    int i;
    TipoLivro livros[NL];

    cout << "Leitura das informacoes dos livros...." << endl;
    for (i = 0; i < NL; i++)
    {
        cout << "\nTitulo do livro " << i + 1 << ": ";
        cin.getline(livros[i].titulo, NC);
        cout << "Genero do livro " << i + 1 << ": ";
        cin.getline(livros[i].genero, NC);
        cout << "Preco do livro " << i + 1 << ": ";
        cin >> livros[i].preco;
        cin.ignore();
    }
    
    cout << "\n\nTitulos de Livros Policiais e com preco menor que R$70,00 \n";
    for (i = 0; i < NL; i++)
    {
        if (strcmp(livros[i].genero, "Policial") == 0 && livros[i].preco < 70.00)
        {
            cout << "\n*****************************"
                 << "\nTitulo do livro: " << livros[i].titulo;
        }
    }
}