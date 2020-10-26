Info<< "Level Set\n" << endl;
 fvScalarMatrix TEqn
 (
     fvm::ddt(x)
   - ep*fvm::laplacian(x)
   + c*F
 );
 TEqn.relax();
 TEqn.solve();
 x.storePrevIter();

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

 //mesh.update();

runTime.write();
n=x.size();//n:length of x in the i-th core
N=x.size();//N:design freedom
reduce(N, sumOp<scalar>()); 
