Info<< "Initialization\n" << endl;
std::remove("Voluse.txt");
std::remove("Time.txt");
std::remove("Compliance.txt"); 

int i=0;
double opt=0;
scalar n(0),N(0),lam(0.1),C(0),V(0),Vmax(0),area=gSum(mesh.V());
n=x.size();//n:length of x in the i-th core
N=x.size();//N:design freedom
reduce(N, sumOp<scalar>()); 
double e=0.5;
 for(i=0;i<n;i++)
 {
  if(x[i]>1)
  {x[i]=1;}
  if(x[i]<-1)
  {x[i]=-1;}

  if(x[i]>e)
  {xh[i]=1;}
  else if(x[i]<-e)
  {xh[i]=0;}
  else
  {xh[i]=3.0/4*(x[i]/e-x[i]*x[i]*x[i]/3.0/e/e/e)+0.5;}
 }
