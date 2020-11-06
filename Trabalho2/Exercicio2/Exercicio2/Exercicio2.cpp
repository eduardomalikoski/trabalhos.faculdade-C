#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//função para base de calculo
double func(double salario)
{
	double aliquota;

	if (salario <= 1637.11)
	{
		aliquota = 0.0;
		salario = 0.0;
	}
	else if (salario <= 2453.50)
		aliquota = 0.075;
	else if (salario <= 3271.38)
		aliquota = 0.15;
	else if (salario <= 4087.65)
		aliquota = 0.225;
	else if (salario > 4087.65)
		aliquota = 0.275;

	if (aliquota != 0.0)
		salario = (salario * aliquota);

	return salario;
}

int main()
{
	//variaveis de inicialização
	char funcionario[100];
	double salarioFuncionario;
	double imposto;

	//captando nome e salario do funcionario
	printf("Digite o nome do funcionario:\n");
	gets_s(funcionario);
	printf("Digite o salario do funcionario:\n");
	scanf_s("%lf",&salarioFuncionario);

	//chamando a função com o parâmetro que o usuario digitou
	imposto = func(salarioFuncionario);

	system("cls");

	//imprimindo na tela os dados atualizados
	printf("Nome do funcionario:\n%s", funcionario);
	printf("\nImposto que devera ser pago:\n");
	printf("%.2lf\n", imposto);
	printf("Salario atualizado do funcionario:\n");
	//pequeno calculo para ter o total do salario
	double salarioAtualizado = salarioFuncionario - imposto;
	printf("%.2f\n", salarioAtualizado);
}

