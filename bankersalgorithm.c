#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void main()
{
  int n;
  printf("Enter the number of processes\n");
  scanf("%d",&n);
  int i,j,Allocation[n][4],MaxNeed[n][4],Available[4],RemainingNeed[n][4],count=0,c=0;
  int is_complete[n];
  memset(is_complete,0,sizeof(is_complete));
  printf("Enter the allocations\n");
  for(i=0;i<n;i++)
  {
    printf("Process %d\n",(i+1));
    
    for(j=0;j<4;j++)
    { 

      scanf("%d",&Allocation[i][j]);
    }
  }
  printf("Enter the Max Need\n");
  for(i=0;i<n;i++)
  {
    printf("Process %d\n",(i+1));
    for(j=0;j<4;j++)
    {
      scanf("%d",&MaxNeed[i][j]);
    }
  }
  printf("Available resources\n");
  for(i=0;i<4;i++)
  {
    scanf("%d",&Available[i]);
  }
  
  for(i=0;i<n;i++)
  {
    
    for(j=0;j<4;j++)
    {
     RemainingNeed[i][j]=MaxNeed[i][j]-Allocation[i][j];
    }
  }
  i=0;
  while(count!=n)
  {
    i=i%n;
    if(is_complete[i]==0)
    {
      c=0;
      for(int j=0;j<4;j++)
        {
          if(RemainingNeed[i][j]<=Available[j])
          {
            c++;
          }
        }
      if(c==4)
      {
        printf("P(%d) --> ",(i+1));
        count++;
        is_complete[i]=1;
        for(int j=0;j<4;j++)
          {
            Available[j]+=Allocation[i][j];
          }
      }
    }
    i++;

  }


}