#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float thirdharmonicequation(float s1,float s2,float s3,float s4)
{
float value1;
value1=1-2*(cos(3*s1))+2*(cos(3*s2))-2*(cos(3*s3))+2*(cos(3*s4));
return value1;
}
float fifthharmonicequation(float s1,float s2,float s3,float s4)
{
float value2;
value2=1-2*(cos(5*s1))+2*(cos(5*s2))-2*(cos(5*s3))+2*(cos(5*s4));
return value2;
}
float seventhharmonicequation(float s1,float s2,float s3,float s4)
{
float value3;
value3=1-2*(cos(7*s1))+2*(cos(7*s2))-2*(cos(7*s3))+2*(cos(7*s4));
return value3;
}
float ninthharmonicequation(float s1,float s2,float s3,float s4)
{
float value4;
value4=1-2*(cos(9*s1))+2*(cos(9*s2))-2*(cos(9*s3))+2*(cos(9*s4));
return value4;
}
void main()
{
        float a,b,c,d,a1,a2,a3,a4;
        a2=22.53;
        a1=10.62;
        a4=34.16;
        a3=26.51;
    a=thirdharmonicequation(a1,a2,a3,a4);
    b=thirdharmonicequation(a1,a2,a3,a4);
    c=thirdharmonicequation(a1,a2,a3,a4);
    d=thirdharmonicequation(a1,a2,a3,a4);
printf("values:%f,%f,%f,%f",a,b,c,d);
}
