#include <stdio.h>
#include <string.h>

int gcd(int a,int b)
{
  if(b==0)
  return a;
  else
  gcd(b,a%b);
}
int lcm(int a,int b)
{
  return ((a*b)/gcd(a,b));
}
int hyperperiod(float period[],int n)
{
  int k=period[0];
  n--;
  while(n>=1)
  {
    k=lcm(k,period[n--]);

  }
  return k;
}
int edf(float *period,int n,int t,float *deadline)
{
  int i,small=10000.0f,smallindex=0;
  for(i=0;i<n;i++)
  {
    if(period[i]<small && (period[i]-t)<=deadline[i])
    {
      small=period[i];
      smallindex=i;
    }
  }
  if(small==10000.0f)
  {
    return -1;
  }
  return smallindex;
}

int main()
{
  int i,j,n,c,d,k,nextTime=0,time=0,task,preemption_count;
  float exec[30],period[30],individual_util[30],flag[30],release[30];
  float deadline[30],instance[30],ex[30],responsemax[30],responsemin[30],tempmax;
  float util=0;
  printf("\nEARLIEST DEADLINE FIRST SCHEDULLING\n");
  printf("Enter the number of process -> ");
  scanf("%d",&n);
  printf("\n Enter the data\n");
  for(i=0;i<n;i++)
  {
    printf("\nRelease time -> ");
    scanf("%f",&release[i]);
    printf("Period time -> ");
    scanf("%f",&period[i]);
    printf("Exceution time -> ");
    scanf("%f",&exec[i]);
    printf("Deadline -> ");
    scanf("%f",&deadline[i]);
  }
  for(i=0;i<n;i++)
  {
    individual_util[i]=exec[i]/period[i];
    util+=individual_util[i];
    responsemax[i]=exec[i];
    deadline[i]=period[i];
    instance[i]=0.0f;
  }
  util=util*100;
  if(util>100)
  {
    printf("Utilization factor = %0.2f \n\nScheduling is not possible as Utilization factor is above 100\n",util);
  }
  else{
    printf("Utilization factor = %0.2f \n\nScheduling is  possible as Utilization factor is below 100\n",util);
    printf("\nHyperperiod of the given task set is : %d\n\n",k=hyperperiod(period,n));
    c=0;
    while(time<k)
    {
      nextTime=time+1;
      task=edf(period,n,time,deadline);
      if(task==-1)
      {
        printf("(%d,%d) -->  ",time,nextTime);
        printf("idle\n ");
        time++;
        continue;
      }
      instance[task]++;
      printf("(%d,%d) -->  ",time,nextTime);
      printf("Task %d\n",(task+1));
      ex[c++]=task;
      if(instance[task]==exec[task])
      {
        tempmax=nextTime-(period[task]-deadline[task]);
        if(instance[task]<tempmax)
        {
          responsemax[task]=tempmax;
        }
        else
        {
        responsemin[task]=instance[task];
        }
        if(deadline[task]==k)
        {
          responsemin[task]=responsemax[task];
        }
        period[task]+=deadline[task];
        instance[task]=0.0f;
      }
      time++;
    }
    for(i=0;i<n;i++)
    {
      printf("\n\nMaximum Response time of Task %d = %f",i+1,responsemax[i]);
      printf("\n\nMinimum Response time of Task %d = %f",i+1,responsemin[i]);
    }
    preemption_count=0;
    for(i=0;i<k;i=j)
    {
     flag[i]=1;
     d=ex[i];
     for(j=i+1;d==ex[j];j++)
     {
       flag[d]++;
     }
     if(flag[d]==exec[d])
     {
       flag[d]=1;
     }
     else{
       flag[d]++;
       preemption_count++;
     }
    }
    printf("\n\nPreemption count = %d",preemption_count); 
  }
 return 0;

}