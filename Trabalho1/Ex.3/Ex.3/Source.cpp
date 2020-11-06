#include <stdio.h>
#include <stdlib.h>

int main()
{

	//declaracao das variaveis
	int m;
	int i; //linha
	int j; //coluna
	int diagPrincipal = 0;
	int diagSecundaria = 0;
	int testLinha = 1;
	int testColuna = 1;
	int matriz[100][100];
	int vetLinha[100] = { 1 }; //para receber a quantidade de linhas
	int vetColuna[100] = { 1 }; //para receber a quantidade de colunas

	printf("Insira o tamanho da matriz MxM:\n");
	scanf_s("%d", &m);

	matriz[m][m];

	//Laço de repetição para fazer o loop nas linhas e colunas da matriz
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("Digite o valor da linha %d e coluna %d:\n", i, j);
			scanf_s("%d", &matriz[i][j]);
		}
	}

	system("cls");
	printf("\nVisualizacao da matriz feita:\n");
	//Loop nos valores em cada posição da matriz para visualização
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

	//Calculo para soma das linhas
	printf("\nSoma das linhas:\n");
	vetLinha[m];
	for (i = 0; i < m; i++) //Loop nas posicoes da matriz
	{
		vetLinha[i] = 0;
		for (j = 0; j < m; j++)
		{
			vetLinha[i] += matriz[i][j]; //vetor para somar as linhas [i]
		}
	}

	for (i = 0; i < m; i++)
	{
		printf("%d ", vetLinha[i]); //visualização das respectivas linhas
	}

	//Calculo para soma das colunas
	printf("\nSoma das colunas:\n");

	vetColuna[m];
	for (j = 0; j < m; j++) //Loop nas posicoes da matriz
	{
		vetColuna[j] = 0;
		for (i = 0; i < m; i++)
		{
			vetColuna[j] += matriz[i][j]; //vetor para somar as colunas [j]
		}
	}

	for (i = 0; i < m; i++)
	{
		printf("%d ", vetColuna[i]); //visualização das respectivas colunas
	}

	//Calculo  da soma diagonal principal
	for (i = 0; i < m; i++)
	{
		diagPrincipal += matriz[i][i];
	}

	//Calculo da soma diagonal secundária
	for (i = 0; i < m; i++)
	{
		diagSecundaria += matriz[i][m - i - 1];
	}

	printf("\n\nSoma diagonal principal:\n");
	printf("%d\n", diagPrincipal);
	printf("Soma da diagonal secundaria:\n");
	printf("%d\n\n", diagSecundaria);

	for (i = 1; i < m; i++) //inicio dos testes 
	{
		if (vetLinha[i] != vetLinha[i - 1])
		{
			testLinha = 0;
			break;
		}
		else if (vetColuna[i] != vetColuna[i - 1])
		{
			testColuna = 0;
			break;
		}
	}

	//verificação se é um quadrado magico atravez da estrutura condicional
	if (testLinha && testColuna && diagPrincipal == diagSecundaria && diagPrincipal == vetLinha[0])
	{
		printf("Parabens, o quadrado e magico:)\n");
	}
	else
	{
		printf("O quadrado nao e magico:\n");
	}

	return 0;
}