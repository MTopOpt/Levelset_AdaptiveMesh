Description
-----------
The code presented is a parallel solver for levelset topology optimization method with adaptive mesh refinement

Installation
------------
Before running this solver, following softwares are needed.  
(a) **OpenFOAM 5.0**  

Run the solver
--------------
 After finishing above works, users should run **wmake** in the src folder, and then run **blockMesh** and **decomposePar** in the app folder. Finally, topology optimization solver can run in the app folder by **mpirun –n 16 MTO_levelset**, where 16 is the default number of cores for parallel computing.
 
Postplot
--------
After the optimization, users should run **reconstructPar** in the app folder and then run **paraFoam** to view the results with Paraview.  

Solid displacement problem  
-----------------------------
![image](https://github.com/MTopOpt/Levelset_AdaptiveMesh/blob/master/Levelset%2BAdaptiveMeshRefine/1.gif)  
