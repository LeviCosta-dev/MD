#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    if (n <= 1)
    {
        printf("Nao eh primo\n");
        return 0;
    }

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i== 0)
        {
            printf("Nao eh primo\n");
            return 0;
        }
    }

    printf("Eh primo\n");

    return 0;
}