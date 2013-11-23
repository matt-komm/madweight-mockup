//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#ifndef MG5_Sigma_sm_ucx_uuuxcx_H
#define MG5_Sigma_sm_ucx_uuuxcx_H

#include <complex> 
#include <vector> 

#include "Parameters_sm.h"

using namespace std; 

//==========================================================================
// A class for calculating the matrix elements for
// Process: u c~ > u u u~ c~ WEIGHTED=4
// Process: u d~ > u u u~ d~ WEIGHTED=4
// Process: u s~ > u u u~ s~ WEIGHTED=4
// Process: c u~ > c c c~ u~ WEIGHTED=4
// Process: c d~ > c c c~ d~ WEIGHTED=4
// Process: c s~ > c c c~ s~ WEIGHTED=4
// Process: d u~ > d d d~ u~ WEIGHTED=4
// Process: d c~ > d d d~ c~ WEIGHTED=4
// Process: d s~ > d d d~ s~ WEIGHTED=4
// Process: s u~ > s s s~ u~ WEIGHTED=4
// Process: s c~ > s s s~ c~ WEIGHTED=4
// Process: s d~ > s s s~ d~ WEIGHTED=4
//--------------------------------------------------------------------------

class P0_Sigma_sm_ucx_uuuxcx_qcd_4j
{
  public:

    // Constructor.
    P0_Sigma_sm_ucx_uuuxcx_qcd_4j() {}

    // Initialize process.
    virtual void initProc(string param_card_name); 

    // Calculate flavour-independent parts of cross section.
    virtual void sigmaKin(); 

    // Evaluate sigmaHat(sHat).
    virtual double sigmaHat(); 

    // Info on the subprocess.
    virtual string name() const {return "u c~ > u u u~ c~ (sm)";}

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
    static const int nexternal = 6; 
    static const int nprocesses = 2; 

  private:

    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]); 
    static const int nwavefuncs = 22; 
    std::complex<double> w[nwavefuncs][18]; 
    static const int namplitudes = 14; 
    std::complex<double> amp[namplitudes]; 
    double matrix_ucx_uuuxcx(); 

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


#endif  // MG5_Sigma_sm_ucx_uuuxcx_H
