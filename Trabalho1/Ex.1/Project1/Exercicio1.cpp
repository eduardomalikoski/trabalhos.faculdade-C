#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Variáveis de entrada
    int i = 0;
    float counters = 0;
    float countern = 0;
    float countersexm = 0;
    float countersexf = 0;
    float percsexm;
    float percsexf;
    int sexo;
    int x;
    char c;
    
    for (i = 0; i < 10; i++) //Laço de repetição para contagem do sexo e a escolha
    {
        printf("Digite seu sexo (1 para feminino || 2 para masculino)\n");
        scanf_s("%d", &sexo);
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Gostou do produto? (1 para sim || 2 para nao)\n");
        scanf_s("%d", &x);
        while ((c = getchar()) != '\n' && c != EOF) {}
        //Estruturas condicionais para definir qual contagem deverá ser feita
        if ((sexo == 1) && (x == 1))
        {
            countersexf++;
        }
        else if ((sexo == 2) && (x == 2))
        {
            countersexm++;
        }
        if (x == 1)
        {
            counters++;
        }
        else if (x == 2)
        {
            countern++;
        }
    }
    //Calculo da porcentagem 
    percsexf = (float) (countersexf * 100.0) / 10.0;
    percsexm = (float) (countersexm * 100.0) / 10.0;
    //Saída de dados para obtenção do resultado da pesquisa
    printf("O numero de pessoas que responderam sim: %1.0f\n", counters);
    printf("O numero de pessoas que responderam nao: %1.0f\n", countern);
    printf("A porcentagem de pessoas do sexo feminino que responderam sim: %2.0f%%\n", percsexf);
    printf("A porcentagem de pessoas do sexo masculino que responderam nao: %2.0f%%\n", percsexm);

    system("pause");
    return 0;
}