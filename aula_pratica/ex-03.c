#include <stdio.h>


//----------------------------------------------------------------------------------------//


// Funções que vou usar
int primo(int n);
int prox_primo(int n);


//----------------------------------------------------------------------------------------//


int main(void)
{
    printf("Questao: 03\n\n");
    // Criando a variável que vai receber o número do usuário
    int n, i = 0;
    printf("Digite um numero para saber seus fatores primos\n");
    scanf("%d", &n);

    printf("Os fatores primos sao:\n");
    printf("%d = ", n);

    while(n != 1)
    {
        int aux;
        int ft = prox_primo(i);
        if (n % ft == 0)
        {
            if (n == ft)
            {
                aux = n;
            }

            n = n / ft;
            
            if (aux == ft)
            {
                printf("%d\n", ft);
            }

            else
            {
                printf("%d . ", ft); 
            }
        }

        else
        {
            i++;
        }
    }


    return 0;
}


//----------------------------------------------------------------------------------------//


// Função que checa se um número é primo ou não
int primo(int n)
{
    if (n < 2)
    {
        return 0;
    }

    if (n = 2)
    {
        return 1;
    }

    int p = 1;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            p = 0;
            break;
        }
    }

    return p;
}


//----------------------------------------------------------------------------------------//


// Função que dado um número diz o menor número primo maior que o número dado
int prox_primo(int n)
{
    int i = n + 1;
    while(!primo(i))
    {
        i++;
    }

    return i;
}