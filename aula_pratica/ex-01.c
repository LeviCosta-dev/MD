#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Questao: 01\n\n");
    // Recebendo o número
    printf("Digite um numero para saber se ele eh primo:  ");
    int n;

    scanf("%d", &n);

    // Checando se é menor ou igual a 1
    if (n <= 1)
    {
        printf("Nao eh primo\n");
        return 0;
    }

    // Criando uma variável para não ter que chamar a função sqrt várias vezes no loop para ficar mais eficaz
    int limite = sqrte(n);

    // Checando os divisores
    for (int i = 2; i < limite; i++)
    {
        if (n % i== 0)
        {
            // Se achar um divisor, o número não é primo e encerra a função
            printf("Nao eh primo\n");
            return 0;
        }
    }

    printf("Eh primo\n");

    return 0;
}