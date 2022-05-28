#include <iostream>
using namespace std;

#define x 15

struct client{
    char nome[x], endereco[x], cpf[x];
    int numero_conta[x], ano_abertura[x];
    float saldo[x];  
};

typedef struct client clientela;
int main(){
    clientela les_clients; 
    cout << "Nome do cliente: ";
    cin.getline(les_clients.nome, x);
    cout << "Endereco: ";
    cin.getline(les_clients.endereco, x);
    cout << "CPF: ";
    cin.getline(les_clients.cpf, x);
    cout << "Numero da conta: ";
    cin >> les_clients.numero_conta[x];
    cout << "Ano de abertura da conta: ";
    cin >> les_clients.ano_abertura[x];
    cout << "Saldo: ";
    cin >> les_clients.saldo[x];

    cout << les_clients.nome << endl
         << les_clients.endereco << endl
         << les_clients.cpf << endl
         << les_clients.numero_conta[x] << endl
         << les_clients.ano_abertura[x] << endl
         << les_clients.saldo[x] << endl;
}
