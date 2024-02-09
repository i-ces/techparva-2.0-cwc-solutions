#include <stdio.h>

// function to calculate the total number of times the stamp was dipped in the ink pad
int calculate_dip_count(int stamp_times[], int n, int ink_duration)
{
    int dip_count = 0;
    int current_dip_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (stamp_times[i] == 0 || stamp_times[i] > current_dip_time)
        {
            dip_count++;
            current_dip_time = stamp_times[i] + ink_duration;
        }
    }
    return dip_count;
}

int main()
{

    int n;
    scanf("%d", &n);

    if (n == 0)
    {
        printf("%d", n);
        return 0;
    }

    int stamp_times[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stamp_times[i]);
    }

    int ink_duration;
    scanf("%d", &ink_duration);

    if (ink_duration == 0)
    {
        printf("%d", n);
        return 0;
    }

    printf("%d", calculate_dip_count(stamp_times, n, ink_duration));
}