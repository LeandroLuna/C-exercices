/*********************************************

Leandro de Jesus Luna - RM86492
Pedro Fernandes - RM84244
Pedro Enrique Pereira Velosa - RM84591
Rafael Procópio Bondezam - RM84346
Fabbio Augusto de Souza - RM84695

**********************************************/
#include <iostream>
#include <locale>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

#define N_Clientes 100 //numero de clientes maximo da clinica
#define N_MED 48       //numero de medidas registradas por dia
#define NC 20          //numero de caracteres das strings usadas no programa
#define NC_LINHA 80
#define NC_SN 4 //numero de caracteres das strings de resposta sim e nao

struct cliente
{
  char id[NC], sexo[NC], hipertensao[NC_SN], diabetes[NC_SN];
  int idade;
};
typedef struct cliente TipoCliente;

struct medida
{
  char hora[NC];
  int sistole, diastole, frequencia, glicemia;
};
typedef struct medida TipoMedida;

int busca_paciente(struct cliente pacientes[], int numero_pacientes, char ID[])
{
  int i_baixo = 0, i_alto = numero_pacientes - 1, i_medio, achou = 0, pos = -1, chave = atoi(ID), comp[numero_pacientes];
  
  for (int i = 0; i < numero_pacientes; i++) // o ideal é deixar esse laço for fora da função, e passar como parametro o valor ja convertido. Mas não quero mexer no escopo principal da atividade. 
  {
    comp[i] = atoi(pacientes[i].id); // nao é possivel comparar a diferença de valores numericos com strings, por isso é necessarios converte-los para int.
  }

  while (achou != 1 && i_baixo <= i_alto)
  {
    i_medio = (i_baixo + i_alto) / 2;
    if (chave == comp[i_medio])
    {
      pos = i_medio;
      achou = 1;
    }
    else
    {
      if (chave < comp[i_medio])
      {
        i_alto = i_medio - 1;
      }
      else
      {
        i_baixo = i_medio + 1;
      }
    }
  }
  return (pos);
}

int medidas_glicose(struct medida indicadores[], int numero_medicoes, int glicose){
  cout << "Picos de glicemia '"<< glicose << "':" << endl;
  for(int i=0; i < numero_medicoes; i++){
    if(glicose == indicadores[i].glicemia){
      cout << "Horario: " << indicadores[i].hora << " || Sistole(mmHg): " << indicadores[i].sistole << " || Diastole(mmHg): " << indicadores[i].diastole
      << " || Pulsacao(bat/min): " << indicadores[i].frequencia << " || Glicose (mg/dL): " << indicadores[i].glicemia << endl;
    }
  }
}

int ordenar_medidas(struct medida medidas_ord[], int qtd_medidas){
  TipoMedida auxiliar;
  int alteracao = 1;
  for(int i = 0; i < qtd_medidas; i++){
    alteracao = 0;
    for(int j = 0; j < qtd_medidas-1; j++){
      if(medidas_ord[j].frequencia < medidas_ord[j+1].frequencia){
        auxiliar = medidas_ord[j];
        medidas_ord[j] = medidas_ord[j+1];
        medidas_ord[j+1] = auxiliar;
        alteracao = 1;
      }
    }
  }
}

int main()
{
  //setlocale(LC_ALL, ""); Nunca funcionou
  FILE *arq;
  int i, np, nm, n, resp;
  int maior; //variavel que armazena o maior valor de glicemia
  int cont;  //variavel que armazena quantas medidas de pressao com valores acima de 14:10
  char id[NC];
  char aux[NC_LINHA];
  TipoMedida medidas[N_MED];
  TipoCliente clientes[N_Clientes];

  arq = fopen("ListaClientes.txt", "rt");
  if (arq == NULL)
  {
    printf("Problemas na abertura do arquivo\n");
    return -1;
  }
  else
  {
    np = 0;
    fgets(aux, NC_LINHA, arq);
    cout << aux << endl;
    while (fscanf(arq, "%s%i%s%s%s", clientes[np].id, &clientes[np].idade, clientes[np].sexo, clientes[np].hipertensao, clientes[np].diabetes) != EOF)
    {
      cout << clientes[np].id << "\t\t " << clientes[np].idade << " \t" << clientes[np].sexo << "\t" << clientes[np].hipertensao << "\t\t" << clientes[np].diabetes << endl;
      np++;
    }
    fclose(arq);
    do
    {
      cout << "\n************  Lista de Clientes com Registros Atualizados *********************\n";
      cout << "\t1393\n\t1492\n ";
      cout << "Qual ID de cliente que quer analisar: ";
      cin.getline(id, 80);
      cout << "cliente a consultar: " << id << endl;  
      n = busca_paciente(clientes, np, id);
      cout << "ID: " << clientes[n].id << " || idade: " << clientes[n].idade << " || sexo: " << clientes[n].sexo << " || hipertensao: " << clientes[n].hipertensao << " || diabetes: " << clientes[n].diabetes << endl;
      system("pause");
      strcat(id, "_01_06");
      strcat(id, ".txt");
      arq = fopen(id, "rt");
      if (arq == NULL)
      {
        printf("Problemas na abertura do arquivo\n");
        return -1;
      }
      nm = 0;
      fgets(aux, NC_LINHA, arq);
      while (nm < N_MED)
      {
        fscanf(arq, "%s%i%i%i%i", medidas[nm].hora, &medidas[nm].sistole, &medidas[nm].diastole, &medidas[nm].frequencia, &medidas[nm].glicemia);
        nm++;
      }
      fclose(arq);

      do
      {
        system("cls");
        cout << "1) Encontrar maior medida de glicemia registrada e apresentar todas as ocorrencias.\n";
        cout << "2) Apresentar quantas medidas foram registradas de pressao sistolica a partir de 14 mmHg e diastolica a partir de 10 mmHg .\n";
        cout << "3) Apresentar os 20 registros com os maiores valores de pulsacao.\n";
        cout << "4) Encerrar analise do cliente.\n";
        cout << "Digite a opcao desejada: ";
        cin >> resp;
        cin.ignore();
        switch (resp)
        {
        case 1:
          system("cls");
          maior = 0;
          for(i=0; i < nm; i++){
            if(medidas[i].glicemia > maior){
              maior = medidas[i].glicemia;
            }
          }
          medidas_glicose(medidas, nm, maior);
          system("pause");
          break;
        case 2:
          system("cls");
          cont = 0;
          cout << "Horarios que a sistole estava maior ou igual 14 e a diastole estava maior ou igual a 10:" << endl;
          for(i=0; i < nm; i++){
            if(medidas[i].sistole >= 14 && medidas[i].diastole >= 10){
              cont++;
              cout << "Horario: " << medidas[i].hora << " || Sistole(mmHg): " << medidas[i].sistole << " || Diastole(mmHg): " << medidas[i].diastole
              << " || Pulsacao(bat/min): " << medidas[i].frequencia << " || Glicose (mg/dL): " << medidas[i].glicemia << endl;
            }
          }
          cout << "Numero de vezes que os valores foram atingidos/ou superados: " << cont << endl;
          system("pause");
          break;
        case 3:
          system("cls");
          cout << "Ordenando 20 medidas em ordem decrescente de pulsacao: " << endl;
          ordenar_medidas(medidas, nm);
          for(i=0; i < 20; i++){
            cout << "Horario: " << medidas[i].hora << " || Sistole(mmHg): " << medidas[i].sistole << " || Diastole(mmHg): " << medidas[i].diastole
            << " || Pulsacao(bat/min): " << medidas[i].frequencia << " || Glicose (mg/dL): " << medidas[i].glicemia << endl;
          }
          system("pause");
          break;
        case 4:
          cout << "Encerrando a avaliacao. \nGerar atualizacao do prontuario!\n\n";
          break;
        default:
          cout << "opcao invalida\n";
        }
      } while (resp != 4);
      cout << "Deseja analisar mais um cliente? (1-sim /Qualquer outro valor - nao): ";
      cin >> resp;
      cin.ignore();
    } while (resp == 1);
  }
  return 0;
}
