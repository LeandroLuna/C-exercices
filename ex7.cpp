#include <iostream>
#include <cstring>
#define N 15
using namespace std;

int main()
{
    char str1[N] = "Linguagem", str2[N] = " C";
    strcat(str1, str2);
    cout << "Palavras concatenadas: " << str1 << endl;
    return 0;
}
