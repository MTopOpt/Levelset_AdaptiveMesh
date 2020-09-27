//Author: Yu Minghao    Updated: May 2020    

#include "fvCFD.H"
#include "dynamicFvMesh.H"
int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    //#include "createMesh.H"
    #include "createDynamicFvMesh.H"
    #include "createControl.H"
    #include "createFields.H"
    #include "readMechanicalProperties.H" 
    #include "opt_initialization.H"
    while (runTime.loop())
    {
        #include "update.H"
        #include "LinearElasticity.H"
        #include "costfunction.H"              
        #include "sensitivity.H"
        #include "levelset.H"
    }
    Info<< " \n" << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
    << "  ClockTime = " << runTime.elapsedClockTime() << " s"
    << nl << endl;
    return 0;
}
