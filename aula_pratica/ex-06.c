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
    int n1, n2, md, s, t;
    scanf("%d %d", &n1, &n2);

    md = euclides_estendido(n1, n2, &s, &t);

    printf("MDC(%d, %d): %d\ns: %d\nt: %d\n", n1, n2, md, s, t);


    return 0;
}