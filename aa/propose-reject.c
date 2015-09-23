#include <stdio.h>

#define N_PPL 3

int main (void)
{
  // Every man and woman are available in the begining
  int freeM[N_PPL] = {1,1,1}; // 1 is free, 0 is matched
  int freeW[N_PPL] = {1,1,1}; 
  int i = 0,j = 0,k,man,wom;
  
  int prefM[N_PPL][N_PPL+1] = {{3,2,1,0},// man 1
			       {2,3,1,0}, // man 2
			       {3,1,2,0}}; // man 3
  
  int prefW[N_PPL][N_PPL+1] = {{3,2,1,0}, // wom 1
			       {2,3,1,0}, // wom 2
			       {3,1,2,0}}; //wom 3

  // Every man
  while(freeM[0] == 1 || freeM[1] == 1 || freeM[2] == 1)
    {
      // get the first unmatched man
      for (i = 0; i < 3; i++)
	{
	  if (freeM[i] == 1)
	    {
	      man = i+1;
	    }
	}
      //Proposes to every woman on his preference order
      for (j = 0; j < N_PPL; j++)
	{
	  wom = prefM[man-1][j];
	  // If she is free they are now a match
	  if (freeW[wom-1] == 1)
	    {//match`em
	      freeW[wom-1] = 0;
	      freeM[man-1] = 0;
	      prefM[man-1][3] = wom;
	      prefW[wom-1][3] = man;
	      break;
	    }
	  // Otherwise, if he is prefered they`ll match. If he is not, they won`t
	  else
	    {
	      for(k=0; k< N_PPL;k++)
		{
		  if (prefW[wom-1][k] == man)
		    {//match`em
		      //ditch her boyfriend
		      freeM[prefW[wom-1][3] - 1] = 1;
		      freeM[man-1] = 0;
		      prefM[man-1][3] = wom;
		      prefW[wom-1][3] = man;
		      break;
		    }// if the prefered is the current ...
		  else if (prefW[wom-1][k] == prefW[wom-1][3])
		    {//reject`im
		      break;
		    }
		}
	    }
	}
    }

  printf ("1-%d, 2-%d, 3-%d\n",prefM[0][3],prefM[1][3],prefM[2][3]);
  
  return 0;
}
