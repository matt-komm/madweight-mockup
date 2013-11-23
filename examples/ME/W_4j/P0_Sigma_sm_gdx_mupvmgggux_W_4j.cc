//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "P0_Sigma_sm_gdx_mupvmgggux_W_4j.h"
#include "HelAmps_sm.h"

using namespace MG5_sm; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g d~ > w+ g g g u~ WEIGHTED=6
// *   Decay: w+ > mu+ vm WEIGHTED=2
// Process: g s~ > w+ g g g c~ WEIGHTED=6
// *   Decay: w+ > mu+ vm WEIGHTED=2

//--------------------------------------------------------------------------
// Initialize process.

void P0_Sigma_sm_gdx_mupvmgggux_W_4j::initProc(string param_card_name) 
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
  jamp2[0] = new double[24]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void P0_Sigma_sm_gdx_mupvmgggux_W_4j::sigmaKin() 
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
  for(int i = 0; i < 24; i++ )
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
  const int denominators[nprocesses] = {576, 576}; 

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
        t[0] = matrix_gdx_wpgggux_wp_mupvm(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_gdx_wpgggux_wp_mupvm(); 
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
      t[0] = matrix_gdx_wpgggux_wp_mupvm(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_gdx_wpgggux_wp_mupvm(); 
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

double P0_Sigma_sm_gdx_mupvmgggux_W_4j::sigmaHat() 
{
  // Select between the different processes
  if(id1 == 21 && id2 == -1)
  {
    // Add matrix elements for processes with beams (21, -1)
    return matrix_element[0]; 
  }
  else if(id1 == 21 && id2 == -3)
  {
    // Add matrix elements for processes with beams (21, -3)
    return matrix_element[0]; 
  }
  else if(id1 == -1 && id2 == 21)
  {
    // Add matrix elements for processes with beams (-1, 21)
    return matrix_element[1]; 
  }
  else if(id1 == -3 && id2 == 21)
  {
    // Add matrix elements for processes with beams (-3, 21)
    return matrix_element[1]; 
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

void P0_Sigma_sm_gdx_mupvmgggux_W_4j::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  vxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]); 
  oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]); 
  ixxxxx(p[perm[2]], mME[2], hel[2], -1, w[2]); 
  oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  FFV2_3(w[2], w[3], pars->GC_100, pars->MW, pars->WW, w[4]); 
  vxxxxx(p[perm[4]], mME[4], hel[4], +1, w[5]); 
  vxxxxx(p[perm[5]], mME[5], hel[5], +1, w[6]); 
  vxxxxx(p[perm[6]], mME[6], hel[6], +1, w[7]); 
  ixxxxx(p[perm[7]], mME[7], hel[7], -1, w[8]); 
  VVV1_1(w[0], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[9]); 
  FFV2_1(w[1], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[10]); 
  VVV1_1(w[9], w[6], pars->GC_10, pars->ZERO, pars->ZERO, w[11]); 
  FFV1_1(w[10], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_3(w[8], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[13]); 
  VVV1_1(w[9], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[14]); 
  FFV1_1(w[10], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[15]); 
  FFV1_2(w[8], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[16]); 
  VVVV1_1(w[9], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[17]); 
  VVVV3_1(w[9], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[18]); 
  VVVV4_1(w[9], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[19]); 
  VVV1_1(w[6], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[20]); 
  FFV1_1(w[10], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[21]); 
  VVV1_1(w[9], w[20], pars->GC_10, pars->ZERO, pars->ZERO, w[22]); 
  FFV1_2(w[8], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[23]); 
  FFV1_2(w[23], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[24]); 
  FFV1_2(w[8], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[25]); 
  FFV1_2(w[25], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[26]); 
  FFV2_2(w[8], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[27]); 
  FFV1_2(w[27], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[28]); 
  FFV1_3(w[27], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[29]); 
  FFV1_2(w[27], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[30]); 
  FFV1_1(w[1], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[31]); 
  FFV1_2(w[27], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[32]); 
  FFV1_1(w[1], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[33]); 
  FFV1_1(w[33], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[34]); 
  FFV1_1(w[1], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[35]); 
  FFV1_1(w[35], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[36]); 
  FFV1_2(w[8], w[20], pars->GC_11, pars->ZERO, pars->ZERO, w[37]); 
  FFV1_1(w[1], w[20], pars->GC_11, pars->ZERO, pars->ZERO, w[38]); 
  FFV2_1(w[33], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[39]); 
  FFV1_1(w[33], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[40]); 
  FFV2_2(w[23], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[41]); 
  FFV1_2(w[23], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[42]); 
  FFV2_1(w[35], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[43]); 
  FFV1_1(w[35], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[44]); 
  FFV2_2(w[25], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[45]); 
  FFV1_2(w[25], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[46]); 
  VVV1_1(w[0], w[6], pars->GC_10, pars->ZERO, pars->ZERO, w[47]); 
  VVV1_1(w[5], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[48]); 
  FFV1_1(w[1], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[49]); 
  FFV1_2(w[8], w[48], pars->GC_11, pars->ZERO, pars->ZERO, w[50]); 
  FFV1_2(w[8], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[51]); 
  FFV1_1(w[1], w[48], pars->GC_11, pars->ZERO, pars->ZERO, w[52]); 
  VVV1_1(w[47], w[48], pars->GC_10, pars->ZERO, pars->ZERO, w[53]); 
  FFV1_1(w[10], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[54]); 
  FFV1_2(w[27], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[55]); 
  FFV1_1(w[1], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[56]); 
  VVV1_1(w[47], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[57]); 
  FFV2_1(w[56], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[58]); 
  FFV1_1(w[56], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[59]); 
  FFV1_1(w[56], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[60]); 
  FFV1_2(w[25], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[61]); 
  FFV1_2(w[8], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[62]); 
  FFV2_2(w[62], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[63]); 
  FFV1_2(w[62], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[64]); 
  FFV1_2(w[62], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[65]); 
  FFV1_1(w[35], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[66]); 
  VVV1_1(w[47], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[67]); 
  FFV1_1(w[10], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[68]); 
  VVVV1_1(w[47], w[5], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[69]); 
  VVVV3_1(w[47], w[5], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[70]); 
  VVVV4_1(w[47], w[5], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[71]); 
  FFV1_2(w[27], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[72]); 
  FFV1_1(w[35], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[73]); 
  FFV1_2(w[25], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[74]); 
  VVV1_1(w[0], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[75]); 
  VVV1_1(w[5], w[6], pars->GC_10, pars->ZERO, pars->ZERO, w[76]); 
  FFV1_1(w[1], w[75], pars->GC_11, pars->ZERO, pars->ZERO, w[77]); 
  FFV1_2(w[8], w[76], pars->GC_11, pars->ZERO, pars->ZERO, w[78]); 
  FFV1_2(w[8], w[75], pars->GC_11, pars->ZERO, pars->ZERO, w[79]); 
  FFV1_1(w[1], w[76], pars->GC_11, pars->ZERO, pars->ZERO, w[80]); 
  VVV1_1(w[75], w[76], pars->GC_10, pars->ZERO, pars->ZERO, w[81]); 
  FFV1_1(w[10], w[75], pars->GC_11, pars->ZERO, pars->ZERO, w[82]); 
  FFV1_2(w[27], w[75], pars->GC_11, pars->ZERO, pars->ZERO, w[83]); 
  VVV1_1(w[75], w[6], pars->GC_10, pars->ZERO, pars->ZERO, w[84]); 
  FFV1_1(w[56], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[85]); 
  FFV1_1(w[56], w[75], pars->GC_11, pars->ZERO, pars->ZERO, w[86]); 
  FFV1_2(w[23], w[75], pars->GC_11, pars->ZERO, pars->ZERO, w[87]); 
  FFV1_2(w[62], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[88]); 
  FFV1_2(w[62], w[75], pars->GC_11, pars->ZERO, pars->ZERO, w[89]); 
  FFV1_1(w[33], w[75], pars->GC_11, pars->ZERO, pars->ZERO, w[90]); 
  VVV1_1(w[75], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[91]); 
  VVVV1_1(w[75], w[5], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[92]); 
  VVVV3_1(w[75], w[5], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[93]); 
  VVVV4_1(w[75], w[5], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[94]); 
  FFV1_1(w[33], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[95]); 
  FFV1_2(w[23], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[96]); 
  FFV1_1(w[1], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[97]); 
  FFV2_1(w[97], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[98]); 
  VVV1_1(w[76], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[99]); 
  FFV1_1(w[97], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[100]); 
  FFV1_1(w[97], w[76], pars->GC_11, pars->ZERO, pars->ZERO, w[101]); 
  FFV1_3(w[27], w[97], pars->GC_11, pars->ZERO, pars->ZERO, w[102]); 
  VVV1_1(w[48], w[6], pars->GC_10, pars->ZERO, pars->ZERO, w[103]); 
  FFV1_1(w[97], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[104]); 
  FFV1_1(w[97], w[48], pars->GC_11, pars->ZERO, pars->ZERO, w[105]); 
  FFV1_1(w[97], w[20], pars->GC_11, pars->ZERO, pars->ZERO, w[106]); 
  FFV1_1(w[97], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[107]); 
  VVV1_1(w[5], w[20], pars->GC_10, pars->ZERO, pars->ZERO, w[108]); 
  VVVV1_1(w[5], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[109]); 
  VVVV3_1(w[5], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[110]); 
  VVVV4_1(w[5], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[111]); 
  FFV1_2(w[8], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[112]); 
  FFV2_2(w[112], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[113]); 
  FFV1_2(w[112], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[114]); 
  FFV1_2(w[112], w[76], pars->GC_11, pars->ZERO, pars->ZERO, w[115]); 
  FFV1_3(w[112], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[116]); 
  FFV1_2(w[112], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[117]); 
  FFV1_2(w[112], w[48], pars->GC_11, pars->ZERO, pars->ZERO, w[118]); 
  FFV1_2(w[112], w[20], pars->GC_11, pars->ZERO, pars->ZERO, w[119]); 
  FFV1_2(w[112], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[120]); 
  VVV1_1(w[0], w[76], pars->GC_10, pars->ZERO, pars->ZERO, w[121]); 
  FFV1_1(w[10], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[122]); 
  VVVV1_1(w[0], w[76], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[123]); 
  VVVV3_1(w[0], w[76], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[124]); 
  VVVV4_1(w[0], w[76], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[125]); 
  FFV1_2(w[25], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[126]); 
  FFV1_2(w[27], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[127]); 
  FFV1_1(w[35], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[128]); 
  VVV1_1(w[0], w[48], pars->GC_10, pars->ZERO, pars->ZERO, w[129]); 
  VVVV1_1(w[0], w[48], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[130]); 
  VVVV3_1(w[0], w[48], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[131]); 
  VVVV4_1(w[0], w[48], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[132]); 
  FFV1_2(w[23], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[133]); 
  FFV1_1(w[33], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[134]); 
  FFV1_1(w[56], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[135]); 
  VVV1_1(w[0], w[20], pars->GC_10, pars->ZERO, pars->ZERO, w[136]); 
  FFV1_2(w[62], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[137]); 
  VVVV1_1(w[0], w[5], w[20], pars->GC_12, pars->ZERO, pars->ZERO, w[138]); 
  VVVV3_1(w[0], w[5], w[20], pars->GC_12, pars->ZERO, pars->ZERO, w[139]); 
  VVVV4_1(w[0], w[5], w[20], pars->GC_12, pars->ZERO, pars->ZERO, w[140]); 
  VVVV1_1(w[0], w[5], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[141]); 
  VVVV3_1(w[0], w[5], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[142]); 
  VVVV4_1(w[0], w[5], w[6], pars->GC_12, pars->ZERO, pars->ZERO, w[143]); 
  VVV1_1(w[141], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[144]); 
  VVV1_1(w[142], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[145]); 
  VVV1_1(w[143], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[146]); 
  FFV1_2(w[8], w[141], pars->GC_11, pars->ZERO, pars->ZERO, w[147]); 
  FFV1_2(w[8], w[142], pars->GC_11, pars->ZERO, pars->ZERO, w[148]); 
  FFV1_2(w[8], w[143], pars->GC_11, pars->ZERO, pars->ZERO, w[149]); 
  FFV1_1(w[1], w[141], pars->GC_11, pars->ZERO, pars->ZERO, w[150]); 
  FFV1_1(w[1], w[142], pars->GC_11, pars->ZERO, pars->ZERO, w[151]); 
  FFV1_1(w[1], w[143], pars->GC_11, pars->ZERO, pars->ZERO, w[152]); 
  VVVV1_1(w[0], w[5], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[153]); 
  VVVV3_1(w[0], w[5], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[154]); 
  VVVV4_1(w[0], w[5], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[155]); 
  VVV1_1(w[153], w[6], pars->GC_10, pars->ZERO, pars->ZERO, w[156]); 
  VVV1_1(w[154], w[6], pars->GC_10, pars->ZERO, pars->ZERO, w[157]); 
  VVV1_1(w[155], w[6], pars->GC_10, pars->ZERO, pars->ZERO, w[158]); 
  FFV1_2(w[8], w[153], pars->GC_11, pars->ZERO, pars->ZERO, w[159]); 
  FFV1_2(w[8], w[154], pars->GC_11, pars->ZERO, pars->ZERO, w[160]); 
  FFV1_2(w[8], w[155], pars->GC_11, pars->ZERO, pars->ZERO, w[161]); 
  FFV1_1(w[1], w[153], pars->GC_11, pars->ZERO, pars->ZERO, w[162]); 
  FFV1_1(w[1], w[154], pars->GC_11, pars->ZERO, pars->ZERO, w[163]); 
  FFV1_1(w[1], w[155], pars->GC_11, pars->ZERO, pars->ZERO, w[164]); 
  VVVV1_1(w[0], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[165]); 
  VVVV3_1(w[0], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[166]); 
  VVVV4_1(w[0], w[6], w[7], pars->GC_12, pars->ZERO, pars->ZERO, w[167]); 
  FFV1_2(w[8], w[165], pars->GC_11, pars->ZERO, pars->ZERO, w[168]); 
  FFV1_2(w[8], w[166], pars->GC_11, pars->ZERO, pars->ZERO, w[169]); 
  FFV1_2(w[8], w[167], pars->GC_11, pars->ZERO, pars->ZERO, w[170]); 
  FFV1_1(w[1], w[165], pars->GC_11, pars->ZERO, pars->ZERO, w[171]); 
  FFV1_1(w[1], w[166], pars->GC_11, pars->ZERO, pars->ZERO, w[172]); 
  FFV1_1(w[1], w[167], pars->GC_11, pars->ZERO, pars->ZERO, w[173]); 
  VVV1_1(w[165], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[174]); 
  VVV1_1(w[166], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[175]); 
  VVV1_1(w[167], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[176]); 
  VVV1_1(w[0], w[109], pars->GC_10, pars->ZERO, pars->ZERO, w[177]); 
  VVV1_1(w[0], w[110], pars->GC_10, pars->ZERO, pars->ZERO, w[178]); 
  VVV1_1(w[0], w[111], pars->GC_10, pars->ZERO, pars->ZERO, w[179]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[8], w[12], w[11], pars->GC_11, amp[0]); 
  VVV1_0(w[11], w[13], w[7], pars->GC_10, amp[1]); 
  FFV1_0(w[8], w[15], w[14], pars->GC_11, amp[2]); 
  VVV1_0(w[14], w[13], w[6], pars->GC_10, amp[3]); 
  FFV1_0(w[16], w[15], w[7], pars->GC_11, amp[4]); 
  FFV1_0(w[16], w[12], w[6], pars->GC_11, amp[5]); 
  FFV1_0(w[8], w[10], w[17], pars->GC_11, amp[6]); 
  FFV1_0(w[8], w[10], w[18], pars->GC_11, amp[7]); 
  FFV1_0(w[8], w[10], w[19], pars->GC_11, amp[8]); 
  FFV1_0(w[8], w[21], w[20], pars->GC_11, amp[9]); 
  FFV1_0(w[8], w[10], w[22], pars->GC_11, amp[10]); 
  FFV1_0(w[16], w[10], w[20], pars->GC_11, amp[11]); 
  FFV1_0(w[23], w[21], w[7], pars->GC_11, amp[12]); 
  FFV1_0(w[24], w[10], w[7], pars->GC_11, amp[13]); 
  FFV1_0(w[23], w[10], w[14], pars->GC_11, amp[14]); 
  FFV1_0(w[25], w[21], w[6], pars->GC_11, amp[15]); 
  FFV1_0(w[25], w[10], w[11], pars->GC_11, amp[16]); 
  FFV1_0(w[26], w[10], w[6], pars->GC_11, amp[17]); 
  FFV1_0(w[28], w[1], w[11], pars->GC_11, amp[18]); 
  VVV1_0(w[11], w[29], w[7], pars->GC_10, amp[19]); 
  FFV1_0(w[30], w[1], w[14], pars->GC_11, amp[20]); 
  VVV1_0(w[14], w[29], w[6], pars->GC_10, amp[21]); 
  FFV1_0(w[30], w[31], w[7], pars->GC_11, amp[22]); 
  FFV1_0(w[28], w[31], w[6], pars->GC_11, amp[23]); 
  FFV1_0(w[27], w[1], w[17], pars->GC_11, amp[24]); 
  FFV1_0(w[27], w[1], w[18], pars->GC_11, amp[25]); 
  FFV1_0(w[27], w[1], w[19], pars->GC_11, amp[26]); 
  FFV1_0(w[32], w[1], w[20], pars->GC_11, amp[27]); 
  FFV1_0(w[27], w[1], w[22], pars->GC_11, amp[28]); 
  FFV1_0(w[27], w[31], w[20], pars->GC_11, amp[29]); 
  FFV1_0(w[32], w[33], w[7], pars->GC_11, amp[30]); 
  FFV1_0(w[27], w[34], w[7], pars->GC_11, amp[31]); 
  FFV1_0(w[27], w[33], w[14], pars->GC_11, amp[32]); 
  FFV1_0(w[32], w[35], w[6], pars->GC_11, amp[33]); 
  FFV1_0(w[27], w[35], w[11], pars->GC_11, amp[34]); 
  FFV1_0(w[27], w[36], w[6], pars->GC_11, amp[35]); 
  FFV2_0(w[37], w[31], w[4], pars->GC_100, amp[36]); 
  FFV2_0(w[16], w[38], w[4], pars->GC_100, amp[37]); 
  FFV1_0(w[8], w[39], w[14], pars->GC_11, amp[38]); 
  FFV1_0(w[16], w[39], w[7], pars->GC_11, amp[39]); 
  FFV2_0(w[16], w[40], w[4], pars->GC_100, amp[40]); 
  FFV2_0(w[25], w[34], w[4], pars->GC_100, amp[41]); 
  FFV2_0(w[26], w[33], w[4], pars->GC_100, amp[42]); 
  FFV1_0(w[41], w[1], w[14], pars->GC_11, amp[43]); 
  FFV1_0(w[41], w[31], w[7], pars->GC_11, amp[44]); 
  FFV2_0(w[42], w[31], w[4], pars->GC_100, amp[45]); 
  FFV2_0(w[24], w[35], w[4], pars->GC_100, amp[46]); 
  FFV2_0(w[23], w[36], w[4], pars->GC_100, amp[47]); 
  FFV1_0(w[8], w[43], w[11], pars->GC_11, amp[48]); 
  FFV1_0(w[16], w[43], w[6], pars->GC_11, amp[49]); 
  FFV2_0(w[16], w[44], w[4], pars->GC_100, amp[50]); 
  FFV1_0(w[45], w[1], w[11], pars->GC_11, amp[51]); 
  FFV1_0(w[45], w[31], w[6], pars->GC_11, amp[52]); 
  FFV2_0(w[46], w[31], w[4], pars->GC_100, amp[53]); 
  FFV2_0(w[50], w[49], w[4], pars->GC_100, amp[54]); 
  FFV2_0(w[51], w[52], w[4], pars->GC_100, amp[55]); 
  FFV1_0(w[8], w[10], w[53], pars->GC_11, amp[56]); 
  FFV1_0(w[8], w[54], w[48], pars->GC_11, amp[57]); 
  FFV1_0(w[51], w[10], w[48], pars->GC_11, amp[58]); 
  FFV1_0(w[27], w[1], w[53], pars->GC_11, amp[59]); 
  FFV1_0(w[55], w[1], w[48], pars->GC_11, amp[60]); 
  FFV1_0(w[27], w[49], w[48], pars->GC_11, amp[61]); 
  FFV1_0(w[8], w[58], w[57], pars->GC_11, amp[62]); 
  FFV1_0(w[51], w[58], w[7], pars->GC_11, amp[63]); 
  FFV2_0(w[51], w[59], w[4], pars->GC_100, amp[64]); 
  FFV1_0(w[27], w[60], w[7], pars->GC_11, amp[65]); 
  FFV1_0(w[55], w[56], w[7], pars->GC_11, amp[66]); 
  FFV1_0(w[27], w[56], w[57], pars->GC_11, amp[67]); 
  FFV2_0(w[25], w[60], w[4], pars->GC_100, amp[68]); 
  FFV2_0(w[61], w[56], w[4], pars->GC_100, amp[69]); 
  FFV1_0(w[63], w[1], w[57], pars->GC_11, amp[70]); 
  FFV1_0(w[63], w[49], w[7], pars->GC_11, amp[71]); 
  FFV2_0(w[64], w[49], w[4], pars->GC_100, amp[72]); 
  FFV1_0(w[65], w[10], w[7], pars->GC_11, amp[73]); 
  FFV1_0(w[62], w[54], w[7], pars->GC_11, amp[74]); 
  FFV1_0(w[62], w[10], w[57], pars->GC_11, amp[75]); 
  FFV2_0(w[65], w[35], w[4], pars->GC_100, amp[76]); 
  FFV2_0(w[62], w[66], w[4], pars->GC_100, amp[77]); 
  FFV1_0(w[8], w[12], w[67], pars->GC_11, amp[78]); 
  VVV1_0(w[67], w[13], w[7], pars->GC_10, amp[79]); 
  FFV1_0(w[8], w[68], w[57], pars->GC_11, amp[80]); 
  VVV1_0(w[57], w[5], w[13], pars->GC_10, amp[81]); 
  FFV1_0(w[51], w[68], w[7], pars->GC_11, amp[82]); 
  FFV1_0(w[51], w[12], w[5], pars->GC_11, amp[83]); 
  FFV1_0(w[8], w[10], w[69], pars->GC_11, amp[84]); 
  FFV1_0(w[8], w[10], w[70], pars->GC_11, amp[85]); 
  FFV1_0(w[8], w[10], w[71], pars->GC_11, amp[86]); 
  FFV1_0(w[25], w[10], w[67], pars->GC_11, amp[87]); 
  FFV1_0(w[25], w[54], w[5], pars->GC_11, amp[88]); 
  FFV1_0(w[61], w[10], w[5], pars->GC_11, amp[89]); 
  FFV1_0(w[28], w[1], w[67], pars->GC_11, amp[90]); 
  VVV1_0(w[67], w[29], w[7], pars->GC_10, amp[91]); 
  FFV1_0(w[72], w[1], w[57], pars->GC_11, amp[92]); 
  VVV1_0(w[57], w[5], w[29], pars->GC_10, amp[93]); 
  FFV1_0(w[72], w[49], w[7], pars->GC_11, amp[94]); 
  FFV1_0(w[28], w[49], w[5], pars->GC_11, amp[95]); 
  FFV1_0(w[27], w[1], w[69], pars->GC_11, amp[96]); 
  FFV1_0(w[27], w[1], w[70], pars->GC_11, amp[97]); 
  FFV1_0(w[27], w[1], w[71], pars->GC_11, amp[98]); 
  FFV1_0(w[27], w[35], w[67], pars->GC_11, amp[99]); 
  FFV1_0(w[55], w[35], w[5], pars->GC_11, amp[100]); 
  FFV1_0(w[27], w[66], w[5], pars->GC_11, amp[101]); 
  FFV1_0(w[8], w[43], w[67], pars->GC_11, amp[102]); 
  FFV2_0(w[51], w[73], w[4], pars->GC_100, amp[103]); 
  FFV1_0(w[51], w[43], w[5], pars->GC_11, amp[104]); 
  FFV1_0(w[45], w[1], w[67], pars->GC_11, amp[105]); 
  FFV2_0(w[74], w[49], w[4], pars->GC_100, amp[106]); 
  FFV1_0(w[45], w[49], w[5], pars->GC_11, amp[107]); 
  FFV2_0(w[78], w[77], w[4], pars->GC_100, amp[108]); 
  FFV2_0(w[79], w[80], w[4], pars->GC_100, amp[109]); 
  FFV1_0(w[8], w[10], w[81], pars->GC_11, amp[110]); 
  FFV1_0(w[8], w[82], w[76], pars->GC_11, amp[111]); 
  FFV1_0(w[79], w[10], w[76], pars->GC_11, amp[112]); 
  FFV1_0(w[27], w[1], w[81], pars->GC_11, amp[113]); 
  FFV1_0(w[83], w[1], w[76], pars->GC_11, amp[114]); 
  FFV1_0(w[27], w[77], w[76], pars->GC_11, amp[115]); 
  FFV1_0(w[8], w[58], w[84], pars->GC_11, amp[116]); 
  FFV1_0(w[79], w[58], w[6], pars->GC_11, amp[117]); 
  FFV2_0(w[79], w[85], w[4], pars->GC_100, amp[118]); 
  FFV1_0(w[27], w[86], w[6], pars->GC_11, amp[119]); 
  FFV1_0(w[83], w[56], w[6], pars->GC_11, amp[120]); 
  FFV1_0(w[27], w[56], w[84], pars->GC_11, amp[121]); 
  FFV2_0(w[23], w[86], w[4], pars->GC_100, amp[122]); 
  FFV2_0(w[87], w[56], w[4], pars->GC_100, amp[123]); 
  FFV1_0(w[63], w[1], w[84], pars->GC_11, amp[124]); 
  FFV1_0(w[63], w[77], w[6], pars->GC_11, amp[125]); 
  FFV2_0(w[88], w[77], w[4], pars->GC_100, amp[126]); 
  FFV1_0(w[89], w[10], w[6], pars->GC_11, amp[127]); 
  FFV1_0(w[62], w[82], w[6], pars->GC_11, amp[128]); 
  FFV1_0(w[62], w[10], w[84], pars->GC_11, amp[129]); 
  FFV2_0(w[89], w[33], w[4], pars->GC_100, amp[130]); 
  FFV2_0(w[62], w[90], w[4], pars->GC_100, amp[131]); 
  FFV1_0(w[8], w[15], w[91], pars->GC_11, amp[132]); 
  VVV1_0(w[91], w[13], w[6], pars->GC_10, amp[133]); 
  FFV1_0(w[8], w[68], w[84], pars->GC_11, amp[134]); 
  VVV1_0(w[84], w[5], w[13], pars->GC_10, amp[135]); 
  FFV1_0(w[79], w[68], w[6], pars->GC_11, amp[136]); 
  FFV1_0(w[79], w[15], w[5], pars->GC_11, amp[137]); 
  FFV1_0(w[8], w[10], w[92], pars->GC_11, amp[138]); 
  FFV1_0(w[8], w[10], w[93], pars->GC_11, amp[139]); 
  FFV1_0(w[8], w[10], w[94], pars->GC_11, amp[140]); 
  FFV1_0(w[23], w[10], w[91], pars->GC_11, amp[141]); 
  FFV1_0(w[23], w[82], w[5], pars->GC_11, amp[142]); 
  FFV1_0(w[87], w[10], w[5], pars->GC_11, amp[143]); 
  FFV1_0(w[30], w[1], w[91], pars->GC_11, amp[144]); 
  VVV1_0(w[91], w[29], w[6], pars->GC_10, amp[145]); 
  FFV1_0(w[72], w[1], w[84], pars->GC_11, amp[146]); 
  VVV1_0(w[84], w[5], w[29], pars->GC_10, amp[147]); 
  FFV1_0(w[72], w[77], w[6], pars->GC_11, amp[148]); 
  FFV1_0(w[30], w[77], w[5], pars->GC_11, amp[149]); 
  FFV1_0(w[27], w[1], w[92], pars->GC_11, amp[150]); 
  FFV1_0(w[27], w[1], w[93], pars->GC_11, amp[151]); 
  FFV1_0(w[27], w[1], w[94], pars->GC_11, amp[152]); 
  FFV1_0(w[27], w[33], w[91], pars->GC_11, amp[153]); 
  FFV1_0(w[83], w[33], w[5], pars->GC_11, amp[154]); 
  FFV1_0(w[27], w[90], w[5], pars->GC_11, amp[155]); 
  FFV1_0(w[8], w[39], w[91], pars->GC_11, amp[156]); 
  FFV2_0(w[79], w[95], w[4], pars->GC_100, amp[157]); 
  FFV1_0(w[79], w[39], w[5], pars->GC_11, amp[158]); 
  FFV1_0(w[41], w[1], w[91], pars->GC_11, amp[159]); 
  FFV2_0(w[96], w[77], w[4], pars->GC_100, amp[160]); 
  FFV1_0(w[41], w[77], w[5], pars->GC_11, amp[161]); 
  FFV1_0(w[8], w[98], w[99], pars->GC_11, amp[162]); 
  FFV1_0(w[78], w[98], w[7], pars->GC_11, amp[163]); 
  FFV2_0(w[78], w[100], w[4], pars->GC_100, amp[164]); 
  FFV1_0(w[27], w[101], w[7], pars->GC_11, amp[165]); 
  VVV1_0(w[76], w[7], w[102], pars->GC_10, amp[166]); 
  FFV1_0(w[27], w[100], w[76], pars->GC_11, amp[167]); 
  FFV2_0(w[25], w[101], w[4], pars->GC_100, amp[168]); 
  FFV1_0(w[25], w[98], w[76], pars->GC_11, amp[169]); 
  FFV1_0(w[8], w[98], w[103], pars->GC_11, amp[170]); 
  FFV1_0(w[50], w[98], w[6], pars->GC_11, amp[171]); 
  FFV2_0(w[50], w[104], w[4], pars->GC_100, amp[172]); 
  FFV1_0(w[27], w[105], w[6], pars->GC_11, amp[173]); 
  VVV1_0(w[48], w[6], w[102], pars->GC_10, amp[174]); 
  FFV1_0(w[27], w[104], w[48], pars->GC_11, amp[175]); 
  FFV2_0(w[23], w[105], w[4], pars->GC_100, amp[176]); 
  FFV1_0(w[23], w[98], w[48], pars->GC_11, amp[177]); 
  FFV1_0(w[88], w[98], w[7], pars->GC_11, amp[178]); 
  FFV1_0(w[64], w[98], w[6], pars->GC_11, amp[179]); 
  FFV1_0(w[63], w[104], w[7], pars->GC_11, amp[180]); 
  FFV2_0(w[64], w[104], w[4], pars->GC_100, amp[181]); 
  FFV1_0(w[63], w[100], w[6], pars->GC_11, amp[182]); 
  FFV2_0(w[88], w[100], w[4], pars->GC_100, amp[183]); 
  FFV1_0(w[62], w[98], w[20], pars->GC_11, amp[184]); 
  FFV2_0(w[62], w[106], w[4], pars->GC_100, amp[185]); 
  FFV1_0(w[30], w[107], w[7], pars->GC_11, amp[186]); 
  FFV1_0(w[28], w[107], w[6], pars->GC_11, amp[187]); 
  FFV1_0(w[72], w[104], w[7], pars->GC_11, amp[188]); 
  FFV1_0(w[28], w[104], w[5], pars->GC_11, amp[189]); 
  FFV1_0(w[72], w[100], w[6], pars->GC_11, amp[190]); 
  FFV1_0(w[30], w[100], w[5], pars->GC_11, amp[191]); 
  FFV1_0(w[27], w[107], w[20], pars->GC_11, amp[192]); 
  VVV1_0(w[5], w[20], w[102], pars->GC_10, amp[193]); 
  FFV1_0(w[27], w[106], w[5], pars->GC_11, amp[194]); 
  FFV2_0(w[37], w[107], w[4], pars->GC_100, amp[195]); 
  FFV1_0(w[8], w[98], w[108], pars->GC_11, amp[196]); 
  FFV1_0(w[37], w[98], w[5], pars->GC_11, amp[197]); 
  FFV1_0(w[41], w[107], w[7], pars->GC_11, amp[198]); 
  FFV2_0(w[42], w[107], w[4], pars->GC_100, amp[199]); 
  FFV1_0(w[96], w[98], w[7], pars->GC_11, amp[200]); 
  FFV1_0(w[42], w[98], w[5], pars->GC_11, amp[201]); 
  FFV2_0(w[96], w[100], w[4], pars->GC_100, amp[202]); 
  FFV1_0(w[41], w[100], w[5], pars->GC_11, amp[203]); 
  FFV1_0(w[45], w[107], w[6], pars->GC_11, amp[204]); 
  FFV2_0(w[46], w[107], w[4], pars->GC_100, amp[205]); 
  FFV1_0(w[74], w[98], w[6], pars->GC_11, amp[206]); 
  FFV1_0(w[46], w[98], w[5], pars->GC_11, amp[207]); 
  FFV2_0(w[74], w[104], w[4], pars->GC_100, amp[208]); 
  FFV1_0(w[45], w[104], w[5], pars->GC_11, amp[209]); 
  FFV1_0(w[8], w[98], w[109], pars->GC_11, amp[210]); 
  FFV1_0(w[8], w[98], w[110], pars->GC_11, amp[211]); 
  FFV1_0(w[8], w[98], w[111], pars->GC_11, amp[212]); 
  FFV1_0(w[27], w[97], w[109], pars->GC_11, amp[213]); 
  FFV1_0(w[27], w[97], w[110], pars->GC_11, amp[214]); 
  FFV1_0(w[27], w[97], w[111], pars->GC_11, amp[215]); 
  FFV1_0(w[113], w[1], w[99], pars->GC_11, amp[216]); 
  FFV1_0(w[113], w[80], w[7], pars->GC_11, amp[217]); 
  FFV2_0(w[114], w[80], w[4], pars->GC_100, amp[218]); 
  FFV1_0(w[115], w[10], w[7], pars->GC_11, amp[219]); 
  VVV1_0(w[76], w[7], w[116], pars->GC_10, amp[220]); 
  FFV1_0(w[114], w[10], w[76], pars->GC_11, amp[221]); 
  FFV2_0(w[115], w[35], w[4], pars->GC_100, amp[222]); 
  FFV1_0(w[113], w[35], w[76], pars->GC_11, amp[223]); 
  FFV1_0(w[113], w[1], w[103], pars->GC_11, amp[224]); 
  FFV1_0(w[113], w[52], w[6], pars->GC_11, amp[225]); 
  FFV2_0(w[117], w[52], w[4], pars->GC_100, amp[226]); 
  FFV1_0(w[118], w[10], w[6], pars->GC_11, amp[227]); 
  VVV1_0(w[48], w[6], w[116], pars->GC_10, amp[228]); 
  FFV1_0(w[117], w[10], w[48], pars->GC_11, amp[229]); 
  FFV2_0(w[118], w[33], w[4], pars->GC_100, amp[230]); 
  FFV1_0(w[113], w[33], w[48], pars->GC_11, amp[231]); 
  FFV1_0(w[113], w[85], w[7], pars->GC_11, amp[232]); 
  FFV1_0(w[113], w[59], w[6], pars->GC_11, amp[233]); 
  FFV1_0(w[117], w[58], w[7], pars->GC_11, amp[234]); 
  FFV2_0(w[117], w[59], w[4], pars->GC_100, amp[235]); 
  FFV1_0(w[114], w[58], w[6], pars->GC_11, amp[236]); 
  FFV2_0(w[114], w[85], w[4], pars->GC_100, amp[237]); 
  FFV1_0(w[113], w[56], w[20], pars->GC_11, amp[238]); 
  FFV2_0(w[119], w[56], w[4], pars->GC_100, amp[239]); 
  FFV1_0(w[120], w[15], w[7], pars->GC_11, amp[240]); 
  FFV1_0(w[120], w[12], w[6], pars->GC_11, amp[241]); 
  FFV1_0(w[117], w[68], w[7], pars->GC_11, amp[242]); 
  FFV1_0(w[117], w[12], w[5], pars->GC_11, amp[243]); 
  FFV1_0(w[114], w[68], w[6], pars->GC_11, amp[244]); 
  FFV1_0(w[114], w[15], w[5], pars->GC_11, amp[245]); 
  FFV1_0(w[120], w[10], w[20], pars->GC_11, amp[246]); 
  VVV1_0(w[5], w[20], w[116], pars->GC_10, amp[247]); 
  FFV1_0(w[119], w[10], w[5], pars->GC_11, amp[248]); 
  FFV2_0(w[120], w[38], w[4], pars->GC_100, amp[249]); 
  FFV1_0(w[113], w[1], w[108], pars->GC_11, amp[250]); 
  FFV1_0(w[113], w[38], w[5], pars->GC_11, amp[251]); 
  FFV1_0(w[120], w[39], w[7], pars->GC_11, amp[252]); 
  FFV2_0(w[120], w[40], w[4], pars->GC_100, amp[253]); 
  FFV1_0(w[113], w[95], w[7], pars->GC_11, amp[254]); 
  FFV1_0(w[113], w[40], w[5], pars->GC_11, amp[255]); 
  FFV2_0(w[114], w[95], w[4], pars->GC_100, amp[256]); 
  FFV1_0(w[114], w[39], w[5], pars->GC_11, amp[257]); 
  FFV1_0(w[120], w[43], w[6], pars->GC_11, amp[258]); 
  FFV2_0(w[120], w[44], w[4], pars->GC_100, amp[259]); 
  FFV1_0(w[113], w[73], w[6], pars->GC_11, amp[260]); 
  FFV1_0(w[113], w[44], w[5], pars->GC_11, amp[261]); 
  FFV2_0(w[117], w[73], w[4], pars->GC_100, amp[262]); 
  FFV1_0(w[117], w[43], w[5], pars->GC_11, amp[263]); 
  FFV1_0(w[113], w[1], w[109], pars->GC_11, amp[264]); 
  FFV1_0(w[113], w[1], w[110], pars->GC_11, amp[265]); 
  FFV1_0(w[113], w[1], w[111], pars->GC_11, amp[266]); 
  FFV1_0(w[112], w[10], w[109], pars->GC_11, amp[267]); 
  FFV1_0(w[112], w[10], w[110], pars->GC_11, amp[268]); 
  FFV1_0(w[112], w[10], w[111], pars->GC_11, amp[269]); 
  FFV1_0(w[8], w[12], w[121], pars->GC_11, amp[270]); 
  VVV1_0(w[121], w[13], w[7], pars->GC_10, amp[271]); 
  FFV1_0(w[8], w[122], w[99], pars->GC_11, amp[272]); 
  FFV1_0(w[78], w[122], w[7], pars->GC_11, amp[273]); 
  VVV1_0(w[0], w[99], w[13], pars->GC_10, amp[274]); 
  FFV1_0(w[78], w[12], w[0], pars->GC_11, amp[275]); 
  FFV1_0(w[8], w[10], w[123], pars->GC_11, amp[276]); 
  FFV1_0(w[8], w[10], w[124], pars->GC_11, amp[277]); 
  FFV1_0(w[8], w[10], w[125], pars->GC_11, amp[278]); 
  FFV1_0(w[25], w[10], w[121], pars->GC_11, amp[279]); 
  FFV1_0(w[25], w[122], w[76], pars->GC_11, amp[280]); 
  FFV1_0(w[126], w[10], w[76], pars->GC_11, amp[281]); 
  FFV1_0(w[28], w[1], w[121], pars->GC_11, amp[282]); 
  VVV1_0(w[121], w[29], w[7], pars->GC_10, amp[283]); 
  FFV1_0(w[127], w[1], w[99], pars->GC_11, amp[284]); 
  FFV1_0(w[127], w[80], w[7], pars->GC_11, amp[285]); 
  VVV1_0(w[0], w[99], w[29], pars->GC_10, amp[286]); 
  FFV1_0(w[28], w[80], w[0], pars->GC_11, amp[287]); 
  FFV1_0(w[27], w[1], w[123], pars->GC_11, amp[288]); 
  FFV1_0(w[27], w[1], w[124], pars->GC_11, amp[289]); 
  FFV1_0(w[27], w[1], w[125], pars->GC_11, amp[290]); 
  FFV1_0(w[27], w[35], w[121], pars->GC_11, amp[291]); 
  FFV1_0(w[127], w[35], w[76], pars->GC_11, amp[292]); 
  FFV1_0(w[27], w[128], w[76], pars->GC_11, amp[293]); 
  FFV1_0(w[8], w[43], w[121], pars->GC_11, amp[294]); 
  FFV2_0(w[78], w[128], w[4], pars->GC_100, amp[295]); 
  FFV1_0(w[78], w[43], w[0], pars->GC_11, amp[296]); 
  FFV1_0(w[45], w[1], w[121], pars->GC_11, amp[297]); 
  FFV2_0(w[126], w[80], w[4], pars->GC_100, amp[298]); 
  FFV1_0(w[45], w[80], w[0], pars->GC_11, amp[299]); 
  FFV1_0(w[8], w[15], w[129], pars->GC_11, amp[300]); 
  VVV1_0(w[129], w[13], w[6], pars->GC_10, amp[301]); 
  FFV1_0(w[8], w[122], w[103], pars->GC_11, amp[302]); 
  FFV1_0(w[50], w[122], w[6], pars->GC_11, amp[303]); 
  VVV1_0(w[0], w[103], w[13], pars->GC_10, amp[304]); 
  FFV1_0(w[50], w[15], w[0], pars->GC_11, amp[305]); 
  FFV1_0(w[8], w[10], w[130], pars->GC_11, amp[306]); 
  FFV1_0(w[8], w[10], w[131], pars->GC_11, amp[307]); 
  FFV1_0(w[8], w[10], w[132], pars->GC_11, amp[308]); 
  FFV1_0(w[23], w[10], w[129], pars->GC_11, amp[309]); 
  FFV1_0(w[23], w[122], w[48], pars->GC_11, amp[310]); 
  FFV1_0(w[133], w[10], w[48], pars->GC_11, amp[311]); 
  FFV1_0(w[30], w[1], w[129], pars->GC_11, amp[312]); 
  VVV1_0(w[129], w[29], w[6], pars->GC_10, amp[313]); 
  FFV1_0(w[127], w[1], w[103], pars->GC_11, amp[314]); 
  FFV1_0(w[127], w[52], w[6], pars->GC_11, amp[315]); 
  VVV1_0(w[0], w[103], w[29], pars->GC_10, amp[316]); 
  FFV1_0(w[30], w[52], w[0], pars->GC_11, amp[317]); 
  FFV1_0(w[27], w[1], w[130], pars->GC_11, amp[318]); 
  FFV1_0(w[27], w[1], w[131], pars->GC_11, amp[319]); 
  FFV1_0(w[27], w[1], w[132], pars->GC_11, amp[320]); 
  FFV1_0(w[27], w[33], w[129], pars->GC_11, amp[321]); 
  FFV1_0(w[127], w[33], w[48], pars->GC_11, amp[322]); 
  FFV1_0(w[27], w[134], w[48], pars->GC_11, amp[323]); 
  FFV1_0(w[8], w[39], w[129], pars->GC_11, amp[324]); 
  FFV2_0(w[50], w[134], w[4], pars->GC_100, amp[325]); 
  FFV1_0(w[50], w[39], w[0], pars->GC_11, amp[326]); 
  FFV1_0(w[41], w[1], w[129], pars->GC_11, amp[327]); 
  FFV2_0(w[133], w[52], w[4], pars->GC_100, amp[328]); 
  FFV1_0(w[41], w[52], w[0], pars->GC_11, amp[329]); 
  FFV1_0(w[30], w[135], w[7], pars->GC_11, amp[330]); 
  FFV1_0(w[28], w[135], w[6], pars->GC_11, amp[331]); 
  FFV1_0(w[127], w[85], w[7], pars->GC_11, amp[332]); 
  FFV1_0(w[127], w[59], w[6], pars->GC_11, amp[333]); 
  FFV1_0(w[28], w[85], w[0], pars->GC_11, amp[334]); 
  FFV1_0(w[30], w[59], w[0], pars->GC_11, amp[335]); 
  FFV1_0(w[27], w[135], w[20], pars->GC_11, amp[336]); 
  FFV1_0(w[127], w[56], w[20], pars->GC_11, amp[337]); 
  FFV1_0(w[27], w[56], w[136], pars->GC_11, amp[338]); 
  FFV2_0(w[37], w[135], w[4], pars->GC_100, amp[339]); 
  FFV1_0(w[8], w[58], w[136], pars->GC_11, amp[340]); 
  FFV1_0(w[37], w[58], w[0], pars->GC_11, amp[341]); 
  FFV1_0(w[41], w[135], w[7], pars->GC_11, amp[342]); 
  FFV2_0(w[42], w[135], w[4], pars->GC_100, amp[343]); 
  FFV1_0(w[133], w[58], w[7], pars->GC_11, amp[344]); 
  FFV2_0(w[133], w[59], w[4], pars->GC_100, amp[345]); 
  FFV1_0(w[42], w[58], w[0], pars->GC_11, amp[346]); 
  FFV1_0(w[41], w[59], w[0], pars->GC_11, amp[347]); 
  FFV1_0(w[45], w[135], w[6], pars->GC_11, amp[348]); 
  FFV2_0(w[46], w[135], w[4], pars->GC_100, amp[349]); 
  FFV1_0(w[126], w[58], w[6], pars->GC_11, amp[350]); 
  FFV2_0(w[126], w[85], w[4], pars->GC_100, amp[351]); 
  FFV1_0(w[46], w[58], w[0], pars->GC_11, amp[352]); 
  FFV1_0(w[45], w[85], w[0], pars->GC_11, amp[353]); 
  FFV1_0(w[137], w[15], w[7], pars->GC_11, amp[354]); 
  FFV1_0(w[137], w[12], w[6], pars->GC_11, amp[355]); 
  FFV1_0(w[88], w[122], w[7], pars->GC_11, amp[356]); 
  FFV1_0(w[64], w[122], w[6], pars->GC_11, amp[357]); 
  FFV1_0(w[88], w[12], w[0], pars->GC_11, amp[358]); 
  FFV1_0(w[64], w[15], w[0], pars->GC_11, amp[359]); 
  FFV1_0(w[137], w[10], w[20], pars->GC_11, amp[360]); 
  FFV1_0(w[62], w[122], w[20], pars->GC_11, amp[361]); 
  FFV1_0(w[62], w[10], w[136], pars->GC_11, amp[362]); 
  FFV2_0(w[137], w[38], w[4], pars->GC_100, amp[363]); 
  FFV1_0(w[63], w[1], w[136], pars->GC_11, amp[364]); 
  FFV1_0(w[63], w[38], w[0], pars->GC_11, amp[365]); 
  FFV1_0(w[137], w[39], w[7], pars->GC_11, amp[366]); 
  FFV2_0(w[137], w[40], w[4], pars->GC_100, amp[367]); 
  FFV1_0(w[63], w[134], w[7], pars->GC_11, amp[368]); 
  FFV2_0(w[64], w[134], w[4], pars->GC_100, amp[369]); 
  FFV1_0(w[63], w[40], w[0], pars->GC_11, amp[370]); 
  FFV1_0(w[64], w[39], w[0], pars->GC_11, amp[371]); 
  FFV1_0(w[137], w[43], w[6], pars->GC_11, amp[372]); 
  FFV2_0(w[137], w[44], w[4], pars->GC_100, amp[373]); 
  FFV1_0(w[63], w[128], w[6], pars->GC_11, amp[374]); 
  FFV2_0(w[88], w[128], w[4], pars->GC_100, amp[375]); 
  FFV1_0(w[63], w[44], w[0], pars->GC_11, amp[376]); 
  FFV1_0(w[88], w[43], w[0], pars->GC_11, amp[377]); 
  FFV1_0(w[8], w[122], w[108], pars->GC_11, amp[378]); 
  FFV1_0(w[37], w[122], w[5], pars->GC_11, amp[379]); 
  FFV1_0(w[8], w[68], w[136], pars->GC_11, amp[380]); 
  VVV1_0(w[136], w[5], w[13], pars->GC_10, amp[381]); 
  FFV1_0(w[37], w[68], w[0], pars->GC_11, amp[382]); 
  VVV1_0(w[0], w[108], w[13], pars->GC_10, amp[383]); 
  FFV1_0(w[8], w[10], w[138], pars->GC_11, amp[384]); 
  FFV1_0(w[8], w[10], w[139], pars->GC_11, amp[385]); 
  FFV1_0(w[8], w[10], w[140], pars->GC_11, amp[386]); 
  FFV1_0(w[96], w[122], w[7], pars->GC_11, amp[387]); 
  FFV1_0(w[42], w[122], w[5], pars->GC_11, amp[388]); 
  FFV1_0(w[133], w[68], w[7], pars->GC_11, amp[389]); 
  FFV1_0(w[133], w[12], w[5], pars->GC_11, amp[390]); 
  FFV1_0(w[42], w[68], w[0], pars->GC_11, amp[391]); 
  FFV1_0(w[96], w[12], w[0], pars->GC_11, amp[392]); 
  FFV1_0(w[74], w[122], w[6], pars->GC_11, amp[393]); 
  FFV1_0(w[46], w[122], w[5], pars->GC_11, amp[394]); 
  FFV1_0(w[126], w[68], w[6], pars->GC_11, amp[395]); 
  FFV1_0(w[126], w[15], w[5], pars->GC_11, amp[396]); 
  FFV1_0(w[46], w[68], w[0], pars->GC_11, amp[397]); 
  FFV1_0(w[74], w[15], w[0], pars->GC_11, amp[398]); 
  FFV1_0(w[127], w[1], w[108], pars->GC_11, amp[399]); 
  FFV1_0(w[127], w[38], w[5], pars->GC_11, amp[400]); 
  FFV1_0(w[72], w[1], w[136], pars->GC_11, amp[401]); 
  VVV1_0(w[136], w[5], w[29], pars->GC_10, amp[402]); 
  FFV1_0(w[72], w[38], w[0], pars->GC_11, amp[403]); 
  VVV1_0(w[0], w[108], w[29], pars->GC_10, amp[404]); 
  FFV1_0(w[27], w[1], w[138], pars->GC_11, amp[405]); 
  FFV1_0(w[27], w[1], w[139], pars->GC_11, amp[406]); 
  FFV1_0(w[27], w[1], w[140], pars->GC_11, amp[407]); 
  FFV1_0(w[127], w[95], w[7], pars->GC_11, amp[408]); 
  FFV1_0(w[127], w[40], w[5], pars->GC_11, amp[409]); 
  FFV1_0(w[72], w[134], w[7], pars->GC_11, amp[410]); 
  FFV1_0(w[28], w[134], w[5], pars->GC_11, amp[411]); 
  FFV1_0(w[72], w[40], w[0], pars->GC_11, amp[412]); 
  FFV1_0(w[28], w[95], w[0], pars->GC_11, amp[413]); 
  FFV1_0(w[127], w[73], w[6], pars->GC_11, amp[414]); 
  FFV1_0(w[127], w[44], w[5], pars->GC_11, amp[415]); 
  FFV1_0(w[72], w[128], w[6], pars->GC_11, amp[416]); 
  FFV1_0(w[30], w[128], w[5], pars->GC_11, amp[417]); 
  FFV1_0(w[72], w[44], w[0], pars->GC_11, amp[418]); 
  FFV1_0(w[30], w[73], w[0], pars->GC_11, amp[419]); 
  FFV2_0(w[74], w[134], w[4], pars->GC_100, amp[420]); 
  FFV1_0(w[45], w[134], w[5], pars->GC_11, amp[421]); 
  FFV2_0(w[126], w[95], w[4], pars->GC_100, amp[422]); 
  FFV1_0(w[126], w[39], w[5], pars->GC_11, amp[423]); 
  FFV1_0(w[45], w[95], w[0], pars->GC_11, amp[424]); 
  FFV1_0(w[74], w[39], w[0], pars->GC_11, amp[425]); 
  FFV2_0(w[133], w[73], w[4], pars->GC_100, amp[426]); 
  FFV1_0(w[133], w[43], w[5], pars->GC_11, amp[427]); 
  FFV2_0(w[96], w[128], w[4], pars->GC_100, amp[428]); 
  FFV1_0(w[41], w[128], w[5], pars->GC_11, amp[429]); 
  FFV1_0(w[96], w[43], w[0], pars->GC_11, amp[430]); 
  FFV1_0(w[41], w[73], w[0], pars->GC_11, amp[431]); 
  FFV1_0(w[8], w[10], w[144], pars->GC_11, amp[432]); 
  FFV1_0(w[8], w[10], w[145], pars->GC_11, amp[433]); 
  FFV1_0(w[8], w[10], w[146], pars->GC_11, amp[434]); 
  FFV1_0(w[147], w[10], w[7], pars->GC_11, amp[435]); 
  FFV1_0(w[148], w[10], w[7], pars->GC_11, amp[436]); 
  FFV1_0(w[149], w[10], w[7], pars->GC_11, amp[437]); 
  FFV1_0(w[25], w[10], w[141], pars->GC_11, amp[438]); 
  FFV1_0(w[25], w[10], w[142], pars->GC_11, amp[439]); 
  FFV1_0(w[25], w[10], w[143], pars->GC_11, amp[440]); 
  FFV1_0(w[27], w[1], w[144], pars->GC_11, amp[441]); 
  FFV1_0(w[27], w[1], w[145], pars->GC_11, amp[442]); 
  FFV1_0(w[27], w[1], w[146], pars->GC_11, amp[443]); 
  FFV1_0(w[27], w[150], w[7], pars->GC_11, amp[444]); 
  FFV1_0(w[27], w[151], w[7], pars->GC_11, amp[445]); 
  FFV1_0(w[27], w[152], w[7], pars->GC_11, amp[446]); 
  FFV1_0(w[27], w[35], w[141], pars->GC_11, amp[447]); 
  FFV1_0(w[27], w[35], w[142], pars->GC_11, amp[448]); 
  FFV1_0(w[27], w[35], w[143], pars->GC_11, amp[449]); 
  FFV2_0(w[147], w[35], w[4], pars->GC_100, amp[450]); 
  FFV2_0(w[148], w[35], w[4], pars->GC_100, amp[451]); 
  FFV2_0(w[149], w[35], w[4], pars->GC_100, amp[452]); 
  FFV2_0(w[25], w[150], w[4], pars->GC_100, amp[453]); 
  FFV2_0(w[25], w[151], w[4], pars->GC_100, amp[454]); 
  FFV2_0(w[25], w[152], w[4], pars->GC_100, amp[455]); 
  FFV1_0(w[8], w[10], w[156], pars->GC_11, amp[456]); 
  FFV1_0(w[8], w[10], w[157], pars->GC_11, amp[457]); 
  FFV1_0(w[8], w[10], w[158], pars->GC_11, amp[458]); 
  FFV1_0(w[159], w[10], w[6], pars->GC_11, amp[459]); 
  FFV1_0(w[160], w[10], w[6], pars->GC_11, amp[460]); 
  FFV1_0(w[161], w[10], w[6], pars->GC_11, amp[461]); 
  FFV1_0(w[23], w[10], w[153], pars->GC_11, amp[462]); 
  FFV1_0(w[23], w[10], w[154], pars->GC_11, amp[463]); 
  FFV1_0(w[23], w[10], w[155], pars->GC_11, amp[464]); 
  FFV1_0(w[27], w[1], w[156], pars->GC_11, amp[465]); 
  FFV1_0(w[27], w[1], w[157], pars->GC_11, amp[466]); 
  FFV1_0(w[27], w[1], w[158], pars->GC_11, amp[467]); 
  FFV1_0(w[27], w[162], w[6], pars->GC_11, amp[468]); 
  FFV1_0(w[27], w[163], w[6], pars->GC_11, amp[469]); 
  FFV1_0(w[27], w[164], w[6], pars->GC_11, amp[470]); 
  FFV1_0(w[27], w[33], w[153], pars->GC_11, amp[471]); 
  FFV1_0(w[27], w[33], w[154], pars->GC_11, amp[472]); 
  FFV1_0(w[27], w[33], w[155], pars->GC_11, amp[473]); 
  FFV2_0(w[159], w[33], w[4], pars->GC_100, amp[474]); 
  FFV2_0(w[160], w[33], w[4], pars->GC_100, amp[475]); 
  FFV2_0(w[161], w[33], w[4], pars->GC_100, amp[476]); 
  FFV2_0(w[23], w[162], w[4], pars->GC_100, amp[477]); 
  FFV2_0(w[23], w[163], w[4], pars->GC_100, amp[478]); 
  FFV2_0(w[23], w[164], w[4], pars->GC_100, amp[479]); 
  FFV2_0(w[168], w[56], w[4], pars->GC_100, amp[480]); 
  FFV2_0(w[169], w[56], w[4], pars->GC_100, amp[481]); 
  FFV2_0(w[170], w[56], w[4], pars->GC_100, amp[482]); 
  FFV1_0(w[27], w[56], w[165], pars->GC_11, amp[483]); 
  FFV1_0(w[27], w[56], w[166], pars->GC_11, amp[484]); 
  FFV1_0(w[27], w[56], w[167], pars->GC_11, amp[485]); 
  FFV2_0(w[62], w[171], w[4], pars->GC_100, amp[486]); 
  FFV2_0(w[62], w[172], w[4], pars->GC_100, amp[487]); 
  FFV2_0(w[62], w[173], w[4], pars->GC_100, amp[488]); 
  FFV1_0(w[62], w[10], w[165], pars->GC_11, amp[489]); 
  FFV1_0(w[62], w[10], w[166], pars->GC_11, amp[490]); 
  FFV1_0(w[62], w[10], w[167], pars->GC_11, amp[491]); 
  FFV1_0(w[8], w[10], w[174], pars->GC_11, amp[492]); 
  FFV1_0(w[8], w[10], w[175], pars->GC_11, amp[493]); 
  FFV1_0(w[8], w[10], w[176], pars->GC_11, amp[494]); 
  FFV1_0(w[168], w[10], w[5], pars->GC_11, amp[495]); 
  FFV1_0(w[169], w[10], w[5], pars->GC_11, amp[496]); 
  FFV1_0(w[170], w[10], w[5], pars->GC_11, amp[497]); 
  FFV1_0(w[27], w[1], w[174], pars->GC_11, amp[498]); 
  FFV1_0(w[27], w[1], w[175], pars->GC_11, amp[499]); 
  FFV1_0(w[27], w[1], w[176], pars->GC_11, amp[500]); 
  FFV1_0(w[27], w[171], w[5], pars->GC_11, amp[501]); 
  FFV1_0(w[27], w[172], w[5], pars->GC_11, amp[502]); 
  FFV1_0(w[27], w[173], w[5], pars->GC_11, amp[503]); 
  FFV1_0(w[8], w[10], w[177], pars->GC_11, amp[504]); 
  FFV1_0(w[8], w[10], w[178], pars->GC_11, amp[505]); 
  FFV1_0(w[8], w[10], w[179], pars->GC_11, amp[506]); 
  FFV1_0(w[8], w[122], w[109], pars->GC_11, amp[507]); 
  FFV1_0(w[8], w[122], w[110], pars->GC_11, amp[508]); 
  FFV1_0(w[8], w[122], w[111], pars->GC_11, amp[509]); 
  FFV1_0(w[27], w[1], w[177], pars->GC_11, amp[510]); 
  FFV1_0(w[27], w[1], w[178], pars->GC_11, amp[511]); 
  FFV1_0(w[27], w[1], w[179], pars->GC_11, amp[512]); 
  FFV1_0(w[127], w[1], w[109], pars->GC_11, amp[513]); 
  FFV1_0(w[127], w[1], w[110], pars->GC_11, amp[514]); 
  FFV1_0(w[127], w[1], w[111], pars->GC_11, amp[515]); 

}
double P0_Sigma_sm_gdx_mupvmgggux_W_4j::matrix_gdx_wpgggux_wp_mupvm() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 516; 
  const int ncolor = 24; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {54, 54, 54, 54, 54, 54, 54, 54, 54, 54,
      54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54};
  static const double cf[ncolor][ncolor] = {{512, -64, -64, 8, 8, 80, -64, 8,
      8, -1, -1, -10, 8, -1, 80, -10, 71, 62, -1, -10, -10, 62, 62, -28}, {-64,
      512, 8, 80, -64, 8, 8, -64, -1, -10, 8, -1, -1, -10, -10, 62, 62, -28, 8,
      -1, 80, -10, 71, 62}, {-64, 8, 512, -64, 80, 8, 8, -1, 80, -10, 71, 62,
      -64, 8, 8, -1, -1, -10, -10, -1, 62, -28, -10, 62}, {8, 80, -64, 512, 8,
      -64, -1, -10, -10, 62, 62, -28, 8, -64, -1, -10, 8, -1, -1, 8, 71, 62,
      80, -10}, {8, -64, 80, 8, 512, -64, -1, 8, 71, 62, 80, -10, -10, -1, 62,
      -28, -10, 62, -64, 8, 8, -1, -1, -10}, {80, 8, 8, -64, -64, 512, -10, -1,
      62, -28, -10, 62, -1, 8, 71, 62, 80, -10, 8, -64, -1, -10, 8, -1}, {-64,
      8, 8, -1, -1, -10, 512, -64, -64, 8, 8, 80, 80, -10, 8, -1, 62, 71, -10,
      62, -1, -10, -28, 62}, {8, -64, -1, -10, 8, -1, -64, 512, 8, 80, -64, 8,
      -10, 62, -1, -10, -28, 62, 80, -10, 8, -1, 62, 71}, {8, -1, 80, -10, 71,
      62, -64, 8, 512, -64, 80, 8, 8, -1, -64, 8, -10, -1, 62, -28, -10, -1,
      62, -10}, {-1, -10, -10, 62, 62, -28, 8, 80, -64, 512, 8, -64, -1, -10,
      8, -64, -1, 8, 71, 62, -1, 8, -10, 80}, {-1, 8, 71, 62, 80, -10, 8, -64,
      80, 8, 512, -64, 62, -28, -10, -1, 62, -10, 8, -1, -64, 8, -10, -1},
      {-10, -1, 62, -28, -10, 62, 80, 8, 8, -64, -64, 512, 71, 62, -1, 8, -10,
      80, -1, -10, 8, -64, -1, 8}, {8, -1, -64, 8, -10, -1, 80, -10, 8, -1, 62,
      71, 512, -64, -64, 8, 8, 80, 62, -10, -28, 62, -1, -10}, {-1, -10, 8,
      -64, -1, 8, -10, 62, -1, -10, -28, 62, -64, 512, 8, 80, -64, 8, -10, 80,
      62, 71, 8, -1}, {80, -10, 8, -1, 62, 71, 8, -1, -64, 8, -10, -1, -64, 8,
      512, -64, 80, 8, -28, 62, 62, -10, -10, -1}, {-10, 62, -1, -10, -28, 62,
      -1, -10, 8, -64, -1, 8, 8, 80, -64, 512, 8, -64, 62, 71, -10, 80, -1, 8},
      {71, 62, -1, 8, -10, 80, 62, -28, -10, -1, 62, -10, 8, -64, 80, 8, 512,
      -64, -1, 8, -10, -1, -64, 8}, {62, -28, -10, -1, 62, -10, 71, 62, -1, 8,
      -10, 80, 80, 8, 8, -64, -64, 512, -10, -1, -1, 8, 8, -64}, {-1, 8, -10,
      -1, -64, 8, -10, 80, 62, 71, 8, -1, 62, -10, -28, 62, -1, -10, 512, -64,
      -64, 8, 8, 80}, {-10, -1, -1, 8, 8, -64, 62, -10, -28, 62, -1, -10, -10,
      80, 62, 71, 8, -1, -64, 512, 8, 80, -64, 8}, {-10, 80, 62, 71, 8, -1, -1,
      8, -10, -1, -64, 8, -28, 62, 62, -10, -10, -1, -64, 8, 512, -64, 80, 8},
      {62, -10, -28, 62, -1, -10, -10, -1, -1, 8, 8, -64, 62, 71, -10, 80, -1,
      8, 8, 80, -64, 512, 8, -64}, {62, 71, -10, 80, -1, 8, -28, 62, 62, -10,
      -10, -1, -1, 8, -10, -1, -64, 8, 8, -64, 80, 8, 512, -64}, {-28, 62, 62,
      -10, -10, -1, 62, 71, -10, 80, -1, 8, -10, -1, -1, 8, 8, -64, 80, 8, 8,
      -64, -64, 512}};

  // Calculate color flows
  jamp[0] = +std::complex<double> (0, 1) * amp[1] + std::complex<double> (0, 1)
      * amp[8] - std::complex<double> (0, 1) * amp[6] + amp[9] -
      std::complex<double> (0, 1) * amp[10] + std::complex<double> (0, 1) *
      amp[15] + amp[16] + amp[18] + std::complex<double> (0, 1) * amp[19] +
      std::complex<double> (0, 1) * amp[23] + std::complex<double> (0, 1) *
      amp[26] - std::complex<double> (0, 1) * amp[24] - std::complex<double>
      (0, 1) * amp[28] + amp[29] + amp[36] + amp[51] + std::complex<double> (0,
      1) * amp[52] + std::complex<double> (0, 1) * amp[53] + amp[162] +
      std::complex<double> (0, 1) * amp[165] + amp[166] + std::complex<double>
      (0, 1) * amp[168] + std::complex<double> (0, 1) * amp[169] - amp[187] +
      std::complex<double> (0, 1) * amp[192] + amp[193] + std::complex<double>
      (0, 1) * amp[195] + amp[196] + std::complex<double> (0, 1) * amp[197] -
      amp[204] - amp[205] - amp[207] - amp[212] + amp[210] - amp[215] +
      amp[213] + std::complex<double> (0, 1) * amp[271] + amp[272] -
      std::complex<double> (0, 1) * amp[274] + std::complex<double> (0, 1) *
      amp[278] - std::complex<double> (0, 1) * amp[276] + amp[279] +
      std::complex<double> (0, 1) * amp[280] + amp[282] + std::complex<double>
      (0, 1) * amp[283] - std::complex<double> (0, 1) * amp[286] +
      std::complex<double> (0, 1) * amp[290] - std::complex<double> (0, 1) *
      amp[288] + amp[297] + amp[378] + std::complex<double> (0, 1) * amp[379] -
      std::complex<double> (0, 1) * amp[383] + std::complex<double> (0, 1) *
      amp[386] - std::complex<double> (0, 1) * amp[384] - amp[394] -
      std::complex<double> (0, 1) * amp[404] + std::complex<double> (0, 1) *
      amp[407] - std::complex<double> (0, 1) * amp[405] + std::complex<double>
      (0, 1) * amp[434] - std::complex<double> (0, 1) * amp[432] - amp[440] +
      amp[438] + std::complex<double> (0, 1) * amp[443] - std::complex<double>
      (0, 1) * amp[441] - amp[446] + amp[444] + amp[453] - amp[455] +
      std::complex<double> (0, 1) * amp[506] - std::complex<double> (0, 1) *
      amp[504] - amp[509] + amp[507] + std::complex<double> (0, 1) * amp[512] -
      std::complex<double> (0, 1) * amp[510];
  jamp[1] = +std::complex<double> (0, 1) * amp[3] + std::complex<double> (0, 1)
      * amp[6] + std::complex<double> (0, 1) * amp[7] - amp[9] +
      std::complex<double> (0, 1) * amp[10] + std::complex<double> (0, 1) *
      amp[12] + amp[14] + amp[20] + std::complex<double> (0, 1) * amp[21] +
      std::complex<double> (0, 1) * amp[22] + std::complex<double> (0, 1) *
      amp[24] + std::complex<double> (0, 1) * amp[25] + std::complex<double>
      (0, 1) * amp[28] - amp[29] - amp[36] + amp[43] + std::complex<double> (0,
      1) * amp[44] + std::complex<double> (0, 1) * amp[45] + amp[170] +
      std::complex<double> (0, 1) * amp[173] + amp[174] + std::complex<double>
      (0, 1) * amp[176] + std::complex<double> (0, 1) * amp[177] - amp[186] -
      std::complex<double> (0, 1) * amp[192] - amp[193] - std::complex<double>
      (0, 1) * amp[195] - amp[196] - std::complex<double> (0, 1) * amp[197] -
      amp[198] - amp[199] - amp[201] - amp[210] - amp[211] - amp[213] -
      amp[214] + std::complex<double> (0, 1) * amp[301] + amp[302] -
      std::complex<double> (0, 1) * amp[304] + std::complex<double> (0, 1) *
      amp[308] - std::complex<double> (0, 1) * amp[306] + amp[309] +
      std::complex<double> (0, 1) * amp[310] + amp[312] + std::complex<double>
      (0, 1) * amp[313] - std::complex<double> (0, 1) * amp[316] +
      std::complex<double> (0, 1) * amp[320] - std::complex<double> (0, 1) *
      amp[318] + amp[327] - amp[378] - std::complex<double> (0, 1) * amp[379] +
      std::complex<double> (0, 1) * amp[383] - std::complex<double> (0, 1) *
      amp[386] + std::complex<double> (0, 1) * amp[384] - amp[388] +
      std::complex<double> (0, 1) * amp[404] - std::complex<double> (0, 1) *
      amp[407] + std::complex<double> (0, 1) * amp[405] + std::complex<double>
      (0, 1) * amp[458] - std::complex<double> (0, 1) * amp[456] - amp[464] +
      amp[462] + std::complex<double> (0, 1) * amp[467] - std::complex<double>
      (0, 1) * amp[465] - amp[470] + amp[468] + amp[477] - amp[479] +
      std::complex<double> (0, 1) * amp[504] + std::complex<double> (0, 1) *
      amp[505] - amp[507] - amp[508] + std::complex<double> (0, 1) * amp[510] +
      std::complex<double> (0, 1) * amp[511];
  jamp[2] = +amp[54] - std::complex<double> (0, 1) * amp[56] + amp[57] -
      std::complex<double> (0, 1) * amp[59] + amp[61] + std::complex<double>
      (0, 1) * amp[79] + std::complex<double> (0, 1) * amp[86] -
      std::complex<double> (0, 1) * amp[84] + amp[87] + std::complex<double>
      (0, 1) * amp[88] + amp[90] + std::complex<double> (0, 1) * amp[91] +
      std::complex<double> (0, 1) * amp[95] + std::complex<double> (0, 1) *
      amp[98] - std::complex<double> (0, 1) * amp[96] + amp[105] +
      std::complex<double> (0, 1) * amp[106] + std::complex<double> (0, 1) *
      amp[107] - amp[162] - std::complex<double> (0, 1) * amp[165] - amp[166] -
      std::complex<double> (0, 1) * amp[168] - std::complex<double> (0, 1) *
      amp[169] - amp[170] + std::complex<double> (0, 1) * amp[171] +
      std::complex<double> (0, 1) * amp[172] - amp[174] + std::complex<double>
      (0, 1) * amp[175] - amp[189] - amp[206] - amp[208] - amp[209] + amp[212]
      + amp[211] + amp[215] + amp[214] - std::complex<double> (0, 1) * amp[271]
      - amp[272] + std::complex<double> (0, 1) * amp[274] -
      std::complex<double> (0, 1) * amp[278] + std::complex<double> (0, 1) *
      amp[276] - amp[279] - std::complex<double> (0, 1) * amp[280] - amp[282] -
      std::complex<double> (0, 1) * amp[283] + std::complex<double> (0, 1) *
      amp[286] - std::complex<double> (0, 1) * amp[290] + std::complex<double>
      (0, 1) * amp[288] - amp[297] - amp[302] + std::complex<double> (0, 1) *
      amp[303] + std::complex<double> (0, 1) * amp[304] + std::complex<double>
      (0, 1) * amp[306] + std::complex<double> (0, 1) * amp[307] +
      std::complex<double> (0, 1) * amp[316] + std::complex<double> (0, 1) *
      amp[318] + std::complex<double> (0, 1) * amp[319] - amp[393] +
      std::complex<double> (0, 1) * amp[432] + std::complex<double> (0, 1) *
      amp[433] - amp[438] - amp[439] + std::complex<double> (0, 1) * amp[441] +
      std::complex<double> (0, 1) * amp[442] - amp[444] - amp[445] - amp[453] -
      amp[454] - std::complex<double> (0, 1) * amp[506] - std::complex<double>
      (0, 1) * amp[505] + amp[509] + amp[508] - std::complex<double> (0, 1) *
      amp[512] - std::complex<double> (0, 1) * amp[511];
  jamp[3] = -amp[54] + std::complex<double> (0, 1) * amp[56] - amp[57] +
      std::complex<double> (0, 1) * amp[59] - amp[61] + amp[70] +
      std::complex<double> (0, 1) * amp[71] + std::complex<double> (0, 1) *
      amp[72] + std::complex<double> (0, 1) * amp[74] + amp[75] -
      std::complex<double> (0, 1) * amp[81] + std::complex<double> (0, 1) *
      amp[84] + std::complex<double> (0, 1) * amp[85] + amp[92] -
      std::complex<double> (0, 1) * amp[93] + std::complex<double> (0, 1) *
      amp[94] + std::complex<double> (0, 1) * amp[96] + std::complex<double>
      (0, 1) * amp[97] + amp[170] - std::complex<double> (0, 1) * amp[171] -
      std::complex<double> (0, 1) * amp[172] + amp[174] - std::complex<double>
      (0, 1) * amp[175] - amp[179] - amp[180] - amp[181] + std::complex<double>
      (0, 1) * amp[184] + std::complex<double> (0, 1) * amp[185] - amp[188] -
      amp[193] + std::complex<double> (0, 1) * amp[194] - amp[196] - amp[210] -
      amp[211] - amp[213] - amp[214] + amp[302] - std::complex<double> (0, 1) *
      amp[303] - std::complex<double> (0, 1) * amp[304] - std::complex<double>
      (0, 1) * amp[306] - std::complex<double> (0, 1) * amp[307] -
      std::complex<double> (0, 1) * amp[316] - std::complex<double> (0, 1) *
      amp[318] - std::complex<double> (0, 1) * amp[319] - amp[357] +
      std::complex<double> (0, 1) * amp[361] + amp[362] + amp[364] - amp[378] -
      std::complex<double> (0, 1) * amp[381] + std::complex<double> (0, 1) *
      amp[383] + std::complex<double> (0, 1) * amp[384] + std::complex<double>
      (0, 1) * amp[385] + amp[401] - std::complex<double> (0, 1) * amp[402] +
      std::complex<double> (0, 1) * amp[404] + std::complex<double> (0, 1) *
      amp[405] + std::complex<double> (0, 1) * amp[406] + amp[486] - amp[488] -
      amp[491] + amp[489] + std::complex<double> (0, 1) * amp[494] -
      std::complex<double> (0, 1) * amp[492] + std::complex<double> (0, 1) *
      amp[500] - std::complex<double> (0, 1) * amp[498] - amp[503] + amp[501] +
      std::complex<double> (0, 1) * amp[504] + std::complex<double> (0, 1) *
      amp[505] - amp[507] - amp[508] + std::complex<double> (0, 1) * amp[510] +
      std::complex<double> (0, 1) * amp[511];
  jamp[4] = +amp[108] - std::complex<double> (0, 1) * amp[110] + amp[111] -
      std::complex<double> (0, 1) * amp[113] + amp[115] + std::complex<double>
      (0, 1) * amp[133] + std::complex<double> (0, 1) * amp[140] -
      std::complex<double> (0, 1) * amp[138] + amp[141] + std::complex<double>
      (0, 1) * amp[142] + amp[144] + std::complex<double> (0, 1) * amp[145] +
      std::complex<double> (0, 1) * amp[149] + std::complex<double> (0, 1) *
      amp[152] - std::complex<double> (0, 1) * amp[150] + amp[159] +
      std::complex<double> (0, 1) * amp[160] + std::complex<double> (0, 1) *
      amp[161] - amp[162] + std::complex<double> (0, 1) * amp[163] +
      std::complex<double> (0, 1) * amp[164] - amp[166] + std::complex<double>
      (0, 1) * amp[167] - amp[170] - std::complex<double> (0, 1) * amp[173] -
      amp[174] - std::complex<double> (0, 1) * amp[176] - std::complex<double>
      (0, 1) * amp[177] - amp[191] - amp[200] - amp[202] - amp[203] + amp[212]
      + amp[211] + amp[215] + amp[214] - amp[272] + std::complex<double> (0, 1)
      * amp[273] + std::complex<double> (0, 1) * amp[274] +
      std::complex<double> (0, 1) * amp[276] + std::complex<double> (0, 1) *
      amp[277] + std::complex<double> (0, 1) * amp[286] + std::complex<double>
      (0, 1) * amp[288] + std::complex<double> (0, 1) * amp[289] -
      std::complex<double> (0, 1) * amp[301] - amp[302] + std::complex<double>
      (0, 1) * amp[304] - std::complex<double> (0, 1) * amp[308] +
      std::complex<double> (0, 1) * amp[306] - amp[309] - std::complex<double>
      (0, 1) * amp[310] - amp[312] - std::complex<double> (0, 1) * amp[313] +
      std::complex<double> (0, 1) * amp[316] - std::complex<double> (0, 1) *
      amp[320] + std::complex<double> (0, 1) * amp[318] - amp[327] - amp[387] +
      std::complex<double> (0, 1) * amp[456] + std::complex<double> (0, 1) *
      amp[457] - amp[462] - amp[463] + std::complex<double> (0, 1) * amp[465] +
      std::complex<double> (0, 1) * amp[466] - amp[468] - amp[469] - amp[477] -
      amp[478] - std::complex<double> (0, 1) * amp[506] - std::complex<double>
      (0, 1) * amp[505] + amp[509] + amp[508] - std::complex<double> (0, 1) *
      amp[512] - std::complex<double> (0, 1) * amp[511];
  jamp[5] = -amp[108] + std::complex<double> (0, 1) * amp[110] - amp[111] +
      std::complex<double> (0, 1) * amp[113] - amp[115] + amp[124] +
      std::complex<double> (0, 1) * amp[125] + std::complex<double> (0, 1) *
      amp[126] + std::complex<double> (0, 1) * amp[128] + amp[129] -
      std::complex<double> (0, 1) * amp[135] + std::complex<double> (0, 1) *
      amp[138] + std::complex<double> (0, 1) * amp[139] + amp[146] -
      std::complex<double> (0, 1) * amp[147] + std::complex<double> (0, 1) *
      amp[148] + std::complex<double> (0, 1) * amp[150] + std::complex<double>
      (0, 1) * amp[151] + amp[162] - std::complex<double> (0, 1) * amp[163] -
      std::complex<double> (0, 1) * amp[164] + amp[166] - std::complex<double>
      (0, 1) * amp[167] - amp[178] - amp[182] - amp[183] - std::complex<double>
      (0, 1) * amp[184] - std::complex<double> (0, 1) * amp[185] - amp[190] +
      amp[193] - std::complex<double> (0, 1) * amp[194] + amp[196] - amp[212] +
      amp[210] - amp[215] + amp[213] + amp[272] - std::complex<double> (0, 1) *
      amp[273] - std::complex<double> (0, 1) * amp[274] - std::complex<double>
      (0, 1) * amp[276] - std::complex<double> (0, 1) * amp[277] -
      std::complex<double> (0, 1) * amp[286] - std::complex<double> (0, 1) *
      amp[288] - std::complex<double> (0, 1) * amp[289] - amp[356] -
      std::complex<double> (0, 1) * amp[361] - amp[362] - amp[364] + amp[378] +
      std::complex<double> (0, 1) * amp[381] - std::complex<double> (0, 1) *
      amp[383] - std::complex<double> (0, 1) * amp[384] - std::complex<double>
      (0, 1) * amp[385] - amp[401] + std::complex<double> (0, 1) * amp[402] -
      std::complex<double> (0, 1) * amp[404] - std::complex<double> (0, 1) *
      amp[405] - std::complex<double> (0, 1) * amp[406] - amp[486] - amp[487] -
      amp[489] - amp[490] + std::complex<double> (0, 1) * amp[492] +
      std::complex<double> (0, 1) * amp[493] + std::complex<double> (0, 1) *
      amp[498] + std::complex<double> (0, 1) * amp[499] - amp[501] - amp[502] +
      std::complex<double> (0, 1) * amp[506] - std::complex<double> (0, 1) *
      amp[504] - amp[509] + amp[507] + std::complex<double> (0, 1) * amp[512] -
      std::complex<double> (0, 1) * amp[510];
  jamp[6] = -std::complex<double> (0, 1) * amp[1] - std::complex<double> (0, 1)
      * amp[8] + std::complex<double> (0, 1) * amp[6] - amp[9] +
      std::complex<double> (0, 1) * amp[10] - std::complex<double> (0, 1) *
      amp[15] - amp[16] - amp[18] - std::complex<double> (0, 1) * amp[19] -
      std::complex<double> (0, 1) * amp[23] - std::complex<double> (0, 1) *
      amp[26] + std::complex<double> (0, 1) * amp[24] + std::complex<double>
      (0, 1) * amp[28] - amp[29] - amp[36] - amp[51] - std::complex<double> (0,
      1) * amp[52] - std::complex<double> (0, 1) * amp[53] + amp[62] +
      std::complex<double> (0, 1) * amp[65] + amp[67] + std::complex<double>
      (0, 1) * amp[68] + std::complex<double> (0, 1) * amp[69] -
      std::complex<double> (0, 1) * amp[79] + amp[80] + std::complex<double>
      (0, 1) * amp[81] - std::complex<double> (0, 1) * amp[86] -
      std::complex<double> (0, 1) * amp[85] - amp[87] + std::complex<double>
      (0, 1) * amp[89] - amp[90] - std::complex<double> (0, 1) * amp[91] +
      std::complex<double> (0, 1) * amp[93] - std::complex<double> (0, 1) *
      amp[98] - std::complex<double> (0, 1) * amp[97] - amp[105] - amp[331] +
      std::complex<double> (0, 1) * amp[336] + amp[338] + std::complex<double>
      (0, 1) * amp[339] + amp[340] + std::complex<double> (0, 1) * amp[341] -
      amp[348] - amp[349] - amp[352] + amp[380] + std::complex<double> (0, 1) *
      amp[381] + std::complex<double> (0, 1) * amp[382] - std::complex<double>
      (0, 1) * amp[386] - std::complex<double> (0, 1) * amp[385] - amp[397] +
      std::complex<double> (0, 1) * amp[402] - std::complex<double> (0, 1) *
      amp[407] - std::complex<double> (0, 1) * amp[406] - std::complex<double>
      (0, 1) * amp[434] - std::complex<double> (0, 1) * amp[433] + amp[440] +
      amp[439] - std::complex<double> (0, 1) * amp[443] - std::complex<double>
      (0, 1) * amp[442] + amp[446] + amp[445] + amp[454] + amp[455] - amp[482]
      + amp[480] - amp[485] + amp[483] - std::complex<double> (0, 1) * amp[494]
      + std::complex<double> (0, 1) * amp[492] - amp[497] + amp[495] -
      std::complex<double> (0, 1) * amp[500] + std::complex<double> (0, 1) *
      amp[498];
  jamp[7] = -std::complex<double> (0, 1) * amp[3] - std::complex<double> (0, 1)
      * amp[6] - std::complex<double> (0, 1) * amp[7] + amp[9] -
      std::complex<double> (0, 1) * amp[10] - std::complex<double> (0, 1) *
      amp[12] - amp[14] - amp[20] - std::complex<double> (0, 1) * amp[21] -
      std::complex<double> (0, 1) * amp[22] - std::complex<double> (0, 1) *
      amp[24] - std::complex<double> (0, 1) * amp[25] - std::complex<double>
      (0, 1) * amp[28] + amp[29] + amp[36] - amp[43] - std::complex<double> (0,
      1) * amp[44] - std::complex<double> (0, 1) * amp[45] + amp[116] +
      std::complex<double> (0, 1) * amp[119] + amp[121] + std::complex<double>
      (0, 1) * amp[122] + std::complex<double> (0, 1) * amp[123] -
      std::complex<double> (0, 1) * amp[133] + amp[134] + std::complex<double>
      (0, 1) * amp[135] - std::complex<double> (0, 1) * amp[140] -
      std::complex<double> (0, 1) * amp[139] - amp[141] + std::complex<double>
      (0, 1) * amp[143] - amp[144] - std::complex<double> (0, 1) * amp[145] +
      std::complex<double> (0, 1) * amp[147] - std::complex<double> (0, 1) *
      amp[152] - std::complex<double> (0, 1) * amp[151] - amp[159] - amp[330] -
      std::complex<double> (0, 1) * amp[336] - amp[338] - std::complex<double>
      (0, 1) * amp[339] - amp[340] - std::complex<double> (0, 1) * amp[341] -
      amp[342] - amp[343] - amp[346] - amp[380] - std::complex<double> (0, 1) *
      amp[381] - std::complex<double> (0, 1) * amp[382] + std::complex<double>
      (0, 1) * amp[386] + std::complex<double> (0, 1) * amp[385] - amp[391] -
      std::complex<double> (0, 1) * amp[402] + std::complex<double> (0, 1) *
      amp[407] + std::complex<double> (0, 1) * amp[406] - std::complex<double>
      (0, 1) * amp[458] - std::complex<double> (0, 1) * amp[457] + amp[464] +
      amp[463] - std::complex<double> (0, 1) * amp[467] - std::complex<double>
      (0, 1) * amp[466] + amp[470] + amp[469] + amp[478] + amp[479] - amp[480]
      - amp[481] - amp[483] - amp[484] - std::complex<double> (0, 1) * amp[492]
      - std::complex<double> (0, 1) * amp[493] - amp[495] - amp[496] -
      std::complex<double> (0, 1) * amp[498] - std::complex<double> (0, 1) *
      amp[499];
  jamp[8] = -amp[62] - std::complex<double> (0, 1) * amp[65] - amp[67] -
      std::complex<double> (0, 1) * amp[68] - std::complex<double> (0, 1) *
      amp[69] + std::complex<double> (0, 1) * amp[79] - amp[80] -
      std::complex<double> (0, 1) * amp[81] + std::complex<double> (0, 1) *
      amp[86] + std::complex<double> (0, 1) * amp[85] + amp[87] -
      std::complex<double> (0, 1) * amp[89] + amp[90] + std::complex<double>
      (0, 1) * amp[91] - std::complex<double> (0, 1) * amp[93] +
      std::complex<double> (0, 1) * amp[98] + std::complex<double> (0, 1) *
      amp[97] + amp[105] + amp[109] + std::complex<double> (0, 1) * amp[110] +
      amp[112] + std::complex<double> (0, 1) * amp[113] + amp[114] - amp[116] +
      std::complex<double> (0, 1) * amp[117] + std::complex<double> (0, 1) *
      amp[118] + std::complex<double> (0, 1) * amp[120] - amp[121] - amp[134] -
      std::complex<double> (0, 1) * amp[135] + std::complex<double> (0, 1) *
      amp[136] + std::complex<double> (0, 1) * amp[138] + std::complex<double>
      (0, 1) * amp[139] - std::complex<double> (0, 1) * amp[147] +
      std::complex<double> (0, 1) * amp[150] + std::complex<double> (0, 1) *
      amp[151] - std::complex<double> (0, 1) * amp[271] - std::complex<double>
      (0, 1) * amp[278] - std::complex<double> (0, 1) * amp[277] - amp[279] +
      std::complex<double> (0, 1) * amp[281] - amp[282] - std::complex<double>
      (0, 1) * amp[283] + std::complex<double> (0, 1) * amp[287] -
      std::complex<double> (0, 1) * amp[290] - std::complex<double> (0, 1) *
      amp[289] - amp[297] + std::complex<double> (0, 1) * amp[298] +
      std::complex<double> (0, 1) * amp[299] - amp[334] - amp[350] - amp[351] -
      amp[353] - amp[395] + std::complex<double> (0, 1) * amp[432] +
      std::complex<double> (0, 1) * amp[433] - amp[438] - amp[439] +
      std::complex<double> (0, 1) * amp[441] + std::complex<double> (0, 1) *
      amp[442] - amp[444] - amp[445] - amp[453] - amp[454] + amp[482] +
      amp[481] + amp[485] + amp[484] + std::complex<double> (0, 1) * amp[494] +
      std::complex<double> (0, 1) * amp[493] + amp[497] + amp[496] +
      std::complex<double> (0, 1) * amp[500] + std::complex<double> (0, 1) *
      amp[499];
  jamp[9] = -amp[109] - std::complex<double> (0, 1) * amp[110] - amp[112] -
      std::complex<double> (0, 1) * amp[113] - amp[114] + amp[116] -
      std::complex<double> (0, 1) * amp[117] - std::complex<double> (0, 1) *
      amp[118] - std::complex<double> (0, 1) * amp[120] + amp[121] + amp[134] +
      std::complex<double> (0, 1) * amp[135] - std::complex<double> (0, 1) *
      amp[136] - std::complex<double> (0, 1) * amp[138] - std::complex<double>
      (0, 1) * amp[139] + std::complex<double> (0, 1) * amp[147] -
      std::complex<double> (0, 1) * amp[150] - std::complex<double> (0, 1) *
      amp[151] + amp[216] + std::complex<double> (0, 1) * amp[217] +
      std::complex<double> (0, 1) * amp[218] + amp[220] + std::complex<double>
      (0, 1) * amp[221] - amp[232] - amp[236] - amp[237] + std::complex<double>
      (0, 1) * amp[238] + std::complex<double> (0, 1) * amp[239] - amp[244] +
      amp[247] + std::complex<double> (0, 1) * amp[248] + amp[250] - amp[266] +
      amp[264] - amp[269] + amp[267] + std::complex<double> (0, 1) * amp[274] +
      std::complex<double> (0, 1) * amp[276] + std::complex<double> (0, 1) *
      amp[277] + amp[284] + std::complex<double> (0, 1) * amp[285] +
      std::complex<double> (0, 1) * amp[286] + std::complex<double> (0, 1) *
      amp[288] + std::complex<double> (0, 1) * amp[289] - amp[332] +
      std::complex<double> (0, 1) * amp[337] - amp[338] - amp[340] - amp[380] -
      std::complex<double> (0, 1) * amp[381] + std::complex<double> (0, 1) *
      amp[383] + std::complex<double> (0, 1) * amp[384] + std::complex<double>
      (0, 1) * amp[385] + amp[399] - std::complex<double> (0, 1) * amp[402] +
      std::complex<double> (0, 1) * amp[404] + std::complex<double> (0, 1) *
      amp[405] + std::complex<double> (0, 1) * amp[406] - amp[480] - amp[481] -
      amp[483] - amp[484] - std::complex<double> (0, 1) * amp[492] -
      std::complex<double> (0, 1) * amp[493] - amp[495] - amp[496] -
      std::complex<double> (0, 1) * amp[498] - std::complex<double> (0, 1) *
      amp[499] - std::complex<double> (0, 1) * amp[506] + std::complex<double>
      (0, 1) * amp[504] - std::complex<double> (0, 1) * amp[512] +
      std::complex<double> (0, 1) * amp[510] - amp[515] + amp[513];
  jamp[10] = +amp[55] + std::complex<double> (0, 1) * amp[56] + amp[58] +
      std::complex<double> (0, 1) * amp[59] + amp[60] - amp[62] +
      std::complex<double> (0, 1) * amp[63] + std::complex<double> (0, 1) *
      amp[64] + std::complex<double> (0, 1) * amp[66] - amp[67] - amp[80] -
      std::complex<double> (0, 1) * amp[81] + std::complex<double> (0, 1) *
      amp[82] + std::complex<double> (0, 1) * amp[84] + std::complex<double>
      (0, 1) * amp[85] - std::complex<double> (0, 1) * amp[93] +
      std::complex<double> (0, 1) * amp[96] + std::complex<double> (0, 1) *
      amp[97] - amp[116] - std::complex<double> (0, 1) * amp[119] - amp[121] -
      std::complex<double> (0, 1) * amp[122] - std::complex<double> (0, 1) *
      amp[123] + std::complex<double> (0, 1) * amp[133] - amp[134] -
      std::complex<double> (0, 1) * amp[135] + std::complex<double> (0, 1) *
      amp[140] + std::complex<double> (0, 1) * amp[139] + amp[141] -
      std::complex<double> (0, 1) * amp[143] + amp[144] + std::complex<double>
      (0, 1) * amp[145] - std::complex<double> (0, 1) * amp[147] +
      std::complex<double> (0, 1) * amp[152] + std::complex<double> (0, 1) *
      amp[151] + amp[159] - std::complex<double> (0, 1) * amp[301] -
      std::complex<double> (0, 1) * amp[308] - std::complex<double> (0, 1) *
      amp[307] - amp[309] + std::complex<double> (0, 1) * amp[311] - amp[312] -
      std::complex<double> (0, 1) * amp[313] + std::complex<double> (0, 1) *
      amp[317] - std::complex<double> (0, 1) * amp[320] - std::complex<double>
      (0, 1) * amp[319] - amp[327] + std::complex<double> (0, 1) * amp[328] +
      std::complex<double> (0, 1) * amp[329] - amp[335] - amp[344] - amp[345] -
      amp[347] - amp[389] + std::complex<double> (0, 1) * amp[456] +
      std::complex<double> (0, 1) * amp[457] - amp[462] - amp[463] +
      std::complex<double> (0, 1) * amp[465] + std::complex<double> (0, 1) *
      amp[466] - amp[468] - amp[469] - amp[477] - amp[478] + amp[482] +
      amp[481] + amp[485] + amp[484] + std::complex<double> (0, 1) * amp[494] +
      std::complex<double> (0, 1) * amp[493] + amp[497] + amp[496] +
      std::complex<double> (0, 1) * amp[500] + std::complex<double> (0, 1) *
      amp[499];
  jamp[11] = -amp[55] - std::complex<double> (0, 1) * amp[56] - amp[58] -
      std::complex<double> (0, 1) * amp[59] - amp[60] + amp[62] -
      std::complex<double> (0, 1) * amp[63] - std::complex<double> (0, 1) *
      amp[64] - std::complex<double> (0, 1) * amp[66] + amp[67] + amp[80] +
      std::complex<double> (0, 1) * amp[81] - std::complex<double> (0, 1) *
      amp[82] - std::complex<double> (0, 1) * amp[84] - std::complex<double>
      (0, 1) * amp[85] + std::complex<double> (0, 1) * amp[93] -
      std::complex<double> (0, 1) * amp[96] - std::complex<double> (0, 1) *
      amp[97] + amp[224] + std::complex<double> (0, 1) * amp[225] +
      std::complex<double> (0, 1) * amp[226] + amp[228] + std::complex<double>
      (0, 1) * amp[229] - amp[233] - amp[234] - amp[235] - std::complex<double>
      (0, 1) * amp[238] - std::complex<double> (0, 1) * amp[239] - amp[242] -
      amp[247] - std::complex<double> (0, 1) * amp[248] - amp[250] - amp[264] -
      amp[265] - amp[267] - amp[268] + std::complex<double> (0, 1) * amp[304] +
      std::complex<double> (0, 1) * amp[306] + std::complex<double> (0, 1) *
      amp[307] + amp[314] + std::complex<double> (0, 1) * amp[315] +
      std::complex<double> (0, 1) * amp[316] + std::complex<double> (0, 1) *
      amp[318] + std::complex<double> (0, 1) * amp[319] - amp[333] -
      std::complex<double> (0, 1) * amp[337] + amp[338] + amp[340] + amp[380] +
      std::complex<double> (0, 1) * amp[381] - std::complex<double> (0, 1) *
      amp[383] - std::complex<double> (0, 1) * amp[384] - std::complex<double>
      (0, 1) * amp[385] - amp[399] + std::complex<double> (0, 1) * amp[402] -
      std::complex<double> (0, 1) * amp[404] - std::complex<double> (0, 1) *
      amp[405] - std::complex<double> (0, 1) * amp[406] - amp[482] + amp[480] -
      amp[485] + amp[483] - std::complex<double> (0, 1) * amp[494] +
      std::complex<double> (0, 1) * amp[492] - amp[497] + amp[495] -
      std::complex<double> (0, 1) * amp[500] + std::complex<double> (0, 1) *
      amp[498] - std::complex<double> (0, 1) * amp[504] - std::complex<double>
      (0, 1) * amp[505] - std::complex<double> (0, 1) * amp[510] -
      std::complex<double> (0, 1) * amp[511] - amp[513] - amp[514];
  jamp[12] = -std::complex<double> (0, 1) * amp[1] + amp[2] -
      std::complex<double> (0, 1) * amp[3] - std::complex<double> (0, 1) *
      amp[8] - std::complex<double> (0, 1) * amp[7] - amp[16] +
      std::complex<double> (0, 1) * amp[17] - amp[18] - std::complex<double>
      (0, 1) * amp[19] - std::complex<double> (0, 1) * amp[21] -
      std::complex<double> (0, 1) * amp[26] - std::complex<double> (0, 1) *
      amp[25] + std::complex<double> (0, 1) * amp[31] + amp[32] + amp[38] +
      std::complex<double> (0, 1) * amp[41] + std::complex<double> (0, 1) *
      amp[42] - amp[51] - amp[54] + std::complex<double> (0, 1) * amp[56] -
      amp[57] + std::complex<double> (0, 1) * amp[59] - amp[61] -
      std::complex<double> (0, 1) * amp[79] - std::complex<double> (0, 1) *
      amp[86] + std::complex<double> (0, 1) * amp[84] - amp[87] -
      std::complex<double> (0, 1) * amp[88] - amp[90] - std::complex<double>
      (0, 1) * amp[91] - std::complex<double> (0, 1) * amp[95] -
      std::complex<double> (0, 1) * amp[98] + std::complex<double> (0, 1) *
      amp[96] - amp[105] - std::complex<double> (0, 1) * amp[106] -
      std::complex<double> (0, 1) * amp[107] + amp[300] - std::complex<double>
      (0, 1) * amp[301] + std::complex<double> (0, 1) * amp[305] -
      std::complex<double> (0, 1) * amp[308] - std::complex<double> (0, 1) *
      amp[307] - std::complex<double> (0, 1) * amp[313] - std::complex<double>
      (0, 1) * amp[320] - std::complex<double> (0, 1) * amp[319] + amp[321] +
      std::complex<double> (0, 1) * amp[323] + amp[324] + std::complex<double>
      (0, 1) * amp[325] + std::complex<double> (0, 1) * amp[326] - amp[398] -
      amp[411] - amp[420] - amp[421] - amp[425] - std::complex<double> (0, 1) *
      amp[434] - std::complex<double> (0, 1) * amp[433] + amp[440] + amp[439] -
      std::complex<double> (0, 1) * amp[443] - std::complex<double> (0, 1) *
      amp[442] + amp[446] + amp[445] + amp[454] + amp[455] -
      std::complex<double> (0, 1) * amp[458] + std::complex<double> (0, 1) *
      amp[456] - amp[461] + amp[459] - std::complex<double> (0, 1) * amp[467] +
      std::complex<double> (0, 1) * amp[465] - amp[473] + amp[471] - amp[476] +
      amp[474];
  jamp[13] = +amp[54] - std::complex<double> (0, 1) * amp[56] + amp[57] -
      std::complex<double> (0, 1) * amp[59] + amp[61] - amp[70] -
      std::complex<double> (0, 1) * amp[71] - std::complex<double> (0, 1) *
      amp[72] - std::complex<double> (0, 1) * amp[74] - amp[75] +
      std::complex<double> (0, 1) * amp[81] - std::complex<double> (0, 1) *
      amp[84] - std::complex<double> (0, 1) * amp[85] - amp[92] +
      std::complex<double> (0, 1) * amp[93] - std::complex<double> (0, 1) *
      amp[94] - std::complex<double> (0, 1) * amp[96] - std::complex<double>
      (0, 1) * amp[97] - amp[124] + std::complex<double> (0, 1) * amp[127] -
      amp[129] + std::complex<double> (0, 1) * amp[130] + std::complex<double>
      (0, 1) * amp[131] + amp[132] - std::complex<double> (0, 1) * amp[133] +
      std::complex<double> (0, 1) * amp[135] - std::complex<double> (0, 1) *
      amp[140] - std::complex<double> (0, 1) * amp[139] - std::complex<double>
      (0, 1) * amp[145] - amp[146] + std::complex<double> (0, 1) * amp[147] -
      std::complex<double> (0, 1) * amp[152] - std::complex<double> (0, 1) *
      amp[151] + amp[153] + std::complex<double> (0, 1) * amp[155] + amp[156] -
      amp[300] + std::complex<double> (0, 1) * amp[301] - std::complex<double>
      (0, 1) * amp[305] + std::complex<double> (0, 1) * amp[308] +
      std::complex<double> (0, 1) * amp[307] + std::complex<double> (0, 1) *
      amp[313] + std::complex<double> (0, 1) * amp[320] + std::complex<double>
      (0, 1) * amp[319] - amp[321] - std::complex<double> (0, 1) * amp[323] -
      amp[324] - std::complex<double> (0, 1) * amp[325] - std::complex<double>
      (0, 1) * amp[326] - amp[359] - amp[368] - amp[369] - amp[371] - amp[410]
      - std::complex<double> (0, 1) * amp[456] - std::complex<double> (0, 1) *
      amp[457] - amp[459] - amp[460] - std::complex<double> (0, 1) * amp[465] -
      std::complex<double> (0, 1) * amp[466] - amp[471] - amp[472] - amp[474] -
      amp[475] + amp[487] + amp[488] + amp[491] + amp[490] -
      std::complex<double> (0, 1) * amp[494] - std::complex<double> (0, 1) *
      amp[493] - std::complex<double> (0, 1) * amp[500] - std::complex<double>
      (0, 1) * amp[499] + amp[503] + amp[502];
  jamp[14] = +std::complex<double> (0, 1) * amp[1] - amp[2] +
      std::complex<double> (0, 1) * amp[3] + std::complex<double> (0, 1) *
      amp[8] + std::complex<double> (0, 1) * amp[7] + amp[16] -
      std::complex<double> (0, 1) * amp[17] + amp[18] + std::complex<double>
      (0, 1) * amp[19] + std::complex<double> (0, 1) * amp[21] +
      std::complex<double> (0, 1) * amp[26] + std::complex<double> (0, 1) *
      amp[25] - std::complex<double> (0, 1) * amp[31] - amp[32] - amp[38] -
      std::complex<double> (0, 1) * amp[41] - std::complex<double> (0, 1) *
      amp[42] + amp[51] - amp[109] - std::complex<double> (0, 1) * amp[110] -
      amp[112] - std::complex<double> (0, 1) * amp[113] - amp[114] - amp[132] +
      std::complex<double> (0, 1) * amp[133] + std::complex<double> (0, 1) *
      amp[137] + std::complex<double> (0, 1) * amp[140] - std::complex<double>
      (0, 1) * amp[138] + std::complex<double> (0, 1) * amp[145] +
      std::complex<double> (0, 1) * amp[152] - std::complex<double> (0, 1) *
      amp[150] - amp[153] + std::complex<double> (0, 1) * amp[154] - amp[156] +
      std::complex<double> (0, 1) * amp[157] + std::complex<double> (0, 1) *
      amp[158] + std::complex<double> (0, 1) * amp[271] + std::complex<double>
      (0, 1) * amp[278] + std::complex<double> (0, 1) * amp[277] + amp[279] -
      std::complex<double> (0, 1) * amp[281] + amp[282] + std::complex<double>
      (0, 1) * amp[283] - std::complex<double> (0, 1) * amp[287] +
      std::complex<double> (0, 1) * amp[290] + std::complex<double> (0, 1) *
      amp[289] + amp[297] - std::complex<double> (0, 1) * amp[298] -
      std::complex<double> (0, 1) * amp[299] - amp[396] - amp[413] - amp[422] -
      amp[423] - amp[424] + std::complex<double> (0, 1) * amp[434] -
      std::complex<double> (0, 1) * amp[432] - amp[440] + amp[438] +
      std::complex<double> (0, 1) * amp[443] - std::complex<double> (0, 1) *
      amp[441] - amp[446] + amp[444] + amp[453] - amp[455] +
      std::complex<double> (0, 1) * amp[458] + std::complex<double> (0, 1) *
      amp[457] + amp[461] + amp[460] + std::complex<double> (0, 1) * amp[467] +
      std::complex<double> (0, 1) * amp[466] + amp[473] + amp[472] + amp[476] +
      amp[475];
  jamp[15] = +amp[109] + std::complex<double> (0, 1) * amp[110] + amp[112] +
      std::complex<double> (0, 1) * amp[113] + amp[114] + amp[132] -
      std::complex<double> (0, 1) * amp[133] - std::complex<double> (0, 1) *
      amp[137] - std::complex<double> (0, 1) * amp[140] + std::complex<double>
      (0, 1) * amp[138] - std::complex<double> (0, 1) * amp[145] -
      std::complex<double> (0, 1) * amp[152] + std::complex<double> (0, 1) *
      amp[150] + amp[153] - std::complex<double> (0, 1) * amp[154] + amp[156] -
      std::complex<double> (0, 1) * amp[157] - std::complex<double> (0, 1) *
      amp[158] - amp[216] - std::complex<double> (0, 1) * amp[217] -
      std::complex<double> (0, 1) * amp[218] - amp[220] - std::complex<double>
      (0, 1) * amp[221] - amp[224] + std::complex<double> (0, 1) * amp[227] -
      amp[228] + std::complex<double> (0, 1) * amp[230] + std::complex<double>
      (0, 1) * amp[231] - amp[245] - amp[254] - amp[256] - amp[257] + amp[266]
      + amp[265] + amp[269] + amp[268] - std::complex<double> (0, 1) * amp[274]
      - std::complex<double> (0, 1) * amp[276] - std::complex<double> (0, 1) *
      amp[277] - amp[284] - std::complex<double> (0, 1) * amp[285] -
      std::complex<double> (0, 1) * amp[286] - std::complex<double> (0, 1) *
      amp[288] - std::complex<double> (0, 1) * amp[289] - amp[300] +
      std::complex<double> (0, 1) * amp[301] - std::complex<double> (0, 1) *
      amp[304] + std::complex<double> (0, 1) * amp[308] - std::complex<double>
      (0, 1) * amp[306] + std::complex<double> (0, 1) * amp[313] - amp[314] -
      std::complex<double> (0, 1) * amp[316] + std::complex<double> (0, 1) *
      amp[320] - std::complex<double> (0, 1) * amp[318] - amp[321] +
      std::complex<double> (0, 1) * amp[322] - amp[324] - amp[408] -
      std::complex<double> (0, 1) * amp[456] - std::complex<double> (0, 1) *
      amp[457] - amp[459] - amp[460] - std::complex<double> (0, 1) * amp[465] -
      std::complex<double> (0, 1) * amp[466] - amp[471] - amp[472] - amp[474] -
      amp[475] + std::complex<double> (0, 1) * amp[506] + std::complex<double>
      (0, 1) * amp[505] + std::complex<double> (0, 1) * amp[512] +
      std::complex<double> (0, 1) * amp[511] + amp[515] + amp[514];
  jamp[16] = -amp[2] + std::complex<double> (0, 1) * amp[3] +
      std::complex<double> (0, 1) * amp[4] + std::complex<double> (0, 1) *
      amp[6] + std::complex<double> (0, 1) * amp[7] + std::complex<double> (0,
      1) * amp[10] + amp[11] + std::complex<double> (0, 1) * amp[21] +
      std::complex<double> (0, 1) * amp[24] + std::complex<double> (0, 1) *
      amp[25] + amp[27] + std::complex<double> (0, 1) * amp[28] +
      std::complex<double> (0, 1) * amp[30] - amp[32] + amp[37] - amp[38] +
      std::complex<double> (0, 1) * amp[39] + std::complex<double> (0, 1) *
      amp[40] + amp[124] - std::complex<double> (0, 1) * amp[127] + amp[129] -
      std::complex<double> (0, 1) * amp[130] - std::complex<double> (0, 1) *
      amp[131] - amp[132] + std::complex<double> (0, 1) * amp[133] -
      std::complex<double> (0, 1) * amp[135] + std::complex<double> (0, 1) *
      amp[140] + std::complex<double> (0, 1) * amp[139] + std::complex<double>
      (0, 1) * amp[145] + amp[146] - std::complex<double> (0, 1) * amp[147] +
      std::complex<double> (0, 1) * amp[152] + std::complex<double> (0, 1) *
      amp[151] - amp[153] - std::complex<double> (0, 1) * amp[155] - amp[156] -
      amp[354] + std::complex<double> (0, 1) * amp[360] - amp[362] +
      std::complex<double> (0, 1) * amp[363] - amp[364] + std::complex<double>
      (0, 1) * amp[365] - amp[366] - amp[367] - amp[370] + std::complex<double>
      (0, 1) * amp[381] - std::complex<double> (0, 1) * amp[386] -
      std::complex<double> (0, 1) * amp[385] - amp[401] + std::complex<double>
      (0, 1) * amp[402] + std::complex<double> (0, 1) * amp[403] -
      std::complex<double> (0, 1) * amp[407] - std::complex<double> (0, 1) *
      amp[406] - amp[412] + std::complex<double> (0, 1) * amp[458] +
      std::complex<double> (0, 1) * amp[457] + amp[461] + amp[460] +
      std::complex<double> (0, 1) * amp[467] + std::complex<double> (0, 1) *
      amp[466] + amp[473] + amp[472] + amp[476] + amp[475] - amp[486] -
      amp[487] - amp[489] - amp[490] + std::complex<double> (0, 1) * amp[492] +
      std::complex<double> (0, 1) * amp[493] + std::complex<double> (0, 1) *
      amp[498] + std::complex<double> (0, 1) * amp[499] - amp[501] - amp[502];
  jamp[17] = +amp[2] - std::complex<double> (0, 1) * amp[3] -
      std::complex<double> (0, 1) * amp[4] - std::complex<double> (0, 1) *
      amp[6] - std::complex<double> (0, 1) * amp[7] - std::complex<double> (0,
      1) * amp[10] - amp[11] - std::complex<double> (0, 1) * amp[21] -
      std::complex<double> (0, 1) * amp[24] - std::complex<double> (0, 1) *
      amp[25] - amp[27] - std::complex<double> (0, 1) * amp[28] -
      std::complex<double> (0, 1) * amp[30] + amp[32] - amp[37] + amp[38] -
      std::complex<double> (0, 1) * amp[39] - std::complex<double> (0, 1) *
      amp[40] + amp[224] - std::complex<double> (0, 1) * amp[227] + amp[228] -
      std::complex<double> (0, 1) * amp[230] - std::complex<double> (0, 1) *
      amp[231] - amp[240] + std::complex<double> (0, 1) * amp[246] - amp[247] +
      std::complex<double> (0, 1) * amp[249] - amp[250] + std::complex<double>
      (0, 1) * amp[251] - amp[252] - amp[253] - amp[255] - amp[264] - amp[265]
      - amp[267] - amp[268] + amp[300] - std::complex<double> (0, 1) * amp[301]
      + std::complex<double> (0, 1) * amp[304] - std::complex<double> (0, 1) *
      amp[308] + std::complex<double> (0, 1) * amp[306] - std::complex<double>
      (0, 1) * amp[313] + amp[314] + std::complex<double> (0, 1) * amp[316] -
      std::complex<double> (0, 1) * amp[320] + std::complex<double> (0, 1) *
      amp[318] + amp[321] - std::complex<double> (0, 1) * amp[322] + amp[324] -
      std::complex<double> (0, 1) * amp[383] + std::complex<double> (0, 1) *
      amp[386] - std::complex<double> (0, 1) * amp[384] - amp[399] +
      std::complex<double> (0, 1) * amp[400] - std::complex<double> (0, 1) *
      amp[404] + std::complex<double> (0, 1) * amp[407] - std::complex<double>
      (0, 1) * amp[405] - amp[409] - std::complex<double> (0, 1) * amp[458] +
      std::complex<double> (0, 1) * amp[456] - amp[461] + amp[459] -
      std::complex<double> (0, 1) * amp[467] + std::complex<double> (0, 1) *
      amp[465] - amp[473] + amp[471] - amp[476] + amp[474] -
      std::complex<double> (0, 1) * amp[504] - std::complex<double> (0, 1) *
      amp[505] - std::complex<double> (0, 1) * amp[510] - std::complex<double>
      (0, 1) * amp[511] - amp[513] - amp[514];
  jamp[18] = +amp[0] - std::complex<double> (0, 1) * amp[1] -
      std::complex<double> (0, 1) * amp[3] - std::complex<double> (0, 1) *
      amp[8] - std::complex<double> (0, 1) * amp[7] + std::complex<double> (0,
      1) * amp[13] - amp[14] - std::complex<double> (0, 1) * amp[19] - amp[20]
      - std::complex<double> (0, 1) * amp[21] - std::complex<double> (0, 1) *
      amp[26] - std::complex<double> (0, 1) * amp[25] + amp[34] +
      std::complex<double> (0, 1) * amp[35] - amp[43] + std::complex<double>
      (0, 1) * amp[46] + std::complex<double> (0, 1) * amp[47] + amp[48] -
      amp[108] + std::complex<double> (0, 1) * amp[110] - amp[111] +
      std::complex<double> (0, 1) * amp[113] - amp[115] - std::complex<double>
      (0, 1) * amp[133] - std::complex<double> (0, 1) * amp[140] +
      std::complex<double> (0, 1) * amp[138] - amp[141] - std::complex<double>
      (0, 1) * amp[142] - amp[144] - std::complex<double> (0, 1) * amp[145] -
      std::complex<double> (0, 1) * amp[149] - std::complex<double> (0, 1) *
      amp[152] + std::complex<double> (0, 1) * amp[150] - amp[159] -
      std::complex<double> (0, 1) * amp[160] - std::complex<double> (0, 1) *
      amp[161] + amp[270] - std::complex<double> (0, 1) * amp[271] +
      std::complex<double> (0, 1) * amp[275] - std::complex<double> (0, 1) *
      amp[278] - std::complex<double> (0, 1) * amp[277] - std::complex<double>
      (0, 1) * amp[283] - std::complex<double> (0, 1) * amp[290] -
      std::complex<double> (0, 1) * amp[289] + amp[291] + std::complex<double>
      (0, 1) * amp[293] + amp[294] + std::complex<double> (0, 1) * amp[295] +
      std::complex<double> (0, 1) * amp[296] - amp[392] - amp[417] - amp[428] -
      amp[429] - amp[430] - std::complex<double> (0, 1) * amp[434] +
      std::complex<double> (0, 1) * amp[432] - amp[437] + amp[435] -
      std::complex<double> (0, 1) * amp[443] + std::complex<double> (0, 1) *
      amp[441] - amp[449] + amp[447] - amp[452] + amp[450] -
      std::complex<double> (0, 1) * amp[458] - std::complex<double> (0, 1) *
      amp[457] + amp[464] + amp[463] - std::complex<double> (0, 1) * amp[467] -
      std::complex<double> (0, 1) * amp[466] + amp[470] + amp[469] + amp[478] +
      amp[479];
  jamp[19] = -amp[70] + std::complex<double> (0, 1) * amp[73] - amp[75] +
      std::complex<double> (0, 1) * amp[76] + std::complex<double> (0, 1) *
      amp[77] + amp[78] - std::complex<double> (0, 1) * amp[79] +
      std::complex<double> (0, 1) * amp[81] - std::complex<double> (0, 1) *
      amp[86] - std::complex<double> (0, 1) * amp[85] - std::complex<double>
      (0, 1) * amp[91] - amp[92] + std::complex<double> (0, 1) * amp[93] -
      std::complex<double> (0, 1) * amp[98] - std::complex<double> (0, 1) *
      amp[97] + amp[99] + std::complex<double> (0, 1) * amp[101] + amp[102] +
      amp[108] - std::complex<double> (0, 1) * amp[110] + amp[111] -
      std::complex<double> (0, 1) * amp[113] + amp[115] - amp[124] -
      std::complex<double> (0, 1) * amp[125] - std::complex<double> (0, 1) *
      amp[126] - std::complex<double> (0, 1) * amp[128] - amp[129] +
      std::complex<double> (0, 1) * amp[135] - std::complex<double> (0, 1) *
      amp[138] - std::complex<double> (0, 1) * amp[139] - amp[146] +
      std::complex<double> (0, 1) * amp[147] - std::complex<double> (0, 1) *
      amp[148] - std::complex<double> (0, 1) * amp[150] - std::complex<double>
      (0, 1) * amp[151] - amp[270] + std::complex<double> (0, 1) * amp[271] -
      std::complex<double> (0, 1) * amp[275] + std::complex<double> (0, 1) *
      amp[278] + std::complex<double> (0, 1) * amp[277] + std::complex<double>
      (0, 1) * amp[283] + std::complex<double> (0, 1) * amp[290] +
      std::complex<double> (0, 1) * amp[289] - amp[291] - std::complex<double>
      (0, 1) * amp[293] - amp[294] - std::complex<double> (0, 1) * amp[295] -
      std::complex<double> (0, 1) * amp[296] - amp[358] - amp[374] - amp[375] -
      amp[377] - amp[416] - std::complex<double> (0, 1) * amp[432] -
      std::complex<double> (0, 1) * amp[433] - amp[435] - amp[436] -
      std::complex<double> (0, 1) * amp[441] - std::complex<double> (0, 1) *
      amp[442] - amp[447] - amp[448] - amp[450] - amp[451] + amp[487] +
      amp[488] + amp[491] + amp[490] - std::complex<double> (0, 1) * amp[494] -
      std::complex<double> (0, 1) * amp[493] - std::complex<double> (0, 1) *
      amp[500] - std::complex<double> (0, 1) * amp[499] + amp[503] + amp[502];
  jamp[20] = -amp[0] + std::complex<double> (0, 1) * amp[1] +
      std::complex<double> (0, 1) * amp[3] + std::complex<double> (0, 1) *
      amp[8] + std::complex<double> (0, 1) * amp[7] - std::complex<double> (0,
      1) * amp[13] + amp[14] + std::complex<double> (0, 1) * amp[19] + amp[20]
      + std::complex<double> (0, 1) * amp[21] + std::complex<double> (0, 1) *
      amp[26] + std::complex<double> (0, 1) * amp[25] - amp[34] -
      std::complex<double> (0, 1) * amp[35] + amp[43] - std::complex<double>
      (0, 1) * amp[46] - std::complex<double> (0, 1) * amp[47] - amp[48] -
      amp[55] - std::complex<double> (0, 1) * amp[56] - amp[58] -
      std::complex<double> (0, 1) * amp[59] - amp[60] - amp[78] +
      std::complex<double> (0, 1) * amp[79] + std::complex<double> (0, 1) *
      amp[83] + std::complex<double> (0, 1) * amp[86] - std::complex<double>
      (0, 1) * amp[84] + std::complex<double> (0, 1) * amp[91] +
      std::complex<double> (0, 1) * amp[98] - std::complex<double> (0, 1) *
      amp[96] - amp[99] + std::complex<double> (0, 1) * amp[100] - amp[102] +
      std::complex<double> (0, 1) * amp[103] + std::complex<double> (0, 1) *
      amp[104] + std::complex<double> (0, 1) * amp[301] + std::complex<double>
      (0, 1) * amp[308] + std::complex<double> (0, 1) * amp[307] + amp[309] -
      std::complex<double> (0, 1) * amp[311] + amp[312] + std::complex<double>
      (0, 1) * amp[313] - std::complex<double> (0, 1) * amp[317] +
      std::complex<double> (0, 1) * amp[320] + std::complex<double> (0, 1) *
      amp[319] + amp[327] - std::complex<double> (0, 1) * amp[328] -
      std::complex<double> (0, 1) * amp[329] - amp[390] - amp[419] - amp[426] -
      amp[427] - amp[431] + std::complex<double> (0, 1) * amp[434] +
      std::complex<double> (0, 1) * amp[433] + amp[437] + amp[436] +
      std::complex<double> (0, 1) * amp[443] + std::complex<double> (0, 1) *
      amp[442] + amp[449] + amp[448] + amp[452] + amp[451] +
      std::complex<double> (0, 1) * amp[458] - std::complex<double> (0, 1) *
      amp[456] - amp[464] + amp[462] + std::complex<double> (0, 1) * amp[467] -
      std::complex<double> (0, 1) * amp[465] - amp[470] + amp[468] + amp[477] -
      amp[479];
  jamp[21] = +amp[55] + std::complex<double> (0, 1) * amp[56] + amp[58] +
      std::complex<double> (0, 1) * amp[59] + amp[60] + amp[78] -
      std::complex<double> (0, 1) * amp[79] - std::complex<double> (0, 1) *
      amp[83] - std::complex<double> (0, 1) * amp[86] + std::complex<double>
      (0, 1) * amp[84] - std::complex<double> (0, 1) * amp[91] -
      std::complex<double> (0, 1) * amp[98] + std::complex<double> (0, 1) *
      amp[96] + amp[99] - std::complex<double> (0, 1) * amp[100] + amp[102] -
      std::complex<double> (0, 1) * amp[103] - std::complex<double> (0, 1) *
      amp[104] - amp[216] + std::complex<double> (0, 1) * amp[219] - amp[220] +
      std::complex<double> (0, 1) * amp[222] + std::complex<double> (0, 1) *
      amp[223] - amp[224] - std::complex<double> (0, 1) * amp[225] -
      std::complex<double> (0, 1) * amp[226] - amp[228] - std::complex<double>
      (0, 1) * amp[229] - amp[243] - amp[260] - amp[262] - amp[263] + amp[266]
      + amp[265] + amp[269] + amp[268] - amp[270] + std::complex<double> (0, 1)
      * amp[271] - std::complex<double> (0, 1) * amp[274] +
      std::complex<double> (0, 1) * amp[278] - std::complex<double> (0, 1) *
      amp[276] + std::complex<double> (0, 1) * amp[283] - amp[284] -
      std::complex<double> (0, 1) * amp[286] + std::complex<double> (0, 1) *
      amp[290] - std::complex<double> (0, 1) * amp[288] - amp[291] +
      std::complex<double> (0, 1) * amp[292] - amp[294] - std::complex<double>
      (0, 1) * amp[304] - std::complex<double> (0, 1) * amp[306] -
      std::complex<double> (0, 1) * amp[307] - amp[314] - std::complex<double>
      (0, 1) * amp[315] - std::complex<double> (0, 1) * amp[316] -
      std::complex<double> (0, 1) * amp[318] - std::complex<double> (0, 1) *
      amp[319] - amp[414] - std::complex<double> (0, 1) * amp[432] -
      std::complex<double> (0, 1) * amp[433] - amp[435] - amp[436] -
      std::complex<double> (0, 1) * amp[441] - std::complex<double> (0, 1) *
      amp[442] - amp[447] - amp[448] - amp[450] - amp[451] +
      std::complex<double> (0, 1) * amp[506] + std::complex<double> (0, 1) *
      amp[505] + std::complex<double> (0, 1) * amp[512] + std::complex<double>
      (0, 1) * amp[511] + amp[515] + amp[514];
  jamp[22] = -amp[0] + std::complex<double> (0, 1) * amp[1] +
      std::complex<double> (0, 1) * amp[5] + std::complex<double> (0, 1) *
      amp[8] - std::complex<double> (0, 1) * amp[6] - std::complex<double> (0,
      1) * amp[10] - amp[11] + std::complex<double> (0, 1) * amp[19] +
      std::complex<double> (0, 1) * amp[26] - std::complex<double> (0, 1) *
      amp[24] - amp[27] - std::complex<double> (0, 1) * amp[28] +
      std::complex<double> (0, 1) * amp[33] - amp[34] - amp[37] - amp[48] +
      std::complex<double> (0, 1) * amp[49] + std::complex<double> (0, 1) *
      amp[50] + amp[70] - std::complex<double> (0, 1) * amp[73] + amp[75] -
      std::complex<double> (0, 1) * amp[76] - std::complex<double> (0, 1) *
      amp[77] - amp[78] + std::complex<double> (0, 1) * amp[79] -
      std::complex<double> (0, 1) * amp[81] + std::complex<double> (0, 1) *
      amp[86] + std::complex<double> (0, 1) * amp[85] + std::complex<double>
      (0, 1) * amp[91] + amp[92] - std::complex<double> (0, 1) * amp[93] +
      std::complex<double> (0, 1) * amp[98] + std::complex<double> (0, 1) *
      amp[97] - amp[99] - std::complex<double> (0, 1) * amp[101] - amp[102] -
      amp[355] - std::complex<double> (0, 1) * amp[360] + amp[362] -
      std::complex<double> (0, 1) * amp[363] + amp[364] - std::complex<double>
      (0, 1) * amp[365] - amp[372] - amp[373] - amp[376] - std::complex<double>
      (0, 1) * amp[381] + std::complex<double> (0, 1) * amp[386] +
      std::complex<double> (0, 1) * amp[385] + amp[401] - std::complex<double>
      (0, 1) * amp[402] - std::complex<double> (0, 1) * amp[403] +
      std::complex<double> (0, 1) * amp[407] + std::complex<double> (0, 1) *
      amp[406] - amp[418] + std::complex<double> (0, 1) * amp[434] +
      std::complex<double> (0, 1) * amp[433] + amp[437] + amp[436] +
      std::complex<double> (0, 1) * amp[443] + std::complex<double> (0, 1) *
      amp[442] + amp[449] + amp[448] + amp[452] + amp[451] + amp[486] -
      amp[488] - amp[491] + amp[489] + std::complex<double> (0, 1) * amp[494] -
      std::complex<double> (0, 1) * amp[492] + std::complex<double> (0, 1) *
      amp[500] - std::complex<double> (0, 1) * amp[498] - amp[503] + amp[501];
  jamp[23] = +amp[0] - std::complex<double> (0, 1) * amp[1] -
      std::complex<double> (0, 1) * amp[5] - std::complex<double> (0, 1) *
      amp[8] + std::complex<double> (0, 1) * amp[6] + std::complex<double> (0,
      1) * amp[10] + amp[11] - std::complex<double> (0, 1) * amp[19] -
      std::complex<double> (0, 1) * amp[26] + std::complex<double> (0, 1) *
      amp[24] + amp[27] + std::complex<double> (0, 1) * amp[28] -
      std::complex<double> (0, 1) * amp[33] + amp[34] + amp[37] + amp[48] -
      std::complex<double> (0, 1) * amp[49] - std::complex<double> (0, 1) *
      amp[50] + amp[216] - std::complex<double> (0, 1) * amp[219] + amp[220] -
      std::complex<double> (0, 1) * amp[222] - std::complex<double> (0, 1) *
      amp[223] - amp[241] - std::complex<double> (0, 1) * amp[246] + amp[247] -
      std::complex<double> (0, 1) * amp[249] + amp[250] - std::complex<double>
      (0, 1) * amp[251] - amp[258] - amp[259] - amp[261] - amp[266] + amp[264]
      - amp[269] + amp[267] + amp[270] - std::complex<double> (0, 1) * amp[271]
      + std::complex<double> (0, 1) * amp[274] - std::complex<double> (0, 1) *
      amp[278] + std::complex<double> (0, 1) * amp[276] - std::complex<double>
      (0, 1) * amp[283] + amp[284] + std::complex<double> (0, 1) * amp[286] -
      std::complex<double> (0, 1) * amp[290] + std::complex<double> (0, 1) *
      amp[288] + amp[291] - std::complex<double> (0, 1) * amp[292] + amp[294] +
      std::complex<double> (0, 1) * amp[383] - std::complex<double> (0, 1) *
      amp[386] + std::complex<double> (0, 1) * amp[384] + amp[399] -
      std::complex<double> (0, 1) * amp[400] + std::complex<double> (0, 1) *
      amp[404] - std::complex<double> (0, 1) * amp[407] + std::complex<double>
      (0, 1) * amp[405] - amp[415] - std::complex<double> (0, 1) * amp[434] +
      std::complex<double> (0, 1) * amp[432] - amp[437] + amp[435] -
      std::complex<double> (0, 1) * amp[443] + std::complex<double> (0, 1) *
      amp[441] - amp[449] + amp[447] - amp[452] + amp[450] -
      std::complex<double> (0, 1) * amp[506] + std::complex<double> (0, 1) *
      amp[504] - std::complex<double> (0, 1) * amp[512] + std::complex<double>
      (0, 1) * amp[510] - amp[515] + amp[513];

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



