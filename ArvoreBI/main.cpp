#include <iostream>
#include <locale>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct informacoes
{
    int hashcode;
    char coordenadas[16];
} typedef TipoInfo;

struct no
{
    TipoInfo dado;
    struct no *esq, *dir;
};

typedef struct no *TipoArvore;

void insere(TipoArvore *p, TipoInfo info)
{
    TipoArvore novo;
    if (*p == NULL)
    {
        novo = (TipoArvore)malloc(sizeof(struct no));
        if (novo != NULL)
        {
            novo->dado.hashcode = info.hashcode;
            strcpy(novo->dado.coordenadas, info.coordenadas);
            novo->dir = NULL;
            novo->esq = NULL;
            *p = novo;
        }
    }
    else
    {
        if (info.hashcode < (*p)->dado.hashcode)
        {
            insere(&(*p)->esq, info);
        }
        else
        {
            insere(&(*p)->dir, info);
        }
    }
}
void lista_em_ordem(TipoArvore p)
{
    if (p != NULL)
    {
        if (p->esq != NULL)
        {
            lista_em_ordem(p->esq);
        }
        cout << p->dado.hashcode << " || " << p->dado.coordenadas << endl;
        if (p->dir != NULL)
        {
            lista_em_ordem(p->dir);
        }
    }
}

void lista_pos_ordem(TipoArvore p)
{
    if (p != NULL)
    {
        if (p->esq != NULL)
        {
            lista_pos_ordem(p->esq);
        }
        if (p->dir != NULL)
        {
            lista_pos_ordem(p->dir);
        }
        cout << p->dado.hashcode << " || " << p->dado.coordenadas << endl;
    }
}

void lista_pre_ordem(TipoArvore p)
{
    if (p != NULL)
    {
        cout << p->dado.hashcode << " || " << p->dado.coordenadas << endl;
        if (p->esq != NULL)
        {
            lista_pre_ordem(p->esq);
        }
        if (p->dir != NULL)
        {
            lista_pre_ordem(p->dir);
        }
    }
}

void lista_pos_ordem_invertida(TipoArvore p)
{
    if (p != NULL)
    {
        if (p->dir != NULL)
        {
            lista_pos_ordem_invertida(p->dir);
        }
        if (p->esq != NULL)
        {
            lista_pos_ordem_invertida(p->esq);
        }
        cout << p->dado.hashcode << endl;
    }
}

int consulta(TipoArvore p, int info)
{
    if (p != NULL)
    {
        if (p->dado.hashcode == info)
            return 1;
        else if (info < p->dado.hashcode)
            return consulta(p->esq, info);
        else
            return consulta(p->dir, info);
    }
    else
        return 0;
}

int consultaComp(TipoArvore p, int info, int cont)
{
    if (p != NULL)
    {
        cont++;
        if (p->dado.hashcode == info)
            return cont;
        else if (info < p->dado.hashcode)
            return consultaComp(p->esq, info, cont);
        else
            return consultaComp(p->dir, info, cont);
    }
    else
        return cont;
}

int main()
{
    int valor;
    int op;
    TipoArvore tree;
    TipoInfo parainserir[10];
    tree = NULL;

    for (int i = 0; i < 9; i++)
    {
        cout << "Hashcode: ";
        cin.sync();
        cin >> parainserir[i].hashcode;
        insere(&tree, parainserir[i]);
    }

    cout << "\n\n ***** LISTA EM ORDEM *****\n";
    lista_em_ordem(tree);
    cout << "\n *****************************\n";
    cout << "\n\n ***** LISTA PRE-ORDEM *****\n";
    lista_pre_ordem(tree);
    cout << "\n *****************************\n";
    cout << "\n\n ***** LISTA POS-ORDEM *****\n";
    lista_pos_ordem(tree);
    cout << "\n *****************************\n";
    cout << "\n\n ***** LISTA POS-ORDEM INVERTIDA*****\n";
    lista_pos_ordem_invertida(tree);
    cout << "\n *****************************\n";

    cout << "Digite um valor positivo a ser procurado ou zero e negativo para sair: " << endl;
    cin >> valor;
    while (valor > 0)
    {
        if (consulta(tree, valor))
            cout << "Valor encontrado " << endl;
        else
            cout << "Valor NÃO encontrado " << endl;

        cout << "Numero de comparacoes: " << consultaComp(tree, valor, 0) << endl;
        cout << "Digite um valor positivo a ser procurado ou zero e negativo para sair: " << endl;
        cin >> valor;
    }
    return 0;
}