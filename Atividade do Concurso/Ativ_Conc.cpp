//Nome: Leandro de Jesus Luna        --RM: 86492
//Nome: Pedro Fernandees             --RM: 84244
//Nome: Pedro Enrique Pereira Velosa --RM: 84591
//Nome: Rafael Procopio Bondezam     --RM: 84346
//Nome: Fabbio Augusto de Souza      --RM: 84695

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

#define limite 8
int main(){
    char URL[limite][127], cpf[limite][20];
    float avaliador1[limite], avaliador2[limite],avaliador3[limite], media[limite], maior_media = 0;
    int projetos, x, y=0, projetos_minerva[limite], vencedor_minerva;
    bool repetir=true;

    while(repetir == true){
    cout << "Numeros de participantes do concurso (maximo 8): ";
    cin >> projetos;
    if(projetos > limite || projetos < 1){
        cout << "Numero de participantes invalido. Maximo de participantes 8 e minimo 1." << endl;
    }
    else{
        repetir = false;
        system("cls");
    }
    }
    for(x=0; x < projetos; x++){
        cout << "Informe o CPF do " << x+1 << "o participante: ";
        cin.sync();
        cin.getline(cpf[x], 20);
        cout << "Informe a URL do projeto do " << x+1 << "o participante: ";
        cin.sync();
        cin.getline(URL[x], 127);
        system("cls");
    }
    system("cls");
    cout << "Todos os projetos foram cadastrados com sucesso. Iniciando julgamento dos projetos.." << endl;
    for(x=0; x < projetos; x++){
        cout << "\nProjeto numero: '" << x+1 << "'. Candidato '"<< cpf[x] <<"', URL: '" << URL[x] << "'" << endl;
        cout << "-----APURACAO DAS NOTAS-----" << endl;
        cout << "Jurado 1. NOTA: ";
        cin >> avaliador1[x];
        cout << "Jurado 2. NOTA: ";
        cin >> avaliador2[x];
        cout << "Jurado 3. NOTA: ";
        cin >> avaliador3[x];
        media[x] = (avaliador1[x]+avaliador2[x]+avaliador3[x])/3;
        cout << "Media final do projeto " << x+1 << ": " << media[x] << endl;
    }
    system("cls");
    cout << "Todas a apuracao ja foi realizada. Anunciando vencedores.." << endl;

    for(x = 0; x < projetos; x++){
        if(maior_media < media[x]){
            maior_media = media[x];
        }
    }
    
    for(x=0; x < projetos; x++){
        if(maior_media == media[x]){
            projetos_minerva[y] = x;
            y++;
        }
    }
    
    if(y == 1){
        cout << "Maior media: " << maior_media 
             << "\n*****O GRANDE VENCEDOR E' O PROJETO NUMERO " << projetos_minerva[0]+1 << "!!!*****"
             << "\nCPF DO CAMPEAO: " << cpf[projetos_minerva[0]]
             << "\nURL DO PROJETO: " << URL[projetos_minerva[0]] << endl;
    }
    else{
        cout << "Maiores medias: " << maior_media
             << "\nProjetos com as maiores notas iguais para a decisao final: "<< endl;
        for(x=0; x < y; x++){
            cout << "***************************************************"
                 << "\nProjeto numero: " << projetos_minerva[x]+1
                 << "\nCPF: " << cpf[projetos_minerva[x]]
                 << "\nURL: " << URL[projetos_minerva[x]] << endl;
        }
        cout << "***************************************************"
             << "\nVOTO MINERVA! Informe o numero do projeto para o desempate: ";
        cin >> vencedor_minerva;
        system("cls");
        cout << "*****O GRANDE VENCEDOR APOS O VOTO DO ORGANIZADOR E' O PROJETO NUMERO " << vencedor_minerva << "!!!*****"
             << "\nCPF DO CAMPEAO: " << cpf[vencedor_minerva-1]
             << "\nURL DO PROJETO: " << URL[vencedor_minerva-1] << endl;
    }
}
