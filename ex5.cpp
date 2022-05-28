#include <iostream>
using namespace std;
#define i 10

int main()
{
    float saldos[i];
    int N, negativo = 0;

    for (N = 0; N < i; N++)
    {
        cout << "Digite o valor da sua conta: ";
        cin >> saldos[N];
    }
    cout << "\nSaldos positivos sao: " << endl;
    for (N = 0; N < i; N++)
    {
        if (saldos[N] > 0)
            cout << saldos[N] << ", ";
        else
            negativo++;
    }
    cout << "\nNumero de clientes no negativo: " << negativo << endl;
}
