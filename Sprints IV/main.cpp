// Nome: Leandro de Jesus Luna        --RM: 86492
// Nome: Pedro Fernandees             --RM: 84244
// Nome: Rafael Procopio Bondezam     --RM: 84346
// Nome: Fabbio Augusto de Souza      --RM: 84695

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TipoPilhaChar.h" // Criar um arquivo header TipoPilhaChar.h
#define NS 10
#define NC 40
int main()
{
    setlocale(LC_ALL, "");
    char verifica[10];
    char servico[NS][NC], usuario[NS][NC], senha[NS][NC]; // NC de 'servico' e 'usuario' nao sao utilizados no codigo apresentado
    FILE *arq;
    char service[NC], user[NC], password[NC], codigo[NC];
    int ano;
    unsigned int i, k = 0;
    int valor;
    int op, continua;

    TipoPilha pilha;
    char inverter[NC], descriptografar[NC];
    int submenu;

    init(&pilha);

    do
    {
        cout << "Digite \n 0 para encerrar programa \n";
        cout << " 1 para cadastramento de servicos (iniciando arquivo)\n 2 recuperar login de um servico\n Opcao: ";
        cin >> op;
        switch (op)
        {
        case 0:
            cout << "Programa encerrado...\n";
            break;
        case 1:
            cout << "\nInforme ano com 4 digitos para usar como chave de acesso: ";
            cin >> ano;
            valor = ano % 8 + 1;
            arq = fopen("memoria.txt", "wt");
            if (arq == NULL)
            {
                printf("Problemas na abertura do arquivo\n");
            }
            else
            {
                strcpy(verifica, "teste");
                for (i = 0; i < strlen(verifica); i++)
                {
                    push(&pilha, verifica[i]);
                }

                k = 0;
                while (!isEmpty(pilha))
                {
                    pop(&pilha, &verifica[k]);
                    k++;
                }
                verifica[k] = '\0';

                for (i = 0; i < strlen(verifica); i++)
                    verifica[i] = (int)verifica[i] + valor;

                fprintf(arq, "%s\n", verifica);
                do
                {
                    cout << "\nServico: ";
                    cin >> service;
                    cout << "Usuario: ";
                    cin >> user;
                    cout << "Senha: ";
                    strcpy(inverter, "");
                    cin.sync();
                    cin.getline(password, NC);

                    // Implementação do trecho de programa que codificaa senha fazendo uso da pilha para a inversão de cada palavra da senha gerando a variável código.
                    k = 0;
                    for (i = 0; i < strlen(password); i++)
                    {
                        if ((char)password[i] != '&' && (char)password[i] != '!' && (char)password[i] != '@' && (char)password[i] != '#' && (char)password[i] != '$' && (char)password[i] != '%' && (char)password[i] != '*' && (char)password[i] != '_')
                        {
                            push(&pilha, password[i]);
                        }
                        else
                        {
                            while (!isEmpty(pilha))
                            {
                                pop(&pilha, &inverter[k]);
                                k++;
                            }
                            inverter[k] = password[i];
                            k++;
                        }
                    }
                    while (!isEmpty(pilha))
                    {
                        pop(&pilha, &inverter[k]);
                        k++;
                    }
                    inverter[k] = '\0'; // indica o final da senha invertida

                    strcpy(codigo, "");
                    for (i = 0; i < strlen(inverter); i++) // senha codificada
                    {
                        if ((char)inverter[i] != '&' && (char)inverter[i] != '!' && (char)inverter[i] != '@' && (char)inverter[i] != '#' && (char)inverter[i] != '$' && (char)inverter[i] != '%' && (char)inverter[i] != '*' && (char)inverter[i] != '_')
                        {
                            codigo[i] = (int)inverter[i] + valor;
                        }
                        else
                        {
                            codigo[i] = (char)inverter[i];
                        }
                    };
                    codigo[strlen(inverter)] = '\0'; // indica o final da string 'codigo'
                    fprintf(arq, "%s\t%s\t%s\n", service, user, codigo);
                    cout << "\nDigite 1 para continuar cadastramento de servicos e qualquer outro valor para encerrar: ";
                    cin >> continua;
                } while (continua == 1);
                fclose(arq);
            }
            break;
        case 2:
            cout << "\nInforme ano com 4 digitos para usar como chave de acesso: ";
            cin >> ano;
            valor = ano % 8 + 1;
            arq = fopen("memoria.txt", "rt");
            if (arq == NULL)
            {
                printf("Problemas na abertura do arquivo\n");
            }
            else
            {
                strcpy(verifica, "");
                fgets(verifica, 80, arq); //obtém do arquivo a palavra teste para verificação do ano correto

                for (i = 0; i < strlen(verifica) - 1; i++)
                {
                    push(&pilha, verifica[i]);
                }
                verifica[i] = '\0';

                k = 0;
                while (!isEmpty(pilha))
                {
                    pop(&pilha, &verifica[k]);
                    k++;
                }

                for (i = 0; i < strlen(verifica); i++)
                    verifica[i] = (int)verifica[i] - valor;

                if (strcmp(verifica, "teste") != 0)
                    cout << "\t Ano nao confere... \n\n";
                else
                {
                    i = 0;
                    while (i < NC && fscanf(arq, "%s%s%s", servico[i], usuario[i], senha[i]) != EOF)
                    {
                        i++;
                    }
                    //Elaboração do trecho de programa que faz a decodificação completa de uma senha retornando usuário e a senha original para apresentar ao usuário;
                    int j = i;
                    do
                    {
                        cout << "\n*****Servicos Cadastrados*****" << endl;
                        for (k = 0; k < j; k++)
                        {
                            cout << k + 1 << "] " << servico[k] << endl;
                        }

                        //Consulta da senha escolhendo o serviço por identificação de opção em um menu até que usuário encerre o programa
                        continua = 1;
                        while (continua == 1)
                        {
                            cout << "\nEscolha a posicao de um servico para obter usuario e senha decodificada: ";
                            cin >> submenu;
                            if (submenu > j || submenu <= 0)
                            {
                                cout << "Opcao Invalida! Selecione um novo valor no menu anterior." << endl;
                            }
                            else
                            {
                                continua = 0;
                            }
                        }

                        cout << "Usuario: " << usuario[submenu - 1] << endl;

                        k = 0;
                        for (i = 0; i < strlen(senha[submenu - 1]); i++)
                        {
                            if ((char)senha[submenu - 1][i] != '&' && (char)senha[submenu - 1][i] != '!' && (char)senha[submenu - 1][i] != '@' && (char)senha[submenu - 1][i] != '#' && (char)senha[submenu - 1][i] != '$' && (char)senha[submenu - 1][i] != '%' && (char)senha[submenu - 1][i] != '*' && (char)senha[submenu - 1][i] != '_')
                            {
                                push(&pilha, senha[submenu - 1][i]);
                            }
                            else
                            {
                                while (!isEmpty(pilha))
                                {
                                    pop(&pilha, &descriptografar[k]);
                                    k++;
                                }
                                descriptografar[k] = senha[submenu - 1][i];
                                k++;
                            }
                        }
                        while (!isEmpty(pilha))
                        {
                            pop(&pilha, &descriptografar[k]);
                            k++;
                        }
                        descriptografar[k] = '\0';

                        for (i = 0; i < strlen(descriptografar); i++) // senha descodificada
                        {
                            if ((char)descriptografar[i] != '&' && (char)descriptografar[i] != '!' && (char)descriptografar[i] != '@' && (char)descriptografar[i] != '#' && (char)descriptografar[i] != '$' && (char)descriptografar[i] != '%' && (char)descriptografar[i] != '*' && (char)descriptografar[i] != '_')
                            {
                                descriptografar[i] = (int)descriptografar[i] - valor;
                            }
                            else
                            {
                                descriptografar[i] = (char)descriptografar[i];
                            }
                        };

                        cout << "Senha descriptografada: " << descriptografar;

                        cout << "\nDigite 1 para pesquisar outros servicos e qualquer outro valor voltar ao menu principal: ";
                        cin >> continua;
                    } while (continua == 1);
                    fclose(arq);
                }
            }
            break;
        default:
            cout << "Opcao Invalida\n";
        }
    } while (op != 0);
    return 0;
}