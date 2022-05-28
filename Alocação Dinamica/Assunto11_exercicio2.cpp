#include <iostream>
#include<locale>
#include <stdlib.h>
using namespace std;

struct livro{
    char titulo[50], autor[30];
    float preco;
};

typedef struct livro TipoLivro;

int main() {
    setlocale(LC_ALL,"");
    TipoLivro *pont;

    pont = (TipoLivro*) malloc(sizeof(TipoLivro));

    if (pont == NULL)
        cout << "Não foi possível alocar espaço requisitado \n";
    else{
        cout <<"sizeof TipoLivro: " << sizeof(TipoLivro) <<endl;
        cout << "digite título: ";
        cin.getline(pont->titulo, 50);
        cout << "digite autor: ";
        cin.getline(pont->autor, 30);
        cout << "Preço R$";
        cin >> pont->preco;


        cout <<"Apresentação do livro armazenado na região alocada dinamicamente\n ";
        cout <<"Título do livro: " << pont->titulo << "\n Autor: "<< pont->autor << "\n  R$"<< pont->preco << endl;

        free(pont);
        }
    return 0;
}
