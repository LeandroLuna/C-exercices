//Nome: Leandro de Jesus Luna        --RM: 86492
//Nome: Pedro Fernandees             --RM: 84244
//Nome: Rafael Procopio Bondezam     --RM: 84346
//Nome: Fabbio Augusto de Souza      --RM: 84695

#include <iostream>
#include <locale>
#include <stdlib.h>
#include <string.h>
using namespace std;
// #include "TipoFilaCidadao.h"

struct dados_cidadao
{
    int cpf;
    char servico_solicitado[10], documentacao[15];
} typedef dados_do_cidadao;

struct Processo
{
    int pid;
    char owner[10];
};
typedef struct Processo TipoProcesso;

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

int main()
{
    StructCidadao ini, fim;
    dados_do_cidadao data;
    int menu = 1, menu_inicial, posicao = 0;
    init(&ini, &fim);

    while (menu == 1)
    {
        cout << "\nEscolha uma das opcoes a seguir:\n\n\t1) Chegada do Cidadao\n\t2) Atendimento\n\t3) Encerra o atendimento\n\nOpcao desejada: ";
        cin >> menu_inicial;

        switch (menu_inicial)
        {
        case 1:
            system("cls");
            enqueue(&ini, &fim);
            break;
        case 2:
            system("cls");

            if (dequeue(&ini, &fim, &data) == 0)
            {
                cout << "Fila vazia" << endl;
            }
            else
            {
                posicao = posicao + 1;
                cout << "Qual o status dos documentos do cidadao de posicao '" << posicao << "': \n\tCompleto\n\tPendente\n\tIncompleto\nOpcao desejada: ";
                cin.sync();
                cin.getline(data.documentacao, 15);
                cout << "CPF: " << data.cpf << endl;
                cout << "Tipo de servico: " << data.servico_solicitado << endl;
                if (strcmp(data.documentacao, "Pendente") == 0)
                {
                    cout << "Documentacao: " << data.documentacao << endl;
                    enqueue_pendente(&ini, &fim, &data);
                }
                else
                {
                    cout << "Documentacao: " << data.documentacao << endl;
                }
            }
            break;
        case 3:
            system("cls");
            if (isEmpty(ini, fim) == 1)
            {
                cout << "Saindo do menu. Parando o programa..";
                menu = 0;
            }
            else
            {
                cout << "Nao pode sair do menu. Ainda ha gente a ser atendida! Retornando ao menu principal.." << endl;
            }
            break;

        default:
            cout << "Opcao invalida.";
            break;
        }
    };
}