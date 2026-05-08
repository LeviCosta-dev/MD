#include <stdio.h>

int mdc(int n1, int n2);

int main(void)
{
    int q1, q2;
    printf("Digite a quantidade de fatores primos do primeiro numero e do segundo\n");
    scanf("%d %d", &q1, &q2);

    int p1 = 1, p2 = 1, aux;

    printf("Digite os fatores primos dos numeros\n");
    for (int i = 0; i < q1; i++)
    {
        scanf("%d", &aux);
        p1 = p1 * aux;
    }

    for (int i = 0; i < q2; i++)
    {
        scanf("%d", &aux);
        p2 = p2 * aux;
    }


    printf("O MDC entre %d e %d eh %d\n", p1, p2, mdc(p1, p2));


    return 0;
}


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