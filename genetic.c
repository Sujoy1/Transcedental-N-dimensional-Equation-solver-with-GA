#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct fitnode
{
    int solnindex;
    float fitness;
};
/* write the necessary functions */
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
float fitness(float a,float b,float c,float d)
{
    float a1,a2,a3,a4,fitvalue;
    a1=thirdharmonicequation(a,b,c,d);
    a2=fifthharmonicequation(a,b,c,d);
    a3=seventhharmonicequation(a,b,c,d);
    a4=ninthharmonicequation(a,b,c,d);
    fitvalue=a1*a2*a3*a4;
    return abs(fitvalue);
}
int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;
    while (n!=0)
    {
        remainder = n%2;
                n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}
double Convertradiantodegree(double radian){
    double pi = 3.14159;
    return(radian * (180/pi));
}
double Convertdegreetoradian(double degree){
    double pi = 3.14159;
    return(degree * (pi/180));
}
/* This right below is my main code */
void main()
{


    int copyofalpha1[10][13];
    int copyofalpha2[10][13];
    int copyofalpha3[10][13];
    int copyofalpha4[10][13];
    int crosschildrenofalpha1[10][13];
    int crosschildrenofalpha2[10][13];
    int crosschildrenofalpha3[10][13];
    int crosschildrenofalpha4[10][13];

    struct fitnode roulettearr[10];
    struct fitnode checksoln[10];
    struct fitnode roulettewheel[10];
    struct fitnode c[10];
    int count[10];
    struct fitnode temp;
    int crossparentsindex[10];
    int flag1,flag2,flag3,root1=0,root2=0,root3=0,root4=0,i,j,a,n,k1,k2,s,indexbest,gen=0;
    long long soln1,soln2,soln3,soln4;
    float solution1,solution2,solution3,solution4,uproot1=0.0,uproot2=0.0,uproot3=0.0,uproot4=0.0,r,random1,temp2,t1=15.46,t2=24.33,t3=46.11,t4=49.4;
    checksoln[9].fitness=1.0;
/*initializing the population (roots obtained by newton raphson method */
int alpha1[10][13]={{0,0,1,1,0,0,0,0,0,1,0,1,0},{0,0,1,1,0,0,0,0,0,1,0,1,1},{0,0,1,1,0,0,0,0,0,1,1,0,0},{0,0,1,1,0,0,0,0,0,1,1,0,1},{0,0,1,1,0,0,0,0,0,1,1,1,0},{0,0,1,1,0,0,0,0,0,1,0,0,1},{0,0,1,1,0,0,0,0,0,1,0,0,0},{0,0,1,1,0,0,0,0,0,0,1,1,1},{0,0,1,1,0,0,0,0,0,0,1,1,0},{0,0,1,1,0,0,0,0,0,0,1,0,1}};
int alpha2[10][13]={{0,0,1,0,1,1,0,0,0,0,0,0,1},{0,0,1,0,1,1,0,0,0,0,0,1,0},{0,0,1,0,1,1,0,0,0,0,0,1,1},{0,0,1,0,1,1,0,0,0,0,1,0,0},{0,0,1,0,1,1,0,0,0,0,1,0,1},{0,0,1,0,1,1,0,0,0,0,1,1,0},{0,0,1,0,1,1,0,0,0,0,1,1,1},{0,0,1,0,1,1,0,0,0,0,0,0,0},{0,0,1,0,1,0,1,1,1,1,1,1,1},{0,0,1,0,0,1,1,1,1,1,1,1,0}};
int alpha3[10][13]={{1,0,0,1,0,0,0,0,0,0,0,1,1},{1,0,0,1,0,0,0,0,0,0,1,0,0},{1,0,0,1,0,0,0,0,0,0,1,0,1},{1,0,0,1,0,0,0,0,0,0,1,1,0},{1,0,0,1,0,0,0,0,0,0,1,1,1},{1,0,0,1,0,0,0,0,0,1,0,0,0},{1,0,0,1,0,0,0,0,0,0,0,0,1},{1,0,0,1,0,0,0,0,0,0,0,0,0},{1,0,0,0,1,1,1,1,1,1,1,1,1},{1,0,0,0,1,1,1,1,1,1,1,1,0}};
int alpha4[10][13]={{1,0,0,1,1,0,1,0,0,1,1,0,0},{1,0,0,1,1,0,1,0,0,1,1,0,1},{1,0,0,1,1,0,1,0,0,1,1,1,0},{1,0,0,1,1,0,1,0,0,1,1,1,1},{1,0,0,1,1,0,1,0,1,0,0,0,0},{1,0,0,1,1,0,1,0,0,1,0,1,1},{1,0,0,1,1,0,1,0,0,1,0,1,0},{1,0,0,1,1,0,1,0,0,1,0,0,1},{1,0,0,1,1,0,1,0,0,1,0,0,0},{1,0,0,1,1,0,1,0,0,0,1,1,1}};
while((gen<5000)||(checksoln[9].fitness>=0.000001))
    {
        gen++;
        /*copying the populations */
for(i=0;i<10;i++)
{
    for(j=0;j<13;j++)
    {
        copyofalpha1[i][j]=alpha1[i][j];
        copyofalpha2[i][j]=alpha2[i][j];
        copyofalpha3[i][j]=alpha3[i][j];
        copyofalpha4[i][j]=alpha4[i][j];
    }
}
        /* getting the pairs which perform reproduction */
for(i=0;i<10;i++)
{
    for(j=0;j<13;j++)
    {
     soln1=soln1*10+alpha1[i][j];
     soln2=soln2*10+alpha2[i][j];
     soln3=soln3*10+alpha3[i][j];
     soln4=soln4*10+alpha4[i][j];
    }
    solution1=(float)convertBinaryToDecimal(soln1);
    solution2=(float)convertBinaryToDecimal(soln2);
    solution3=(float)convertBinaryToDecimal(soln3);
    solution4=(float)convertBinaryToDecimal(soln4);
    solution1=Convertdegreetoradian(solution1/100);
    solution2=Convertdegreetoradian(solution2/100);
    solution3=Convertdegreetoradian(solution3/100);
    solution4=Convertdegreetoradian(solution4/100);
c[i].fitness=fitness(solution1,solution2,solution3,solution4);
c[i].solnindex=i;
}
/*sorting the fitness array c */
for (i=0;i<10;i++)
  {
           for (j=0;j<10-i-1;j++)
           {
                       if (c[j].fitness<c[j+1].fitness)
                       {
                           temp=c[j];
                           c[j]=c[j+1];
                           c[j+1]=temp;
                       }
           }
  }

/*arranging  of fitness values */
for(i=0;i<10;i++)
    {
        s=s+c[i].fitness;
    }
for(i=0;i<10;i++)
{
    c[i].fitness=c[i].fitness/s;
}
/* arranging the roulette wheel */

for(i=0;i<10;i++)
{
    roulettewheel[i]=c[i];
roulettewheel[i].fitness=(c[i].fitness)*360;
}
/*selecting parents for crossover(reproduction) using roulette wheel*/
for(i=0;i<10;i++)
{
    count[i]=0;
}
for(i=0;i<10;i++)
{
    r = ((double) rand() / (RAND_MAX));
    r=r*360;
    for(j=0;j<10;j++)
    {
        if(r<roulettewheel[j].fitness&&r>roulettewheel[j+1].fitness&&(j!=9))
            count[roulettewheel[j].solnindex]=count[roulettewheel[j].solnindex]+1;
    }
    if(r<roulettewheel[9].fitness&&r>0)
    {
           count[9]++;
    }
}
/*rearranging the roulette wheel array */
for (i = 0; i < 10; i++)
  {
     roulettearr[i].solnindex=i;
     roulettearr[i].fitness=count[i];
  }
for (i = 0; i < 10; i++)
  {
           for (j = 0; j < 10-i-1; j++)
           {
                       if (roulettearr[j].fitness < roulettearr[j+1].fitness)
                       {
                           temp=roulettearr[j];
                           roulettearr[j]=roulettearr[j+1];
                           roulettearr[j+1]=temp;
                       }
           }
  }



/*gathering all the parents which would mate(crossover)*/

for(i=0;i<10;i++)
{
    if(roulettearr[i].fitness==0)
    {
        flag1=i-1;
        break;
    }
}
for(i=0;i<flag1;i++)
{
    a=roulettearr[i].solnindex;
    flag2=0;
    for(j=0;j<roulettearr[i].fitness;j++)
    {
        flag3=0;
        for(n=0;n<13;n++)
        {
            alpha1[flag2][flag3++]=copyofalpha1[a][flag3++];
            alpha2[flag2][flag3++]=copyofalpha2[a][flag3++];
            alpha3[flag2][flag3++]=copyofalpha3[a][flag3++];
            alpha4[flag2][flag3++]=copyofalpha4[a][flag3++];
        }
        flag2++;
    }
}
/*crossover stage begins: only 5 single-point-crossovers(reproduction) done so that 10 children come up:pairs selected-> (1-2),(2-3),(1-3),(1-4),(2-4) */

/*(1-2) crossover at random1 */
random1=(int)(((double) rand() / (RAND_MAX))*13);
for(i=0;i<random1;i++)
{
    crosschildrenofalpha1[0][i]=alpha1[0][i];
     crosschildrenofalpha2[0][i]=alpha2[0][i];
     crosschildrenofalpha3[0][i]=alpha3[0][i];
      crosschildrenofalpha4[0][i]=alpha4[0][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[0][i]=alpha1[1][i];
crosschildrenofalpha2[0][i]=alpha2[1][i];
crosschildrenofalpha3[0][i]=alpha3[1][i];
crosschildrenofalpha4[0][i]=alpha4[1][i];
}
for(i=0;i<random1;i++)
{

    crosschildrenofalpha1[1][i]=alpha1[1][i];
    crosschildrenofalpha2[1][i]=alpha2[1][i];
    crosschildrenofalpha3[1][i]=alpha3[1][i];
    crosschildrenofalpha4[1][i]=alpha4[1][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[1][i]=alpha1[0][i];
    crosschildrenofalpha2[1][i]=alpha2[0][i];
    crosschildrenofalpha3[1][i]=alpha3[0][i];
    crosschildrenofalpha4[1][i]=alpha4[0][i];
}

/*(2-3) crossover at random1 */
random1=(int)(((double) rand() / (RAND_MAX))*13);
for(i=0;i<random1;i++)
{
    crosschildrenofalpha1[2][i]=alpha1[1][i];
     crosschildrenofalpha2[2][i]=alpha2[1][i];
     crosschildrenofalpha3[2][i]=alpha3[1][i];
      crosschildrenofalpha4[2][i]=alpha4[1][i];
}
for(i=random1;i<13;i++)
{
crosschildrenofalpha1[2][i]=alpha1[2][i];
crosschildrenofalpha2[2][i]=alpha2[2][i];
crosschildrenofalpha3[2][i]=alpha3[2][i];
crosschildrenofalpha4[2][i]=alpha4[2][i];
}
for(i=0;i<random1;i++)
{

    crosschildrenofalpha1[3][i]=alpha1[2][i];
    crosschildrenofalpha2[3][i]=alpha2[2][i];
    crosschildrenofalpha3[3][i]=alpha3[2][i];
    crosschildrenofalpha4[3][i]=alpha4[2][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[3][i]=alpha1[1][i];
    crosschildrenofalpha2[3][i]=alpha2[1][i];
    crosschildrenofalpha3[3][i]=alpha3[1][i];
    crosschildrenofalpha4[3][i]=alpha4[1][i];
}



/*(1-3) crossover at random1 */
random1=(int)(((double) rand() / (RAND_MAX))*13);
for(i=0;i<random1;i++)
{
    crosschildrenofalpha1[4][i]=alpha1[0][i];
     crosschildrenofalpha2[4][i]=alpha2[0][i];
     crosschildrenofalpha3[4][i]=alpha3[0][i];
      crosschildrenofalpha4[4][i]=alpha4[0][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[4][i]=alpha1[2][i];
crosschildrenofalpha2[4][i]=alpha2[2][i];
crosschildrenofalpha3[4][i]=alpha3[2][i];
crosschildrenofalpha4[4][i]=alpha4[2][i];
}
for(i=0;i<random1;i++)
{

    crosschildrenofalpha1[5][i]=alpha1[2][i];
    crosschildrenofalpha2[5][i]=alpha2[2][i];
    crosschildrenofalpha3[5][i]=alpha3[2][i];
    crosschildrenofalpha4[5][i]=alpha4[2][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[5][i]=alpha1[0][i];
    crosschildrenofalpha2[5][i]=alpha2[0][i];
    crosschildrenofalpha3[5][i]=alpha3[0][i];
    crosschildrenofalpha4[5][i]=alpha4[0][i];
}



/*(1-4) crossover at random1 */
random1=(int)(((double) rand() / (RAND_MAX))*13);
for(i=0;i<random1;i++)
{
    crosschildrenofalpha1[6][i]=alpha1[0][i];
     crosschildrenofalpha2[6][i]=alpha2[0][i];
     crosschildrenofalpha3[6][i]=alpha3[0][i];
      crosschildrenofalpha4[6][i]=alpha4[0][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[6][i]=alpha1[3][i];
crosschildrenofalpha2[6][i]=alpha2[3][i];
crosschildrenofalpha3[6][i]=alpha3[3][i];
crosschildrenofalpha4[6][i]=alpha4[3][i];
}
for(i=0;i<random1;i++)
{

    crosschildrenofalpha1[7][i]=alpha1[3][i];
    crosschildrenofalpha2[7][i]=alpha2[3][i];
    crosschildrenofalpha3[7][i]=alpha3[3][i];
    crosschildrenofalpha4[7][i]=alpha4[3][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[7][i]=alpha1[0][i];
    crosschildrenofalpha2[7][i]=alpha2[0][i];
    crosschildrenofalpha3[7][i]=alpha3[0][i];
    crosschildrenofalpha4[7][i]=alpha4[0][i];
}

/*(2-4) crossover at random1 */
random1=(int)(((double) rand() / (RAND_MAX))*13);
for(i=0;i<random1;i++)
{
    crosschildrenofalpha1[8][i]=alpha1[1][i];
     crosschildrenofalpha2[8][i]=alpha2[1][i];
     crosschildrenofalpha3[8][i]=alpha3[1][i];
      crosschildrenofalpha4[8][i]=alpha4[1][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[8][i]=alpha1[3][i];
crosschildrenofalpha2[8][i]=alpha2[3][i];
crosschildrenofalpha3[8][i]=alpha3[3][i];
crosschildrenofalpha4[8][i]=alpha4[3][i];
}
for(i=0;i<random1;i++)
{

    crosschildrenofalpha1[9][i]=alpha1[3][i];
    crosschildrenofalpha2[9][i]=alpha2[3][i];
    crosschildrenofalpha3[9][i]=alpha3[3][i];
    crosschildrenofalpha4[9][i]=alpha4[3][i];
}
for(i=random1;i<13;i++)
{
    crosschildrenofalpha1[9][i]=alpha1[1][i];
    crosschildrenofalpha2[9][i]=alpha2[1][i];
    crosschildrenofalpha3[9][i]=alpha3[1][i];
    crosschildrenofalpha4[9][i]=alpha4[1][i];
}
/* putting the children formed after crossover in place of parents */

for(i=0;i<10;i++)
{
    for(j=0;j<13;j++)
    {
        alpha1[i][j]=crosschildrenofalpha1[i][j];
        alpha2[i][j]=crosschildrenofalpha2[i][j];
        alpha3[i][j]=crosschildrenofalpha3[i][j];
        alpha4[i][j]=crosschildrenofalpha4[i][j];

    }
}
/*mutation stage begins */
for(i=0;i<10;i++)
{
    k1=(int)(((double) rand() / (RAND_MAX))*13);
    k2=(int)(((double) rand() / (RAND_MAX))*13);
    if (alpha1[i][k1]==0)
    {
        alpha1[i][k1]=1;
    }
    else
        {
            alpha1[i][k1]=0;
        }
        if (alpha1[i][k2]==0)
    {
        alpha1[i][k2]=1;
    }
    else
        {
            alpha1[i][k2]=0;
        }
        if (alpha2[i][k1]==0)
    {
        alpha2[i][k1]=1;
    }
    else
        {
            alpha2[i][k1]=0;
        }
        if (alpha2[i][k2]==0)
    {
        alpha2[i][k2]=1;
    }
    else
        {
            alpha2[i][k2]=0;
        }

      if (alpha3[i][k1]==0)
    {
        alpha3[i][k1]=1;
    }
    else
        {
            alpha3[i][k1]=0;
        }
        if (alpha3[i][k2]==0)
    {
        alpha3[i][k2]=1;
    }
    else
        {
            alpha3[i][k2]=0;
        }
        if (alpha4[i][k1]==0)
    {
        alpha4[i][k1]=1;
    }
    else
        {
            alpha4[i][k1]=0;
        }
        if (alpha4[i][k2]==0)
    {
        alpha4[i][k2]=1;
    }
    else
        {
            alpha4[i][k2]=0;
        }
    }
/*evolution stage and recalculation of fitness */

for(i=0;i<10;i++)
{
    for(j=0;j<13;j++)
    {
     soln1=soln1*10+alpha1[i][j] ;
     soln2=soln1*10+alpha2[i][j] ;
     soln3=soln1*10+alpha3[i][j] ;
     soln4=soln1*10+alpha4[i][j] ;
    }
    solution1=(float)convertBinaryToDecimal(soln1);
    solution2=(float)convertBinaryToDecimal(soln2);
    solution3=(float)convertBinaryToDecimal(soln3);
    solution4=(float)convertBinaryToDecimal(soln4);
    solution1=Convertdegreetoradian(solution1/100);
    solution2=Convertdegreetoradian(solution2/100);
    solution3=Convertdegreetoradian(solution3/100);
    solution4=Convertdegreetoradian(solution4/100);
c[i].fitness=fitness(solution1,solution2,solution3,solution4);
}
/* checking if the best solution lies within error limits */
for (i=0;i<10;i++)
  {
     checksoln[i].solnindex=i;
     checksoln[i].fitness=c[i].fitness;
  }
for (i=0;i<10;i++)
  {
           for (j=0;j<10-i-1;j++)
           {
                       if (checksoln[j].fitness < checksoln[j+1].fitness)
                       {
                           temp=checksoln[j];
                           checksoln[j]=checksoln[j+1];
                           checksoln[j+1]=temp;
                       }
           }

       }
       indexbest=checksoln[9].solnindex;
 for(i=0;i<13;i++)
    {
        root1=root1*10+alpha1[indexbest][i];
        root2=root2*10+alpha2[indexbest][i];
        root3=root3*10+alpha3[indexbest][i];
        root4=root4*10+alpha4[indexbest][i];

    }
   uproot1=(float)(convertBinaryToDecimal(root1))/100;
   uproot2=(float)(convertBinaryToDecimal(root2))/100;
   uproot3=(float)(convertBinaryToDecimal(root3))/100;
   uproot4=(float)(convertBinaryToDecimal(root4))/100;

    printf("\nValues for firing angles are :%d,%f       %f,%f,%f,%f\n",gen,checksoln[9].fitness,uproot1,uproot2,uproot3,uproot4);
}


    /* retrieving the best solution and printing the results */
    indexbest=checksoln[9].solnindex;
    for(i=0;i<13;i++)
    {
        root1=root1*10+alpha1[indexbest][i];
        root2=root2*10+alpha2[indexbest][i];
        root3=root3*10+alpha3[indexbest][i];
        root4=root4*10+alpha4[indexbest][i];

    }
   uproot1=(float)(convertBinaryToDecimal(root1))/100;
   uproot2=(float)(convertBinaryToDecimal(root2))/100;
   uproot3=(float)(convertBinaryToDecimal(root3))/100;
   uproot4=(float)(convertBinaryToDecimal(root4))/100;
printf("\nValues for firing angles best are :%d,%f      %f,%f,%f,%f\n",gen,checksoln[9].fitness,uproot1,uproot2,uproot3,uproot4);
}













