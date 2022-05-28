//Nome: Leandro de Jesus Luna        --RM: 86492
//Nome: Pedro Fernandees             --RM: 84244
//Nome: Pedro Enrique Pereira Velosa --RM: 84591
//Nome: Rafael Procopio Bondezam     --RM: 84346
//Nome: Fabbio Augusto de Souza      --RM: 84695

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

#define NC 50 // Maximo de caracteres

struct reg1
{ // estrutura dos componentes
    char nome[NC];
    int cpf;
};
typedef struct reg1 comp;

struct reg // estrutura dos projetos
{
    char projeto[NC], url[NC];
    int investimento;
    float nota1, nota2, nota3, media;
    comp componentes[4];
};
typedef struct reg proj;

int vencedor(proj vencedor[], int v)
{
    v--;
    cout << v;
    cout << "\n\nO grande vencedor e' o projeto '" << vencedor[v].projeto << "' !!!"
         << "\nLink do projeto: " << vencedor[v].url
         << "\nInvestimento: R$" << vencedor[v].investimento
         << "\nNota concebida pelo jurado 1: " << vencedor[v].nota1
         << "\nNota concebida pelo jurado 2: " << vencedor[v].nota2
         << "\nNota concebida pelo jurado 3: " << vencedor[v].nota3
         << "\nMedia Final: " << vencedor[v].media;
    for (int x = 0; x < 4; x++)
    {
        cout << "\nComponente " << x + 1 << ": " << vencedor[v].componentes[x].nome << " || CPF: " << vencedor[v].componentes[x].cpf;
    }
}

int main()
{
    proj projetos[10], minerva[10], aux_bubble;
    int qtd_projetos, x, y, qtd_membros, z, i;
    bool repetir = true, bubble;
    float maior_media = 0;

    while (repetir == true)
    {
        cout << "Numeros de participantes do concurso (maximo 10): "; // Cadastra o numero de projetos do concurso (maximo 10)
        cin >> qtd_projetos;
        cin.sync();
        if (qtd_projetos > 10 || qtd_projetos < 1)
        {
            cout << "Numero de participantes invalido. Maximo de participantes 10 e minimo 1." << endl;
        }
        else
        {
            repetir = false;
            system("cls");
        }
    }
    system("cls");

    cout << "Cadastrando os projetos.." << endl;
    for (y = 0; y < qtd_projetos; y++) // Insere as informacoes de cada um dos projetos
    {
        cout << "Titulo do projeto " << y + 1 << ": ";
        cin.sync();
        cin.getline(projetos[y].projeto, NC);
        cout << "URL do projeto " << y + 1 << ": ";
        cin.sync();
        cin.getline(projetos[y].url, NC);
        cout << "Investimento solicitado do projeto " << y + 1 << ": ";
        cin.sync();
        cin >> projetos[y].investimento;
        repetir = true;
        while (repetir == true)
        {
            cout << "Quantos componentes tem equipe " << y + 1 << "? (max. 4) "; // Insere a quantidade de componentes para cada projeto
            cin >> qtd_membros;
            if (qtd_membros > 4 || qtd_membros < 1)
            {
                cout << "Numero de componentes invalido. Maximo de componentes 4 e minimo 1." << endl;
            }
            else
            {
                repetir = false;
            }
        }
        for (x = 0; x < qtd_membros; x++) // Informacoes dos componentes
        {
            cout << "Nome do componente " << x + 1 << ": ";
            cin.sync();
            cin.getline(projetos[y].componentes[x].nome, NC);
            cout << "CPF do componente " << x + 1 << ": ";
            cin.sync();
            cin >> projetos[y].componentes[x].cpf;
        }
        for (qtd_membros; qtd_membros < 4; qtd_membros++)
        { // Caso o projeto tenha menos de 4 componentes: CPF = 0; NOME = " " (vazio)
            strcpy(projetos[y].componentes[qtd_membros].nome, "");
            projetos[y].componentes[qtd_membros].cpf = 0;
        }
        system("cls");
    }

    cout << "Iniciando julgamento dos projetos.." << endl;
    x = 0;
    do
    {
        cout << "\n-Projeto " << x + 1 << ": " << projetos[x].projeto; // Notas de cada avaliador para cada projeto. Nao foi peço para limitar a nota dos avaliadores, por isso não considerarei.
        cout << "\nNota do avaliador 1: ";
        cin >> projetos[x].nota1;
        cout << "Nota do avaliador 2: ";
        cin >> projetos[x].nota2;
        cout << "Nota do avaliador 3: ";
        cin >> projetos[x].nota3;
        projetos[x].media = (projetos[x].nota1 + projetos[x].nota2 + projetos[x].nota3) / 3; // Calculo da media para cada projeto
        x++;
    } while (x < qtd_projetos);
    system("cls");

    cout << "\nInformacoes dos projetos antes da ordenacao.." << endl; // Listagem da media e o nome de cada projeto antes da ordenacao bubble
    for (x = 0; x < qtd_projetos; x++)
    {
        cout << "Projeto " << x + 1 << ": '" << projetos[x].projeto
             << "' || Media: " << projetos[x].media
             << " || Investimento solicitado: R$" << projetos[x].investimento << endl;
    }

    bubble = true;
    for (x = 0; x < qtd_projetos && bubble == true; x++)
    { // Algoritmo Bubble Sort em ordem crescente, como criterio o 'valor solicitado'
        bubble = false;
        for (i = 0; i < qtd_projetos - 1; i++)
        {
            if (projetos[i].investimento > projetos[i + 1].iex
                aux_bubble = projetos[i];
                projetos[i] = projetos[i + 1];
                projetos[i + 1] = aux_bubble;
                bubble = true;
        }
    }
}

for (x = 0; x < 5; x++)
{ // Soma de 0.5 pontos aos 5 primeiros projetos
    if (projetos[x].media < 10)
    {
        projetos[x].media += 0.5;
        if (projetos[x].media > 10)
        { // limite de 10 pontos
            projetos[x].media = 10;
        }
    }
}

cout << "\n----------------------------------------------\n"
     << "\nInformacoes dos projetos depois da ordenacao, e a media dos 5 primeiros projetos somada a 0.5pts..." << endl; // Apresentacao das informacoes pos ordenacao
for (x = 0; x < qtd_projetos; x++)
{
    cout << "Projeto " << x + 1 << ": '" << projetos[x].projeto
         << "' || Media: " << projetos[x].media
         << " || Investimento solicitado: R$" << projetos[x].investimento << endl;
}

cout << "\n\nIniciando a apuracao dos vencedores..." << endl; // Armazena a maior media para definir o vencedor
for (x = 0; x < qtd_projetos; x++)
{
    if (maior_media < projetos[x].media)
    {
        maior_media = projetos[x].media;
    }
}

y = 0;
for (x = 0; x < qtd_projetos; x++)
{ // Compara o numero de projetos que tem a 'maior media'
    if (maior_media == projetos[x].media)
    {
        minerva[y] = projetos[x];
        y++;
    }
}

if (y == 1)
{ // Caso somente tenha um projeto com a maior media
    //system("cls");
    vencedor(minerva, y);
}
else
{ // Desempate dos projetos com a maior media
    cout << "Ha um empate entre os participantes!!\nIniciando voto minerva..." << endl;
    cout << "\nListas dos " << y << " projetos com a media maxima '" << maior_media << "':" << endl;
    for (x = 0; x < y; x++)
    { // Projetos empatados
        cout << "Nome do projeto " << x + 1 << ": " << minerva[x].projeto << " || URL: " << minerva[x].url << endl;
    }
    cout << "\nInforme o numero do projeto escolhido: "; // Voto minerva
    cin >> z;
    //system("cls");
    vencedor(minerva, z);
}
return 0;
}
