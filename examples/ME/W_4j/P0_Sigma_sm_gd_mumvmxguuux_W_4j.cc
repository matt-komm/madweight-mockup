//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "P0_Sigma_sm_gd_mumvmxguuux_W_4j.h"
#include "HelAmps_sm.h"

using namespace MG5_sm; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g d > w- g u u u~ WEIGHTED=6
// *   Decay: w- > mu- vm~ WEIGHTED=2
// Process: g s > w- g c c c~ WEIGHTED=6
// *   Decay: w- > mu- vm~ WEIGHTED=2

//--------------------------------------------------------------------------
// Initialize process.

void P0_Sigma_sm_gd_mumvmxguuux_W_4j::initProc(string param_card_name) 
{
  // Instantiate the model class and set parameters that stay fixed during run
  pars = Parameters_sm::getInstance(); 
  SLHAReader slha(param_card_name); 
  pars->setIndependentParameters(slha); 
  pars->setIndependentCouplings(); 
  pars->printIndependentParameters(); 
  pars->printIndependentCouplings(); 
  // Set external particle masses for this matrix element
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  jamp2[0] = new double[12]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void P0_Sigma_sm_gd_mumvmxguuux_W_4j::sigmaKin() 
{
  // Set the parameters which change event by event
  pars->setDependentParameters(); 
  pars->setDependentCouplings(); 
  static bool firsttime = true; 
  if (firsttime)
  {
    pars->printDependentParameters(); 
    pars->printDependentCouplings(); 
    firsttime = false; 
  }

  // Reset color flows
  for(int i = 0; i < 12; i++ )
    jamp2[0][i] = 0.; 

  // Local variables and constants
  const int ncomb = 256; 
  static bool goodhel[ncomb] = {ncomb * false}; 
  static int ntry = 0, sum_hel = 0, ngood = 0; 
  static int igood[ncomb]; 
  static int jhel; 
  std::complex<double> * * wfs; 
  double t[nprocesses]; 
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1, -1,
      -1}, {-1, -1, -1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, -1, -1, 1, -1},
      {-1, -1, -1, -1, -1, -1, 1, 1}, {-1, -1, -1, -1, -1, 1, -1, -1}, {-1, -1,
      -1, -1, -1, 1, -1, 1}, {-1, -1, -1, -1, -1, 1, 1, -1}, {-1, -1, -1, -1,
      -1, 1, 1, 1}, {-1, -1, -1, -1, 1, -1, -1, -1}, {-1, -1, -1, -1, 1, -1,
      -1, 1}, {-1, -1, -1, -1, 1, -1, 1, -1}, {-1, -1, -1, -1, 1, -1, 1, 1},
      {-1, -1, -1, -1, 1, 1, -1, -1}, {-1, -1, -1, -1, 1, 1, -1, 1}, {-1, -1,
      -1, -1, 1, 1, 1, -1}, {-1, -1, -1, -1, 1, 1, 1, 1}, {-1, -1, -1, 1, -1,
      -1, -1, -1}, {-1, -1, -1, 1, -1, -1, -1, 1}, {-1, -1, -1, 1, -1, -1, 1,
      -1}, {-1, -1, -1, 1, -1, -1, 1, 1}, {-1, -1, -1, 1, -1, 1, -1, -1}, {-1,
      -1, -1, 1, -1, 1, -1, 1}, {-1, -1, -1, 1, -1, 1, 1, -1}, {-1, -1, -1, 1,
      -1, 1, 1, 1}, {-1, -1, -1, 1, 1, -1, -1, -1}, {-1, -1, -1, 1, 1, -1, -1,
      1}, {-1, -1, -1, 1, 1, -1, 1, -1}, {-1, -1, -1, 1, 1, -1, 1, 1}, {-1, -1,
      -1, 1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1, 1, -1, 1}, {-1, -1, -1, 1, 1, 1,
      1, -1}, {-1, -1, -1, 1, 1, 1, 1, 1}, {-1, -1, 1, -1, -1, -1, -1, -1},
      {-1, -1, 1, -1, -1, -1, -1, 1}, {-1, -1, 1, -1, -1, -1, 1, -1}, {-1, -1,
      1, -1, -1, -1, 1, 1}, {-1, -1, 1, -1, -1, 1, -1, -1}, {-1, -1, 1, -1, -1,
      1, -1, 1}, {-1, -1, 1, -1, -1, 1, 1, -1}, {-1, -1, 1, -1, -1, 1, 1, 1},
      {-1, -1, 1, -1, 1, -1, -1, -1}, {-1, -1, 1, -1, 1, -1, -1, 1}, {-1, -1,
      1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1, -1, 1, 1}, {-1, -1, 1, -1, 1, 1,
      -1, -1}, {-1, -1, 1, -1, 1, 1, -1, 1}, {-1, -1, 1, -1, 1, 1, 1, -1}, {-1,
      -1, 1, -1, 1, 1, 1, 1}, {-1, -1, 1, 1, -1, -1, -1, -1}, {-1, -1, 1, 1,
      -1, -1, -1, 1}, {-1, -1, 1, 1, -1, -1, 1, -1}, {-1, -1, 1, 1, -1, -1, 1,
      1}, {-1, -1, 1, 1, -1, 1, -1, -1}, {-1, -1, 1, 1, -1, 1, -1, 1}, {-1, -1,
      1, 1, -1, 1, 1, -1}, {-1, -1, 1, 1, -1, 1, 1, 1}, {-1, -1, 1, 1, 1, -1,
      -1, -1}, {-1, -1, 1, 1, 1, -1, -1, 1}, {-1, -1, 1, 1, 1, -1, 1, -1}, {-1,
      -1, 1, 1, 1, -1, 1, 1}, {-1, -1, 1, 1, 1, 1, -1, -1}, {-1, -1, 1, 1, 1,
      1, -1, 1}, {-1, -1, 1, 1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1, 1, 1}, {-1,
      1, -1, -1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, -1, -1, 1}, {-1, 1, -1,
      -1, -1, -1, 1, -1}, {-1, 1, -1, -1, -1, -1, 1, 1}, {-1, 1, -1, -1, -1, 1,
      -1, -1}, {-1, 1, -1, -1, -1, 1, -1, 1}, {-1, 1, -1, -1, -1, 1, 1, -1},
      {-1, 1, -1, -1, -1, 1, 1, 1}, {-1, 1, -1, -1, 1, -1, -1, -1}, {-1, 1, -1,
      -1, 1, -1, -1, 1}, {-1, 1, -1, -1, 1, -1, 1, -1}, {-1, 1, -1, -1, 1, -1,
      1, 1}, {-1, 1, -1, -1, 1, 1, -1, -1}, {-1, 1, -1, -1, 1, 1, -1, 1}, {-1,
      1, -1, -1, 1, 1, 1, -1}, {-1, 1, -1, -1, 1, 1, 1, 1}, {-1, 1, -1, 1, -1,
      -1, -1, -1}, {-1, 1, -1, 1, -1, -1, -1, 1}, {-1, 1, -1, 1, -1, -1, 1,
      -1}, {-1, 1, -1, 1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, 1, -1, -1}, {-1, 1,
      -1, 1, -1, 1, -1, 1}, {-1, 1, -1, 1, -1, 1, 1, -1}, {-1, 1, -1, 1, -1, 1,
      1, 1}, {-1, 1, -1, 1, 1, -1, -1, -1}, {-1, 1, -1, 1, 1, -1, -1, 1}, {-1,
      1, -1, 1, 1, -1, 1, -1}, {-1, 1, -1, 1, 1, -1, 1, 1}, {-1, 1, -1, 1, 1,
      1, -1, -1}, {-1, 1, -1, 1, 1, 1, -1, 1}, {-1, 1, -1, 1, 1, 1, 1, -1},
      {-1, 1, -1, 1, 1, 1, 1, 1}, {-1, 1, 1, -1, -1, -1, -1, -1}, {-1, 1, 1,
      -1, -1, -1, -1, 1}, {-1, 1, 1, -1, -1, -1, 1, -1}, {-1, 1, 1, -1, -1, -1,
      1, 1}, {-1, 1, 1, -1, -1, 1, -1, -1}, {-1, 1, 1, -1, -1, 1, -1, 1}, {-1,
      1, 1, -1, -1, 1, 1, -1}, {-1, 1, 1, -1, -1, 1, 1, 1}, {-1, 1, 1, -1, 1,
      -1, -1, -1}, {-1, 1, 1, -1, 1, -1, -1, 1}, {-1, 1, 1, -1, 1, -1, 1, -1},
      {-1, 1, 1, -1, 1, -1, 1, 1}, {-1, 1, 1, -1, 1, 1, -1, -1}, {-1, 1, 1, -1,
      1, 1, -1, 1}, {-1, 1, 1, -1, 1, 1, 1, -1}, {-1, 1, 1, -1, 1, 1, 1, 1},
      {-1, 1, 1, 1, -1, -1, -1, -1}, {-1, 1, 1, 1, -1, -1, -1, 1}, {-1, 1, 1,
      1, -1, -1, 1, -1}, {-1, 1, 1, 1, -1, -1, 1, 1}, {-1, 1, 1, 1, -1, 1, -1,
      -1}, {-1, 1, 1, 1, -1, 1, -1, 1}, {-1, 1, 1, 1, -1, 1, 1, -1}, {-1, 1, 1,
      1, -1, 1, 1, 1}, {-1, 1, 1, 1, 1, -1, -1, -1}, {-1, 1, 1, 1, 1, -1, -1,
      1}, {-1, 1, 1, 1, 1, -1, 1, -1}, {-1, 1, 1, 1, 1, -1, 1, 1}, {-1, 1, 1,
      1, 1, 1, -1, -1}, {-1, 1, 1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1, 1, 1, 1, -1},
      {-1, 1, 1, 1, 1, 1, 1, 1}, {1, -1, -1, -1, -1, -1, -1, -1}, {1, -1, -1,
      -1, -1, -1, -1, 1}, {1, -1, -1, -1, -1, -1, 1, -1}, {1, -1, -1, -1, -1,
      -1, 1, 1}, {1, -1, -1, -1, -1, 1, -1, -1}, {1, -1, -1, -1, -1, 1, -1, 1},
      {1, -1, -1, -1, -1, 1, 1, -1}, {1, -1, -1, -1, -1, 1, 1, 1}, {1, -1, -1,
      -1, 1, -1, -1, -1}, {1, -1, -1, -1, 1, -1, -1, 1}, {1, -1, -1, -1, 1, -1,
      1, -1}, {1, -1, -1, -1, 1, -1, 1, 1}, {1, -1, -1, -1, 1, 1, -1, -1}, {1,
      -1, -1, -1, 1, 1, -1, 1}, {1, -1, -1, -1, 1, 1, 1, -1}, {1, -1, -1, -1,
      1, 1, 1, 1}, {1, -1, -1, 1, -1, -1, -1, -1}, {1, -1, -1, 1, -1, -1, -1,
      1}, {1, -1, -1, 1, -1, -1, 1, -1}, {1, -1, -1, 1, -1, -1, 1, 1}, {1, -1,
      -1, 1, -1, 1, -1, -1}, {1, -1, -1, 1, -1, 1, -1, 1}, {1, -1, -1, 1, -1,
      1, 1, -1}, {1, -1, -1, 1, -1, 1, 1, 1}, {1, -1, -1, 1, 1, -1, -1, -1},
      {1, -1, -1, 1, 1, -1, -1, 1}, {1, -1, -1, 1, 1, -1, 1, -1}, {1, -1, -1,
      1, 1, -1, 1, 1}, {1, -1, -1, 1, 1, 1, -1, -1}, {1, -1, -1, 1, 1, 1, -1,
      1}, {1, -1, -1, 1, 1, 1, 1, -1}, {1, -1, -1, 1, 1, 1, 1, 1}, {1, -1, 1,
      -1, -1, -1, -1, -1}, {1, -1, 1, -1, -1, -1, -1, 1}, {1, -1, 1, -1, -1,
      -1, 1, -1}, {1, -1, 1, -1, -1, -1, 1, 1}, {1, -1, 1, -1, -1, 1, -1, -1},
      {1, -1, 1, -1, -1, 1, -1, 1}, {1, -1, 1, -1, -1, 1, 1, -1}, {1, -1, 1,
      -1, -1, 1, 1, 1}, {1, -1, 1, -1, 1, -1, -1, -1}, {1, -1, 1, -1, 1, -1,
      -1, 1}, {1, -1, 1, -1, 1, -1, 1, -1}, {1, -1, 1, -1, 1, -1, 1, 1}, {1,
      -1, 1, -1, 1, 1, -1, -1}, {1, -1, 1, -1, 1, 1, -1, 1}, {1, -1, 1, -1, 1,
      1, 1, -1}, {1, -1, 1, -1, 1, 1, 1, 1}, {1, -1, 1, 1, -1, -1, -1, -1}, {1,
      -1, 1, 1, -1, -1, -1, 1}, {1, -1, 1, 1, -1, -1, 1, -1}, {1, -1, 1, 1, -1,
      -1, 1, 1}, {1, -1, 1, 1, -1, 1, -1, -1}, {1, -1, 1, 1, -1, 1, -1, 1}, {1,
      -1, 1, 1, -1, 1, 1, -1}, {1, -1, 1, 1, -1, 1, 1, 1}, {1, -1, 1, 1, 1, -1,
      -1, -1}, {1, -1, 1, 1, 1, -1, -1, 1}, {1, -1, 1, 1, 1, -1, 1, -1}, {1,
      -1, 1, 1, 1, -1, 1, 1}, {1, -1, 1, 1, 1, 1, -1, -1}, {1, -1, 1, 1, 1, 1,
      -1, 1}, {1, -1, 1, 1, 1, 1, 1, -1}, {1, -1, 1, 1, 1, 1, 1, 1}, {1, 1, -1,
      -1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, -1, -1, 1}, {1, 1, -1, -1, -1,
      -1, 1, -1}, {1, 1, -1, -1, -1, -1, 1, 1}, {1, 1, -1, -1, -1, 1, -1, -1},
      {1, 1, -1, -1, -1, 1, -1, 1}, {1, 1, -1, -1, -1, 1, 1, -1}, {1, 1, -1,
      -1, -1, 1, 1, 1}, {1, 1, -1, -1, 1, -1, -1, -1}, {1, 1, -1, -1, 1, -1,
      -1, 1}, {1, 1, -1, -1, 1, -1, 1, -1}, {1, 1, -1, -1, 1, -1, 1, 1}, {1, 1,
      -1, -1, 1, 1, -1, -1}, {1, 1, -1, -1, 1, 1, -1, 1}, {1, 1, -1, -1, 1, 1,
      1, -1}, {1, 1, -1, -1, 1, 1, 1, 1}, {1, 1, -1, 1, -1, -1, -1, -1}, {1, 1,
      -1, 1, -1, -1, -1, 1}, {1, 1, -1, 1, -1, -1, 1, -1}, {1, 1, -1, 1, -1,
      -1, 1, 1}, {1, 1, -1, 1, -1, 1, -1, -1}, {1, 1, -1, 1, -1, 1, -1, 1}, {1,
      1, -1, 1, -1, 1, 1, -1}, {1, 1, -1, 1, -1, 1, 1, 1}, {1, 1, -1, 1, 1, -1,
      -1, -1}, {1, 1, -1, 1, 1, -1, -1, 1}, {1, 1, -1, 1, 1, -1, 1, -1}, {1, 1,
      -1, 1, 1, -1, 1, 1}, {1, 1, -1, 1, 1, 1, -1, -1}, {1, 1, -1, 1, 1, 1, -1,
      1}, {1, 1, -1, 1, 1, 1, 1, -1}, {1, 1, -1, 1, 1, 1, 1, 1}, {1, 1, 1, -1,
      -1, -1, -1, -1}, {1, 1, 1, -1, -1, -1, -1, 1}, {1, 1, 1, -1, -1, -1, 1,
      -1}, {1, 1, 1, -1, -1, -1, 1, 1}, {1, 1, 1, -1, -1, 1, -1, -1}, {1, 1, 1,
      -1, -1, 1, -1, 1}, {1, 1, 1, -1, -1, 1, 1, -1}, {1, 1, 1, -1, -1, 1, 1,
      1}, {1, 1, 1, -1, 1, -1, -1, -1}, {1, 1, 1, -1, 1, -1, -1, 1}, {1, 1, 1,
      -1, 1, -1, 1, -1}, {1, 1, 1, -1, 1, -1, 1, 1}, {1, 1, 1, -1, 1, 1, -1,
      -1}, {1, 1, 1, -1, 1, 1, -1, 1}, {1, 1, 1, -1, 1, 1, 1, -1}, {1, 1, 1,
      -1, 1, 1, 1, 1}, {1, 1, 1, 1, -1, -1, -1, -1}, {1, 1, 1, 1, -1, -1, -1,
      1}, {1, 1, 1, 1, -1, -1, 1, -1}, {1, 1, 1, 1, -1, -1, 1, 1}, {1, 1, 1, 1,
      -1, 1, -1, -1}, {1, 1, 1, 1, -1, 1, -1, 1}, {1, 1, 1, 1, -1, 1, 1, -1},
      {1, 1, 1, 1, -1, 1, 1, 1}, {1, 1, 1, 1, 1, -1, -1, -1}, {1, 1, 1, 1, 1,
      -1, -1, 1}, {1, 1, 1, 1, 1, -1, 1, -1}, {1, 1, 1, 1, 1, -1, 1, 1}, {1, 1,
      1, 1, 1, 1, -1, -1}, {1, 1, 1, 1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, 1, 1,
      -1}, {1, 1, 1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {192, 192}; 

  ntry = ntry + 1; 

  // Reset the matrix elements
  for(int i = 0; i < nprocesses; i++ )
  {
    matrix_element[i] = 0.; 
  }
  // Define permutation
  int perm[nexternal]; 
  for(int i = 0; i < nexternal; i++ )
  {
    perm[i] = i; 
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0; ihel < ncomb; ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions(perm, helicities[ihel]); 
        t[0] = matrix_gd_wmguuux_wm_mumvmx(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_gd_wmguuux_wm_mumvmx(); 
        double tsum = 0; 
        for(int iproc = 0; iproc < nprocesses; iproc++ )
        {
          matrix_element[iproc] += t[iproc]; 
          tsum += t[iproc]; 
        }
        // Store which helicities give non-zero result
        if (tsum != 0. && !goodhel[ihel])
        {
          goodhel[ihel] = true; 
          ngood++; 
          igood[ngood] = ihel; 
        }
      }
    }
    jhel = 0; 
    sum_hel = min(sum_hel, ngood); 
  }
  else
  {
    // Only use the "good" helicities
    for(int j = 0; j < sum_hel; j++ )
    {
      jhel++; 
      if (jhel >= ngood)
        jhel = 0; 
      double hwgt = double(ngood)/double(sum_hel); 
      int ihel = igood[jhel]; 
      calculate_wavefunctions(perm, helicities[ihel]); 
      t[0] = matrix_gd_wmguuux_wm_mumvmx(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_gd_wmguuux_wm_mumvmx(); 
      for(int iproc = 0; iproc < nprocesses; iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt; 
      }
    }
  }

  for (int i = 0; i < nprocesses; i++ )
    matrix_element[i] /= denominators[i]; 



}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double P0_Sigma_sm_gd_mumvmxguuux_W_4j::sigmaHat() 
{
  // Select between the different processes
  if(id1 == 1 && id2 == 21)
  {
    // Add matrix elements for processes with beams (1, 21)
    return matrix_element[1]; 
  }
  else if(id1 == 21 && id2 == 1)
  {
    // Add matrix elements for processes with beams (21, 1)
    return matrix_element[0]; 
  }
  else if(id1 == 3 && id2 == 21)
  {
    // Add matrix elements for processes with beams (3, 21)
    return matrix_element[1]; 
  }
  else if(id1 == 21 && id2 == 3)
  {
    // Add matrix elements for processes with beams (21, 3)
    return matrix_element[0]; 
  }
  else
  {
    // Return 0 if not correct initial state assignment
    return 0.; 
  }
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void P0_Sigma_sm_gd_mumvmxguuux_W_4j::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  vxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]); 
  ixxxxx(p[perm[1]], mME[1], hel[1], +1, w[1]); 
  oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]); 
  ixxxxx(p[perm[3]], mME[3], hel[3], -1, w[3]); 
  FFV2_3(w[3], w[2], pars->GC_100, pars->MW, pars->WW, w[4]); 
  vxxxxx(p[perm[4]], mME[4], hel[4], +1, w[5]); 
  oxxxxx(p[perm[5]], mME[5], hel[5], +1, w[6]); 
  oxxxxx(p[perm[6]], mME[6], hel[6], +1, w[7]); 
  ixxxxx(p[perm[7]], mME[7], hel[7], -1, w[8]); 
  VVV1_1(w[0], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[9]); 
  FFV2_1(w[6], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[10]); 
  FFV1_1(w[7], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[11]); 
  FFV1_3(w[1], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_2(w[8], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[13]); 
  FFV1_3(w[8], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[14]); 
  FFV1_1(w[10], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[15]); 
  VVV1_1(w[9], w[14], pars->GC_10, pars->ZERO, pars->ZERO, w[16]); 
  FFV1_2(w[1], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[17]); 
  FFV2_1(w[7], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[18]); 
  FFV1_1(w[6], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[19]); 
  FFV1_3(w[1], w[18], pars->GC_11, pars->ZERO, pars->ZERO, w[20]); 
  FFV1_3(w[8], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[21]); 
  FFV1_1(w[18], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[22]); 
  VVV1_1(w[9], w[21], pars->GC_10, pars->ZERO, pars->ZERO, w[23]); 
  FFV2_2(w[1], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[24]); 
  FFV1_3(w[24], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[25]); 
  FFV1_3(w[24], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[26]); 
  FFV1_2(w[24], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[27]); 
  FFV1_2(w[1], w[21], pars->GC_11, pars->ZERO, pars->ZERO, w[28]); 
  FFV1_1(w[7], w[21], pars->GC_11, pars->ZERO, pars->ZERO, w[29]); 
  FFV1_2(w[1], w[14], pars->GC_11, pars->ZERO, pars->ZERO, w[30]); 
  FFV1_1(w[6], w[14], pars->GC_11, pars->ZERO, pars->ZERO, w[31]); 
  FFV1_1(w[6], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[32]); 
  FFV1_1(w[7], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[33]); 
  FFV2_1(w[32], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[34]); 
  FFV1_3(w[8], w[33], pars->GC_11, pars->ZERO, pars->ZERO, w[35]); 
  FFV1_3(w[8], w[32], pars->GC_11, pars->ZERO, pars->ZERO, w[36]); 
  FFV2_1(w[33], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[37]); 
  FFV1_3(w[24], w[32], pars->GC_11, pars->ZERO, pars->ZERO, w[38]); 
  FFV1_2(w[8], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[39]); 
  FFV1_3(w[39], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[40]); 
  FFV1_3(w[39], w[32], pars->GC_11, pars->ZERO, pars->ZERO, w[41]); 
  FFV1_2(w[1], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[42]); 
  FFV2_2(w[42], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[43]); 
  FFV1_1(w[32], w[14], pars->GC_11, pars->ZERO, pars->ZERO, w[44]); 
  FFV1_1(w[32], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[45]); 
  FFV1_1(w[18], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[46]); 
  FFV1_2(w[24], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[47]); 
  VVV1_1(w[5], w[14], pars->GC_10, pars->ZERO, pars->ZERO, w[48]); 
  FFV1_1(w[7], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[49]); 
  FFV1_1(w[6], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[50]); 
  FFV2_1(w[49], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[51]); 
  FFV1_3(w[8], w[50], pars->GC_11, pars->ZERO, pars->ZERO, w[52]); 
  FFV1_3(w[8], w[49], pars->GC_11, pars->ZERO, pars->ZERO, w[53]); 
  FFV2_1(w[50], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[54]); 
  FFV1_3(w[24], w[49], pars->GC_11, pars->ZERO, pars->ZERO, w[55]); 
  FFV1_3(w[39], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[56]); 
  FFV1_3(w[39], w[49], pars->GC_11, pars->ZERO, pars->ZERO, w[57]); 
  FFV1_1(w[49], w[21], pars->GC_11, pars->ZERO, pars->ZERO, w[58]); 
  FFV1_1(w[49], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[59]); 
  FFV1_1(w[10], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[60]); 
  VVV1_1(w[5], w[21], pars->GC_10, pars->ZERO, pars->ZERO, w[61]); 
  FFV1_2(w[8], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[62]); 
  FFV1_3(w[62], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[63]); 
  FFV1_3(w[62], w[50], pars->GC_11, pars->ZERO, pars->ZERO, w[64]); 
  FFV1_3(w[62], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[65]); 
  FFV1_3(w[62], w[33], pars->GC_11, pars->ZERO, pars->ZERO, w[66]); 
  FFV1_2(w[62], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[67]); 
  FFV1_2(w[1], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[68]); 
  FFV2_2(w[68], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[69]); 
  FFV1_3(w[68], w[18], pars->GC_11, pars->ZERO, pars->ZERO, w[70]); 
  FFV1_2(w[68], w[14], pars->GC_11, pars->ZERO, pars->ZERO, w[71]); 
  FFV1_3(w[68], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[72]); 
  FFV1_2(w[68], w[21], pars->GC_11, pars->ZERO, pars->ZERO, w[73]); 
  FFV1_2(w[68], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[74]); 
  FFV1_1(w[50], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[75]); 
  FFV1_1(w[18], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[76]); 
  FFV1_2(w[24], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[77]); 
  VVV1_1(w[0], w[14], pars->GC_10, pars->ZERO, pars->ZERO, w[78]); 
  FFV1_1(w[33], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[79]); 
  FFV1_1(w[10], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[80]); 
  VVV1_1(w[0], w[21], pars->GC_10, pars->ZERO, pars->ZERO, w[81]); 
  FFV1_2(w[39], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[82]); 
  FFV1_2(w[42], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[83]); 
  VVVV1_1(w[0], w[5], w[14], pars->GC_12, pars->ZERO, pars->ZERO, w[84]); 
  VVVV3_1(w[0], w[5], w[14], pars->GC_12, pars->ZERO, pars->ZERO, w[85]); 
  VVVV4_1(w[0], w[5], w[14], pars->GC_12, pars->ZERO, pars->ZERO, w[86]); 
  VVVV1_1(w[0], w[5], w[21], pars->GC_12, pars->ZERO, pars->ZERO, w[87]); 
  VVVV3_1(w[0], w[5], w[21], pars->GC_12, pars->ZERO, pars->ZERO, w[88]); 
  VVVV4_1(w[0], w[5], w[21], pars->GC_12, pars->ZERO, pars->ZERO, w[89]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[8], w[11], w[12], pars->GC_11, amp[0]); 
  FFV1_0(w[13], w[7], w[12], pars->GC_11, amp[1]); 
  FFV1_0(w[1], w[15], w[14], pars->GC_11, amp[2]); 
  FFV1_0(w[1], w[10], w[16], pars->GC_11, amp[3]); 
  FFV1_0(w[17], w[10], w[14], pars->GC_11, amp[4]); 
  FFV1_0(w[8], w[19], w[20], pars->GC_11, amp[5]); 
  FFV1_0(w[13], w[6], w[20], pars->GC_11, amp[6]); 
  FFV1_0(w[1], w[22], w[21], pars->GC_11, amp[7]); 
  FFV1_0(w[1], w[18], w[23], pars->GC_11, amp[8]); 
  FFV1_0(w[17], w[18], w[21], pars->GC_11, amp[9]); 
  FFV1_0(w[8], w[19], w[25], pars->GC_11, amp[10]); 
  FFV1_0(w[8], w[11], w[26], pars->GC_11, amp[11]); 
  FFV1_0(w[13], w[7], w[26], pars->GC_11, amp[12]); 
  FFV1_0(w[13], w[6], w[25], pars->GC_11, amp[13]); 
  FFV1_0(w[27], w[7], w[21], pars->GC_11, amp[14]); 
  FFV1_0(w[24], w[7], w[23], pars->GC_11, amp[15]); 
  FFV1_0(w[24], w[11], w[21], pars->GC_11, amp[16]); 
  FFV1_0(w[27], w[6], w[14], pars->GC_11, amp[17]); 
  FFV1_0(w[24], w[19], w[14], pars->GC_11, amp[18]); 
  FFV1_0(w[24], w[6], w[16], pars->GC_11, amp[19]); 
  FFV2_0(w[28], w[11], w[4], pars->GC_100, amp[20]); 
  FFV2_0(w[17], w[29], w[4], pars->GC_100, amp[21]); 
  FFV2_0(w[30], w[19], w[4], pars->GC_100, amp[22]); 
  FFV2_0(w[17], w[31], w[4], pars->GC_100, amp[23]); 
  FFV1_0(w[1], w[34], w[35], pars->GC_11, amp[24]); 
  FFV1_0(w[1], w[37], w[36], pars->GC_11, amp[25]); 
  FFV1_0(w[8], w[33], w[38], pars->GC_11, amp[26]); 
  FFV1_0(w[24], w[33], w[36], pars->GC_11, amp[27]); 
  FFV1_0(w[1], w[34], w[40], pars->GC_11, amp[28]); 
  FFV1_0(w[1], w[18], w[41], pars->GC_11, amp[29]); 
  FFV1_0(w[24], w[7], w[41], pars->GC_11, amp[30]); 
  FFV1_0(w[39], w[7], w[38], pars->GC_11, amp[31]); 
  FFV1_0(w[43], w[7], w[36], pars->GC_11, amp[32]); 
  FFV1_0(w[42], w[18], w[36], pars->GC_11, amp[33]); 
  FFV1_0(w[42], w[34], w[14], pars->GC_11, amp[34]); 
  FFV2_0(w[42], w[44], w[4], pars->GC_100, amp[35]); 
  FFV1_0(w[8], w[45], w[20], pars->GC_11, amp[36]); 
  FFV1_0(w[1], w[46], w[36], pars->GC_11, amp[37]); 
  VVV1_0(w[36], w[5], w[20], pars->GC_10, amp[38]); 
  FFV1_0(w[8], w[45], w[25], pars->GC_11, amp[39]); 
  FFV1_0(w[47], w[7], w[36], pars->GC_11, amp[40]); 
  VVV1_0(w[36], w[5], w[25], pars->GC_10, amp[41]); 
  FFV1_0(w[24], w[45], w[14], pars->GC_11, amp[42]); 
  VVV1_0(w[5], w[14], w[38], pars->GC_10, amp[43]); 
  FFV1_0(w[24], w[44], w[5], pars->GC_11, amp[44]); 
  FFV2_0(w[30], w[45], w[4], pars->GC_100, amp[45]); 
  FFV1_0(w[1], w[34], w[48], pars->GC_11, amp[46]); 
  FFV1_0(w[30], w[34], w[5], pars->GC_11, amp[47]); 
  FFV1_0(w[1], w[51], w[52], pars->GC_11, amp[48]); 
  FFV1_0(w[1], w[54], w[53], pars->GC_11, amp[49]); 
  FFV1_0(w[8], w[50], w[55], pars->GC_11, amp[50]); 
  FFV1_0(w[24], w[50], w[53], pars->GC_11, amp[51]); 
  FFV1_0(w[1], w[51], w[56], pars->GC_11, amp[52]); 
  FFV1_0(w[1], w[10], w[57], pars->GC_11, amp[53]); 
  FFV1_0(w[24], w[6], w[57], pars->GC_11, amp[54]); 
  FFV1_0(w[39], w[6], w[55], pars->GC_11, amp[55]); 
  FFV1_0(w[43], w[6], w[53], pars->GC_11, amp[56]); 
  FFV1_0(w[42], w[10], w[53], pars->GC_11, amp[57]); 
  FFV1_0(w[42], w[51], w[21], pars->GC_11, amp[58]); 
  FFV2_0(w[42], w[58], w[4], pars->GC_100, amp[59]); 
  FFV1_0(w[8], w[59], w[12], pars->GC_11, amp[60]); 
  FFV1_0(w[1], w[60], w[53], pars->GC_11, amp[61]); 
  VVV1_0(w[53], w[5], w[12], pars->GC_10, amp[62]); 
  FFV1_0(w[8], w[59], w[26], pars->GC_11, amp[63]); 
  FFV1_0(w[47], w[6], w[53], pars->GC_11, amp[64]); 
  VVV1_0(w[53], w[5], w[26], pars->GC_10, amp[65]); 
  FFV1_0(w[24], w[59], w[21], pars->GC_11, amp[66]); 
  VVV1_0(w[5], w[21], w[55], pars->GC_10, amp[67]); 
  FFV1_0(w[24], w[58], w[5], pars->GC_11, amp[68]); 
  FFV2_0(w[28], w[59], w[4], pars->GC_100, amp[69]); 
  FFV1_0(w[1], w[51], w[61], pars->GC_11, amp[70]); 
  FFV1_0(w[28], w[51], w[5], pars->GC_11, amp[71]); 
  FFV1_0(w[1], w[54], w[63], pars->GC_11, amp[72]); 
  FFV1_0(w[1], w[18], w[64], pars->GC_11, amp[73]); 
  FFV1_0(w[24], w[7], w[64], pars->GC_11, amp[74]); 
  FFV1_0(w[24], w[50], w[63], pars->GC_11, amp[75]); 
  FFV1_0(w[1], w[37], w[65], pars->GC_11, amp[76]); 
  FFV1_0(w[1], w[10], w[66], pars->GC_11, amp[77]); 
  FFV1_0(w[24], w[6], w[66], pars->GC_11, amp[78]); 
  FFV1_0(w[24], w[33], w[65], pars->GC_11, amp[79]); 
  FFV1_0(w[43], w[7], w[65], pars->GC_11, amp[80]); 
  FFV1_0(w[43], w[6], w[63], pars->GC_11, amp[81]); 
  FFV1_0(w[42], w[10], w[63], pars->GC_11, amp[82]); 
  FFV1_0(w[42], w[18], w[65], pars->GC_11, amp[83]); 
  FFV1_0(w[67], w[7], w[12], pars->GC_11, amp[84]); 
  FFV1_0(w[1], w[60], w[63], pars->GC_11, amp[85]); 
  VVV1_0(w[63], w[5], w[12], pars->GC_10, amp[86]); 
  FFV1_0(w[67], w[6], w[20], pars->GC_11, amp[87]); 
  FFV1_0(w[1], w[46], w[65], pars->GC_11, amp[88]); 
  VVV1_0(w[65], w[5], w[20], pars->GC_10, amp[89]); 
  FFV1_0(w[67], w[7], w[26], pars->GC_11, amp[90]); 
  FFV1_0(w[67], w[6], w[25], pars->GC_11, amp[91]); 
  FFV1_0(w[47], w[7], w[65], pars->GC_11, amp[92]); 
  VVV1_0(w[65], w[5], w[25], pars->GC_10, amp[93]); 
  FFV1_0(w[47], w[6], w[63], pars->GC_11, amp[94]); 
  VVV1_0(w[63], w[5], w[26], pars->GC_10, amp[95]); 
  FFV1_0(w[69], w[7], w[52], pars->GC_11, amp[96]); 
  FFV1_0(w[8], w[50], w[70], pars->GC_11, amp[97]); 
  FFV1_0(w[69], w[50], w[14], pars->GC_11, amp[98]); 
  FFV2_0(w[71], w[50], w[4], pars->GC_100, amp[99]); 
  FFV1_0(w[69], w[6], w[35], pars->GC_11, amp[100]); 
  FFV1_0(w[8], w[33], w[72], pars->GC_11, amp[101]); 
  FFV1_0(w[69], w[33], w[21], pars->GC_11, amp[102]); 
  FFV2_0(w[73], w[33], w[4], pars->GC_100, amp[103]); 
  FFV1_0(w[69], w[7], w[56], pars->GC_11, amp[104]); 
  FFV1_0(w[69], w[6], w[40], pars->GC_11, amp[105]); 
  FFV1_0(w[39], w[7], w[72], pars->GC_11, amp[106]); 
  FFV1_0(w[39], w[6], w[70], pars->GC_11, amp[107]); 
  FFV1_0(w[74], w[10], w[14], pars->GC_11, amp[108]); 
  VVV1_0(w[5], w[14], w[72], pars->GC_10, amp[109]); 
  FFV1_0(w[71], w[10], w[5], pars->GC_11, amp[110]); 
  FFV1_0(w[74], w[18], w[21], pars->GC_11, amp[111]); 
  VVV1_0(w[5], w[21], w[70], pars->GC_10, amp[112]); 
  FFV1_0(w[73], w[18], w[5], pars->GC_11, amp[113]); 
  FFV2_0(w[74], w[29], w[4], pars->GC_100, amp[114]); 
  FFV1_0(w[69], w[7], w[61], pars->GC_11, amp[115]); 
  FFV1_0(w[69], w[29], w[5], pars->GC_11, amp[116]); 
  FFV2_0(w[74], w[31], w[4], pars->GC_100, amp[117]); 
  FFV1_0(w[69], w[6], w[48], pars->GC_11, amp[118]); 
  FFV1_0(w[69], w[31], w[5], pars->GC_11, amp[119]); 
  FFV1_0(w[8], w[75], w[20], pars->GC_11, amp[120]); 
  FFV1_0(w[1], w[76], w[52], pars->GC_11, amp[121]); 
  VVV1_0(w[0], w[52], w[20], pars->GC_10, amp[122]); 
  FFV1_0(w[8], w[75], w[25], pars->GC_11, amp[123]); 
  FFV1_0(w[77], w[7], w[52], pars->GC_11, amp[124]); 
  VVV1_0(w[0], w[52], w[25], pars->GC_10, amp[125]); 
  FFV1_0(w[24], w[75], w[14], pars->GC_11, amp[126]); 
  FFV1_0(w[77], w[50], w[14], pars->GC_11, amp[127]); 
  FFV1_0(w[24], w[50], w[78], pars->GC_11, amp[128]); 
  FFV2_0(w[30], w[75], w[4], pars->GC_100, amp[129]); 
  FFV1_0(w[1], w[54], w[78], pars->GC_11, amp[130]); 
  FFV1_0(w[30], w[54], w[0], pars->GC_11, amp[131]); 
  FFV1_0(w[8], w[79], w[12], pars->GC_11, amp[132]); 
  FFV1_0(w[1], w[80], w[35], pars->GC_11, amp[133]); 
  VVV1_0(w[0], w[35], w[12], pars->GC_10, amp[134]); 
  FFV1_0(w[8], w[79], w[26], pars->GC_11, amp[135]); 
  FFV1_0(w[77], w[6], w[35], pars->GC_11, amp[136]); 
  VVV1_0(w[0], w[35], w[26], pars->GC_10, amp[137]); 
  FFV1_0(w[24], w[79], w[21], pars->GC_11, amp[138]); 
  FFV1_0(w[77], w[33], w[21], pars->GC_11, amp[139]); 
  FFV1_0(w[24], w[33], w[81], pars->GC_11, amp[140]); 
  FFV2_0(w[28], w[79], w[4], pars->GC_100, amp[141]); 
  FFV1_0(w[1], w[37], w[81], pars->GC_11, amp[142]); 
  FFV1_0(w[28], w[37], w[0], pars->GC_11, amp[143]); 
  FFV1_0(w[82], w[7], w[12], pars->GC_11, amp[144]); 
  FFV1_0(w[1], w[80], w[40], pars->GC_11, amp[145]); 
  VVV1_0(w[0], w[40], w[12], pars->GC_10, amp[146]); 
  FFV1_0(w[82], w[6], w[20], pars->GC_11, amp[147]); 
  FFV1_0(w[1], w[76], w[56], pars->GC_11, amp[148]); 
  VVV1_0(w[0], w[56], w[20], pars->GC_10, amp[149]); 
  FFV1_0(w[82], w[7], w[26], pars->GC_11, amp[150]); 
  FFV1_0(w[82], w[6], w[25], pars->GC_11, amp[151]); 
  FFV1_0(w[77], w[7], w[56], pars->GC_11, amp[152]); 
  FFV1_0(w[77], w[6], w[40], pars->GC_11, amp[153]); 
  VVV1_0(w[0], w[56], w[25], pars->GC_10, amp[154]); 
  VVV1_0(w[0], w[40], w[26], pars->GC_10, amp[155]); 
  FFV1_0(w[83], w[10], w[14], pars->GC_11, amp[156]); 
  FFV1_0(w[42], w[80], w[14], pars->GC_11, amp[157]); 
  FFV1_0(w[42], w[10], w[78], pars->GC_11, amp[158]); 
  FFV1_0(w[83], w[18], w[21], pars->GC_11, amp[159]); 
  FFV1_0(w[42], w[76], w[21], pars->GC_11, amp[160]); 
  FFV1_0(w[42], w[18], w[81], pars->GC_11, amp[161]); 
  FFV2_0(w[83], w[29], w[4], pars->GC_100, amp[162]); 
  FFV1_0(w[43], w[7], w[81], pars->GC_11, amp[163]); 
  FFV1_0(w[43], w[29], w[0], pars->GC_11, amp[164]); 
  FFV2_0(w[83], w[31], w[4], pars->GC_100, amp[165]); 
  FFV1_0(w[43], w[6], w[78], pars->GC_11, amp[166]); 
  FFV1_0(w[43], w[31], w[0], pars->GC_11, amp[167]); 
  FFV1_0(w[1], w[80], w[48], pars->GC_11, amp[168]); 
  FFV1_0(w[30], w[80], w[5], pars->GC_11, amp[169]); 
  FFV1_0(w[1], w[60], w[78], pars->GC_11, amp[170]); 
  VVV1_0(w[78], w[5], w[12], pars->GC_10, amp[171]); 
  FFV1_0(w[30], w[60], w[0], pars->GC_11, amp[172]); 
  VVV1_0(w[0], w[48], w[12], pars->GC_10, amp[173]); 
  FFV1_0(w[1], w[10], w[84], pars->GC_11, amp[174]); 
  FFV1_0(w[1], w[10], w[85], pars->GC_11, amp[175]); 
  FFV1_0(w[1], w[10], w[86], pars->GC_11, amp[176]); 
  FFV1_0(w[1], w[76], w[61], pars->GC_11, amp[177]); 
  FFV1_0(w[28], w[76], w[5], pars->GC_11, amp[178]); 
  FFV1_0(w[1], w[46], w[81], pars->GC_11, amp[179]); 
  VVV1_0(w[81], w[5], w[20], pars->GC_10, amp[180]); 
  FFV1_0(w[28], w[46], w[0], pars->GC_11, amp[181]); 
  VVV1_0(w[0], w[61], w[20], pars->GC_10, amp[182]); 
  FFV1_0(w[1], w[18], w[87], pars->GC_11, amp[183]); 
  FFV1_0(w[1], w[18], w[88], pars->GC_11, amp[184]); 
  FFV1_0(w[1], w[18], w[89], pars->GC_11, amp[185]); 
  FFV1_0(w[77], w[7], w[61], pars->GC_11, amp[186]); 
  FFV1_0(w[77], w[29], w[5], pars->GC_11, amp[187]); 
  FFV1_0(w[47], w[7], w[81], pars->GC_11, amp[188]); 
  VVV1_0(w[81], w[5], w[25], pars->GC_10, amp[189]); 
  FFV1_0(w[47], w[29], w[0], pars->GC_11, amp[190]); 
  VVV1_0(w[0], w[61], w[25], pars->GC_10, amp[191]); 
  FFV1_0(w[24], w[7], w[87], pars->GC_11, amp[192]); 
  FFV1_0(w[24], w[7], w[88], pars->GC_11, amp[193]); 
  FFV1_0(w[24], w[7], w[89], pars->GC_11, amp[194]); 
  FFV1_0(w[77], w[6], w[48], pars->GC_11, amp[195]); 
  FFV1_0(w[77], w[31], w[5], pars->GC_11, amp[196]); 
  FFV1_0(w[47], w[6], w[78], pars->GC_11, amp[197]); 
  VVV1_0(w[78], w[5], w[26], pars->GC_10, amp[198]); 
  FFV1_0(w[47], w[31], w[0], pars->GC_11, amp[199]); 
  VVV1_0(w[0], w[48], w[26], pars->GC_10, amp[200]); 
  FFV1_0(w[24], w[6], w[84], pars->GC_11, amp[201]); 
  FFV1_0(w[24], w[6], w[85], pars->GC_11, amp[202]); 
  FFV1_0(w[24], w[6], w[86], pars->GC_11, amp[203]); 

}
double P0_Sigma_sm_gd_mumvmxguuux_W_4j::matrix_gd_wmguuux_wm_mumvmx() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 204; 
  const int ncolor = 12; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; 
  static const double cf[ncolor][ncolor] = {{48, 16, 16, 6, 0, 16, -2, 0, -6,
      -2, -2, 6}, {16, 48, 6, 16, 16, 0, 0, -2, -2, -6, 6, -2}, {16, 6, 48, 16,
      -2, 0, 0, 16, -2, 6, -6, -2}, {6, 16, 16, 48, 0, -2, 16, 0, 6, -2, -2,
      -6}, {0, 16, -2, 0, 48, 16, 16, 6, 0, -2, 16, 0}, {16, 0, 0, -2, 16, 48,
      6, 16, -2, 0, 0, 16}, {-2, 0, 0, 16, 16, 6, 48, 16, 16, 0, 0, -2}, {0,
      -2, 16, 0, 6, 16, 16, 48, 0, 16, -2, 0}, {-6, -2, -2, 6, 0, -2, 16, 0,
      48, 16, 16, 6}, {-2, -6, 6, -2, -2, 0, 0, 16, 16, 48, 6, 16}, {-2, 6, -6,
      -2, 16, 0, 0, -2, 16, 6, 48, 16}, {6, -2, -2, -6, 0, 16, -2, 0, 6, 16,
      16, 48}};

  // Calculate color flows
  jamp[0] = +1./2. * (+1./3. * std::complex<double> (0, 1) * amp[2] + 1./3. *
      std::complex<double> (0, 1) * amp[4] + std::complex<double> (0, 1) *
      amp[5] - amp[8] + std::complex<double> (0, 1) * amp[9] +
      std::complex<double> (0, 1) * amp[10] + std::complex<double> (0, 1) *
      amp[14] - amp[15] + 1./3. * std::complex<double> (0, 1) * amp[17] + 1./3.
      * std::complex<double> (0, 1) * amp[18] + std::complex<double> (0, 1) *
      amp[21] + 1./3. * std::complex<double> (0, 1) * amp[22] + 1./3. *
      std::complex<double> (0, 1) * amp[23] - amp[32] - amp[33] - 1./3. *
      amp[34] - 1./3. * amp[35] - amp[36] + std::complex<double> (0, 1) *
      amp[38] - amp[39] - amp[40] + std::complex<double> (0, 1) * amp[41] -
      1./3. * amp[42] - 1./3. * amp[44] - 1./3. * amp[45] - 1./3. * amp[47] -
      1./3. * amp[156] - 1./3. * amp[157] - amp[159] - std::complex<double> (0,
      1) * amp[161] - amp[162] - std::complex<double> (0, 1) * amp[163] -
      amp[164] - 1./3. * amp[165] - 1./3. * amp[167] - 1./3. * amp[169] -
      amp[180] + amp[185] + amp[184] - std::complex<double> (0, 1) * amp[188] -
      amp[189] - amp[190] + amp[194] + amp[193] - 1./3. * amp[199]);
  jamp[1] = +1./2. * (-std::complex<double> (0, 1) * amp[1] -
      std::complex<double> (0, 1) * amp[2] - amp[3] - 1./3. *
      std::complex<double> (0, 1) * amp[5] - 1./3. * std::complex<double> (0,
      1) * amp[6] - 1./3. * std::complex<double> (0, 1) * amp[10] -
      std::complex<double> (0, 1) * amp[12] - 1./3. * std::complex<double> (0,
      1) * amp[13] - std::complex<double> (0, 1) * amp[18] - amp[19] -
      std::complex<double> (0, 1) * amp[22] + amp[28] + 1./3. * amp[29] + 1./3.
      * amp[30] + amp[31] + 1./3. * amp[36] + 1./3. * amp[39] + amp[42] -
      std::complex<double> (0, 1) * amp[43] + amp[45] - std::complex<double>
      (0, 1) * amp[46] + amp[47] + amp[144] + amp[145] - std::complex<double>
      (0, 1) * amp[146] + 1./3. * amp[147] + amp[150] + 1./3. * amp[151] -
      std::complex<double> (0, 1) * amp[155] - std::complex<double> (0, 1) *
      amp[168] + amp[169] - amp[173] + amp[176] - amp[174] - amp[200] +
      amp[203] - amp[201]);
  jamp[2] = +1./2. * (-std::complex<double> (0, 1) * amp[0] + amp[3] -
      std::complex<double> (0, 1) * amp[4] - 1./3. * std::complex<double> (0,
      1) * amp[7] - 1./3. * std::complex<double> (0, 1) * amp[9] -
      std::complex<double> (0, 1) * amp[11] - 1./3. * std::complex<double> (0,
      1) * amp[14] - 1./3. * std::complex<double> (0, 1) * amp[16] -
      std::complex<double> (0, 1) * amp[17] + amp[19] - 1./3. *
      std::complex<double> (0, 1) * amp[20] - 1./3. * std::complex<double> (0,
      1) * amp[21] - std::complex<double> (0, 1) * amp[23] + amp[56] + amp[57]
      + 1./3. * amp[58] + 1./3. * amp[59] + amp[60] - std::complex<double> (0,
      1) * amp[62] + amp[63] + amp[64] - std::complex<double> (0, 1) * amp[65]
      + 1./3. * amp[66] + 1./3. * amp[68] + 1./3. * amp[69] + 1./3. * amp[71] +
      amp[156] + std::complex<double> (0, 1) * amp[158] + 1./3. * amp[159] +
      1./3. * amp[160] + 1./3. * amp[162] + 1./3. * amp[164] + amp[165] +
      std::complex<double> (0, 1) * amp[166] + amp[167] + amp[171] - amp[176] -
      amp[175] + 1./3. * amp[178] + 1./3. * amp[190] + std::complex<double> (0,
      1) * amp[197] + amp[198] + amp[199] - amp[203] - amp[202]);
  jamp[3] = +1./2. * (+1./3. * std::complex<double> (0, 1) * amp[0] + 1./3. *
      std::complex<double> (0, 1) * amp[1] + std::complex<double> (0, 1) *
      amp[6] + std::complex<double> (0, 1) * amp[7] + amp[8] + 1./3. *
      std::complex<double> (0, 1) * amp[11] + 1./3. * std::complex<double> (0,
      1) * amp[12] + std::complex<double> (0, 1) * amp[13] + amp[15] +
      std::complex<double> (0, 1) * amp[16] + std::complex<double> (0, 1) *
      amp[20] - amp[52] - 1./3. * amp[53] - 1./3. * amp[54] - amp[55] - 1./3. *
      amp[60] - 1./3. * amp[63] - amp[66] + std::complex<double> (0, 1) *
      amp[67] - amp[69] + std::complex<double> (0, 1) * amp[70] - amp[71] -
      1./3. * amp[144] - amp[147] - amp[148] + std::complex<double> (0, 1) *
      amp[149] - 1./3. * amp[150] - amp[151] + std::complex<double> (0, 1) *
      amp[154] + std::complex<double> (0, 1) * amp[177] - amp[178] + amp[182] -
      amp[185] + amp[183] + amp[191] - amp[194] + amp[192]);
  jamp[4] = +1./2. * (-1./3. * amp[24] - amp[25] - 1./3. * amp[26] - amp[27] -
      1./3. * amp[28] - amp[29] - amp[30] - 1./3. * amp[31] - amp[37] -
      std::complex<double> (0, 1) * amp[38] - std::complex<double> (0, 1) *
      amp[41] - 1./3. * amp[100] - 1./3. * amp[101] - amp[102] - amp[103] -
      amp[104] - 1./3. * amp[105] - 1./3. * amp[106] - amp[107] +
      std::complex<double> (0, 1) * amp[112] - amp[113] + std::complex<double>
      (0, 1) * amp[115] - 1./3. * amp[133] - 1./3. * amp[136] - amp[139] -
      std::complex<double> (0, 1) * amp[140] - std::complex<double> (0, 1) *
      amp[142] - 1./3. * amp[145] - std::complex<double> (0, 1) * amp[149] -
      amp[152] - 1./3. * amp[153] - std::complex<double> (0, 1) * amp[154] -
      std::complex<double> (0, 1) * amp[179] + amp[180] - amp[182] - amp[183] -
      amp[184] + std::complex<double> (0, 1) * amp[186] + amp[189] - amp[191] -
      amp[192] - amp[193]);
  jamp[5] = +1./2. * (+amp[24] + 1./3. * amp[25] + amp[26] + 1./3. * amp[27] +
      1./3. * amp[32] + 1./3. * amp[33] + amp[34] + amp[35] + 1./3. * amp[37] +
      1./3. * amp[40] + std::complex<double> (0, 1) * amp[43] + amp[44] +
      std::complex<double> (0, 1) * amp[46] + 1./3. * amp[76] + amp[77] +
      amp[78] + 1./3. * amp[79] + 1./3. * amp[80] + amp[81] + amp[82] + 1./3. *
      amp[83] - std::complex<double> (0, 1) * amp[86] + 1./3. * amp[88] + 1./3.
      * amp[92] + amp[94] - std::complex<double> (0, 1) * amp[95] + amp[133] -
      std::complex<double> (0, 1) * amp[134] - std::complex<double> (0, 1) *
      amp[137] + amp[157] - std::complex<double> (0, 1) * amp[158] -
      std::complex<double> (0, 1) * amp[166] + std::complex<double> (0, 1) *
      amp[168] - amp[171] + amp[173] + amp[174] + amp[175] -
      std::complex<double> (0, 1) * amp[197] - amp[198] + amp[200] + amp[201] +
      amp[202]);
  jamp[6] = +1./2. * (+1./3. * amp[48] + amp[49] + 1./3. * amp[50] + amp[51] +
      1./3. * amp[52] + amp[53] + amp[54] + 1./3. * amp[55] + amp[61] +
      std::complex<double> (0, 1) * amp[62] + std::complex<double> (0, 1) *
      amp[65] + 1./3. * amp[96] + 1./3. * amp[97] + amp[98] + amp[99] + 1./3. *
      amp[104] + amp[105] + amp[106] + 1./3. * amp[107] - std::complex<double>
      (0, 1) * amp[109] + amp[110] - std::complex<double> (0, 1) * amp[118] +
      1./3. * amp[121] + 1./3. * amp[124] + amp[127] + std::complex<double> (0,
      1) * amp[128] + std::complex<double> (0, 1) * amp[130] +
      std::complex<double> (0, 1) * amp[146] + 1./3. * amp[148] + 1./3. *
      amp[152] + amp[153] + std::complex<double> (0, 1) * amp[155] +
      std::complex<double> (0, 1) * amp[170] - amp[171] + amp[173] + amp[174] +
      amp[175] - std::complex<double> (0, 1) * amp[195] - amp[198] + amp[200] +
      amp[201] + amp[202]);
  jamp[7] = +1./2. * (-amp[48] - 1./3. * amp[49] - amp[50] - 1./3. * amp[51] -
      1./3. * amp[56] - 1./3. * amp[57] - amp[58] - amp[59] - 1./3. * amp[61] -
      1./3. * amp[64] - std::complex<double> (0, 1) * amp[67] - amp[68] -
      std::complex<double> (0, 1) * amp[70] - 1./3. * amp[72] - amp[73] -
      amp[74] - 1./3. * amp[75] - amp[80] - 1./3. * amp[81] - 1./3. * amp[82] -
      amp[83] - 1./3. * amp[85] + std::complex<double> (0, 1) * amp[89] -
      amp[92] + std::complex<double> (0, 1) * amp[93] - 1./3. * amp[94] -
      amp[121] + std::complex<double> (0, 1) * amp[122] + std::complex<double>
      (0, 1) * amp[125] - amp[160] + std::complex<double> (0, 1) * amp[161] +
      std::complex<double> (0, 1) * amp[163] - std::complex<double> (0, 1) *
      amp[177] + amp[180] - amp[182] - amp[183] - amp[184] +
      std::complex<double> (0, 1) * amp[188] + amp[189] - amp[191] - amp[192] -
      amp[193]);
  jamp[8] = +1./2. * (-1./3. * std::complex<double> (0, 1) * amp[2] - 1./3. *
      std::complex<double> (0, 1) * amp[4] - std::complex<double> (0, 1) *
      amp[5] + amp[8] - std::complex<double> (0, 1) * amp[9] -
      std::complex<double> (0, 1) * amp[10] - std::complex<double> (0, 1) *
      amp[14] + amp[15] - 1./3. * std::complex<double> (0, 1) * amp[17] - 1./3.
      * std::complex<double> (0, 1) * amp[18] - std::complex<double> (0, 1) *
      amp[21] - 1./3. * std::complex<double> (0, 1) * amp[22] - 1./3. *
      std::complex<double> (0, 1) * amp[23] - amp[96] - amp[97] - 1./3. *
      amp[98] - 1./3. * amp[99] - 1./3. * amp[108] - 1./3. * amp[110] -
      amp[111] - std::complex<double> (0, 1) * amp[112] - amp[114] -
      std::complex<double> (0, 1) * amp[115] - amp[116] - 1./3. * amp[117] -
      1./3. * amp[119] - amp[120] - std::complex<double> (0, 1) * amp[122] -
      amp[123] - amp[124] - std::complex<double> (0, 1) * amp[125] - 1./3. *
      amp[126] - 1./3. * amp[127] - 1./3. * amp[129] - 1./3. * amp[131] - 1./3.
      * amp[172] + amp[182] - amp[185] + amp[183] - std::complex<double> (0, 1)
      * amp[186] - amp[187] + amp[191] - amp[194] + amp[192] - 1./3. *
      amp[196]);
  jamp[9] = +1./2. * (+std::complex<double> (0, 1) * amp[1] +
      std::complex<double> (0, 1) * amp[2] + amp[3] + 1./3. *
      std::complex<double> (0, 1) * amp[5] + 1./3. * std::complex<double> (0,
      1) * amp[6] + 1./3. * std::complex<double> (0, 1) * amp[10] +
      std::complex<double> (0, 1) * amp[12] + 1./3. * std::complex<double> (0,
      1) * amp[13] + std::complex<double> (0, 1) * amp[18] + amp[19] +
      std::complex<double> (0, 1) * amp[22] + amp[72] + 1./3. * amp[73] + 1./3.
      * amp[74] + amp[75] + amp[84] + amp[85] + std::complex<double> (0, 1) *
      amp[86] + 1./3. * amp[87] + amp[90] + 1./3. * amp[91] +
      std::complex<double> (0, 1) * amp[95] + 1./3. * amp[120] + 1./3. *
      amp[123] + amp[126] - std::complex<double> (0, 1) * amp[128] + amp[129] -
      std::complex<double> (0, 1) * amp[130] + amp[131] - std::complex<double>
      (0, 1) * amp[170] + amp[171] + amp[172] - amp[176] - amp[175] + amp[198]
      - amp[203] - amp[202]);
  jamp[10] = +1./2. * (+std::complex<double> (0, 1) * amp[0] - amp[3] +
      std::complex<double> (0, 1) * amp[4] + 1./3. * std::complex<double> (0,
      1) * amp[7] + 1./3. * std::complex<double> (0, 1) * amp[9] +
      std::complex<double> (0, 1) * amp[11] + 1./3. * std::complex<double> (0,
      1) * amp[14] + 1./3. * std::complex<double> (0, 1) * amp[16] +
      std::complex<double> (0, 1) * amp[17] - amp[19] + 1./3. *
      std::complex<double> (0, 1) * amp[20] + 1./3. * std::complex<double> (0,
      1) * amp[21] + std::complex<double> (0, 1) * amp[23] + amp[100] +
      amp[101] + 1./3. * amp[102] + 1./3. * amp[103] + amp[108] +
      std::complex<double> (0, 1) * amp[109] + 1./3. * amp[111] + 1./3. *
      amp[113] + 1./3. * amp[114] + 1./3. * amp[116] + amp[117] +
      std::complex<double> (0, 1) * amp[118] + amp[119] + amp[132] +
      std::complex<double> (0, 1) * amp[134] + amp[135] + amp[136] +
      std::complex<double> (0, 1) * amp[137] + 1./3. * amp[138] + 1./3. *
      amp[139] + 1./3. * amp[141] + 1./3. * amp[143] - amp[173] + amp[176] -
      amp[174] + 1./3. * amp[181] + 1./3. * amp[187] + std::complex<double> (0,
      1) * amp[195] + amp[196] - amp[200] + amp[203] - amp[201]);
  jamp[11] = +1./2. * (-1./3. * std::complex<double> (0, 1) * amp[0] - 1./3. *
      std::complex<double> (0, 1) * amp[1] - std::complex<double> (0, 1) *
      amp[6] - std::complex<double> (0, 1) * amp[7] - amp[8] - 1./3. *
      std::complex<double> (0, 1) * amp[11] - 1./3. * std::complex<double> (0,
      1) * amp[12] - std::complex<double> (0, 1) * amp[13] - amp[15] -
      std::complex<double> (0, 1) * amp[16] - std::complex<double> (0, 1) *
      amp[20] - amp[76] - 1./3. * amp[77] - 1./3. * amp[78] - amp[79] - 1./3. *
      amp[84] - amp[87] - amp[88] - std::complex<double> (0, 1) * amp[89] -
      1./3. * amp[90] - amp[91] - std::complex<double> (0, 1) * amp[93] - 1./3.
      * amp[132] - 1./3. * amp[135] - amp[138] + std::complex<double> (0, 1) *
      amp[140] - amp[141] + std::complex<double> (0, 1) * amp[142] - amp[143] +
      std::complex<double> (0, 1) * amp[179] - amp[180] - amp[181] + amp[185] +
      amp[184] - amp[189] + amp[194] + amp[193]);

  // Sum and square the color flows to get the matrix element
  double matrix = 0; 
  for(i = 0; i < ncolor; i++ )
  {
    ztemp = 0.; 
    for(j = 0; j < ncolor; j++ )
      ztemp = ztemp + cf[i][j] * jamp[j]; 
    matrix = matrix + real(ztemp * conj(jamp[i]))/denom[i]; 
  }

  // Store the leading color flows for choice of color
  for(i = 0; i < ncolor; i++ )
    jamp2[0][i] += real(jamp[i] * conj(jamp[i])); 

  return matrix; 
}



