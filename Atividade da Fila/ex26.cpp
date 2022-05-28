#include <iostream>
#include <locale>
#include <stdlib.h>
using namespace std;

struct no
{
    int dado;
    struct no *prox;
};
typedef struct no *TipoFila;

void init(TipoFila *ini, TipoFila *fim)
{
    *ini = NULL;
    *fim = NULL;
}

int isEmpty(TipoFila ini, TipoFila fim)
{
    if ((ini == NULL) && (fim == NULL))
        return (1);
    else
        return (0);
}

void enqueue(TipoFila *ini, TipoFila *fim, int v)
{
    TipoFila novo;
    novo = (TipoFila)malloc(sizeof(struct no));
    if (novo == NULL)
        cout << "Fila Cheia \n";
    else
    {
        novo->dado = v;
        novo->prox = NULL;
        if (isEmpty(*ini, *fim))
        {
            *ini = novo;
        }
        else
        {
            (*fim)->prox = novo;
        }
        *fim = novo;
    }
}
int dequeue(TipoFila *ini, TipoFila *fim, int *v)
{
    TipoFila aux = *ini;
    if (isEmpty(*ini, *fim))
        return 0;
    else
    {
        *v = aux->dado;
        *ini = aux->prox;
        if (*ini == NULL)
            *fim = NULL;
        free(aux);
        return 1;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    TipoFila ini, fim;
    int valor;
    init(&ini, &fim);
    enqueue(&ini, &fim, 8);
    enqueue(&ini, &fim, 5);
    enqueue(&ini, &fim, 3);
    if (dequeue(&ini, &fim, &valor))
        cout << "Valor retirado da fila: " << valor << endl;
    else
        cout << "Fila vazia\n";

    if (dequeue(&ini, &fim, &valor))
        cout << "Valor retirado da fila: " << valor << endl;
    else
        cout << "Fila vazia\n";

    if (dequeue(&ini, &fim, &valor))
        cout << "Valor retirado da fila: " << valor << endl;
    else
        cout << "Fila vazia\n";

    if (dequeue(&ini, &fim, &valor))
        cout << "Valor retirado da fila: " << valor << endl;
    else
        cout << "Fila vazia\n";

    return 0;
}