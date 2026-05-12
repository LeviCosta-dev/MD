#include <stdio.h>


//----------------------------------------------------------------------------------------//


// Funções que vou usar
int checar_coprimo(int a, int b);
int mdc(int a, int b);
int resolver_congruencia(int a, int m);


//----------------------------------------------------------------------------------------//


int main(void)
{
    printf("Questao: 09\n\n");

    // Primeira congruência
    int a1, b1, m1;
    printf("Primeira congruencia:\n");

    // Escaneando os valores
    printf("Digite o valor de a:  ");
    scanf("%d", &a1);

    printf("Digite o valor de b:  ");
    scanf("%d", &b1);

    printf("Digite o valor de m:  ");
    scanf("%d", &m1);
    printf("\n");
    

    // Segunda congruência
    int a2, b2, m2;
    printf("Segunda congruencia:\n");

    // Escaneando os valores
    printf("Digite o valor de a:  ");
    scanf("%d", &a2);

    printf("Digite o valor de b:  ");
    scanf("%d", &b2);

    printf("Digite o valor de m:  ");
    scanf("%d", &m2);
    printf("\n");


    // Terceira congruência
    int a3, b3, m3;
    printf("Terceira congruencia:\n");

    // Escaneando os valore
    printf("Digite o valor de a:  ");
    scanf("%d", &a3);

    printf("Digite o valor de b:  ");
    scanf("%d", &b3);

    printf("Digite o valor de m:  ");
    scanf("%d", &m3);


    printf("\n");
    // Checando se os módulos são coprimos
    if (checar_coprimo(m1, m2) || checar_coprimo(m1, m3) || checar_coprimo(m2, m3))
    {
        printf("Os modulos nao sao coprimos entao nao eh possivel usar o Teorema Chines do Resto\n");
        return 1;
    }

    // Criando coeficientes para usar em congruências
    int M = m1 * m2 * m3;
    int M1 = M / m1;
    int M2 = M / m2;
    int M3 = M / m3;

    // Resolvendo as 3 congruências
    int s1 = resolver_congruencia(M1, m1);
    int s2 = resolver_congruencia(M2, m2);
    int s3 = resolver_congruencia(M3, m3);

    // Achando a solução
    int x0 = (M1 * s1 * b1) + (M2 * s2 * b2) + (M3 * s3 * b3);
    int x = x0 % M;


    // Saída
    printf("Usando o Teorema Chines do Resto, a solucao unica no intervalo (0, %d) eh: %d\n", M, x);



    return 0;
}


//----------------------------------------------------------------------------------------//


// Função que checa se dois números são coprimos
int checar_coprimo(int a, int b)
{
    if (mdc(a, b) != 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//----------------------------------------------------------------------------------------//


// Função que calcula o mdc usando o algoritmo de Euclides
int mdc(int n1, int n2)
{
    if (n1 % n2 == 0)
    {
        return n2;
    }
    else
    {
        return mdc(n2, n1 % n2);
    }
}


//----------------------------------------------------------------------------------------//


// Função que resolve uma congruência do tipo a * x congruente 1  mod m
int resolver_congruencia(int a, int m)
{
    for (int i = 1; i < m; i++)
    {
        if ((a * i) % m == 1)
        {
            return i;
        }
    }
}