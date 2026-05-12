#include <stdio.h>

// Função que faz o caminho contrário de Euclides para descobrir os parâmetros s e t, sabendo que o s é 1 quando b é 0 e que o t do próximo passo é o valor de s
int euclides_estendido(int a, int b, int *s, int *t)
{
    // Caso base
    if (b == 0)
    {
        *s = 1;
        *t = 0;
        return a;
    }

    int s1, t1;

    int mdc = euclides_estendido(b, a % b, &s1, &t1);;

    *s = t1;
    *t = s1 - (a / b) * t1;

    return mdc;
}

int main(void)
{
    printf("Questao: 07\n\n");
    // Escaneando os números do usuário para calcular a função inversa
    int a, b, s, t;
    printf("Digite dois numeros coprimos para saber sua operacao inversa\n");
    scanf("%d %d", &a, &b);

    // Checando se os números são coprimos
    if (euclides_estendido(a, b, &s, &t) != 1)
    {
        printf("Os numeros que você digitou nao sao coprimos, logo, nao tem operacao inversa\n");
        return 1;
    }

    euclides_estendido(a, b, &s, &t);

    printf("O inverso de %d mod %d eh %d\n", a, b, s);


    return 0;
}