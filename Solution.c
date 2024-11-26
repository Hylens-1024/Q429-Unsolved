#include<stdio.h>

int cache[20] = {0};
int count = 1;
int m, n;

void iter(int current, int remaining, int max)
{
    if(remaining == 0)
    {
        int sum = 0;
        for(int i = 0; i < current; i++)
        {
            sum += cache[i];
        }

        if(sum == m)
        {
            printf("[%d]:", count);
            for(int i = 0; i < current; i++)
            {
                printf("%d", cache[i]);
            }
            printf("\n");
            count++;
        }

        return;
    }

    for(int i = max; i >= 1; i--)
    {
        cache[current] = i;
        iter(current + 1, remaining - 1, i);
    }
}

int main()
{
    printf("Please enter required terms (<=10): ");
    scanf("%d", &n);
    printf("Input their sum: ");
    scanf("%d", &m);

    iter(0, n, m);

    return 0;
}
