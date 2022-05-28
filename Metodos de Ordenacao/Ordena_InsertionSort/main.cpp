#include <iostream>
#include<locale>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define TAMANHO 8

int insertionsort(int vetor[],int n)
{
int eleito, j,i;
int comp=0;
for(i = 1; i <n; i++) {
	eleito = vetor[i];
	j = i-1;
    comp++;
	while (j >= 0 && vetor[j] > eleito) {
        comp++;
		vetor[j+1] = vetor[j];
		j = j-1;
		}
	vetor[j+1] =  eleito;
	}
return comp;
}


int main(){

  setlocale(LC_ALL, "");
  FILE *arq;
  int i;
  int vetor[TAMANHO];


  arq = fopen("arq_dados.txt", "rt");
  if (arq == NULL)  {
     printf("Problemas na abertura do arquivo\n");
     return -1;
  }
  i = 0;
  while (i<TAMANHO) {
      fscanf(arq, "%i", &vetor[i]);
      i++;
  }
  fclose(arq);


  for (i=0; i<TAMANHO;i++)
        cout << vetor[i] <<endl;

  cout <<"\n\nNúmero de comparações: "<<insertionsort(vetor, TAMANHO) <<endl;

  cout<<"\n\nVetor Ordenado\n";
  for (i=0; i<TAMANHO;i++)
        cout << vetor[i] <<endl;

  return 0;
}

