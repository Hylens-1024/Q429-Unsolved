#include<stdio.h>

int cache[20] = {0};
int count = 1;
int m, n;

void iter(int current, int acc)
{
    if (current == n)
    {
        if(acc == m)
        {
            printf("[%d]:", count);
            for (int i = 0; i < current; i++)
            {
                printf("%d", cache[i]);
            }
            printf("\n");
            count++;
        }

        return;
    }

    int max = current == 0 ? m : cache[current - 1];
    for (int i = max; i >= 1; i--)
    {
        cache[current] = i;
        iter(current + 1, acc + i);
    }
}

int main()
{
    printf("Please enter required terms (<=10): ");
    scanf("%d", &n);
    printf("Input their sum: ");
    scanf("%d", &m);

    iter(0, 0);

    return 0;
}
