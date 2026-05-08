#include <stdio.h>

int euclides_estendido(int a, int b, int *s, int *t)
{
    if (b == 0)
    {
        *s = 1;
        *t = 0;
        return a;
    }

    int s1, t1;

    int mdc = euclides_estendido(b, a % b, &s1, &t1);;

    *s = t1;
    *t = s1 - (a / b) * t1;

    return mdc;
}

int main(void)
{
    int a, b, s, t;
    scanf("%d %d", &a, &b);

    euclides_estendido(a, b, &s, &t);

    printf("O inverso de %d mod %d eh %d\n", a, b, s);


    return 0;
}