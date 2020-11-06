#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

int main()
{
	//declaracao de todas as variaveis 
	int i;
	int counter = 1; // para calcular quantos consumidores foram cadastrados.
	int conscounter = 0; // para calcular quantos consumidores passaram de 170 KW.
	int opcao = 0;
	int resposta = 0;
	float maior;
	float menor;
	int numerodacontadomaior;
	int numerodacontadomenor;
	int nmrconta;
	int totalkw;
	float consmedia;
	float soma;
	float totalkwpagar;
	float kw = 1.75;
	int saida;
	//vetores com 100 posicoes, mas todos os calculos foram feitos de acordo com a quantidade de consumidores
	int cons[100];
	int constotalkw[100];
	float constotalkwpagar[100];

	while (true) //Loço While para que o programa esteja sempre em execucao. Apenas pare caso a opcao seja 7.
	{
		system("cls");
		printf("******************************************************************************\n");
		printf("* 1 - Adicionar um novo consumidor                                           *\n");
		printf("* 2 - Listagem completa dos consumidores                                     *\n");
		printf("* 3 - Consumo medio da cidade                                                *\n");
		printf("* 4 - Mostrar o numero de consumidores que ultrapassaram o consumo de 170 KW *\n");
		printf("* 5 - Consumidor que mais gastou                                             *\n");
		printf("* 6 - Consumidor que menos gastou                                            *\n");
		printf("* 7 - Sair do programa                                                       *\n");
		printf("******************************************************************************\n");
		printf("Digite sua opcao: ");
		scanf_s("%d", &opcao);

		switch (opcao) // Switch para o usuario selecionar a opcao de acordo com as alternativas que o mesmo tem.
		{

		case 1: //numero da conta, total de kw consumido e o valor a pagar

			for (i = 0; i < 100; i++) // Laço for para armazenar os dados em variaveis e nos vetores.
			{
				system("cls");
				printf("Insira o numero da conta:\n");
				scanf_s("%d", &nmrconta);
				cons[i] = nmrconta;
				printf("Insira o total de KW consumido:\n");
				scanf_s("%d", &totalkw);
				constotalkw[i] = totalkw;
				totalkwpagar = (float)(totalkw * kw);
				printf("Total a pagar: %2.2f \n", totalkwpagar);
				constotalkwpagar[i] = totalkwpagar;

				printf("Deseja cadastrar um novo consumidor? (1 - sim / 2 - nao)\n");
				scanf_s("%d", &resposta); // Define se o usuario cadastrará um novo consumidor ou nao.

				if (resposta == 2) // Fazendo a condicao utilizando a estrutura condicional if.
				{
					// Variaveis recebendo os valores dos consumidores para calculo do maior consumidor, menor e numero da conta dos mesmos.
					maior = constotalkwpagar[0];
					menor = constotalkwpagar[0];
					numerodacontadomaior = cons[0];
					numerodacontadomenor = cons[0];

					for (i = 0; i < counter; i++) //Loop nos consumidores para verificacao.
					{
						//Estrutura condicional para captar o que mais gastou e o que menos gastou.
						if (constotalkwpagar[i] > maior)
						{
							maior = constotalkwpagar[i];
							numerodacontadomaior = cons[i];
						}
						if (constotalkwpagar[i] < menor)
						{
							menor = constotalkwpagar[i];
							numerodacontadomenor = cons[i];
						}
					}
					break;
				}
				counter++; //contador recebe counter + 1 para adicionar mais um consumidor na contagem.
			}
			break;

		case 2: //Listar o numero da conta, total de KW consumidos, valor a pagar do consumidor que mais gastou e o que menos gastou.

			system("cls");
			printf("Listagem Completa dos consumidores:\n\n");

			for (i = 0; i < counter; i++) //Laço para captar os dados dos consumidores cadastrados e imprimir os mesmos.
			{
				printf("Numero da conta: %d\n", cons[i]);
				printf("Total de KW consumido: %d KW\n", constotalkw[i]);
				printf("Total a pagar: %2.2f\n\n", constotalkwpagar[i]);
			}
			//Listagem dos consumidores que mais gastaram e que menos gastaram de acordo com calculo.
			printf("Consumidor que mais gastou:\n");
			printf("Numero da conta: %d\n", numerodacontadomaior);
			printf("Valor gasto: %2.2f\n\n", maior);
			printf("Consumidor que menos gastou:\n");
			printf("Numero da conta: %d\n", numerodacontadomenor);
			printf("Valor gasto: %2.2f\n\n", menor);
			system("pause");
			break;

		case 3:  //Mostrar a média de consumo da cidade.

			system("cls");
			printf("Media de consumo da cidade:\n\n");

			soma = constotalkw[0];
			for (i = 1; i < counter; i++) //laço para somar os valores gastos pelos consumidores.
			{
				soma += constotalkw[i];
			}

			consmedia = (float)(soma / counter); //media dos consumidores.

			printf("%2.2f\n\n", consmedia);
			system("pause");
			break;

		case 4: //Mostrar o numero de consumidores que ultrapassaram o consumo de 170 KW

			system("cls");

			for (i = 0; i < counter; i++) //laço para passar por todos os consumidores
			{
				//condicao para ver se os consumidores ultrapassaram o consumo de 170 KW.
				if (constotalkw[i] > 170)
				{
					conscounter++; //contador que calcula quantos consumidores ultrapassaram 170 KW.

				}
			}
			printf("O numero de consumidores que ultrapassaram o consumo de 170 KW:\n\n");
			printf("%d consumidores\n\n", conscounter);
			system("pause");
			break;

		case 5: // Consumidor que mais gastou

			system("cls");
			printf("Consumidor que mais gastou:\n");
			printf("Numero da conta: %d\n", numerodacontadomaior);
			printf("Valor gasto: %2.2f\n\n", maior);
			system("pause");
			break;

		case 6: //Consumidor que menos gastou

			system("cls");
			printf("Consumidor que menos gastou:\n");
			printf("Numero da conta: %d\n", numerodacontadomenor);
			printf("Valor gasto: %2.2f\n", menor);
			system("pause");
			break;

		case 7: //Encerrar o programa

			system("cls");
			printf("Obrigado por utilizar o programa!\n");
			system("pause");
			return 0;

		default: // Caso o usuario digite algo fora dos padroes que o programa pede.
			printf("Opcao invalida\n\n");
			system("pause");
			break;
		}
	}
	return 0;
}