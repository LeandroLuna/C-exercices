#include <iostream>
#include <locale.h>

using namespace std;

#include <stdlib.h>

#define NC 19 // n�mero de caracteres para armazenar as coordenadas

struct Boia
{
    int hashcode;
    char coordenada[NC];
    float temperatura;
    float salinidade;
    int alerta;
};
typedef struct Boia TipoBoia;

/* ********TAREFA 1 *************/
#include "TipoFilaCoordenadas.h"

/* ********TAREFA 2 *************/
#include "TipoABB_Boia.h"

void geraFila(TipoArvore p, TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim)
{
    if (p != NULL)
    {
        if (p->dado.alerta)
        {
            enqueue(ini, fim, p->dado.coordenada);
            p->dado.alerta = 0;
        }
        if (p->esq != NULL)
            geraFila(p->esq, ini, fim);
        if (p->dir != NULL)
            geraFila(p->dir, ini, fim);
    }
}

int main()
{
    setlocale(LC_ALL, "");
    TipoArvore tree;
    tree = NULL;
    TipoFilaCoordenadas ini, fim;
    int opcao;
    init(&ini, &fim);
    TipoBoia s;
    char hashcode[5];
    char coord[NC];
    int i, hashcodeInt;

    char hc[9][NC] = {"-23.50°-45.21°", "-25.02°-47.93°", "-22.90°-43.17°", "-24.90°-42.17°", "-25.10°-44.17°", "-22.40°-39.04°",
                      "-24.40°-36.92°", "-26.89°-44.07°", "-27.99°-46.17°"};
    cout << "\nIniciando o cadastramento de 9 boias ja existentes...\n";
    for (i = 0; i < 9; i++)
    {
        cout << endl;
        hashcode[0] = hc[i][1];
        hashcode[1] = hc[i][2];
        hashcode[2] = hc[i][9];
        hashcode[3] = hc[i][10];
        hashcode[4] = '\0';
        hashcodeInt = atoi(hashcode);
        cout << hc[i] << " salinidade: ";
        cin >> s.salinidade;
        cout << hc[i] << " temperatura: ";
        cin >> s.temperatura;
        strcpy(s.coordenada, hc[i]);
        s.hashcode = hashcodeInt;
        s.alerta = 0;
        insere(&tree, s);
    }
    do
    {
        cout << endl;
        cout << " 1- inserir mais 1 boia \n 2- Lista Ordem Descrescente  \n 3- Atualiza Medidas\n";
        cout << " 4- Inicia visita aos locais \n 5- Consulta medidas de 1 boia  \n 0- Sair\n";
        cin >> opcao;
        cin.ignore();
        switch (opcao)
        {
        case 0:
            cout << "******** Sistema de Monitoramento Encerrando ***************" << endl;
            break;
        case 1:
            cout << " Digite coordenadas da boia a ser inserida no sistema (formato: -xx.xx°-xx.xx°): "; //Desconsiderar o caracter 'A' acompanhado do °.
            cin.getline(coord, NC);
            hashcode[0] = coord[1];
            hashcode[1] = coord[2];
            hashcode[2] = coord[8];
            hashcode[3] = coord[9];
            hashcode[4] = '\0';
            hashcodeInt = atoi(hashcode);
            cout << "salinidade: ";
            cin >> s.salinidade;
            cout << "temperatura: ";
            cin >> s.temperatura;
            strcpy(s.coordenada, coord);
            s.hashcode = hashcodeInt;
            s.alerta = 0;
            insere(&tree, s);
            cout << "Boia de coordenada '" << coord
                 << "' inserida com sucesso!" << endl;
            break;
        case 2:
            cout << "\n******************* Lista Ordem Descrescente **********" << endl;
            lista_em_ordemD(tree);
            cout << "*********************************************************" << endl;
            break;
        case 3:
            atualizaMedidas(tree);
            cout << "Gera uma fila com as coordenadas das boias \n";
            geraFila(tree, &ini, &fim);
            break;
        case 4:
            cout << "\nInicia visita dos locais com coordenadas na fila \n";

            if (isEmpty(ini, fim))
                cout << "Nao foi ainda gerada fila de locais\n";
            else
            {
                while (dequeue(&ini, &fim, coord))
                {
                    cout << "Coordenadas da boia visitada: " << coord << endl;
                }
            }
            break;
        case 5:
            cout << "\nhash code \t Coordenada\n";
            lista_em_ordemD(tree);
            cout << "escolha o hash code do sensor que deseja consultar as ultimas medidas do solo: ";
            cin >> hashcodeInt;
            if (!consulta(tree, hashcodeInt))
            {
                cout << "Nao ha sensor identificado com esse codigo.\n";
            }
            break;
        default:
            cout << "Opcao invalida\n";
        }
    } while (opcao != 0);

    return 0;
}
