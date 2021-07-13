#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define max 30
void sort(int*,int*,int);
void main()
{
  int i,j,n,at[max],bt[max],tat[max],comp[max],wt[max];
  float awt=0,atat=0;
  int is_complete[max];
  memset(is_complete,0,sizeof(is_complete));
  printf("Enter the number of process --> ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nProcess %d\n",i+1);
    printf("Arrival time --> ");
    scanf("%d",&at[i]);
    printf("\nBurst time --> ");
    scanf("%d",&bt[i]);
  }
 
  int temp=0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(at[j]>at[j+1])
      {
        temp=at[j];
        at[j]=at[j+1];
        at[j+1]=temp;
        temp=bt[j];
        bt[j]=bt[j+1];
        bt[j+1]=temp;
        

      }
    }
  }
  int current_time=0,completed=0;
  while(completed!=n)
  {
    float hrrn=-99999;
    float temp=0;
    int idx=-1;
    for(i=0;i<n;i++)
    {
      if(at[i]<=current_time && is_complete[i]==0)
      {
        temp=((bt[i]+(current_time-at[i]))/bt[i]);
        if(hrrn<temp)
        {
          hrrn=temp;
          idx=i;
        }

      }
    }
    if(idx!=-1)
    {
      current_time+=bt[idx];
      comp[idx]=current_time;
      tat[idx]=comp[idx]-at[idx];
      wt[idx]=tat[idx]-bt[idx];
      awt+=wt[idx];
      atat+=tat[idx];
      is_complete[idx]=1;
      completed++;
    }
    else
    current_time++;
  }
   printf("PROCESS\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\t WAITING TIME\t TURN AROUND TIME\n");
    for(int i=0;i<n;i++)
   {
      printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],comp[i],wt[i],tat[i]);
   }
   printf("Average waiting time => %f",awt/n);
   printf("\nAverage Turn around time => %f",atat/n);
}
