#include<stdio.h>
#define SIZE 23

int partition(int a[], int i, int f)  
{
  int new[SIZE];
  int x,b = i,e = f;
  int pivot = a[i];
  for(x = i+1; x<=f; x++)
    {
      if (a[x] <= pivot)
	{
	  new[b] = a[x];
	  b++;
	}
      else
	{
	  new[e] = a[x];
	  e--;	    
	}	  
    }
  new[b] = pivot;
  memcpy(&(a[i]),&(new[i]),(f-i+1)*sizeof(int));
  return b;
}

void quicksort(int a[], int i, int f)
{
  int p;
  if (i < f)
    {
      p = partition(a, i, f);
      quicksort(a,i,p-1);
      quicksort(a,p+1,f);
    }
}

int main (void)
{
  int i;
  int a[SIZE] = {-1, 18, 65, 5, 3,
		 2, 7, 1, -15, 78,
		 -89, -7,-15,0,38,
		 -41,-189,-14,-77,-8
		 ,22,21,99};
  quicksort(a, 0, SIZE-1);
  for (i=0;i<SIZE;i++)
    printf("%d ",a[i]); 
  return 0;
}
