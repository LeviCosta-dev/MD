#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void)
{
    printf("Questao: 02\n\n");
    // inicializando o número em 2 pois é o primeiro primo e começando a contar os 60 segundos
    int n = 2;
    clock_t inicio = clock();

    while (1)
    {
        // Verificando o tempo de execução
        double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;

        // Se passar de 60seg o código encerra
        if (tempo >= 60.0)
        {
            break;
        }
        
        // criando uma variável que funciona como bool para saber se o número é primo ou não
        int primo = 1;

        int limite = sqrt(n);

        for (int i = 2; i <= limite; i++)
        {
            tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
            
            // Checando o tempo de execução novamente
            if (tempo >= 60.0)
            {
                break;
            }

            // Se achar um divisor, primo recebe 0 e o código não entra no if
            if (n % i == 0)
            {
                primo = 0;
                break;
            }
        }

        if (primo)
        {
            printf("%d\n", n);
        }

        // Incrementando o número para checagem
        n++;
    }
}