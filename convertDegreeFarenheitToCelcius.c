#include<stdio.h>
void main()
{
    float fahrenheit,celcius;
    printf("\n Enter the temperature in fahrenheit");
    scanf("%f",&fahrenheit);
    celcius=(0.56)*(fahrenheit-32);
    printf("\n Temperature in degree celcius is %f",celcius);
}
