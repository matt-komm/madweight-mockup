//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#ifndef MG5_Sigma_sm_uux_budxbxemvexbbx_H
#define MG5_Sigma_sm_uux_budxbxemvexbbx_H

#include <complex> 
#include <vector> 

#include "Parameters_sm.h"

using namespace std; 

//==========================================================================
// A class for calculating the matrix elements for
// Process: u u~ > t t~ h WEIGHTED=4
// *   Decay: t > b u d~ WEIGHTED=4
// *   Decay: t~ > b~ e- ve~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: c c~ > t t~ h WEIGHTED=4
// *   Decay: t > b u d~ WEIGHTED=4
// *   Decay: t~ > b~ e- ve~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: d d~ > t t~ h WEIGHTED=4
// *   Decay: t > b u d~ WEIGHTED=4
// *   Decay: t~ > b~ e- ve~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: s s~ > t t~ h WEIGHTED=4
// *   Decay: t > b u d~ WEIGHTED=4
// *   Decay: t~ > b~ e- ve~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: u u~ > t t~ h WEIGHTED=4
// *   Decay: t > b c s~ WEIGHTED=4
// *   Decay: t~ > b~ e- ve~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: c c~ > t t~ h WEIGHTED=4
// *   Decay: t > b c s~ WEIGHTED=4
// *   Decay: t~ > b~ e- ve~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: d d~ > t t~ h WEIGHTED=4
// *   Decay: t > b c s~ WEIGHTED=4
// *   Decay: t~ > b~ e- ve~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: s s~ > t t~ h WEIGHTED=4
// *   Decay: t > b c s~ WEIGHTED=4
// *   Decay: t~ > b~ e- ve~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: u u~ > t t~ h WEIGHTED=4
// *   Decay: t > b u d~ WEIGHTED=4
// *   Decay: t~ > b~ mu- vm~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: c c~ > t t~ h WEIGHTED=4
// *   Decay: t > b u d~ WEIGHTED=4
// *   Decay: t~ > b~ mu- vm~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: d d~ > t t~ h WEIGHTED=4
// *   Decay: t > b u d~ WEIGHTED=4
// *   Decay: t~ > b~ mu- vm~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: s s~ > t t~ h WEIGHTED=4
// *   Decay: t > b u d~ WEIGHTED=4
// *   Decay: t~ > b~ mu- vm~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: u u~ > t t~ h WEIGHTED=4
// *   Decay: t > b c s~ WEIGHTED=4
// *   Decay: t~ > b~ mu- vm~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: c c~ > t t~ h WEIGHTED=4
// *   Decay: t > b c s~ WEIGHTED=4
// *   Decay: t~ > b~ mu- vm~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: d d~ > t t~ h WEIGHTED=4
// *   Decay: t > b c s~ WEIGHTED=4
// *   Decay: t~ > b~ mu- vm~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
// Process: s s~ > t t~ h WEIGHTED=4
// *   Decay: t > b c s~ WEIGHTED=4
// *   Decay: t~ > b~ mu- vm~ WEIGHTED=4
// *   Decay: h > b b~ WEIGHTED=2
//--------------------------------------------------------------------------

class P0_Sigma_sm_uux_budxbxemvexbbx_semiTTbar_Hbb
{
  public:

    // Constructor.
    P0_Sigma_sm_uux_budxbxemvexbbx_semiTTbar_Hbb() {}

    // Initialize process.
    virtual void initProc(string param_card_name); 

    // Calculate flavour-independent parts of cross section.
    virtual void sigmaKin(); 

    // Evaluate sigmaHat(sHat).
    virtual double sigmaHat(); 

    // Info on the subprocess.
    virtual string name() const {return "u u~ > b u d~ b~ e- ve~ b b~ (sm)";}

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
    static const int nexternal = 10; 
    static const int nprocesses = 2; 

  private:

    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]); 
    static const int nwavefuncs = 18; 
    std::complex<double> w[nwavefuncs][18]; 
    static const int namplitudes = 2; 
    std::complex<double> amp[namplitudes]; 
    double matrix_uux_ttxh_t_budx_tx_bxemvex_h_bbx(); 

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


#endif  // MG5_Sigma_sm_uux_budxbxemvexbbx_H
