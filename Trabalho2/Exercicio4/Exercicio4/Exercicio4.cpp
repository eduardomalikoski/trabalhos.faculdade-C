#include <iostream>
#include <stdio.h>
#include <math.h>

void calc_hexa(float L, float* area, float* perimetro) //funcao como pedido utilizando ponteiros
{
	*area = (3 * (pow(L, 2)) * sqrt(3)) / 2; //pow para fazer a potenciacao e sqrt para a raiz quadrada
	*perimetro = (6 * L); //calculo do perimetro passando lado x 6
}
int main()
{
	//variaveis de inicializacao para sobrepor os parametros exigidos na funcao
	float ladoHexagono, area, perimetro; 

	printf("Digite o lado do hexagono:\n");
	scanf_s("%f", &ladoHexagono); //lê o lado do hexagono

	while (ladoHexagono > 0) //laço while para verificar sempre se o lado é maior que 0
	{
		calc_hexa(ladoHexagono, &area, &perimetro); //chamando a função para os calculos
		//imprimindo na tela a area e o perimetro
		printf("\nLado do hexagono: %.2f\n", ladoHexagono);
		printf("A area do hexagono: %.2f\n", area);
		printf("O perimetro do hexagono: % .2f\n", perimetro);

		printf("\n\nDigite o lado do hexagono:"); //entao perguntando novamente até o usuário colocar um numero < 0
		scanf_s("%f", &ladoHexagono);
	}
	printf("Ate logo...");
}