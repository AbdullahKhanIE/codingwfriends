#include <stdio.h>
#define N 200
void makelow(char str[]);
int strln(char str[]);

int main()
{
    char str[N];
    fgets(str, N, stdin);
    str[strln(str) - 1] = '\0';
    

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
void makelow(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
        }
    }
}