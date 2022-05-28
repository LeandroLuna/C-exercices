#include <iostream>
#include <locale>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct dados_cidadao
{
    int cpf;
    char servico_solicitado[10], documentacao[15];
} typedef dados_do_cidadao;

struct cidadao
{
    dados_do_cidadao dados;
    struct cidadao *prox;
};
typedef struct cidadao *StructCidadao;

void init(StructCidadao *ini, StructCidadao *fim)
{
    *ini = NULL;
    *fim = NULL;
}

int isEmpty(StructCidadao ini, StructCidadao fim)
{
    if ((ini == NULL) && (fim == NULL))
        return (1);
    else
        return (0);
}

void enqueue(StructCidadao *ini, StructCidadao *fim)
{
    StructCidadao novo;

    novo = (StructCidadao)malloc(sizeof(struct cidadao));
    if (novo == NULL)
        cout << "Fila Cheia \n";
    else
    {
        cout << "CPF do cliente: ";
        cin >> novo->dados.cpf;
        cout << "Servico solicitado (RG, CPF OU CNH): ";
        cin.sync();
        cin.getline(novo->dados.servico_solicitado, 10);
        system("cls");

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

void enqueue_pendente(StructCidadao *ini, StructCidadao *fim, dados_do_cidadao *cidadao)
{
    StructCidadao novo;
    novo = (StructCidadao)malloc(sizeof(struct cidadao));
    if (novo == NULL)
        cout << "Fila Cheia \n";
    else
    {
        novo->dados = *cidadao;
        novo->prox = 0;
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

int dequeue(StructCidadao *ini, StructCidadao *fim, dados_do_cidadao *cidadao)
{
    StructCidadao aux = *ini;
    if (isEmpty(*ini, *fim))
        return 0;
    else
    {
        aux->dados.documentacao[15] = cidadao->documentacao[15];
        *cidadao = aux->dados;
        *ini = aux->prox;
        if (*ini == NULL)
            *fim = NULL;
        free(aux);
        return 1;
    }
}