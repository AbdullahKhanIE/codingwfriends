#include <stdio.h>
#define N 100

void makecap(char str1[]);
int strln(char str[]);
void strcom(char str1[], char str[]);
void maxchar(char str[], int len, char maxalpha[]);

int main()
{
    char str1[N], str2[N], maxalpha[26];
    fgets(str1, N, stdin);
    fgets(str2, N, stdin);
    str1[strln(str1) - 1] = '\0';
    str2[strln(str2) - 1] = '\0';
    makecap(str1);
    makecap(str2);
    strcom(str1, str2);
    maxchar(str1, strln(str1), maxalpha);
    return 0;
}


void makecap(char str1[])
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 97 && str1[i] <= 122)
        {
            str1[i] = str1[i] - 32;
        }
    }
}
int strln(char str[])
{
    int len=0;
    for (int i = 0; str[i]!='\0'; i++)
    {
        len++;
    }
    return len;
}

void strcom(char str1[], char str2[])
{
    int i, j, count = 0;
    int len1 = strln(str1);
    int len2 = strln(str2);
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
