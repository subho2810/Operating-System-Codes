#include <stdio.h>
#include <conio.h>
#include <math.h>
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
int hyperperiod(int *period,int n)
{
  int k=period[0];
  n--;
  while(n>=1)
  {
    k=lcm(k,period[n--]);

  }
  return k;
}
void swap(int *a,int j)
{
  int temp=a[j];
  a[j]=a[j+1];
  a[j+1]=temp;
}
int main()
{
  int i,j,n,exec[30],period[30],rt[30],ready[30],pr_id[30];
  float utilization = 0;
  int totalExecutionTime=0,lcm_pr;
  printf("Enter the number of process -> ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("P %d\n",(i+1));
    
    printf("Period time -> ");
    scanf("%d",&period[i]);
    printf("Exceution time -> ");
    scanf("%d",&exec[i]);
    pr_id[i]=i+1;
    ready[i]=1;
    rt[i]=exec[i];
    
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(period[j]>period[j+1])
      {
        swap(period,j);
        swap(exec,j);
        swap(pr_id,j);
        swap(rt,j);
        swap(ready,j);
      }
    }
  }
  lcm_pr=hyperperiod(period,n);
  printf("\nProcess No.\t\tExecution time \t\t Period\n");
   for(int i=0 ; i<n ; i++)
   {
        totalExecutionTime+=(lcm_pr/period[i])*exec[i];
        printf("%d\t\t\t%d\t\t\t%d\n",pr_id[i],exec[i],period[i]);        
   }
   if(totalExecutionTime > lcm_pr){
        printf("\n\nTotal execution time is more than LCM so RMS is not feasible here\n");
        return 0;
    }
    utilization=(totalExecutionTime*1.0/lcm_pr) *100;
    printf("Utilization -> %f \n",utilization);
    printf("LCM -> %d \n",lcm_pr);
    printf("\nTIME\t\tRUNNING PROCESS\n");
    for( i=0 ; i<lcm_pr ; i++){
        if(i>=period[0])
            for(int j=0 ; j<n ; j++){
                if(!(i%period[j]))
                    ready[j]=1;
            }
        for(int j=0 ; j<n ; j++){
            if(ready[j]==1){
                if(rt[j]>0){
                    if(!(--(rt[j]))){
                        ready[j]=0;
                        rt[j]=exec[j];
                    }
                }
                printf("%d\t\t\tP%d\n",i,pr_id[j]);
                break;
            }
            if(j == n-1)
                   printf("(%d) Empty Slot\n",i);
        }
        
    }
}
