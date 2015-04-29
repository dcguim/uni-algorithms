#include<iostream>
#include<vector>
#include<math.h>

double calculate (double x, std::vector<double>* vet)
{
  int i;
  double res = 0,pot = 1;
  std::cout << "size: " << vet->size() << "\n";
  for (i = 0; i < vet->size(); i++)
    {      
      res = res + (*vet)[i]*pot;
      pot = x*pot;
    } 
  return res;
}

int main (void)
{
  double r,x = 10.0;
  // Is there a better way to initialize a distinct vector??
  double v[3] = {1,2,3};
  std::vector<double> vet(&v[0],&v[0]+3);
  r = calculate(x, &vet);
  std::cout << "res: " << r << "\n";
  return 0;
}
