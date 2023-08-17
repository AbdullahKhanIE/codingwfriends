#include <stdio.h>
void printn(int n);

int main()
{
    int input;
    scanf("%d", &input);
    printf("The natural numbers are : ");
    printn(input);
    return 0;
}

void printn(int n)
{
    if (n > 0)
    {
        printn(n - 1);
        printf("%d ", n); 
    }
}
