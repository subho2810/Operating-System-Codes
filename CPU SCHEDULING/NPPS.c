#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define max 30
void main()
{
  int n,i,j,at[max],wt[max],tat[max],bt[max],comp[max],process[max],priority[max],st[max],rt[max];
  float atat=0,awt=0,art=0;
  int is_complete[max];
  memset(is_complete,0,sizeof(is_complete));
  printf("Enter the number of process --> ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nProcess %d",i+1);
    printf("\nArrival time --> ");
    scanf("%d",&at[i]);
    printf("Burst time     --> ");
    scanf("%d",&bt[i]);
    printf("Priority given --> ");
    scanf("%d",&priority[i]);
    process[i]=i+1;
  }
  int current_time=0;
  int completed=0;
  int prev=0;
  while(completed!=n)
  {
    int idx=-1;
    int mx=-1;
    for(i=0;i<n;i++)
    {
      if(at[i]<=current_time && is_complete[i]==0)
      {
        if(priority[i]>mx)
        {
          mx=priority[i];
          idx=i;
        }
        if(priority[i]==mx)
        {
          if(at[i]<at[idx])
          {
            mx=priority[i];
            idx=i;
          }
        }
      }
    }
    if(idx!=-1)
    {
     st[idx]=current_time;
     comp[idx]=current_time+bt[idx];
     tat[idx]=comp[idx]-at[idx];
     wt[idx]=tat[idx]-bt[idx];
     rt[idx]=st[idx]-at[idx];

     awt+=wt[idx];
     atat+=tat[idx];
     art+=rt[idx];
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
  printf("PROCESS  PRIORITY  AT\t  BT\t  CT\t  WT\t  TAT\t  RT\n");
  for(int i=0;i<n;i++)
   {
      printf("%d\t %d\t   %d\t   %d\t   %d\t   %d\t   %d\t   %d\n",process[i],priority[i],at[i],bt[i],comp[i],wt[i],tat[i],rt[i]);
   }
   printf("Average waiting time => %f",awt/n);
   printf("\nAverage Turn around time => %f",atat/n);
   printf("\nAverage Response time=> %f",art/n);
}