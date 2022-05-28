#include <iostream>
#include <cstring>
#include "C:\Users\leand\OneDrive\Área de Trabalho\Programming\Exercicios C++\Atividade da Fila\ex26.h"

using namespace std;

#define MAX 15
struct rotulo // declaração do formato do registro "rotulo"
{
    int x;
    float y;
    char nome[MAX];
};
typedef struct rotulo Tipo_Exemplo2; // definição de um novo tipo, de estrutura "rotulo" declarada anteriormente

int main()
{
    Tipo_Exemplo2 qlq = {1, 2.35, "Primeiro"}; // podesse atribuir valores, respectivamente, a cada tipo de dado declarado no registro
    cout << " x= " << qlq.x << "\t y= " << qlq.y << "\t n= " << qlq.nome << endl;
    qlq.y = 3.14; // altera o valor do campo "y" da variavel "qlq" do tipo "tipo_exemplo2"
    qlq.x = 0;
    strcpy(qlq.nome, "Segundo");
    cout << " x= " << qlq.x << "\t y= " << qlq.y << "\t n= " << qlq.nome << endl;
    return 0;
}
