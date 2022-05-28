//Criação correta da pilha de caracteres no arquivo TipoPilhaChar.h

#include <iostream>
#include <stdlib.h>
using namespace std;

struct no
{
    char dado;
    struct no *prox;
};
typedef struct no *TipoPilha;

void init(TipoPilha *topo)
{
    *topo = NULL;
}

int isEmpty(TipoPilha topo)
{
    if (topo == NULL)
        return (1);
    else
        return (0);
}

void push(TipoPilha *topo, char elem)
{
    TipoPilha novo;
    novo = (TipoPilha)malloc(sizeof(struct no));
    if (novo != NULL)
    {
        novo->dado = elem;
        novo->prox = *topo;
        *topo = novo;
    }
    else
        cout << "Stack overflow \n";
}

int pop(TipoPilha *topo, char *elem)
{
    TipoPilha aux;
    aux = *topo;
    if (!isEmpty(*topo))
    {
        *elem = aux->dado;
        *topo = (*topo)->prox;
        free(aux);
        return (1);
    }
    else
    {
        return (0);
    }
}

int top(TipoPilha topo, char *elem)
{
    if (!isEmpty(topo))
    {
        *elem = topo->dado;
        return (1);
    }
    return (0);
}
