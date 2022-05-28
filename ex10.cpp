#include <iostream>
#include <cstring>
#define N_CONV 4
#define chars 15

int main()
{
    char convidados[N_CONV][chars];
    int i = 1;
    while (i == 1)
    {
        std::cout << "Nome do convidado: ";
        std::cin.getline(convidados[0], chars);
        std::cout << "Nome inserido: " << convidados[0] << std::endl;
    }
    return 0;
}