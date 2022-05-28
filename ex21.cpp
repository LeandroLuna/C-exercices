#include <iostream>
using namespace std;

void dobro_metade(int n, int *dobro, float *metade) // *dobro = conteúdo de dobro; *metade = conteúdo de metade
{
    *dobro = n + n;
    *metade = n / 2.0; // Para gerar o resultado correto, a expressão deve ser avaliada como ''float''. Isso pode ser obtido de duas formas:
    //adicionando um elemento neutro de tipo ''float'' à expressão;
    //forçando a avaliação de ''n'' ou ''2'' como float.
}

int main()
{
    int x = 17, d;
    float m;
    dobro_metade(x, &d, &m); // &d = endereço na memoria de d; &m = endereço na memoria de m
    cout << "O dobro de " << x << " eh " << d << " e a metade eh " << m << "." << endl;
    return 0;
}