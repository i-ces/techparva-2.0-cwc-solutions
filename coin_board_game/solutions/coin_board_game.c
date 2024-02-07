#include <stdio.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int calculateMaxCoins(int board[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    int dp[MAX_ROWS + 1][MAX_COLS + 1];

    for (int i = 0; i <= rows; ++i)
        for (int j = 0; j <= cols; ++j)
            dp[i][j] = (i == 0 || j == 0) ? 0 : max(dp[i - 1][j], dp[i][j - 1]) + board[i - 1][j - 1];

    return dp[rows][cols];
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows and columns (separated by a space): ");
    scanf("%d %d", &rows, &cols);

    int board[MAX_ROWS][MAX_COLS];

    printf("Enter the board values (%d rows x %d columns):\n", rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            scanf("%d", &board[i][j]);

    printf("The maximum number of coins in any one path is: %d\n", calculateMaxCoins(board, rows, cols));

    return 0;
}
