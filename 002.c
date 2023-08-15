#include <stdio.h>
#define N 200
int strln(char str[]);
int main()
{
    char str[N], small[N], large[N];
    fgets(str, N, stdin);
    str[strln(str) - 1] = '\0';
    int len = 0, min = 2147483647, max = -2147483648;
    int max_i = 0, min_i = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        while (str[i] != ' ' && str[i] != '\0')
        {
            len++;
            i++;
        }
        if (len > max)
        {
            max = len;
            max_i = i;
        }
        if (len < min)
        {
            min = len;
            min_i = i;
        }
        len = 0;
    }
    int j = 0;
    for (int i = max_i - max; i < max_i; i++)
    {
        large[j] = str[i];
        j++;
    }
    large[j] = '\0';
    j = 0;
    for (int i = min_i - min; i < min_i; i++)
    {
        small[j] = str[i];
        j++;
    }
    small[j] = '\0';
    // printf("%d   %d\n%d   %d\n", max, max_i, min, min_i);
    printf("The largest word is '%s' and\nsmallest word is '%s'\n", large, small);
    return 0;
}

int strln(char str[])
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}