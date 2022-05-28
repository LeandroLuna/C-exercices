#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int predios[5][4], menor, aps_caros[5], caro, z=0;
    int i, j;

    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            cout << "Informe o valor do apartamento '" << j << "' do andar '" << i << "': ";
            cin >> predios[i][j];
        }        
    }
    menor = predios[0][0];
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            if(menor > predios[i][j]){
                menor = predios[i][j];
            }
        }        
    }
    
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            if(aps_caros[i] < predios[i][j]){
                aps_caros[i] = predios[i][j];
            }
        }
    }

    caro = aps_caros[0];
    for(i = 1; i<5; i++){
        if(caro < aps_caros[i]){
            caro = aps_caros[i];
            z++;
        } 
    }

    cout << "Andar com predio de maior valor: " << z << endl;
    cout << "Apartamento de menor valor: " << menor; 
}