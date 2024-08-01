// ResummationHV.cc
// Uses Hacked Version of Pythia8.209
// Creates Scattering Events, Extracts Particle 4-Momentum, and Runs Anti-kt Jet Algorithm
// Output: ResummationHV.dat
//
// Input Specified in ResummationHV.cmnd
//
// Requires Two Arguments:
// DMShower, DMHadron, DMDecay, SMShower, SMHadron
// Minimum Jet p_T
//
// Author: Joel Doss, jdoss@uoregon.edu

#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC2.h"

using namespace Pythia8;





int main(int argc,char** argv) {
     
    if(argc <2)
    {
        printf(" Pythia main file to analyse dark QCD events\n");
        printf(" The program needs one argument: The name \n of the settings file from which to read the input\n (e.g. inputZprime.dat).\n");
        printf(" Aborted!\n");
        exit(1);
    }
 

     
    Pythia pythia;
    pythia.readFile(argv[1]);

     

    pythia.readString("Random:setSeed = on");
    pythia.readString("Random:seed = 666");
    

    // Run Pythia

    pythia.init();
	
    for (int ev=0; ; ev++) {	
	
        if (ev < 10){
            	cout << "\n" << ev << ": \n "<< endl;
            	pythia.event.list();
        }
        if (!pythia.next()) {
            	if (pythia.info.atEndOfFile()) break;
                continue;
        };
    	
    }//closes loop over events
	
	pythia.stat();
   
	return 0;
}
