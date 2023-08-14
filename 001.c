#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

void makelow(char str1[]);
void strcom(char str1[], char str[]);
void maxchar(char str[], int len, char maxalpha[]);

int main()
{
    char str1[N], str2[N], maxalpha[26];
    fgets(str1, N, stdin);
    fgets(str2, N, stdin);
    str1[strlen(str1) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';
    makelow(str1);
    makelow(str2);
    strcom(str1, str2);
    maxchar(str1, strlen(str1), maxalpha);

    return 0;
}


void makelow(char str1[])
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 97 && str1[i] <= 122)
        {
            str1[i] = str1[i] - 32;
        }
    }
}

void strcom(char str1[], char str2[])
{
    int i, j, count = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2)
    {
        return;
    }
    for (i = 0; i <= len1 - len2; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
            if ((j == len2 - 1 && str1[i + j + 1] == ' ' && str1[i - 1] == ' ') || (j == len2 - 1 && str1[i + j + 1] == ' ' && i == 0) || (j == len2 - 1 && str1[i - 1] == ' ' && i + j + 1 == len1))
            {
                ++count;
            }
        }
    }
    printf("The frequency of the word of \"%s\" is %d\n", str2, count);
}

void maxchar(char str[], int len, char maxalpha[26])
{
    for (int i = 0; i < 26; i++)
    {
        maxalpha[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            int x = str[i] - 65;
            maxalpha[x] += 1;
        }
    }
    int max = maxalpha[0], count = 0;
    for (int i = 1; i < 26; i++)
    {
        if (max < maxalpha[i])
        {
            max = maxalpha[i];
            count = i;
        }
    }
    printf("The Highest frequency of character \'%c\' appears number of times : %d\n", count + 97, max);
}