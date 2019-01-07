#include<stdio.h>
#include<math.h>
void main()
{
    int x1,x2,y1,y2;
    float distance;
    printf("\n Enter x and y coordinate of first point:");
    scanf("%d%d",&x1,&y1);
    printf("\n Enter x and y coordinate of second point:");
    scanf("%d%d",&x2,&y2);
    distance=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    printf("\n Distance=%f",distance);
}
