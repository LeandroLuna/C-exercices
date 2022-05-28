#include <iostream>
#include <cstring>
#define N_CONV 4
#define chars 15

int main()
{
    char convidados[N_CONV][chars];
    int i;

    for (i = 0; i < N_CONV; i++)
    {
        std::cout << "Nome do convidado: ";
        std::cin.getline(convidados[i], chars);
    }
    std::cout << "Nome do 2 convidado: " << convidados[1] << std::endl;
    return 0;
}