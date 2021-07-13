#include <stdio.h>
#include <conio.h>
#define max 30
void main()
{
  int i,j,n,bt[max],wt[max],tat[max];
  float awt=0,atat=0;
  
  printf("Enter the number of processes -->  ");
  scanf("%d",&n);
  printf("Enter the Burst Time from the user\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
  }
  printf("PROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
  for(i=0;i<n;i++)
  {
    wt[i]=0;
    tat[i]=0;
    for(j=0;j<i;j++)
    {
      wt[i]=wt[i]+bt[j];
    }
    tat[i]=wt[i]+bt[i];
    awt=awt+wt[i];
    atat=atat+tat[i];
    printf("%d\t%d\t\t%d\t\t%d\n",(i+1),bt[i],wt[i],tat[i]);
  }
  printf("Average waiting time = %f ",(awt/n));
  printf("Average Turn Around Time = %f",(atat/n));
  getch();
  

}