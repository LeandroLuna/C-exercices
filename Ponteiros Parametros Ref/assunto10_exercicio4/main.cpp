#include <iostream>

using namespace std;

struct Aluno{
    char nome[30];
    float nota1, nota2, media;
};

typedef struct Aluno TipoAluno;

void leitura(TipoAluno *p_aluno){
    cout << "Digite nome do aluno: ";
    cin.getline(p_aluno->nome, 30);
    cout << "Digite primeira nota do aluno: ";
    cin >> p_aluno->nota1;
    cout << "Digite segunda nota do aluno: ";
    cin >> p_aluno->nota2;
}

void calcula_media(TipoAluno *p_aluno){
    p_aluno->media = (p_aluno->nota1 + p_aluno->nota2)/2;
}

void imprime(TipoAluno aluno){
      cout << "Nome: " << aluno.nome <<" nota1: " << aluno.nota1 << " nota2: "
      << aluno.nota2 << " media: " << aluno.media << endl;
}

int main(){
    TipoAluno aluno;
    leitura(&aluno);
    calcula_media(&aluno);
    imprime(aluno);
    return 0;
}














/*int main(){
    TipoAluno aluno;
    char resp;
    do{
        leitura(&aluno);
        calcula_media(&aluno);
        imprime(aluno);
        cout << "Há outro aluno na turma? (S/N): ";
        cin >> resp;
        cin.ignore();
    } while (resp == 's' || resp == 'S');
    return 0;
}
*/
