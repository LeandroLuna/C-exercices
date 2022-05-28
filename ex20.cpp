#include <iostream>
using namespace std;

void delta(char x) // nao retorna nenhum valor
{
    cout << x;
}
int main()
{
    int vetor[5] = {1, 2, 3, 4, 5};
    //char z='funcao retorna nada';
    //delta(z); // funcao não pode ser designada a nada

    for (int x = 0; x < 5; x++)
    {
        cout << "Antes: " << vetor[x] << "|| Depois: ";
        vetor[x] += 2;
        cout << vetor[x] << "\n\n";
    }
    return 0;
}

bool alteracao = true;
void bubbleSort(int vetor[], int n)
{ // vetor a ser ordenado e quantidade de elementos
    for (int x = 0; x < n && alteracao == true; x++)
    {
        alteracao = false;
        for (int x = 0; x < n - 1; x++)
        {
            if (vetor[x] > vetor[x + 1])
            {                             //ORDEM CRESCENTE
                int aux_vetor = vetor[x]; // variavel auxiliar para armazenar as informações de vetor[x] antes de serem subscritas
                vetor[x] = vetor[x + 1];
                vetor[x + 1] = aux_vetor;
                alteracao = true;
            }
        }
    }
}