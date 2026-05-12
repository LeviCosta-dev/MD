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
    printf("Questao: 06\n\n");
    // Escaneando dois números do usuário
    int n1, n2, md, s, t;
    printf("Digite dois numeros para saber os coeficientes s e t\n");
    scanf("%d %d", &n1, &n2);

    // Calculando o MDC e atualizando os valores de s e t
    md = euclides_estendido(n1, n2, &s, &t);

    // Saída
    printf("MDC(%d, %d): %d\ns: %d\nt: %d\n", n1, n2, md, s, t);


    return 0;
}