#include <iostream>
using namespace std;

float media_peso(float x, float y){
    return((x*0.4+y*0.6)/2);
}

char conceito(int x){
    if(x >= 8.5){
        return('E');
    }
    else if(x > 5 && x < 8.5){
        return('B');
    }
    else{
        return('R');
    }
}

int main(){
    float a, b, medias[3];
    int z;
    
    for(z=0; z<4; z++){
        cout << "Informe a primeira nota do aluno " << z+1 << ": ";
        cin >> a;
        cout << "Informe a segunda nota do aluno " << z+1 << ": ";
        cin >> b;
        medias[z] = media_peso(a,b);
    }
    system("cls");
    for(z=0; z<4; z++){
    cout << "Media do aluno " << z+1 << ": " << medias[z] << " || " << "Conceito do aluno: " << conceito(medias[z]) << endl; 
    }
    return 0;
}