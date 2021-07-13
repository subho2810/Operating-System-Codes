#include <stdio.h>
#include <conio.h>
#include <string.h>
#define max 30
void main()
{
  int n,i,j,at[max],wt[max],tat[max],bt[max],comp[max];
  float atat=0,awt=0;
  int is_complete[max];
  memset(is_complete,0,sizeof(is_complete));
  printf("Enter the number of process --> ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nProcess %d\n",i+1);
    printf("Arrival time --> ");
    scanf("%d",&at[i]);
    printf("Burst time --> ");
    scanf("%d",&bt[i]);
  }
  int current_time=0;
  int completed=0;
  int prev=0;
  printf("PROCESS\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\t WAITING TIME\t TURN AROUND TIME\n");
  while(completed!=n)
  {
    int idx=-1;
    int mn=10000000;

    for(i=0;i<n;i++)
    {
      if(at[i]<=current_time && is_complete[i]==0)
      {
        if(bt[i]<mn)
        {
          mn=bt[i];
          idx=i;
        }
        if(bt[i]==mn)
        {
          if(at[i]<at[idx])
          {
            mn=bt[i];
            idx=i;
          }
        }
      }
    }
    if(idx!=-1)
    {
      comp[idx]=current_time+bt[idx];
      tat[idx]=comp[idx]-at[idx];
      wt[idx]=tat[idx]-bt[idx];
      awt=awt+wt[idx];
      atat=atat+tat[idx];
      is_complete[idx]=1;
      completed++;
      current_time=comp[idx];
      prev=current_time;
       

    }
    else
    {
      current_time++;
    }
  }
   for(int i=0;i<n;i++)
   {
      printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],comp[i],wt[i],tat[i]);
   }
   printf("Average waiting time => %f",awt/n);
   printf("\nAverage Turn around time => %f",atat/n);



}