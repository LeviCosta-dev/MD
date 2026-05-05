#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void)
{
    int n = 2;
    clock_t inicio = clock();

    while (1)
    {
        double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;

        if (tempo >= 60.0)
        {
            break;
        }
        
        int primo = 1;

        int limite = sqrt(n);

        for (int i = 2; i <= limite; i++)
        {
            tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
            if (tempo >= 60.0)
            {
                break;
            }

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

        n++;
    }
}