#include<stdio.h>

void merge(double l[],int ll, double r[],int rl, double v[])
{
  int i = 0,j = 0,k = 0;
  while ((i < ll) && (j < rl))
    {
      if (l[i] < r[j])
	{
	  v[k] = l[i];
	  i++;
	}
      else
	{
	  v[k] = r[j];
	  j++;
	}
      k++;
    }
  while (i < ll)
    {
      v[k] = l[i];
      i++;
      k++;
    }
  while(j< rl)
    {
      v[k] = r[j];
      j++;
      k++;
    }
}
void mergesort (double v[], int size)
{
  if (size > 1)
    { 
      int i = 0, odd = 0, mid = (size)/2;
      double left[10],rite[10];
      int ll = mid, rl = mid;
      for (i=0;i<mid;i++)
	{
	  left[i] = v[i];
	  rite[i] = v[i+mid];
	}
      if (size%2 == 1)
	{
	  odd = 1;
	  rl++;
	  rite[mid] = v[size-1];
	}
      mergesort(left,ll);
      mergesort(rite,rl);
      merge(left,ll,rite,rl,v);
    }
}


int main(void)
{
  double arr[15] = {11.0,-77.22,-108.03,2056.1,35.44,12.14,-33.0,-9050.0,7.509,99.002,-14,17,0.9,98098,-4000};
  
  int i,size = sizeof(arr)/sizeof(double);
  mergesort(arr,size);
  printf("sorted vector:\n");
  for (i = 0; i < size ;i++)
    printf("%f ", arr[i]);
  return 0;
}
