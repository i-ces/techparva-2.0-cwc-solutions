#include <stdio.h>

int calculate_coins_by_sudru(int stack_1[], int stack_2[], int length_1, int length_2)
{
    int sudru = 0, seamoon = 0, turn = 0, pointer_1 = 0, pointer_2 = 0;

    while (pointer_1 < length_1 || pointer_2 < length_2)
    {
        if (pointer_1 == length_1)
        {
            if (turn % 2 == 0)
                sudru += stack_2[pointer_2];
            else
                seamoon += stack_2[pointer_2];
            pointer_2++;
        }
        else if (pointer_2 == length_2)
        {
            if (turn % 2 == 0)
                sudru += stack_1[pointer_1];
            else
                seamoon += stack_1[pointer_1];
            pointer_1++;
        }
        else if (turn % 2 == 0)
        {
            if (stack_1[pointer_1] > stack_2[pointer_2])
            {
                sudru += stack_1[pointer_1];
                pointer_1++;
            }
            else
            {
                sudru += stack_2[pointer_2];
                pointer_2++;
            }
        }
        else
        {
            if (stack_1[pointer_1] > stack_2[pointer_2])
            {
                seamoon += stack_1[pointer_1];
                pointer_1++;
            }
            else
            {
                seamoon += stack_2[pointer_2];
                pointer_2++;
            }
        }
        turn++;
    }
    return sudru;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 0)
    {
        printf("\n");
        return 0;
    }

    int coin_stack_1[n], coin_stack_2[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &coin_stack_1[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &coin_stack_2[i]);

    int result = calculate_coins_by_sudru(coin_stack_1, coin_stack_2, n, n);

    printf("The total number of coins collected by Sudru: %d\n", result);

    return 0;
}
