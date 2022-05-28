#include <iostream>
#include <locale>
#include <stdlib.h>
using namespace std;

struct no
{
    int dado;        /*define elemento do tipo_inteiro*/
    struct no *prox; /*define ponteiro para o próximo no*/
};
typedef struct no *TipoLista;

int main()
{
    TipoLista lista, novo;
    lista = (TipoLista)malloc(sizeof(struct no));
    if (lista == NULL)
        cout << "não foi possível alocar espaço requisitado \n";
    else
    {
        cout << "digite valor do elemento inteiro: ";
        cin >> lista->dado;
        lista->prox = NULL;
    }
    novo = (TipoLista)malloc(sizeof(struct no));
    if (novo == NULL)
        cout << "não foi possível alocar espaço requisitado \n";
    else
    {
        cout << "digite valor do elemento inteiro: ";
        cin >> novo->dado;
        novo->prox = lista;
        lista = novo;
    }
    free(novo);
    free(lista);
    return 0;
}