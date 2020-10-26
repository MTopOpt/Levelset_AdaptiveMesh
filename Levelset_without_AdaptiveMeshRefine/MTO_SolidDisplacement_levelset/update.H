//***********************************//update mu and lambda
opt=opt+1;

if(solid_area)
{
   forAll(cells, i)
   {
      xh[cells[i]]=1.0;
   }
}
xh.correctBoundaryConditions();
if(runTime.writeTime())
{
   xh.write(); 
   //x.write();    
}

mu=(Emin+xh*(E-Emin))/(2.0*(1.0 + Po));
lambda=(Emin+xh*(E-Emin))*Po/((1.0 + Po)*(1.0 - 2.0*Po));
if (planeStress)
{
   lambda=(Emin+xh*(E-Emin))*Po/((1.0 + Po)*(1.0 - Po));
}
