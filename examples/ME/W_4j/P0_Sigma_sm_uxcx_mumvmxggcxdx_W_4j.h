//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#ifndef MG5_Sigma_sm_uxcx_mumvmxggcxdx_H
#define MG5_Sigma_sm_uxcx_mumvmxggcxdx_H

#include <complex> 
#include <vector> 

#include "Parameters_sm.h"

using namespace std; 

//==========================================================================
// A class for calculating the matrix elements for
// Process: u~ c~ > w- g g c~ d~ WEIGHTED=6
// *   Decay: w- > mu- vm~ WEIGHTED=2
// Process: u~ s~ > w- g g s~ d~ WEIGHTED=6
// *   Decay: w- > mu- vm~ WEIGHTED=2
// Process: c~ d~ > w- g g d~ s~ WEIGHTED=6
// *   Decay: w- > mu- vm~ WEIGHTED=2
//--------------------------------------------------------------------------

class P0_Sigma_sm_uxcx_mumvmxggcxdx_W_4j
{
  public:

    // Constructor.
    P0_Sigma_sm_uxcx_mumvmxggcxdx_W_4j() {}

    // Initialize process.
    virtual void initProc(string param_card_name); 

    // Calculate flavour-independent parts of cross section.
    virtual void sigmaKin(); 

    // Evaluate sigmaHat(sHat).
    virtual double sigmaHat(); 

    // Info on the subprocess.
    virtual string name() const {return "u~ c~ > mu- vm~ g g c~ d~ (sm)";}

    virtual int code() const {return 0;}

    const vector<double> & getMasses() const {return mME;}

    // Get and set momenta for matrix element evaluation
    vector < double * > getMomenta(){return p;}
    void setMomenta(vector < double * > & momenta){p = momenta;}
    void setInitial(int inid1, int inid2){id1 = inid1; id2 = inid2;}

    // Get matrix element vector
    const double * getMatrixElements() const {return matrix_element;}

    // Constants for array limits
    static const int ninitial = 2; 
    static const int nexternal = 8; 
    static const int nprocesses = 2; 

  private:

    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]); 
    static const int nwavefuncs = 63; 
    std::complex<double> w[nwavefuncs][18]; 
    static const int namplitudes = 102; 
    std::complex<double> amp[namplitudes]; 
    double matrix_uxcx_wmggcxdx_wm_mumvmx(); 

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses]; 

    // Color flows, used when selecting color
    double * jamp2[nprocesses]; 

    // Pointer to the model parameters
    Parameters_sm * pars; 

    // vector with external particle masses
    vector<double> mME; 

    // vector with momenta (to be changed each event)
    vector < double * > p; 
    // Initial particle ids
    int id1, id2; 

}; 


#endif  // MG5_Sigma_sm_uxcx_mumvmxggcxdx_H
