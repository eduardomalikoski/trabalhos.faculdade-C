#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

//criando a funcao com os parametros
void func(char nome[], char sobrenome[], int pos);

int main(void)
{
	//variaveis de entrada
	char nome[101];
	char sobrenome[101]; 
	int pos; 

	printf("Insira seu primeiro nome: ");
	gets_s(nome); //recebe o nome

	printf("Insira seu ultimo nome: ");
	gets_s(sobrenome); //recebe o ultimo nome

	printf("Insira a posicao: ");
	scanf_s("%d", &pos); //recebe a posicao onde sera parado 

	func(nome, sobrenome, pos); //chama a funcao

	return 0;
}
//func para receber o nome e sobrenome de acordo com a posição
void func(char nome[], char sobrenome[], int pos)
{
	char var[202];
	//funcoes do string.h
	strncpy_s(var, nome, pos);
	strcat_s(var, sobrenome);
	strcat_s(var, &nome[pos]);
	puts(var);
}