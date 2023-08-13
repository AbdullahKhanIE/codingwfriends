#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100
void makelow(char str1[]);
int strcom(char str1[], char str[]);

int main()
{
    char str1[N], str2[N], temp[N];
    fgets(str1, N, stdin);
    fgets(str2, N, stdin);
    str1[strlen(str1) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';
    makelow(str1);
    makelow(str2);
    int count = strcom(str1, str2);
    printf("%d\n", count);

    return 0;
}

void makelow(char str1[])
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 65 && str1[i] <= 90)
        {
            str1[i] = str1[i] + 32;
        }
    }
}
int strcom(char str1[], char str2[])
{
    int i, j, count = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2)
    {
        return 0;
    }
    for (i = 0; i <= len1 - len2; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
            if (j == len2 - 1)
            {
                count++;
            }
        }
    }
    return count;
}