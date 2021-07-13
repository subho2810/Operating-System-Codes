import java.io.*;
class bankersalgo
{
  public static void main(String args[])throws IOException
  {
    BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
    int process;
    System.out.println("Enter the number of processes");
    process=Integer.parseInt(in.readLine());
    int Allocation[][]=new int[process][3];
    int maxneed[][]=new int[process][3];
    int available[]=new int[3];
    int Remainingneed[][]=new int[process][3];
    int iscompleted[]=new int[process];
    System.out.println("Enter the allocation");
    for(int i=0;i<process;i++)
    {
      System.out.println("P"+(i+1));
      for(int j=0;j<3;j++)
      {
        Allocation[i][j]=Integer.parseInt(in.readLine());
      }
    }
    System.out.println("Enter the max need");
    for(int i=0;i<process;i++)
    {
      System.out.println("P"+(i+1));
      for(int j=0;j<3;j++)
      {
        maxneed[i][j]=Integer.parseInt(in.readLine());
      }
    }
    for(int i=0;i<process;i++)
    {
      
      for(int j=0;j<3;j++)
      {
        Remainingneed[i][j]=maxneed[i][j]-Allocation[i][j];
      }
    }
    System.out.println("Available resources");
    for(int i=0;i<3;i++)
    {
      available[i]=Integer.parseInt(in.readLine());
    }
    String sequence="";
    int count=0;
    int i=0;
    while(count!=process)
    {
      
      i=i%process;
      if(iscompleted[i]==0)
      {
        int c=0;
        for(int j=0;j<3;j++)
        {
          if(Remainingneed[i][j]<=available[j])
          {
            c++;
          }
        }
         
        if(c==3)
        {
          sequence=sequence+"P"+(i+1)+" --> ";
          count++;
          iscompleted[i]=1;
          for(int j=0;j<3;j++)
          {
            available[j]+=Allocation[i][j];
          }
        }
      }
      i++;
    }
    System.out.println(sequence);
    }


  }
