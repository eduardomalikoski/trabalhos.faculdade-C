#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
//criação das structs
struct ponto2d
{
    int x, y; //atributos
};

//estruturas
struct ponto2d ponto_inicial;
struct ponto2d ponto_final;

int main()
{
    int resposta = 0; //variavel para verificação de qual opcao o usuario irá querer
    double distancia; //variavel que fará o calculo da distancia

    while (true) //laço de repetição para sempre mostrar o menu
    {
        //menu das opcoes
        system("cls");
        printf("[1] - Digitar os valores do primeiro ponto\n");
        printf("[2] - Digitar os valores do segundo ponto\n");
        printf("[3] - Mostrar a distância entre os pontos\n");
        printf("[4] - Sair\n");
        printf("\nDigite sua opcao: ");
        scanf_s("%d", &resposta); //lendo qual a opcao
        system("cls");
        switch (resposta) //fazendo um switch case para cada pedido do usuario
        {
        case 1: //ler e armazenar os pontos iniciais
            system("cls");
            printf("Digite o valor de x1:\n");
            scanf_s("%d", &ponto_inicial.x);
            printf("Digite o valor de y1:\n");
            scanf_s("%d", &ponto_inicial.y);
            break;
        case 2: //ler e armazenar os pontos finais
            system("cls");
            printf("Digite o valor de x2:\n");
            scanf_s("%d", &ponto_final.x);
            printf("Digite o valor de y2:\n");
            scanf_s("%d", &ponto_final.y);
            break;
        case 3: //efetuar o calculo e mostrar ao usuario
            system("cls");
            //fiz um sqrt para pegar a raiz e o pow para elevar ao quadrado o ponto inicial menos o ponto final
            distancia = sqrt(pow(ponto_inicial.x - ponto_final.x, 2) + pow(ponto_inicial.y - ponto_final.y, 2));
            printf("A distancia entre os pontos e:\n");
            printf("%.2f\n", distancia);
            system("pause");
            break;
        case 4: //despedida
            system("cls");
            printf("Obrigado e ate mais...\n");
            system("pause");
            return 0;
        default: //por default exibirá esta mensagem e voltará ao menu principal
            printf("Voce digitou o numero errado!");
        }
    }
}