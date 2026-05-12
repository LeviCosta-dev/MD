#include <stdio.h>

// Função que vou usar
int mdc(int n1, int n2);

int main(void)
{
    printf("Questao: 04\n\n");
    // Recebendo do usuário quantos fatores primos tem os números
    int q1, q2;
    printf("Digite a quantidade de fatores primos do primeiro numero e do segundo numero\n");
    scanf("%d %d", &q1, &q2);

    int p1 = 1, p2 = 1, aux;

    // Escaneando os fatores primos do primeiro número 
    printf("Digite os fatores primos do primeiro numero\n");
    for (int i = 0; i < q1; i++)
    {
        // Quando escaneio o número, já multiplico pelo resultado acumulado para descobrir o número mais rapidamente
        scanf("%d", &aux);
        p1 = p1 * aux;
    }

    // Escaneando os fatores primos do segundo número 
    printf("Agora digite os fatores primos do segundo numero\n");
    for (int i = 0; i < q2; i++)
    {
        scanf("%d", &aux);
        p2 = p2 * aux;
    }


    // Saída do programa
    printf("O MDC entre %d e %d eh %d\n", p1, p2, mdc(p1, p2));


    return 0;
}


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