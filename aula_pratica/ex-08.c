#include <stdio.h>


//----------------------------------------------------------------------------------------//


// Função que vou usar
int mdc(int n1, int n2);


//----------------------------------------------------------------------------------------//


int main(void)
{
    printf("Questao: 08\n\n");
    // Escaneando os valores do usuário para resolver a congruência
    int a, b, m;
    // Escaneando a
    printf("Digite o valor de a:  ");
    scanf("%d", &a);

    printf("Digite o valor de b:  ");
    scanf("%d", &b);

    printf("Digite o valor de m:  ");
    scanf("%d", &m);
    
    int d = mdc(a, m);

    int a1 = a / d;
    int b1 = b / d;
    int m1 = m / d;
    int resto = b1 % m1;

    for (int i = 0; i < m; i++)
    {
        if ((a1 * i) % m1 == resto)
        {
            printf("%d\n", i);
        }
    }
}


//----------------------------------------------------------------------------------------//


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