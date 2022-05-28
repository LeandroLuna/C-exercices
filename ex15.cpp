#include <iostream>
#include <string.h>
using namespace std;

#define x 15
#define max 2000
struct client
{
    char nome[x], endereco[x], cpf[x];
    int numero_conta, ano_abertura;
    float saldo;
};
typedef struct client clientela;

int main()
{
    clientela clients[max];
    int j = 0, z, antigos = 0, negativados = 0;
    char i, vagabundo[x];

    do
    {
        cout << "Nome do cliente: ";
        cin.getline(clients[j].nome, x);
        cout << "Endereco: ";
        cin.getline(clients[j].endereco, x);
        cout << "CPF: ";
        cin.getline(clients[j].cpf, x);
        cout << "Numero da conta: ";
        cin >> clients[j].numero_conta;
        cout << "Ano de abertura da conta: ";
        cin >> clients[j].ano_abertura;
        cout << "Saldo: ";
        cin >> clients[j].saldo;
        j++;
        cout << "Quer registra mais 1? s ou n: ";
        cin >> i;
        cin.ignore();
    } while (i == 's' && j < max);

    for (z = 0; z < j; z++)
    {
        cout << "\n\n****************************" << endl;
        cout << "**\t Informacoes do Cliente " << z << ":" << endl;
        cout << "**\t Nome: " << clients[z].nome << endl;
        cout << "**\t CPF: " << clients[z].cpf << endl;
        cout << "**\t Endereco: " << clients[z].endereco << endl;
        cout << "**\t Numero da Conta: " << clients[z].numero_conta << endl;
        cout << "**\t Ano de Abertura: " << clients[z].ano_abertura << endl;
        cout << "**\t Saldo: " << clients[z].saldo << endl;
        cout << "**********************************\n\n\n";
    }

    for (z = 0; z < j; z++)
    {
        if (clients[z].ano_abertura <= 2011)
        {
            antigos++;
        }
    }
    cout << "Numero de clientes que abriram conta a mais de 10 anos: " << antigos << endl;

    negativados = 0;
    for (z = 0; z < j; z++)
    {
        if (clients[z].saldo < 0)
        {
            negativados++;
        }
    }
    cout << "Numero de clientes com saldo negativo: " << negativados << endl;

    cout << "CPF do meliante: ";
    cin.getline(vagabundo, x);

    z = 0;
    while (strcmp(vagabundo, clients[z].cpf) != 0 && z < max)
    {
        z++;
    }
    if (z < max)
    {
        cout << "\n\n****************************" << endl;
        cout << "**\t Informacoes do Cliente " << z << ":" << endl;
        cout << "**\t Nome: " << clients[z].nome << endl;
        cout << "**\t CPF: " << clients[z].cpf << endl;
        cout << "**\t Endereco: " << clients[z].endereco << endl;
        cout << "**\t Numero da Conta: " << clients[z].numero_conta << endl;
        cout << "**\t Ano de Abertura: " << clients[z].ano_abertura << endl;
        cout << "**\t Saldo: " << clients[z].saldo << endl;
        cout << "**********************************\n\n\n";
    }
    else{
        cout << "Cliente nao encontrado \n";
    }
}