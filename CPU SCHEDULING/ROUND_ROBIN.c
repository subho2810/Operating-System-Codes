#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define max 100
void push(int,int);
void pop();
int empty();
int front1();
void swap(int*,int);
int q[max],front=-1,rear=-1;

void main()
{
  
   int tq,n,i,idx,j,at[max],wt[max],tat[max],bt[max],comp[max],st[max],rt[max];
   float atat=0,awt=0,art=0;
   int mark[max];
   int p[max];
   int burst_remaining[max];
   printf("Enter the number of processes\n");
   scanf("%d",&n);
   printf("Enter the Time Quantam\n");
   scanf("%d",&tq);
   for(int i=0;i<n;i++)
   {
     printf("\nProcess %d",i+1);
     printf("\nArrival time --> ");
     scanf("%d",&at[i]);
     printf("Burst time --> ");
     scanf("%d",&bt[i]);
     burst_remaining[i]=bt[i];
     p[i]=i+1;
   }
  int temp=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(at[j]>at[j+1])
      {
        swap(at,j);
        swap(p,j);
        swap(bt,j);
        swap(burst_remaining,j);
      }
    }
  }
   
   int current_time=0;
   push(0,n);
   int completed=0;
   memset(mark,0,sizeof(mark));
   mark[0]=1;
   while(completed!=n)
   {
     idx=front1();
     pop(); 
     if(burst_remaining[idx]==bt[idx])
     {
       st[idx]=(current_time>at[idx])?current_time:at[idx];
       current_time=st[idx];
     }
     if(burst_remaining[idx]-tq>0)
     {
       burst_remaining[idx]-=tq;
       current_time+=tq;
     }
     else{
       current_time+=burst_remaining[idx];
       burst_remaining[idx]=0;
       completed++;
       comp[idx]=current_time;
       tat[idx]=comp[idx]-at[idx];
       wt[idx]=tat[idx]-bt[idx];
       rt[idx]=st[idx]-at[idx];

       awt+=wt[idx];
       atat+=tat[idx];
       art+=rt[idx];
       
     }
     for(int i=1;i<n;i++)
     {
       if(burst_remaining[i]>0 && at[i]<=current_time && mark[i]==0){
         push(i,n);
         mark[i]=1;
       }
     }
     if(burst_remaining[idx]>0)
     push(idx,n);

     if(empty()==1)
     {
       for(int i=1;i<n;i++)
     {
       if(burst_remaining[i]>0){
         push(i,n);
         mark[i]=1;
         break;
       }
     }
     }
   }
    temp=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(p[j]>p[j+1])
      {
        swap(at,j);
        swap(p,j);
        swap(bt,j);
        swap(wt,j);
        swap(rt,j);
        swap(tat,j);
        swap(comp,j);
      }
    }
  }
  printf("PROCESS\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tWAITING TIME\tTURN AROUND TIME\tRESPONSE TIME\n");
  for(int i=0;i<n;i++)
   {
      printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i],at[i],bt[i],comp[i],wt[i],tat[i],rt[i]);
   }
   printf("Average waiting time => %f",awt/n);
   printf("\nAverage Turn around time => %f",atat/n);
    printf("\nAverage Response time=> %f",art/n);
}
void swap(int *a,int j)
{
  int temp=0;
  temp=a[j];
  a[j]=a[j+1];
  a[j+1]=temp;
}
void push(int v,int x)
{
  if(rear==x-1)
  printf("QUEUE\n");
  else
  {
    if(front==-1)
    front=0;
    rear++;
    q[rear]=v;
  }
}
void pop()
{
  if(front==-1)
  printf("QUEUE\n");
  else
  {
    front++;
    if(front>rear)
    front=rear=-1;
  }
}
int empty()
{
  if(front==-1)
  return 1;
  else
  return 0;
}
int front1()
{
  if(front==-1)
   printf("QUEUE\n");
   else
   return q[front];

}

  
