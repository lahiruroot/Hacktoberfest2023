#include <stdio.h>
int main()
{
int a1,a2,a3;
printf("enter numbers",a1,a2,a3);
sacnf("%d %d %d , &a1,&a2,&a3);
if((a1>a2) && (a1>a3))
{
printf("%d",a1);
}
else if (a2>a3)
{
printf("%d",a2);
}
else
{
printf("%d",a3);
}
return 0;
}
