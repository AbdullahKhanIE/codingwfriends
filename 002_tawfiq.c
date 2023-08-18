#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], word[50], max[20], min[20];
    int i = 0, j = 0;
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    while (str[i] != ' ' && str[i] != '\0')
    {
        max[j] = min[j] = str[i];
        j++;
        i++;
    }
    max[j] = min[j] = '\0';
    i++;
    while (str[i] != '\0')
    {
        j = 0;
        while (str[i] != ' ' && str[i] != '\0')
        {
            word[j] = str[i];
            i++;
            j++;
        }
        word[j] = '\0';
        if (strlen(word) > strlen(max))
        {
            strcpy(max, word);
        }
        if (strlen(word) < strlen(min))
        {
            strcpy(min, word);
        }
        while (str[i] == ' ')
        {
            i++;
        }
    }
    printf("The largest word is '%s' \n", max);
    printf("The smallest word is '%s' \n", min);

    return 0;
}