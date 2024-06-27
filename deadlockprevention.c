#include<stdio.h>
#include<conio.h>
int max[10][10],alloc[10][10],need[10][10],avail[10],i,j,p,r,finish[10]={0},flag=0;
void fun();
void main( )
{

printf("\n\nSIMULATION OF DEADLOCK PREVENTION");
printf("Enter no. of processes, resources");
scanf("%d%d",&p,&r);
printf("Enter allocation matrix");
for(i=0;i<p;i++)
  for(j=0;j<r;j++)
     scanf("%d",&alloc[i][j]);
printf("enter max matrix");
for(i=0;i<p;i++)                             /*reading the maximum matrix and availale
                                                                          matrix*/
   for(j=0;j<r;j++)
     scanf("%d",&max[i][j]);
printf("enter available matrix");
for(i=0;i<r;i++)
  scanf("%d",&avail[i]);
for(i=0;i<p;i++)
  for(j=0;j<r;j++)
            need[i][j]=max[i][j]-alloc[i][j];
fun(); /*calling function*/
if(flag==0)
{
     if(finish[i]!=1)
     {
           printf("\n\n Failing :Mutual exclusion");
for(j=0;j<r;j++)
{ /*checking for mutual exclusion*/
     if(avail[j]<need[i][j])
          avail[j]=need[i][j];
}
fun();
printf("\n By allocating required resources to process %d dead lock is prevented" ,i);
printf("\n\n lack of no preemption");
for(j=0;j<r;j++)
{
          if(avail[j]<need[i][j])
                avail[j]=need[i][j];
          alloc[i][j]=0;
}
fun( );
printf("\n\n dead lock is prevented by allocating needed resources");
printf(" \n \n failing:Hold and Wait condition ");
for(j=0;j<r;j++)
{                          /*checking hold and wait condition*/
           if(avail[j]<need[i][j])
               avail[j]=need[i][j];
}
fun( );
printf("\n AVOIDING ANY ONE OF THE CONDITION, U CAN PREVEMT DEADLOCK");
}
}
}
void fun( )
{
   while(1)
   {
       for(flag=0,i=0;i<p;i++)
       {
            if(finish[i]==0)
            {
      	for(j=0;j<r;j++)
	{
	 if(need[i][j]<=avail[j])
		continue;
	 else
		break;
                         }
                   if(j==r)
                   {
                        for(j=0;j<r;j++)
 		avail[j]+=alloc[i][j];
	  flag=1;
	  finish[i]=1;
	}
                 }
           }
           if(flag==0)
               break;
          }
}
