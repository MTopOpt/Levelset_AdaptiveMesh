Info<< "\nslove linear elasticity equation\n" << endl;
initialResidual = 0;
iCorr=0;
//D=0*D;
do
{
  {
      fvVectorMatrix DEqn
      (
        - fvm::laplacian(2*mu + lambda, D, "laplacian(DD,D)")
        - divSigmaExp
        //- fvc::grad(threeKalpha*T)
      );

      initialResidual = DEqn.solve().max().initialResidual();

      if (!compactNormalStress)
      {
          divSigmaExp = fvc::div(DEqn.flux());
      }
  }

  {
      volTensorField gradD(fvc::grad(D));
      sigmaD = mu*twoSymm(gradD) + (lambda*I)*tr(gradD);

      if (compactNormalStress)
      {
          divSigmaExp = fvc::div
          (
              sigmaD - (2*mu + lambda)*gradD,
              "div(sigmaD)"
          );
      }
      else
      {
          divSigmaExp += fvc::div(sigmaD);
      }
  }

} while (initialResidual > convergenceTolerance && ++iCorr < nCorr);
//D.storePrevIter();