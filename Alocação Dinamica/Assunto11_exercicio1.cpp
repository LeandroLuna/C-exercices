#include <iostream>
#include<locale>
#include <stdlib.h>
using namespace std;

int main() {
    setlocale(LC_ALL,"");
    float *pont;

    pont = (float*) malloc(sizeof(float));

    if (pont == NULL)
        cout << "Não foi possível alocar espaço requisitado \n";
    else{
        cout <<"sizeof float: " << sizeof(float) <<endl;
        cout << "digite número real: ";
        cin >> *pont;
        cout <<"Apresentação do dado armazenado na região = " << *pont;
        free(pont);
        }
    return 0;
}
