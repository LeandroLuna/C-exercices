#include <iostream>
#include<locale>
#include <stdlib.h>
using namespace std;

int main() {
    setlocale(LC_ALL,"");
    float *pont;

    pont = (float*) malloc(sizeof(float));

    if (pont == NULL)
        cout << "N�o foi poss�vel alocar espa�o requisitado \n";
    else{
        cout <<"sizeof float: " << sizeof(float) <<endl;
        cout << "digite n�mero real: ";
        cin >> *pont;
        cout <<"Apresenta��o do dado armazenado na regi�o = " << *pont;
        free(pont);
        }
    return 0;
}
