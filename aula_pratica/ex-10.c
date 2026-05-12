#include <stdio.h>


//----------------------------------------------------------------------------------------//


// Funções que vou usar
int checar_coprimo(int a, int b);
int mdc(int a, int b);
int resolver_congruencia(int a, int m);


//----------------------------------------------------------------------------------------//


int main(void)
{
    printf("Questao: 10\n\n");

    // Escaneando o número que diz quantas congruências serão
    int n;
    printf("Digite quantas congruencias serao:  ");
    scanf("%d", &n);

    int a[n], b[n], m[n];

    for (int i = 0; i < n; i++)
    {
        // Escaneando a
        printf("Digite o valor de a:  ");
        scanf("%d", &a[i]);

        // Escaneando b
        printf("Digite o valor de b:  ");
        scanf("%d", &b[i]);

        // Escaneando c
        printf("Digite o valor de m:  ");
        scanf("%d", &m[i]);

        printf("\n");
    }

    // Checando se os coeficientes são coprimos
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (checar_coprimo(m[i], m[j]))
            {
                printf("Os modulos nao sao coprimos entao nao eh possivel usar o Teorema Chines do Resto\n");
                return 1;
            }
        }
    }
    // Calculando M
    int M0 = 1;
    for (int i = 0; i < n; i++)
    {
        M0 = M0 * m[i];
    }

    // Calculando os novos coeficientes
    int M[n];
    for (int i = 0; i < n; i++)
    {
        M[i] = M0 / m[i];
    }

    // Resolvendo as congruências
    int s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = resolver_congruencia(M[i], m[i]);
    }

    // Achando a solução única
    int x0 = 0;
    for (int i = 0; i < n; i++)
    {
        x0 += M[i] * s[i] * b[i];
    }

    int x = x0 % M0;


    printf("Usando o Teorema Chines do Resto, a solucao unica no intervalo (0, %d) eh: %d\n", M0, x);



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