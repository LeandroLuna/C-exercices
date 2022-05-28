#include <iostream>
using namespace std;
#include <string.h>

#define x 5
#define limite 20

struct agenda
{
    char nome[limite], endereco[limite];
    int telefone;
};
typedef struct agenda agendamento;

int main()
{
    agendamento agendas[x];
    int z, y = 0, m, telefone;
    bool menu = true, registrado;
    char nome[limite];

    cout << "Quantas pessoas voce quer cadastrar? ";
    cin >> z;

    for (y; y < z; y++)
    {
        cin.ignore();
        cout << "Informe o nome do guerreiro: ";
        cin.getline(agendas[y].nome, limite);
        cout << "Informe o endereco: ";
        cin.getline(agendas[y].endereco, limite);
        cout << "Informe o telefone do vagabundo: ";
        cin >> agendas[y].telefone;
        system("cls");
    }
    system("cls");
    cout << "Apresentando menu: " << endl;
    do
    {
        registrado = false;
        cout << "1) Procurar contato usando o telefone"
             << "\n2) Procurar contato usando o nome"
             << "\n3) Encerrar programa" << endl;
        cout << "Informe a opcao desejada: ";
        cin >> m;
        cin.ignore();
    
        if (m == 1)
        {
            system("cls");
            cout << "Informe o telefone a ser procurado: ";
            cin >> telefone;
            system("cls");
            cout << "Numero a ser procurado '" << telefone << "'." << endl;
            for (y=0; y < z; y++)
            {
                if (telefone == agendas[y].telefone)
                {
                    cout << "********************************"
                         << "\nNome: " << agendas[y].nome
                         << "\nEndereco: " << agendas[y].endereco << endl;
                    registrado = true;
                }
            }
            if (registrado != true)
            {
                cout << "Numero informado nao encontrado." << endl;
            }
        }
        else if (m == 2)
        {
            system("cls");
            cout << "Informe o nome a ser procurado: ";
            cin.getline(nome, limite);
            system("cls");
            cout << "Nome a ser procurado '" << nome << "'." << endl;
            for (y=0; y < z; y++)
            {
                if (strcmp(nome, agendas[y].nome) == 0)
                {
                    cout << "********************************"
                         << "\nTelefone: " << agendas[y].telefone
                         << "\nEndereco: " << agendas[y].endereco << endl;
                    registrado = true;
                }
            }
            if (registrado != true)
            {
                cout << "Nome informado nao encontrado." << endl;
            }
        }
        else
        {
            system("cls");
            cout << "Encerrando programa........";
            menu = false;
        }

    } while (menu == true);
    return 0;
}