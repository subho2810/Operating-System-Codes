#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define max 20
#define f 3
void main()
{
  int refstr[max],i,j,k,l,len,farr[f],miss=0,hit=0;
  float hr,mr;
  memset(farr,-1,sizeof(farr));
  printf("Enter the length of the reference string\n");
  scanf("%d",&len);
  printf("Enter the reference string\n");
  for(i=0;i<len;i++)
  {
    scanf("%d ",&refstr[i]);
  }
  j=0;
  int count=0;
  for(i=0;i<len;i++)
  {
    j=j%f;
    count=0;
    for(k=0;k<f;k++)
    {
      if(farr[k]==refstr[i])
      {
        count=1;
        hit=hit+1;
        break;
      }

    }
    if(count!=1)
    {
      miss=miss+1;
      farr[j]=refstr[i];
      j++;
    }
    if(count==1)
    {
      printf("{Hit} -> ");
    }
    else
    printf("Miss ->  ");
    for(l=0;l<f;l++)
    {
      if(farr[l]!=-1)
      printf("%d ",farr[l]);
      else
      printf(" ");
    }
    printf("\n\n");
  
  }
  float x=len;
   hr=(hit/x)*100;
   mr=(miss/x)*100;
   
  printf("\nHit ratio --> %f\n",hr);
  printf("\nMiss ratio --> %f\n",mr);
  


}