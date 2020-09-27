Info<< "Reading optimization parameters\n" << endl;
IOdictionary optProperties
(
   IOobject
   (
       "optProperties",
       runTime.constant(),
       mesh,
       IOobject::MUST_READ_IF_MODIFIED,
       IOobject::NO_WRITE
   )
);
//optimization parameters

scalar voluse(readScalar(optProperties.lookup("voluse")));
scalar niter(readScalar(optProperties.lookup("niter")));
Switch solid_area(optProperties.lookup("solid_area"));
dimensionedScalar c("c", dimensionSet(0,0,-1,0,0,0,0),1.0);
dimensionedScalar ep("ep", dimensionSet(0,2,-1,0,0,0,0),readScalar(optProperties.lookup("ep")));

Info<< "Reading pseudo-density field\n" << endl;

volScalarField x
(
    IOobject
    (
        "x",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    ),
    mesh
);
volScalarField xh
(
    IOobject
    (
        "xh",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
    scalar(1),
    zeroGradientFvPatchScalarField::typeName
);
volScalarField F(x);
// find the cells in the non-design area
labelList cells;
if(solid_area)
{
  word zoneName="solid_area";
  label zoneID=mesh.cellZones().findZoneID(zoneName);
  cells=mesh.cellZones()[zoneID];
  forAll(cells, i)
  {
     x[cells[i]]=1.0;
  }
}
