#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int calculateMaxCoins(int board[MAX_ROWS][MAX_COLS], int rows, int cols);
int calculateCoins(int dp[MAX_ROWS + 1][MAX_COLS + 1], int row, int col, int board[MAX_ROWS][MAX_COLS]);

int calculateMaxCoins(int board[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    int dp[MAX_ROWS + 1][MAX_COLS + 1];

    for (int i = 0; i <= rows; ++i)
    {
        for (int j = 0; j <= cols; ++j)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= cols; ++j)
        {
            dp[i][j] = calculateCoins(dp, i, j, board);
        }
    }

    return dp[rows][cols];
}

int calculateCoins(int dp[MAX_ROWS + 1][MAX_COLS + 1], int row, int col, int board[MAX_ROWS][MAX_COLS])
{
    if (row <= 0 || col <= 0)
    {
        return 0;
    }

    int coinsOnCell = board[row - 1][col - 1];
    return (dp[row - 1][col] > dp[row][col - 1] ? dp[row - 1][col] : dp[row][col - 1]) + coinsOnCell;
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows and columns (separated by a space): ");
    scanf("%d %d", &rows, &cols);

    int board[MAX_ROWS][MAX_COLS];

    printf("Enter the board values (%d rows x %d columns):\n", rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            scanf("%d", &board[i][j]);
        }
    }

    int maxCoins = calculateMaxCoins(board, rows, cols);

    printf("The maximum number of coins in any one path is: %d\n", maxCoins);

    return 0;
}
