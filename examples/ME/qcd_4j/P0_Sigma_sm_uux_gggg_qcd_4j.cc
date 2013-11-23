//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "P0_Sigma_sm_uux_gggg_qcd_4j.h"
#include "HelAmps_sm.h"

using namespace MG5_sm; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: u u~ > g g g g WEIGHTED=4
// Process: c c~ > g g g g WEIGHTED=4
// Process: d d~ > g g g g WEIGHTED=4
// Process: s s~ > g g g g WEIGHTED=4

//--------------------------------------------------------------------------
// Initialize process.

void P0_Sigma_sm_uux_gggg_qcd_4j::initProc(string param_card_name) 
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
  jamp2[0] = new double[24]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void P0_Sigma_sm_uux_gggg_qcd_4j::sigmaKin() 
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
  const int ncomb = 64; 
  static bool goodhel[ncomb] = {ncomb * false}; 
  static int ntry = 0, sum_hel = 0, ngood = 0; 
  static int igood[ncomb]; 
  static int jhel; 
  std::complex<double> * * wfs; 
  double t[nprocesses]; 
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, 1, -1}, {-1, -1, -1, -1, 1, 1},
      {-1, -1, -1, 1, -1, -1}, {-1, -1, -1, 1, -1, 1}, {-1, -1, -1, 1, 1, -1},
      {-1, -1, -1, 1, 1, 1}, {-1, -1, 1, -1, -1, -1}, {-1, -1, 1, -1, -1, 1},
      {-1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1, 1}, {-1, -1, 1, 1, -1, -1},
      {-1, -1, 1, 1, -1, 1}, {-1, -1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1}, {-1,
      1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, 1}, {-1, 1, -1, -1, 1, -1}, {-1,
      1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, -1}, {-1, 1, -1, 1, -1, 1}, {-1, 1,
      -1, 1, 1, -1}, {-1, 1, -1, 1, 1, 1}, {-1, 1, 1, -1, -1, -1}, {-1, 1, 1,
      -1, -1, 1}, {-1, 1, 1, -1, 1, -1}, {-1, 1, 1, -1, 1, 1}, {-1, 1, 1, 1,
      -1, -1}, {-1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1, 1, -1}, {-1, 1, 1, 1, 1, 1},
      {1, -1, -1, -1, -1, -1}, {1, -1, -1, -1, -1, 1}, {1, -1, -1, -1, 1, -1},
      {1, -1, -1, -1, 1, 1}, {1, -1, -1, 1, -1, -1}, {1, -1, -1, 1, -1, 1}, {1,
      -1, -1, 1, 1, -1}, {1, -1, -1, 1, 1, 1}, {1, -1, 1, -1, -1, -1}, {1, -1,
      1, -1, -1, 1}, {1, -1, 1, -1, 1, -1}, {1, -1, 1, -1, 1, 1}, {1, -1, 1, 1,
      -1, -1}, {1, -1, 1, 1, -1, 1}, {1, -1, 1, 1, 1, -1}, {1, -1, 1, 1, 1, 1},
      {1, 1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, 1}, {1, 1, -1, -1, 1, -1}, {1,
      1, -1, -1, 1, 1}, {1, 1, -1, 1, -1, -1}, {1, 1, -1, 1, -1, 1}, {1, 1, -1,
      1, 1, -1}, {1, 1, -1, 1, 1, 1}, {1, 1, 1, -1, -1, -1}, {1, 1, 1, -1, -1,
      1}, {1, 1, 1, -1, 1, -1}, {1, 1, 1, -1, 1, 1}, {1, 1, 1, 1, -1, -1}, {1,
      1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, -1}, {1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {864, 864}; 

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
        t[0] = matrix_uux_gggg(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_uux_gggg(); 
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
      t[0] = matrix_uux_gggg(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_uux_gggg(); 
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

double P0_Sigma_sm_uux_gggg_qcd_4j::sigmaHat() 
{
  // Select between the different processes
  if(id1 == -3 && id2 == 3)
  {
    // Add matrix elements for processes with beams (-3, 3)
    return matrix_element[1]; 
  }
  else if(id1 == -1 && id2 == 1)
  {
    // Add matrix elements for processes with beams (-1, 1)
    return matrix_element[1]; 
  }
  else if(id1 == 4 && id2 == -4)
  {
    // Add matrix elements for processes with beams (4, -4)
    return matrix_element[0]; 
  }
  else if(id1 == 2 && id2 == -2)
  {
    // Add matrix elements for processes with beams (2, -2)
    return matrix_element[0]; 
  }
  else if(id1 == -4 && id2 == 4)
  {
    // Add matrix elements for processes with beams (-4, 4)
    return matrix_element[1]; 
  }
  else if(id1 == -2 && id2 == 2)
  {
    // Add matrix elements for processes with beams (-2, 2)
    return matrix_element[1]; 
  }
  else if(id1 == 3 && id2 == -3)
  {
    // Add matrix elements for processes with beams (3, -3)
    return matrix_element[0]; 
  }
  else if(id1 == 1 && id2 == -1)
  {
    // Add matrix elements for processes with beams (1, -1)
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

void P0_Sigma_sm_uux_gggg_qcd_4j::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  ixxxxx(p[perm[0]], mME[0], hel[0], +1, w[0]); 
  oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]); 
  vxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]); 
  vxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  vxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]); 
  vxxxxx(p[perm[5]], mME[5], hel[5], +1, w[5]); 
  VVV1_1(w[2], w[3], pars->GC_10, pars->ZERO, pars->ZERO, w[6]); 
  VVV1_1(w[4], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[7]); 
  FFV1_1(w[1], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[8]); 
  FFV1_2(w[0], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[9]); 
  FFV1_3(w[0], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[10]); 
  FFV1_1(w[1], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[11]); 
  VVV1_1(w[6], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_2(w[0], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[13]); 
  FFV1_2(w[0], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[14]); 
  FFV1_1(w[1], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[15]); 
  VVV1_1(w[6], w[4], pars->GC_10, pars->ZERO, pars->ZERO, w[16]); 
  VVV1_1(w[2], w[4], pars->GC_10, pars->ZERO, pars->ZERO, w[17]); 
  VVV1_1(w[3], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[18]); 
  FFV1_1(w[1], w[17], pars->GC_11, pars->ZERO, pars->ZERO, w[19]); 
  FFV1_2(w[0], w[17], pars->GC_11, pars->ZERO, pars->ZERO, w[20]); 
  FFV1_1(w[1], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[21]); 
  VVV1_1(w[17], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[22]); 
  FFV1_2(w[0], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[23]); 
  VVV1_1(w[17], w[3], pars->GC_10, pars->ZERO, pars->ZERO, w[24]); 
  VVV1_1(w[2], w[5], pars->GC_10, pars->ZERO, pars->ZERO, w[25]); 
  VVV1_1(w[3], w[4], pars->GC_10, pars->ZERO, pars->ZERO, w[26]); 
  FFV1_1(w[1], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[27]); 
  FFV1_2(w[0], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[28]); 
  VVV1_1(w[25], w[4], pars->GC_10, pars->ZERO, pars->ZERO, w[29]); 
  VVV1_1(w[25], w[3], pars->GC_10, pars->ZERO, pars->ZERO, w[30]); 
  FFV1_1(w[1], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[31]); 
  FFV1_1(w[31], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[32]); 
  FFV1_3(w[0], w[31], pars->GC_11, pars->ZERO, pars->ZERO, w[33]); 
  FFV1_1(w[31], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[34]); 
  FFV1_1(w[31], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[35]); 
  VVVV1_1(w[3], w[4], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[36]); 
  VVVV3_1(w[3], w[4], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[37]); 
  VVVV4_1(w[3], w[4], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[38]); 
  FFV1_2(w[0], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[39]); 
  FFV1_2(w[39], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[40]); 
  FFV1_3(w[39], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[41]); 
  FFV1_2(w[39], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[42]); 
  FFV1_2(w[39], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[43]); 
  VVV1_1(w[2], w[26], pars->GC_10, pars->ZERO, pars->ZERO, w[44]); 
  FFV1_1(w[15], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[45]); 
  FFV1_2(w[13], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[46]); 
  VVV1_1(w[2], w[10], pars->GC_10, pars->ZERO, pars->ZERO, w[47]); 
  VVV1_1(w[2], w[18], pars->GC_10, pars->ZERO, pars->ZERO, w[48]); 
  FFV1_1(w[11], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[49]); 
  FFV1_2(w[14], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[50]); 
  FFV1_1(w[21], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[51]); 
  VVV1_1(w[2], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[52]); 
  FFV1_2(w[23], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[53]); 
  VVVV1_1(w[2], w[3], w[4], pars->GC_12, pars->ZERO, pars->ZERO, w[54]); 
  VVVV3_1(w[2], w[3], w[4], pars->GC_12, pars->ZERO, pars->ZERO, w[55]); 
  VVVV4_1(w[2], w[3], w[4], pars->GC_12, pars->ZERO, pars->ZERO, w[56]); 
  VVVV1_1(w[2], w[3], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[57]); 
  VVVV3_1(w[2], w[3], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[58]); 
  VVVV4_1(w[2], w[3], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[59]); 
  VVVV1_1(w[2], w[4], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[60]); 
  VVVV3_1(w[2], w[4], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[61]); 
  VVVV4_1(w[2], w[4], w[5], pars->GC_12, pars->ZERO, pars->ZERO, w[62]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[0], w[8], w[7], pars->GC_11, amp[0]); 
  FFV1_0(w[9], w[1], w[7], pars->GC_11, amp[1]); 
  VVV1_0(w[6], w[7], w[10], pars->GC_10, amp[2]); 
  FFV1_0(w[0], w[11], w[12], pars->GC_11, amp[3]); 
  FFV1_0(w[9], w[11], w[5], pars->GC_11, amp[4]); 
  FFV1_0(w[13], w[11], w[6], pars->GC_11, amp[5]); 
  FFV1_0(w[14], w[1], w[12], pars->GC_11, amp[6]); 
  FFV1_0(w[14], w[8], w[5], pars->GC_11, amp[7]); 
  FFV1_0(w[14], w[15], w[6], pars->GC_11, amp[8]); 
  FFV1_0(w[0], w[15], w[16], pars->GC_11, amp[9]); 
  FFV1_0(w[9], w[15], w[4], pars->GC_11, amp[10]); 
  FFV1_0(w[13], w[1], w[16], pars->GC_11, amp[11]); 
  FFV1_0(w[13], w[8], w[4], pars->GC_11, amp[12]); 
  VVVV1_0(w[6], w[4], w[5], w[10], pars->GC_12, amp[13]); 
  VVVV3_0(w[6], w[4], w[5], w[10], pars->GC_12, amp[14]); 
  VVVV4_0(w[6], w[4], w[5], w[10], pars->GC_12, amp[15]); 
  VVV1_0(w[5], w[10], w[16], pars->GC_10, amp[16]); 
  VVV1_0(w[4], w[10], w[12], pars->GC_10, amp[17]); 
  FFV1_0(w[0], w[19], w[18], pars->GC_11, amp[18]); 
  FFV1_0(w[20], w[1], w[18], pars->GC_11, amp[19]); 
  VVV1_0(w[17], w[18], w[10], pars->GC_10, amp[20]); 
  FFV1_0(w[0], w[21], w[22], pars->GC_11, amp[21]); 
  FFV1_0(w[20], w[21], w[5], pars->GC_11, amp[22]); 
  FFV1_0(w[13], w[21], w[17], pars->GC_11, amp[23]); 
  FFV1_0(w[23], w[1], w[22], pars->GC_11, amp[24]); 
  FFV1_0(w[23], w[19], w[5], pars->GC_11, amp[25]); 
  FFV1_0(w[23], w[15], w[17], pars->GC_11, amp[26]); 
  FFV1_0(w[0], w[15], w[24], pars->GC_11, amp[27]); 
  FFV1_0(w[20], w[15], w[3], pars->GC_11, amp[28]); 
  FFV1_0(w[13], w[1], w[24], pars->GC_11, amp[29]); 
  FFV1_0(w[13], w[19], w[3], pars->GC_11, amp[30]); 
  VVVV1_0(w[17], w[3], w[5], w[10], pars->GC_12, amp[31]); 
  VVVV3_0(w[17], w[3], w[5], w[10], pars->GC_12, amp[32]); 
  VVVV4_0(w[17], w[3], w[5], w[10], pars->GC_12, amp[33]); 
  VVV1_0(w[5], w[10], w[24], pars->GC_10, amp[34]); 
  VVV1_0(w[3], w[10], w[22], pars->GC_10, amp[35]); 
  FFV1_0(w[0], w[27], w[26], pars->GC_11, amp[36]); 
  FFV1_0(w[28], w[1], w[26], pars->GC_11, amp[37]); 
  VVV1_0(w[25], w[26], w[10], pars->GC_10, amp[38]); 
  FFV1_0(w[0], w[21], w[29], pars->GC_11, amp[39]); 
  FFV1_0(w[28], w[21], w[4], pars->GC_11, amp[40]); 
  FFV1_0(w[14], w[21], w[25], pars->GC_11, amp[41]); 
  FFV1_0(w[23], w[1], w[29], pars->GC_11, amp[42]); 
  FFV1_0(w[23], w[27], w[4], pars->GC_11, amp[43]); 
  FFV1_0(w[23], w[11], w[25], pars->GC_11, amp[44]); 
  FFV1_0(w[0], w[11], w[30], pars->GC_11, amp[45]); 
  FFV1_0(w[28], w[11], w[3], pars->GC_11, amp[46]); 
  FFV1_0(w[14], w[1], w[30], pars->GC_11, amp[47]); 
  FFV1_0(w[14], w[27], w[3], pars->GC_11, amp[48]); 
  VVVV1_0(w[25], w[3], w[4], w[10], pars->GC_12, amp[49]); 
  VVVV3_0(w[25], w[3], w[4], w[10], pars->GC_12, amp[50]); 
  VVVV4_0(w[25], w[3], w[4], w[10], pars->GC_12, amp[51]); 
  VVV1_0(w[4], w[10], w[30], pars->GC_10, amp[52]); 
  VVV1_0(w[3], w[10], w[29], pars->GC_10, amp[53]); 
  FFV1_0(w[0], w[32], w[26], pars->GC_11, amp[54]); 
  VVV1_0(w[26], w[5], w[33], pars->GC_10, amp[55]); 
  FFV1_0(w[13], w[31], w[26], pars->GC_11, amp[56]); 
  FFV1_0(w[0], w[34], w[18], pars->GC_11, amp[57]); 
  VVV1_0(w[18], w[4], w[33], pars->GC_10, amp[58]); 
  FFV1_0(w[14], w[31], w[18], pars->GC_11, amp[59]); 
  FFV1_0(w[23], w[34], w[5], pars->GC_11, amp[60]); 
  FFV1_0(w[23], w[32], w[4], pars->GC_11, amp[61]); 
  FFV1_0(w[23], w[31], w[7], pars->GC_11, amp[62]); 
  FFV1_0(w[0], w[35], w[7], pars->GC_11, amp[63]); 
  VVV1_0(w[3], w[7], w[33], pars->GC_10, amp[64]); 
  FFV1_0(w[14], w[35], w[5], pars->GC_11, amp[65]); 
  FFV1_0(w[14], w[32], w[3], pars->GC_11, amp[66]); 
  FFV1_0(w[13], w[35], w[4], pars->GC_11, amp[67]); 
  FFV1_0(w[13], w[34], w[3], pars->GC_11, amp[68]); 
  FFV1_0(w[0], w[31], w[36], pars->GC_11, amp[69]); 
  FFV1_0(w[0], w[31], w[37], pars->GC_11, amp[70]); 
  FFV1_0(w[0], w[31], w[38], pars->GC_11, amp[71]); 
  FFV1_0(w[40], w[1], w[26], pars->GC_11, amp[72]); 
  VVV1_0(w[26], w[5], w[41], pars->GC_10, amp[73]); 
  FFV1_0(w[39], w[15], w[26], pars->GC_11, amp[74]); 
  FFV1_0(w[42], w[1], w[18], pars->GC_11, amp[75]); 
  VVV1_0(w[18], w[4], w[41], pars->GC_10, amp[76]); 
  FFV1_0(w[39], w[11], w[18], pars->GC_11, amp[77]); 
  FFV1_0(w[42], w[21], w[5], pars->GC_11, amp[78]); 
  FFV1_0(w[40], w[21], w[4], pars->GC_11, amp[79]); 
  FFV1_0(w[39], w[21], w[7], pars->GC_11, amp[80]); 
  FFV1_0(w[43], w[1], w[7], pars->GC_11, amp[81]); 
  VVV1_0(w[3], w[7], w[41], pars->GC_10, amp[82]); 
  FFV1_0(w[43], w[11], w[5], pars->GC_11, amp[83]); 
  FFV1_0(w[40], w[11], w[3], pars->GC_11, amp[84]); 
  FFV1_0(w[43], w[15], w[4], pars->GC_11, amp[85]); 
  FFV1_0(w[42], w[15], w[3], pars->GC_11, amp[86]); 
  FFV1_0(w[39], w[1], w[36], pars->GC_11, amp[87]); 
  FFV1_0(w[39], w[1], w[37], pars->GC_11, amp[88]); 
  FFV1_0(w[39], w[1], w[38], pars->GC_11, amp[89]); 
  FFV1_0(w[0], w[15], w[44], pars->GC_11, amp[90]); 
  FFV1_0(w[0], w[45], w[26], pars->GC_11, amp[91]); 
  FFV1_0(w[13], w[1], w[44], pars->GC_11, amp[92]); 
  FFV1_0(w[46], w[1], w[26], pars->GC_11, amp[93]); 
  VVVV1_0(w[2], w[26], w[5], w[10], pars->GC_12, amp[94]); 
  VVVV3_0(w[2], w[26], w[5], w[10], pars->GC_12, amp[95]); 
  VVVV4_0(w[2], w[26], w[5], w[10], pars->GC_12, amp[96]); 
  VVV1_0(w[5], w[10], w[44], pars->GC_10, amp[97]); 
  VVV1_0(w[26], w[5], w[47], pars->GC_10, amp[98]); 
  FFV1_0(w[0], w[11], w[48], pars->GC_11, amp[99]); 
  FFV1_0(w[0], w[49], w[18], pars->GC_11, amp[100]); 
  FFV1_0(w[14], w[1], w[48], pars->GC_11, amp[101]); 
  FFV1_0(w[50], w[1], w[18], pars->GC_11, amp[102]); 
  VVVV1_0(w[2], w[18], w[4], w[10], pars->GC_12, amp[103]); 
  VVVV3_0(w[2], w[18], w[4], w[10], pars->GC_12, amp[104]); 
  VVVV4_0(w[2], w[18], w[4], w[10], pars->GC_12, amp[105]); 
  VVV1_0(w[4], w[10], w[48], pars->GC_10, amp[106]); 
  VVV1_0(w[18], w[4], w[47], pars->GC_10, amp[107]); 
  FFV1_0(w[0], w[51], w[7], pars->GC_11, amp[108]); 
  FFV1_0(w[0], w[21], w[52], pars->GC_11, amp[109]); 
  FFV1_0(w[14], w[51], w[5], pars->GC_11, amp[110]); 
  FFV1_0(w[50], w[21], w[5], pars->GC_11, amp[111]); 
  FFV1_0(w[13], w[51], w[4], pars->GC_11, amp[112]); 
  FFV1_0(w[46], w[21], w[4], pars->GC_11, amp[113]); 
  FFV1_0(w[53], w[1], w[7], pars->GC_11, amp[114]); 
  FFV1_0(w[23], w[1], w[52], pars->GC_11, amp[115]); 
  FFV1_0(w[53], w[11], w[5], pars->GC_11, amp[116]); 
  FFV1_0(w[23], w[49], w[5], pars->GC_11, amp[117]); 
  FFV1_0(w[53], w[15], w[4], pars->GC_11, amp[118]); 
  FFV1_0(w[23], w[45], w[4], pars->GC_11, amp[119]); 
  VVVV1_0(w[2], w[3], w[7], w[10], pars->GC_12, amp[120]); 
  VVVV3_0(w[2], w[3], w[7], w[10], pars->GC_12, amp[121]); 
  VVVV4_0(w[2], w[3], w[7], w[10], pars->GC_12, amp[122]); 
  VVV1_0(w[3], w[10], w[52], pars->GC_10, amp[123]); 
  VVV1_0(w[3], w[7], w[47], pars->GC_10, amp[124]); 
  FFV1_0(w[13], w[49], w[3], pars->GC_11, amp[125]); 
  FFV1_0(w[46], w[11], w[3], pars->GC_11, amp[126]); 
  FFV1_0(w[50], w[15], w[3], pars->GC_11, amp[127]); 
  FFV1_0(w[14], w[45], w[3], pars->GC_11, amp[128]); 
  FFV1_0(w[0], w[15], w[54], pars->GC_11, amp[129]); 
  FFV1_0(w[0], w[15], w[55], pars->GC_11, amp[130]); 
  FFV1_0(w[0], w[15], w[56], pars->GC_11, amp[131]); 
  FFV1_0(w[13], w[1], w[54], pars->GC_11, amp[132]); 
  FFV1_0(w[13], w[1], w[55], pars->GC_11, amp[133]); 
  FFV1_0(w[13], w[1], w[56], pars->GC_11, amp[134]); 
  VVV1_0(w[54], w[5], w[10], pars->GC_10, amp[135]); 
  VVV1_0(w[55], w[5], w[10], pars->GC_10, amp[136]); 
  VVV1_0(w[56], w[5], w[10], pars->GC_10, amp[137]); 
  FFV1_0(w[0], w[11], w[57], pars->GC_11, amp[138]); 
  FFV1_0(w[0], w[11], w[58], pars->GC_11, amp[139]); 
  FFV1_0(w[0], w[11], w[59], pars->GC_11, amp[140]); 
  FFV1_0(w[14], w[1], w[57], pars->GC_11, amp[141]); 
  FFV1_0(w[14], w[1], w[58], pars->GC_11, amp[142]); 
  FFV1_0(w[14], w[1], w[59], pars->GC_11, amp[143]); 
  VVV1_0(w[57], w[4], w[10], pars->GC_10, amp[144]); 
  VVV1_0(w[58], w[4], w[10], pars->GC_10, amp[145]); 
  VVV1_0(w[59], w[4], w[10], pars->GC_10, amp[146]); 
  FFV1_0(w[0], w[21], w[60], pars->GC_11, amp[147]); 
  FFV1_0(w[0], w[21], w[61], pars->GC_11, amp[148]); 
  FFV1_0(w[0], w[21], w[62], pars->GC_11, amp[149]); 
  FFV1_0(w[23], w[1], w[60], pars->GC_11, amp[150]); 
  FFV1_0(w[23], w[1], w[61], pars->GC_11, amp[151]); 
  FFV1_0(w[23], w[1], w[62], pars->GC_11, amp[152]); 
  VVV1_0(w[60], w[3], w[10], pars->GC_10, amp[153]); 
  VVV1_0(w[61], w[3], w[10], pars->GC_10, amp[154]); 
  VVV1_0(w[62], w[3], w[10], pars->GC_10, amp[155]); 
  VVV1_0(w[2], w[36], w[10], pars->GC_10, amp[156]); 
  VVV1_0(w[2], w[37], w[10], pars->GC_10, amp[157]); 
  VVV1_0(w[2], w[38], w[10], pars->GC_10, amp[158]); 

}
double P0_Sigma_sm_uux_gggg_qcd_4j::matrix_uux_gggg() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 159; 
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
  jamp[0] = -amp[0] + std::complex<double> (0, 1) * amp[2] - amp[11] -
      std::complex<double> (0, 1) * amp[12] + std::complex<double> (0, 1) *
      amp[13] - std::complex<double> (0, 1) * amp[15] + std::complex<double>
      (0, 1) * amp[16] - amp[55] - std::complex<double> (0, 1) * amp[56] -
      std::complex<double> (0, 1) * amp[63] - amp[64] + amp[67] + amp[71] -
      amp[69] - amp[92] + std::complex<double> (0, 1) * amp[94] -
      std::complex<double> (0, 1) * amp[96] + std::complex<double> (0, 1) *
      amp[97] - std::complex<double> (0, 1) * amp[98] + std::complex<double>
      (0, 1) * amp[120] - std::complex<double> (0, 1) * amp[122] -
      std::complex<double> (0, 1) * amp[124] + amp[134] - amp[132] +
      std::complex<double> (0, 1) * amp[135] - std::complex<double> (0, 1) *
      amp[137] + std::complex<double> (0, 1) * amp[156] - std::complex<double>
      (0, 1) * amp[158];
  jamp[1] = +amp[0] - std::complex<double> (0, 1) * amp[2] - amp[6] -
      std::complex<double> (0, 1) * amp[7] + std::complex<double> (0, 1) *
      amp[14] + std::complex<double> (0, 1) * amp[15] + std::complex<double>
      (0, 1) * amp[17] - amp[58] - std::complex<double> (0, 1) * amp[59] +
      std::complex<double> (0, 1) * amp[63] + amp[64] + amp[65] + amp[70] +
      amp[69] - amp[101] + std::complex<double> (0, 1) * amp[103] -
      std::complex<double> (0, 1) * amp[105] + std::complex<double> (0, 1) *
      amp[106] - std::complex<double> (0, 1) * amp[107] - std::complex<double>
      (0, 1) * amp[120] + std::complex<double> (0, 1) * amp[122] +
      std::complex<double> (0, 1) * amp[124] + amp[143] - amp[141] +
      std::complex<double> (0, 1) * amp[144] - std::complex<double> (0, 1) *
      amp[146] - std::complex<double> (0, 1) * amp[157] - std::complex<double>
      (0, 1) * amp[156];
  jamp[2] = -amp[18] + std::complex<double> (0, 1) * amp[20] - amp[29] -
      std::complex<double> (0, 1) * amp[30] + std::complex<double> (0, 1) *
      amp[31] - std::complex<double> (0, 1) * amp[33] + std::complex<double>
      (0, 1) * amp[34] + amp[55] + std::complex<double> (0, 1) * amp[56] -
      std::complex<double> (0, 1) * amp[57] + amp[58] + amp[68] - amp[71] -
      amp[70] + amp[92] - std::complex<double> (0, 1) * amp[94] +
      std::complex<double> (0, 1) * amp[96] - std::complex<double> (0, 1) *
      amp[97] + std::complex<double> (0, 1) * amp[98] + std::complex<double>
      (0, 1) * amp[104] + std::complex<double> (0, 1) * amp[105] +
      std::complex<double> (0, 1) * amp[107] + amp[133] + amp[132] -
      std::complex<double> (0, 1) * amp[136] - std::complex<double> (0, 1) *
      amp[135] + std::complex<double> (0, 1) * amp[157] + std::complex<double>
      (0, 1) * amp[158];
  jamp[3] = +amp[18] - std::complex<double> (0, 1) * amp[20] - amp[24] -
      std::complex<double> (0, 1) * amp[25] + std::complex<double> (0, 1) *
      amp[32] + std::complex<double> (0, 1) * amp[33] + std::complex<double>
      (0, 1) * amp[35] + std::complex<double> (0, 1) * amp[57] - amp[58] +
      amp[60] - std::complex<double> (0, 1) * amp[62] + amp[64] + amp[70] +
      amp[69] - std::complex<double> (0, 1) * amp[104] - std::complex<double>
      (0, 1) * amp[105] - std::complex<double> (0, 1) * amp[107] - amp[115] +
      std::complex<double> (0, 1) * amp[121] + std::complex<double> (0, 1) *
      amp[122] + std::complex<double> (0, 1) * amp[123] + std::complex<double>
      (0, 1) * amp[124] + amp[152] - amp[150] + std::complex<double> (0, 1) *
      amp[153] - std::complex<double> (0, 1) * amp[155] - std::complex<double>
      (0, 1) * amp[157] - std::complex<double> (0, 1) * amp[156];
  jamp[4] = -amp[36] + std::complex<double> (0, 1) * amp[38] - amp[47] -
      std::complex<double> (0, 1) * amp[48] + std::complex<double> (0, 1) *
      amp[49] - std::complex<double> (0, 1) * amp[51] + std::complex<double>
      (0, 1) * amp[52] - std::complex<double> (0, 1) * amp[54] + amp[55] +
      amp[58] + std::complex<double> (0, 1) * amp[59] + amp[66] - amp[71] -
      amp[70] + std::complex<double> (0, 1) * amp[95] + std::complex<double>
      (0, 1) * amp[96] + std::complex<double> (0, 1) * amp[98] + amp[101] -
      std::complex<double> (0, 1) * amp[103] + std::complex<double> (0, 1) *
      amp[105] - std::complex<double> (0, 1) * amp[106] + std::complex<double>
      (0, 1) * amp[107] + amp[142] + amp[141] - std::complex<double> (0, 1) *
      amp[145] - std::complex<double> (0, 1) * amp[144] + std::complex<double>
      (0, 1) * amp[157] + std::complex<double> (0, 1) * amp[158];
  jamp[5] = +amp[36] - std::complex<double> (0, 1) * amp[38] - amp[42] -
      std::complex<double> (0, 1) * amp[43] + std::complex<double> (0, 1) *
      amp[50] + std::complex<double> (0, 1) * amp[51] + std::complex<double>
      (0, 1) * amp[53] + std::complex<double> (0, 1) * amp[54] - amp[55] +
      amp[61] + std::complex<double> (0, 1) * amp[62] - amp[64] + amp[71] -
      amp[69] - std::complex<double> (0, 1) * amp[95] - std::complex<double>
      (0, 1) * amp[96] - std::complex<double> (0, 1) * amp[98] + amp[115] -
      std::complex<double> (0, 1) * amp[121] - std::complex<double> (0, 1) *
      amp[122] - std::complex<double> (0, 1) * amp[123] - std::complex<double>
      (0, 1) * amp[124] + amp[151] + amp[150] - std::complex<double> (0, 1) *
      amp[154] - std::complex<double> (0, 1) * amp[153] + std::complex<double>
      (0, 1) * amp[156] - std::complex<double> (0, 1) * amp[158];
  jamp[6] = +amp[0] - std::complex<double> (0, 1) * amp[2] + amp[11] +
      std::complex<double> (0, 1) * amp[12] - std::complex<double> (0, 1) *
      amp[13] + std::complex<double> (0, 1) * amp[15] - std::complex<double>
      (0, 1) * amp[16] - amp[21] - std::complex<double> (0, 1) * amp[23] +
      amp[29] - std::complex<double> (0, 1) * amp[31] - std::complex<double>
      (0, 1) * amp[32] - std::complex<double> (0, 1) * amp[34] -
      std::complex<double> (0, 1) * amp[35] - std::complex<double> (0, 1) *
      amp[108] - amp[109] + amp[112] - std::complex<double> (0, 1) * amp[120] -
      std::complex<double> (0, 1) * amp[121] - std::complex<double> (0, 1) *
      amp[123] - amp[134] - amp[133] + std::complex<double> (0, 1) * amp[136] +
      std::complex<double> (0, 1) * amp[137] + amp[149] - amp[147] -
      std::complex<double> (0, 1) * amp[153] + std::complex<double> (0, 1) *
      amp[155];
  jamp[7] = -amp[0] + std::complex<double> (0, 1) * amp[2] + amp[6] +
      std::complex<double> (0, 1) * amp[7] - std::complex<double> (0, 1) *
      amp[14] - std::complex<double> (0, 1) * amp[15] - std::complex<double>
      (0, 1) * amp[17] - amp[39] - std::complex<double> (0, 1) * amp[41] +
      amp[47] - std::complex<double> (0, 1) * amp[49] - std::complex<double>
      (0, 1) * amp[50] - std::complex<double> (0, 1) * amp[52] -
      std::complex<double> (0, 1) * amp[53] + std::complex<double> (0, 1) *
      amp[108] + amp[109] + amp[110] + std::complex<double> (0, 1) * amp[120] +
      std::complex<double> (0, 1) * amp[121] + std::complex<double> (0, 1) *
      amp[123] - amp[143] - amp[142] + std::complex<double> (0, 1) * amp[145] +
      std::complex<double> (0, 1) * amp[146] + amp[148] + amp[147] +
      std::complex<double> (0, 1) * amp[154] + std::complex<double> (0, 1) *
      amp[153];
  jamp[8] = +amp[21] + std::complex<double> (0, 1) * amp[23] - amp[29] +
      std::complex<double> (0, 1) * amp[31] + std::complex<double> (0, 1) *
      amp[32] + std::complex<double> (0, 1) * amp[34] + std::complex<double>
      (0, 1) * amp[35] - amp[37] - std::complex<double> (0, 1) * amp[38] +
      amp[39] - std::complex<double> (0, 1) * amp[40] + std::complex<double>
      (0, 1) * amp[50] + std::complex<double> (0, 1) * amp[51] +
      std::complex<double> (0, 1) * amp[53] + amp[92] - std::complex<double>
      (0, 1) * amp[93] - std::complex<double> (0, 1) * amp[94] -
      std::complex<double> (0, 1) * amp[95] - std::complex<double> (0, 1) *
      amp[97] + amp[113] + amp[133] + amp[132] - std::complex<double> (0, 1) *
      amp[136] - std::complex<double> (0, 1) * amp[135] - amp[149] - amp[148] -
      std::complex<double> (0, 1) * amp[154] - std::complex<double> (0, 1) *
      amp[155];
  jamp[9] = +amp[37] + std::complex<double> (0, 1) * amp[38] - amp[39] +
      std::complex<double> (0, 1) * amp[40] - std::complex<double> (0, 1) *
      amp[50] - std::complex<double> (0, 1) * amp[51] - std::complex<double>
      (0, 1) * amp[53] - std::complex<double> (0, 1) * amp[72] - amp[73] +
      amp[79] - std::complex<double> (0, 1) * amp[80] - amp[82] + amp[89] -
      amp[87] + std::complex<double> (0, 1) * amp[95] + std::complex<double>
      (0, 1) * amp[96] + std::complex<double> (0, 1) * amp[98] + amp[109] +
      std::complex<double> (0, 1) * amp[121] + std::complex<double> (0, 1) *
      amp[122] + std::complex<double> (0, 1) * amp[123] + std::complex<double>
      (0, 1) * amp[124] + amp[148] + amp[147] + std::complex<double> (0, 1) *
      amp[154] + std::complex<double> (0, 1) * amp[153] - std::complex<double>
      (0, 1) * amp[156] + std::complex<double> (0, 1) * amp[158];
  jamp[10] = -amp[19] - std::complex<double> (0, 1) * amp[20] + amp[21] -
      std::complex<double> (0, 1) * amp[22] + std::complex<double> (0, 1) *
      amp[32] + std::complex<double> (0, 1) * amp[33] + std::complex<double>
      (0, 1) * amp[35] + amp[39] + std::complex<double> (0, 1) * amp[41] -
      amp[47] + std::complex<double> (0, 1) * amp[49] + std::complex<double>
      (0, 1) * amp[50] + std::complex<double> (0, 1) * amp[52] +
      std::complex<double> (0, 1) * amp[53] + amp[101] - std::complex<double>
      (0, 1) * amp[102] - std::complex<double> (0, 1) * amp[103] -
      std::complex<double> (0, 1) * amp[104] - std::complex<double> (0, 1) *
      amp[106] + amp[111] + amp[142] + amp[141] - std::complex<double> (0, 1) *
      amp[145] - std::complex<double> (0, 1) * amp[144] - amp[149] - amp[148] -
      std::complex<double> (0, 1) * amp[154] - std::complex<double> (0, 1) *
      amp[155];
  jamp[11] = +amp[19] + std::complex<double> (0, 1) * amp[20] - amp[21] +
      std::complex<double> (0, 1) * amp[22] - std::complex<double> (0, 1) *
      amp[32] - std::complex<double> (0, 1) * amp[33] - std::complex<double>
      (0, 1) * amp[35] - std::complex<double> (0, 1) * amp[75] - amp[76] +
      amp[78] + std::complex<double> (0, 1) * amp[80] + amp[82] + amp[88] +
      amp[87] + std::complex<double> (0, 1) * amp[104] + std::complex<double>
      (0, 1) * amp[105] + std::complex<double> (0, 1) * amp[107] - amp[109] -
      std::complex<double> (0, 1) * amp[121] - std::complex<double> (0, 1) *
      amp[122] - std::complex<double> (0, 1) * amp[123] - std::complex<double>
      (0, 1) * amp[124] + amp[149] - amp[147] - std::complex<double> (0, 1) *
      amp[153] + std::complex<double> (0, 1) * amp[155] + std::complex<double>
      (0, 1) * amp[157] + std::complex<double> (0, 1) * amp[156];
  jamp[12] = -amp[3] - std::complex<double> (0, 1) * amp[5] + amp[11] -
      std::complex<double> (0, 1) * amp[13] - std::complex<double> (0, 1) *
      amp[14] - std::complex<double> (0, 1) * amp[16] - std::complex<double>
      (0, 1) * amp[17] + amp[18] - std::complex<double> (0, 1) * amp[20] +
      amp[29] + std::complex<double> (0, 1) * amp[30] - std::complex<double>
      (0, 1) * amp[31] + std::complex<double> (0, 1) * amp[33] -
      std::complex<double> (0, 1) * amp[34] - amp[99] - std::complex<double>
      (0, 1) * amp[100] - std::complex<double> (0, 1) * amp[103] -
      std::complex<double> (0, 1) * amp[104] - std::complex<double> (0, 1) *
      amp[106] + amp[125] - amp[134] - amp[133] + std::complex<double> (0, 1) *
      amp[136] + std::complex<double> (0, 1) * amp[137] + amp[140] - amp[138] -
      std::complex<double> (0, 1) * amp[144] + std::complex<double> (0, 1) *
      amp[146];
  jamp[13] = -amp[18] + std::complex<double> (0, 1) * amp[20] + amp[24] +
      std::complex<double> (0, 1) * amp[25] - std::complex<double> (0, 1) *
      amp[32] - std::complex<double> (0, 1) * amp[33] - std::complex<double>
      (0, 1) * amp[35] + amp[42] - std::complex<double> (0, 1) * amp[44] -
      amp[45] - std::complex<double> (0, 1) * amp[49] - std::complex<double>
      (0, 1) * amp[50] - std::complex<double> (0, 1) * amp[52] -
      std::complex<double> (0, 1) * amp[53] + amp[99] + std::complex<double>
      (0, 1) * amp[100] + std::complex<double> (0, 1) * amp[103] +
      std::complex<double> (0, 1) * amp[104] + std::complex<double> (0, 1) *
      amp[106] + amp[117] + amp[139] + amp[138] + std::complex<double> (0, 1) *
      amp[145] + std::complex<double> (0, 1) * amp[144] - amp[152] - amp[151] +
      std::complex<double> (0, 1) * amp[154] + std::complex<double> (0, 1) *
      amp[155];
  jamp[14] = +amp[3] + std::complex<double> (0, 1) * amp[5] - amp[11] +
      std::complex<double> (0, 1) * amp[13] + std::complex<double> (0, 1) *
      amp[14] + std::complex<double> (0, 1) * amp[16] + std::complex<double>
      (0, 1) * amp[17] + amp[37] + std::complex<double> (0, 1) * amp[38] +
      amp[45] - std::complex<double> (0, 1) * amp[46] + std::complex<double>
      (0, 1) * amp[49] - std::complex<double> (0, 1) * amp[51] +
      std::complex<double> (0, 1) * amp[52] - amp[92] + std::complex<double>
      (0, 1) * amp[93] + std::complex<double> (0, 1) * amp[94] +
      std::complex<double> (0, 1) * amp[95] + std::complex<double> (0, 1) *
      amp[97] + amp[126] + amp[134] - amp[132] + std::complex<double> (0, 1) *
      amp[135] - std::complex<double> (0, 1) * amp[137] - amp[140] - amp[139] -
      std::complex<double> (0, 1) * amp[145] - std::complex<double> (0, 1) *
      amp[146];
  jamp[15] = -amp[37] - std::complex<double> (0, 1) * amp[38] - amp[45] +
      std::complex<double> (0, 1) * amp[46] - std::complex<double> (0, 1) *
      amp[49] + std::complex<double> (0, 1) * amp[51] - std::complex<double>
      (0, 1) * amp[52] + std::complex<double> (0, 1) * amp[72] + amp[73] +
      amp[76] - std::complex<double> (0, 1) * amp[77] + amp[84] - amp[89] -
      amp[88] - std::complex<double> (0, 1) * amp[95] - std::complex<double>
      (0, 1) * amp[96] - std::complex<double> (0, 1) * amp[98] + amp[99] +
      std::complex<double> (0, 1) * amp[103] - std::complex<double> (0, 1) *
      amp[105] + std::complex<double> (0, 1) * amp[106] - std::complex<double>
      (0, 1) * amp[107] + amp[139] + amp[138] + std::complex<double> (0, 1) *
      amp[145] + std::complex<double> (0, 1) * amp[144] - std::complex<double>
      (0, 1) * amp[157] - std::complex<double> (0, 1) * amp[158];
  jamp[16] = -amp[1] - std::complex<double> (0, 1) * amp[2] + amp[3] -
      std::complex<double> (0, 1) * amp[4] + std::complex<double> (0, 1) *
      amp[14] + std::complex<double> (0, 1) * amp[15] + std::complex<double>
      (0, 1) * amp[17] - amp[42] + std::complex<double> (0, 1) * amp[44] +
      amp[45] + std::complex<double> (0, 1) * amp[49] + std::complex<double>
      (0, 1) * amp[50] + std::complex<double> (0, 1) * amp[52] +
      std::complex<double> (0, 1) * amp[53] - std::complex<double> (0, 1) *
      amp[114] + amp[115] + amp[116] - std::complex<double> (0, 1) * amp[120] -
      std::complex<double> (0, 1) * amp[121] - std::complex<double> (0, 1) *
      amp[123] - amp[140] - amp[139] - std::complex<double> (0, 1) * amp[145] -
      std::complex<double> (0, 1) * amp[146] + amp[151] + amp[150] -
      std::complex<double> (0, 1) * amp[154] - std::complex<double> (0, 1) *
      amp[153];
  jamp[17] = +amp[1] + std::complex<double> (0, 1) * amp[2] - amp[3] +
      std::complex<double> (0, 1) * amp[4] - std::complex<double> (0, 1) *
      amp[14] - std::complex<double> (0, 1) * amp[15] - std::complex<double>
      (0, 1) * amp[17] - amp[76] + std::complex<double> (0, 1) * amp[77] -
      std::complex<double> (0, 1) * amp[81] + amp[82] + amp[83] + amp[88] +
      amp[87] - amp[99] - std::complex<double> (0, 1) * amp[103] +
      std::complex<double> (0, 1) * amp[105] - std::complex<double> (0, 1) *
      amp[106] + std::complex<double> (0, 1) * amp[107] + std::complex<double>
      (0, 1) * amp[120] - std::complex<double> (0, 1) * amp[122] -
      std::complex<double> (0, 1) * amp[124] + amp[140] - amp[138] -
      std::complex<double> (0, 1) * amp[144] + std::complex<double> (0, 1) *
      amp[146] + std::complex<double> (0, 1) * amp[157] + std::complex<double>
      (0, 1) * amp[156];
  jamp[18] = +amp[6] - std::complex<double> (0, 1) * amp[8] - amp[9] -
      std::complex<double> (0, 1) * amp[13] - std::complex<double> (0, 1) *
      amp[14] - std::complex<double> (0, 1) * amp[16] - std::complex<double>
      (0, 1) * amp[17] + amp[36] - std::complex<double> (0, 1) * amp[38] +
      amp[47] + std::complex<double> (0, 1) * amp[48] - std::complex<double>
      (0, 1) * amp[49] + std::complex<double> (0, 1) * amp[51] -
      std::complex<double> (0, 1) * amp[52] - amp[90] - std::complex<double>
      (0, 1) * amp[91] - std::complex<double> (0, 1) * amp[94] -
      std::complex<double> (0, 1) * amp[95] - std::complex<double> (0, 1) *
      amp[97] + amp[128] + amp[131] - amp[129] - std::complex<double> (0, 1) *
      amp[135] + std::complex<double> (0, 1) * amp[137] - amp[143] - amp[142] +
      std::complex<double> (0, 1) * amp[145] + std::complex<double> (0, 1) *
      amp[146];
  jamp[19] = +amp[24] - std::complex<double> (0, 1) * amp[26] - amp[27] -
      std::complex<double> (0, 1) * amp[31] - std::complex<double> (0, 1) *
      amp[32] - std::complex<double> (0, 1) * amp[34] - std::complex<double>
      (0, 1) * amp[35] - amp[36] + std::complex<double> (0, 1) * amp[38] +
      amp[42] + std::complex<double> (0, 1) * amp[43] - std::complex<double>
      (0, 1) * amp[50] - std::complex<double> (0, 1) * amp[51] -
      std::complex<double> (0, 1) * amp[53] + amp[90] + std::complex<double>
      (0, 1) * amp[91] + std::complex<double> (0, 1) * amp[94] +
      std::complex<double> (0, 1) * amp[95] + std::complex<double> (0, 1) *
      amp[97] + amp[119] + amp[130] + amp[129] + std::complex<double> (0, 1) *
      amp[136] + std::complex<double> (0, 1) * amp[135] - amp[152] - amp[151] +
      std::complex<double> (0, 1) * amp[154] + std::complex<double> (0, 1) *
      amp[155];
  jamp[20] = -amp[6] + std::complex<double> (0, 1) * amp[8] + amp[9] +
      std::complex<double> (0, 1) * amp[13] + std::complex<double> (0, 1) *
      amp[14] + std::complex<double> (0, 1) * amp[16] + std::complex<double>
      (0, 1) * amp[17] + amp[19] + std::complex<double> (0, 1) * amp[20] +
      amp[27] - std::complex<double> (0, 1) * amp[28] + std::complex<double>
      (0, 1) * amp[31] - std::complex<double> (0, 1) * amp[33] +
      std::complex<double> (0, 1) * amp[34] - amp[101] + std::complex<double>
      (0, 1) * amp[102] + std::complex<double> (0, 1) * amp[103] +
      std::complex<double> (0, 1) * amp[104] + std::complex<double> (0, 1) *
      amp[106] + amp[127] - amp[131] - amp[130] - std::complex<double> (0, 1) *
      amp[136] - std::complex<double> (0, 1) * amp[137] + amp[143] - amp[141] +
      std::complex<double> (0, 1) * amp[144] - std::complex<double> (0, 1) *
      amp[146];
  jamp[21] = -amp[19] - std::complex<double> (0, 1) * amp[20] - amp[27] +
      std::complex<double> (0, 1) * amp[28] - std::complex<double> (0, 1) *
      amp[31] + std::complex<double> (0, 1) * amp[33] - std::complex<double>
      (0, 1) * amp[34] + amp[73] - std::complex<double> (0, 1) * amp[74] +
      std::complex<double> (0, 1) * amp[75] + amp[76] + amp[86] - amp[89] -
      amp[88] + amp[90] + std::complex<double> (0, 1) * amp[94] -
      std::complex<double> (0, 1) * amp[96] + std::complex<double> (0, 1) *
      amp[97] - std::complex<double> (0, 1) * amp[98] - std::complex<double>
      (0, 1) * amp[104] - std::complex<double> (0, 1) * amp[105] -
      std::complex<double> (0, 1) * amp[107] + amp[130] + amp[129] +
      std::complex<double> (0, 1) * amp[136] + std::complex<double> (0, 1) *
      amp[135] - std::complex<double> (0, 1) * amp[157] - std::complex<double>
      (0, 1) * amp[158];
  jamp[22] = +amp[1] + std::complex<double> (0, 1) * amp[2] + amp[9] -
      std::complex<double> (0, 1) * amp[10] + std::complex<double> (0, 1) *
      amp[13] - std::complex<double> (0, 1) * amp[15] + std::complex<double>
      (0, 1) * amp[16] - amp[24] + std::complex<double> (0, 1) * amp[26] +
      amp[27] + std::complex<double> (0, 1) * amp[31] + std::complex<double>
      (0, 1) * amp[32] + std::complex<double> (0, 1) * amp[34] +
      std::complex<double> (0, 1) * amp[35] + std::complex<double> (0, 1) *
      amp[114] - amp[115] + amp[118] + std::complex<double> (0, 1) * amp[120] +
      std::complex<double> (0, 1) * amp[121] + std::complex<double> (0, 1) *
      amp[123] - amp[131] - amp[130] - std::complex<double> (0, 1) * amp[136] -
      std::complex<double> (0, 1) * amp[137] + amp[152] - amp[150] +
      std::complex<double> (0, 1) * amp[153] - std::complex<double> (0, 1) *
      amp[155];
  jamp[23] = -amp[1] - std::complex<double> (0, 1) * amp[2] - amp[9] +
      std::complex<double> (0, 1) * amp[10] - std::complex<double> (0, 1) *
      amp[13] + std::complex<double> (0, 1) * amp[15] - std::complex<double>
      (0, 1) * amp[16] - amp[73] + std::complex<double> (0, 1) * amp[74] +
      std::complex<double> (0, 1) * amp[81] - amp[82] + amp[85] + amp[89] -
      amp[87] - amp[90] - std::complex<double> (0, 1) * amp[94] +
      std::complex<double> (0, 1) * amp[96] - std::complex<double> (0, 1) *
      amp[97] + std::complex<double> (0, 1) * amp[98] - std::complex<double>
      (0, 1) * amp[120] + std::complex<double> (0, 1) * amp[122] +
      std::complex<double> (0, 1) * amp[124] + amp[131] - amp[129] -
      std::complex<double> (0, 1) * amp[135] + std::complex<double> (0, 1) *
      amp[137] - std::complex<double> (0, 1) * amp[156] + std::complex<double>
      (0, 1) * amp[158];

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



