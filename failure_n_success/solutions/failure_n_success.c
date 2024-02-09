#include <stdio.h>
#include <string.h>
#define MAX_LENGTH_TEAM_NAME 100

struct Pair
{
    char name[MAX_LENGTH_TEAM_NAME];
    int score;
};

typedef struct Pair Pair;

Pair max_consecutive(char name[][MAX_LENGTH_TEAM_NAME], int n)
{
    char current_team[MAX_LENGTH_TEAM_NAME] = "";
    char max_team[MAX_LENGTH_TEAM_NAME] = "";
    int max_count = 0;
    int current_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(name[i], current_team) == 0)
        {
            current_count++;
        }
        else
        {
            if (current_count > max_count)
            {
                max_count = current_count;
                strcpy(max_team, current_team);
            }
            current_count = 1;
            strcpy(current_team, name[i]);
        }
    }
    Pair result;
    strcpy(result.name, max_team);
    result.score = max_count;
    if (result.score == 1)
    {
        strcpy(result.name, "");
        result.score = 0;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    char name[n][MAX_LENGTH_TEAM_NAME];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
    }
    Pair result = max_consecutive(name, n);
    printf("Team with the maximum consecutive occurrences: %s\n", result.name);
    printf("Number of consecutive occurrences: %d\n", result.score);
    return 0;
}
