#include <stdio.h>

// Função que calcula o mdc de dois números usando Euclides
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

int main(void)
{
    printf("Questao: 05\n\n");
    // Escaneando dois números que o usuário quiser
    int n1, n2;
    printf("Digite dois numeros para saber seu MDC\n");
    scanf("%d %d", &n1, &n2);

    printf("MDC(%d, %d) = %d\n", n1, n2, mdc(n1, n2));


    return 0;
}