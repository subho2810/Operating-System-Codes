#include<stdio.h>
#include<String.h>
int at1[30],at2[30],priority2[30],process2[30],at3[30];
int bt1[30],bt2[30],bt3[30];

int Total=0,t1=0,t2=0,t3=0;

int n,i=0,at[30],bt[30],pr[30],j=0,k=0,l=0;

int tq,n,i,idx,j,wt1[30],tat1[30],comp1[30],st1[30],rt1[30],p1[30];
 float atat1=0,awt1=0,art1=0;
int burst_remaining[30]; 
int q[100],front=-1,rear=-1;

int p,wt3[30],tat3[30],comp3[30];
float awt3=0.0,atat3=0.0;

int wt2[30],tat2[30],comp2[30],st2[30],rt2[30];
float awt2=0.0,atat2=0.0,art2=0.0;

int current_time=0;
void swap(int *a,int f)
{
  int temp=0;
  temp=a[f];
  a[f]=a[f+1];
  a[f+1]=temp;
}
void push(int v,int x)
{
  if(rear==x-1)
  printf("\n");
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
  printf("\n");
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
   printf("\n");
   else
   return q[front];

}



void round_robin()
{
  printf("\n\n Round Robin\n");
	int temp=0,idx=0,tq=2;
  int mark[30];
  for(int m=0;m<n;m++)
  {
    for(int f=0;f<j-m-1;m++)
    {
      if(at1[f]>at1[f+1])
      {
        swap(at1,f);
        swap(p1,f);
        swap(bt1,f);
        swap(burst_remaining,f);
      }
    }
  }
   
   //int current_time=0;
   push(0,j);
   int completed=0;
   memset(mark,0,sizeof(mark));
   mark[0]=1;
   while(completed!=j)
   {
     idx=front1();
     pop(); 
     if(burst_remaining[idx]==bt1[idx])
     {
       st1[idx]=(current_time>at1[idx])?current_time:at1[idx];
       current_time=st1[idx];
     }
     if(burst_remaining[idx]-tq>=0)
     {
       burst_remaining[idx]-=tq;
       current_time+=tq;
     }
     else{
       current_time+=burst_remaining[idx];
       burst_remaining[idx]=0;
       completed++;
       comp1[idx]=current_time;
       tat1[idx]=comp1[idx]-at1[idx];
       wt1[idx]=tat1[idx]-bt1[idx];
       rt1[idx]=st1[idx]-at1[idx];

       awt1+=wt1[idx];
       atat1+=tat1[idx];
       art1+=rt1[idx];
       
     }
     for(int m=1;m<n;m++)
     {
       if(burst_remaining[m]>0 && at1[m]<=current_time && mark[m]==0){
         push(m,j);
         mark[m]=1;
       }
     }
     if(burst_remaining[idx]>0)
     push(idx,j);

     if(empty()==1)
     {
       for(int m=1;m<n;m++)
     {
       if(burst_remaining[m]>0){
         push(m,j);
         mark[m]=1;
         break;
       }
     }
     }
   }
    temp=0;
  for(int m=0;m<j;m++)
  {
    for(int f=0;f<j-m-1;f++)
    {
      if(p1[f]>p1[f+1])
      {
        swap(at1,f);
        swap(p1,f);
        swap(bt1,f);
        swap(wt1,f);
        swap(rt1,f);
        swap(tat1,f);
        swap(comp1,f);
      }
    }
  }
  printf("PROCESS\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tWAITING TIME\tTURN AROUND TIME\tRESPONSE TIME\n");
  for(int m=0;m<j;m++)
   {
      printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p1[m],at1[m],bt1[m],comp1[m],wt1[m],tat1[m],rt1[m]);
   }
   printf("Average waiting time => %f",awt1/j);
   printf("\nAverage Turn around time => %f",atat1/j);
    printf("\nAverage Response time=> %f",art1/j);
}

void priority()
{
  printf("\n\n Priority non preemptive\n");
	//int current_time=0;
  int completed=0;
  int prev=0;
  int is_complete[30];
  memset(is_complete,0,sizeof(is_complete));
  int m=0;
  while(completed!=k)
  {
    int idx=-1;
    int mx=-1;
    for(m=0;m<k;m++)
    {
      if(at2[m]<=current_time && is_complete[m]==0)
      {
        if(priority2[m]>mx)
        {
          mx=priority2[m];
          idx=m;
        }
        if(priority2[m]==mx)
        {
          if(at2[m]<at2[idx])
          {
            mx=priority2[m];
            idx=m;
          }
        }
      }
    }
    if(idx!=-1)
    {
     st2[idx]=current_time;
     comp2[idx]=current_time+bt2[idx];
     tat2[idx]=comp2[idx]-at2[idx];
     wt2[idx]=tat2[idx]-bt2[idx];
     rt2[idx]=st2[idx]-at2[idx];

     awt2+=wt2[idx];
     atat2+=tat2[idx];
     art2+=rt2[idx];
     is_complete[idx]=1;
     completed++;
     current_time=comp2[idx];
     prev=current_time;

    }
    else
    {
      current_time++;
    }
  }
  printf("PROCESS  PRIORITY  AT\t  BT\t  CT\t  WT\t  TAT\t  RT\n");
  for(int i=0;i<k;i++)
   {
      printf("%d\t %d\t   %d\t   %d\t   %d\t   %d\t   %d\t   %d\n",process2[i],priority2[i],at2[i],bt2[i],comp2[i],wt2[i],tat2[i],rt2[i]);
   }
   printf("Average waiting time => %f",awt2/k);
   printf("\nAverage Turn around time => %f",atat2/k);
   printf("\nAverage Response time=> %f",art2/k);

}

void fcfs()
{
  printf("\n\n First cum First serve\n");
  int temp=0,m=0,f=0,completed=0;
  int is_complete[30];
  memset(is_complete,0,sizeof(is_complete));
	for(f=0;f<l;f++)
  {
    for(m=0;j<l-f-1;m++)
    {
      if(at3[m]>at3[m+1])
      {
        temp=at3[m];
        at3[m]=at3[m+1];
        at3[m+1]=temp;
        temp=bt3[m];
        bt3[m]=bt3[m+1];
        bt3[m+1]=temp;
        
      }
    }
  }

  printf("PROCESS\tARRIVAL TIME\t BURST TIME\tCOMPLETION TIME\tWAITING TIME\tTURN AROUND TIME\n");
  for(m=0;m<l;m++)
  {
    wt3[m]=0;
    tat3[m]=0;
    comp3[m]=0;
    if(at3[m]>current_time)
    {
      current_time++;
      m--;
      continue;
    }
    current_time+=bt3[m];
    comp3[m]=current_time;
    tat3[m]=comp3[m]-at3[m];
    wt3[m]=tat3[m]-bt3[m];
    awt3=awt3+wt3[m];
    atat3=atat3+tat3[m];
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",m+1,at3[m],bt3[m],comp3[m],wt3[m],tat3[m]);

  }
  printf("Average waiting time => %f",awt3/l);
  printf("\nAverage Turn around time => %f",atat3/l);
  printf("\n");
}



void round_robin1()
{
	printf("Time Quantum between the 3 queues is 10\n");
	for(i=1;i<Total;i=i+10)
	{
		if(t1>10)
		{
			printf("Queue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
			printf("Queue1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("Queue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("Queue2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("Queue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("Queue3 is running for %d units\n",t3);
			t3=0;
		}
	}
}

int main()
{
	printf("Enter the no. of process you want to enter\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process[%d]\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&pr[i]);
		Total=Total+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("Process[%d] belongs to Queue 1\n",i+1);
			at1[j]=at[i];
			bt1[j]=bt[i];
      burst_remaining[j]=bt[i];
      p1[j]=j+1;
			j++;
			t1=t1+bt[i];
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			at2[k]=at[i];
			bt2[k]=bt[i];
			priority2[k]=pr[i];
			process2[k]=k+1;
			k++;
			t2=t2+bt[i];
		}
		
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			at3[l]=at[i];
			bt3[l]=bt[i];
     
			l++;
			t3=t3+bt[i];
		}
	}
	
	round_robin1();
	round_robin();
  priority();
	fcfs();

	
	
}
