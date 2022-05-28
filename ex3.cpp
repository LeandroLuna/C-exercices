#include <iostream>
using namespace std;

int main()
{
    int filhos, pobreza = 0, habitantes = 0;
    float salario, percentual, media, maior_salario = 0, media_filhos = 0;

    cout << "Informe o salario: ";
    cin >> salario;
    while (salario > 0)
    {
        cout << "Numero de filhos: ";
        cin >> filhos;
        if (filhos >= 0)
        {
            media_filhos = media_filhos + filhos;
            habitantes++;
            media = media + salario;

            if (salario > maior_salario)
                maior_salario = salario;

            if (salario < 500)
                pobreza++;

            cout << "Salario do cidadao: ";
            cin >> salario;
        }
        else
        {
            cout << "Numero de filhos nao pode ser menor que 0." << endl;
        }
    }
    if (habitantes > 0)
    {
        cout << "\nMedia de salario: " << media / habitantes;
        cout << "\nMedia de filhos: " << media_filhos / habitantes;
        cout << "\nMaior salario: " << maior_salario;
        cout << "\nPercentual de pessoas com salario ate R$500: " << (float)pobreza / habitantes * 100 << "%" << endl;
    }
    return 0;
}
