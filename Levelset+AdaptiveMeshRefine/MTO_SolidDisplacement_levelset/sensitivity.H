
Info<<"sensitivity analysis"<<endl;
//fsensh=-gradD&&(rho*((E-Emin)/(2.0*(1.0 + Po))*twoSymm(gradD) + (Po*(E-Emin)/((1.0 + Po)*(1.0 - 2.0*Po))*I)*tr(gradD))); 
volScalarField A1=-3*(1-Po)*(1-14*Po+15*Po*Po)/(2*(1+Po)*(7-5*Po)*(1-2*Po)*(1-2*Po))*E*xh;
volScalarField A2=15*(1-Po)/(2*(1+Po)*(7-5*Po))*E*xh;
fsensh.primitiveFieldRef()=-gradD&&(rho*(A1*twoSymm(gradD) + (A2*I)*tr(gradD))); 
fsensh.primitiveFieldRef()=fsensh/fvc::domainIntegrate(mag(fsensh)).value()*area;
if(opt<2)
{
  lam=0.3*fvc::domainIntegrate(mag(fsensh)).value()/area;
}
else
{
  lam=lam+0.5*(V-Vmax)/Vmax;
}

F.primitiveFieldRef()=-fsensh.primitiveFieldRef()-lam;
c.value()=-0.7;

