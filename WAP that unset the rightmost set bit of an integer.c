#include<stdio.h>
int fun(unsigned int n)
{
    return n & (n-1);
}
int main()
{
    int n=7;
    printf("The number after unsetting the ");
    printf("rightmost set bit %d",fun(n));
    return 0;
}
