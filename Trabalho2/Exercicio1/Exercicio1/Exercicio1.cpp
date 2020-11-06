#include <stdio.h>
#include <stdlib.h>

int main()
{
    //variaveis de inicialização e matriz de 8 posições
    int tabuleiro[8][8], i, j;
    //variaveis para contagem das peças
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count0 = 0;

    //pequeno menu para as opções
    printf("Selecione as pecas que serao colocadas:\n");
    printf("1 - peoes\n2 - cavalos\n3 - torres\n4 - bispos\n5 - reis\n6 - rainhas\n0 - nenhuma peca\n\n");

    //laço for para alocar as peças
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("Qual peca deseja colocar no tabuleiro na linha [%d] e coluna [%d]? ", i, j);
            scanf_s("%d", &tabuleiro[i][j]);
        }
    }
    system("cls");
    //mostrando o tabuleiro usando novamente um laço for para fazer um loop nas peças
    printf("********************TABULEIRO********************\n");

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            //escrevendo a matriz completa com as posições
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nQuantidade de cada uma das pecas no tabuleiro: \n");
    //contagem de quantas peças tem de cada 
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (tabuleiro[i][j] == 1)
                count1++;
            else if (tabuleiro[i][j] == 2)
                count2++;
            else if (tabuleiro[i][j] == 3)
                count3++;
            else if (tabuleiro[i][j] == 4)
                count4++;
            else if (tabuleiro[i][j] == 5)
                count5++;
            else if (tabuleiro[i][j] == 6)
                count6++;
            else if (tabuleiro[i][j] == 0)
                count0++;
        }
    }
    //impressão da quantidade de peças
    printf("\nPeoes: %d", count1);
    printf("\nCavalos: %d", count2);
    printf("\nTorres: %d", count3);
    printf("\nBispos: %d", count4);
    printf("\nReis: %d", count5);
    printf("\nRainhas: %d", count6);
    printf("\nNenhuma peca: %d\n", count0);

    system("pause");

}