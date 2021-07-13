#include <stdio.h>
#include <conio.h>
#include <string.h>
#define max 30
void main()
{
  int n,i,j,at[max],wt[max],tat[max],bt[max],comp[max],st[max],rt[max];
  float atat=0,awt=0,art=0;
  int is_complete[max];
  int burst_remaining[max];
  memset(is_complete,0,sizeof(is_complete));
  printf("Enter the number of process --> ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nProcess %d",i+1);
    printf("\nArrival time --> ");
    scanf("%d",&at[i]);
    printf("Burst time --> ");
    scanf("%d",&bt[i]);
    burst_remaining[i]=bt[i];
  }
  int current_time=0;
  int completed=0;
  int prev=0;
  printf("PROCESS\t\tARRIVAL TIME\t\tBURST TIME\t\tCOMPLETION TIME\t\tWAITING TIME\t\tTURN AROUND TIME\tRESPONSE TIME\n");
  while(completed!=n)
  {
    int idx=-1;
    int mn=100000;
    for(i=0;i<n;i++)
    {
      if(at[i]<=current_time && is_complete[i]==0)
      {
        if(burst_remaining[i]<mn)
        {
          mn=burst_remaining[i];
          idx=i;
        }
        if(burst_remaining[i]==mn)
        {
          if(at[i]<at[idx])
          {
            mn=burst_remaining[i];
            idx=i;
          }
        }

      }
    }
    if(idx!=-1)
    {
     if(burst_remaining[idx]==bt[idx])
     {
       st[idx]=current_time;

     }
     burst_remaining[idx]-=1;
     current_time++;
     prev=current_time;

     if(burst_remaining[idx]==0)
     {
       comp[idx]=current_time;
       tat[idx]=comp[idx]-at[idx];
       wt[idx]=tat[idx]-bt[idx];
       rt[idx]=st[idx]-at[idx];

       awt+=wt[idx];
       atat+=tat[idx];
       art+=rt[idx];

       is_complete[idx]=1;
       completed++;

     }
    }
    else{
      current_time++;
    }
  }
  for(int i=0;i<n;i++)
   {
      printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,at[i],bt[i],comp[i],wt[i],tat[i],rt[i]);
   }
   printf("Average waiting time => %f",awt/n);
   printf("\nAverage Turn around time => %f",atat/n);
    printf("\nAverage Response time=> %f",art/n);
}