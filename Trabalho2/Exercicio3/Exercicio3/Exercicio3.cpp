#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#pragma warning(disable:4996)

int main()
{
	FILE* fArquivo; //criando uma file 
	//variaveis para tamanho da frase e a frase em si
	int tamPrimeira, tamSegunda, tamTerceira, tamQuarta, tamQuinta, i;
	char primeiraFrase[50];
	char segundaFrase[50];
	char terceiraFrase[50];
	char quartaFrase[50];
	char quintaFrase[50];
	char nomeArquivo[20];

	//lendo as frases
	printf("Digite a primeira frase: (no max. 50 caracteres)\n");
	gets_s(primeiraFrase);
	printf("Digite a segunda frase: (no max. 50 caracteres)\n");
	gets_s(segundaFrase);
	printf("Digite a terceira frase: (no max. 50 caracteres)\n");
	gets_s(terceiraFrase);
	printf("Digite a quarta frase: (no max. 50 caracteres)\n");
	gets_s(quartaFrase);
	printf("Digite a quinta frase: (no max. 50 caracteres)\n");
	gets_s(quintaFrase);
	fflush(stdin); //limpa os buffers

	//variavel tam para receber o tamanho e laços for para passar para maiúscula 
	tamPrimeira = strlen(primeiraFrase);
	for (i = 0; i < tamPrimeira; i++)
	{
		primeiraFrase[i] = toupper(primeiraFrase[i]);
	}

	tamSegunda = strlen(segundaFrase);
	for (i = 0; i < tamSegunda; i++)
	{
		segundaFrase[i] = toupper(segundaFrase[i]);
	}

	tamTerceira = strlen(terceiraFrase);
	for (i = 0; i < tamTerceira; i++)
	{
		terceiraFrase[i] = toupper(terceiraFrase[i]);
	}

	tamQuarta = strlen(quartaFrase);
	for (i = 0; i < tamQuarta; i++)
	{
		quartaFrase[i] = toupper(quartaFrase[i]);
	}

	tamQuinta = strlen(quintaFrase);
	for (i = 0; i < tamQuinta; i++)
	{
		quintaFrase[i] = toupper(quintaFrase[i]);
	}

	printf("\nDigite o nome do arquivo a ser criado: ");
	gets_s(nomeArquivo); //grava o nome do arquivo

	fArquivo = fopen(nomeArquivo, "w"); //abre o arquivo

	//grava o tamanho da frase e a frase
	fwrite(&tamPrimeira, sizeof(int), 1, fArquivo);
	fwrite(primeiraFrase, sizeof(char), tamPrimeira, fArquivo);

	fwrite(&tamSegunda, sizeof(int), 1, fArquivo);
	fwrite(segundaFrase, sizeof(char), tamSegunda, fArquivo);

	fwrite(&tamTerceira, sizeof(int), 1, fArquivo);
	fwrite(terceiraFrase, sizeof(char), tamTerceira, fArquivo);

	fwrite(&tamQuarta, sizeof(int), 1, fArquivo);
	fwrite(quartaFrase, sizeof(char), tamQuarta, fArquivo);

	fwrite(&tamQuinta, sizeof(int), 1, fArquivo);
	fwrite(quintaFrase, sizeof(char), tamQuinta, fArquivo);

	fclose(fArquivo); //fechando o arquivo como pedido
	fArquivo = fopen(nomeArquivo, "r"); //abrindo o arquivo

	//ler o tamanho das frases e as frases gravadas
	fread(&tamPrimeira, sizeof(int), 1, fArquivo);
	fread(primeiraFrase, sizeof(char), tamPrimeira, fArquivo);

	fread(&tamSegunda, sizeof(int), 1, fArquivo);
	fread(segundaFrase, sizeof(char), tamSegunda, fArquivo);

	fread(&tamTerceira, sizeof(int), 1, fArquivo);
	fread(terceiraFrase, sizeof(char), tamTerceira, fArquivo);

	fread(&tamQuarta, sizeof(int), 1, fArquivo);
	fread(quartaFrase, sizeof(char), tamQuarta, fArquivo);

	fread(&tamQuinta, sizeof(int), 1, fArquivo);
	fread(quintaFrase, sizeof(char), tamQuinta, fArquivo);

	//se não for o fim do arquivo, escrever das as frases
	if (!feof(fArquivo))
	{
		printf("\n\nTexto Lido:\n%s", primeiraFrase);
		printf("\n%s", segundaFrase);
		printf("\n%s", terceiraFrase);
		printf("\n%s", quartaFrase);
		printf("\n%s\n", quintaFrase);
	}
	fclose(fArquivo); //fecha o arquivo e is the end :)
}
