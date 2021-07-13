#include <stdio.h>
#include <conio.h>
#define max 30
void main()
{
  int i,j,n,temp,at[max],bt[max],wt[max],tat[max],comp[max],index[max];
  float awt=0,atat=0;
  printf("Enter the number of process --> ");
  scanf("%d",&n);
  printf("Enter the Burst time of the process\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
    index[i]=i+1;
  }
  printf("\nEnter the arrival time of the process\n");
  temp=0;
  for(i=0;i<n;i++)
  {
    scanf("%d",&at[i]);
  }
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
        temp=index[j];
        index[j]=index[j+1];
        index[j+1]=temp;

      }
    }
  }
 temp=0;
  printf("PROCESS\tARRIVAL TIME\t BURST TIME\tCOMPLETION TIME\tWAITING TIME\tTURN AROUND TIME\n");
  for(i=0;i<n;i++)
  {
    wt[i]=0;
    tat[i]=0;
    comp[i]=0;
    if(at[i]>temp)
    {
      temp=temp+1;
      i--;
      continue;
    }
    temp=temp+bt[i];
    comp[i]=temp;
    tat[i]=comp[i]-at[i];
    wt[i]=tat[i]-bt[i];
    awt=awt+wt[i];
    atat=atat+tat[i];
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",index[i],at[i],bt[i],comp[i],wt[i],tat[i]);

  }
  printf("Average waiting time => %f",awt/n);
  printf("\nAverage Turn around time => %f",atat/n);


}