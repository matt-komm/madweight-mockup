//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "P0_Sigma_sm_gu_guccx_qcd_4j.h"
#include "HelAmps_sm.h"

using namespace MG5_sm; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g u > g u c c~ WEIGHTED=4
// Process: g u > g u d d~ WEIGHTED=4
// Process: g u > g u s s~ WEIGHTED=4
// Process: g c > g c u u~ WEIGHTED=4
// Process: g c > g c d d~ WEIGHTED=4
// Process: g c > g c s s~ WEIGHTED=4
// Process: g d > g d u u~ WEIGHTED=4
// Process: g d > g d c c~ WEIGHTED=4
// Process: g d > g d s s~ WEIGHTED=4
// Process: g s > g s u u~ WEIGHTED=4
// Process: g s > g s c c~ WEIGHTED=4
// Process: g s > g s d d~ WEIGHTED=4

//--------------------------------------------------------------------------
// Initialize process.

void P0_Sigma_sm_gu_guccx_qcd_4j::initProc(string param_card_name) 
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
  jamp2[0] = new double[12]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void P0_Sigma_sm_gu_guccx_qcd_4j::sigmaKin() 
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
  const int denominators[nprocesses] = {96, 96}; 

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
        t[0] = matrix_gu_guccx(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_gu_guccx(); 
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
      t[0] = matrix_gu_guccx(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_gu_guccx(); 
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

double P0_Sigma_sm_gu_guccx_qcd_4j::sigmaHat() 
{
  // Select between the different processes
  if(id1 == 1 && id2 == 21)
  {
    // Add matrix elements for processes with beams (1, 21)
    return matrix_element[1] * 3; 
  }
  else if(id1 == 21 && id2 == 1)
  {
    // Add matrix elements for processes with beams (21, 1)
    return matrix_element[0] * 3; 
  }
  else if(id1 == 2 && id2 == 21)
  {
    // Add matrix elements for processes with beams (2, 21)
    return matrix_element[1] * 3; 
  }
  else if(id1 == 21 && id2 == 2)
  {
    // Add matrix elements for processes with beams (21, 2)
    return matrix_element[0] * 3; 
  }
  else if(id1 == 21 && id2 == 3)
  {
    // Add matrix elements for processes with beams (21, 3)
    return matrix_element[0] * 3; 
  }
  else if(id1 == 21 && id2 == 4)
  {
    // Add matrix elements for processes with beams (21, 4)
    return matrix_element[0] * 3; 
  }
  else if(id1 == 4 && id2 == 21)
  {
    // Add matrix elements for processes with beams (4, 21)
    return matrix_element[1] * 3; 
  }
  else if(id1 == 3 && id2 == 21)
  {
    // Add matrix elements for processes with beams (3, 21)
    return matrix_element[1] * 3; 
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

void P0_Sigma_sm_gu_guccx_qcd_4j::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  vxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]); 
  ixxxxx(p[perm[1]], mME[1], hel[1], +1, w[1]); 
  vxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]); 
  oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  oxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]); 
  ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]); 
  VVV1_1(w[0], w[2], pars->GC_10, pars->ZERO, pars->ZERO, w[6]); 
  FFV1_3(w[1], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[7]); 
  FFV1_1(w[4], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[8]); 
  FFV1_2(w[5], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[9]); 
  FFV1_3(w[5], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[10]); 
  FFV1_1(w[3], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[11]); 
  FFV1_2(w[1], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_1(w[3], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[13]); 
  FFV1_1(w[4], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[14]); 
  FFV1_3(w[1], w[13], pars->GC_11, pars->ZERO, pars->ZERO, w[15]); 
  FFV1_2(w[1], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[16]); 
  FFV1_2(w[5], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[17]); 
  FFV1_1(w[13], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[18]); 
  FFV1_1(w[4], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[19]); 
  FFV1_1(w[3], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[20]); 
  FFV1_3(w[5], w[19], pars->GC_11, pars->ZERO, pars->ZERO, w[21]); 
  FFV1_1(w[19], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[22]); 
  FFV1_2(w[1], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[23]); 
  FFV1_3(w[23], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[24]); 
  FFV1_2(w[23], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[25]); 
  FFV1_2(w[5], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[26]); 
  FFV1_3(w[26], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[27]); 
  FFV1_2(w[26], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[28]); 
  FFV1_1(w[20], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[29]); 
  VVV1_1(w[0], w[10], pars->GC_10, pars->ZERO, pars->ZERO, w[30]); 
  FFV1_1(w[14], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[31]); 
  VVV1_1(w[0], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[32]); 
  FFV1_2(w[16], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[33]); 
  FFV1_2(w[17], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[34]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[5], w[8], w[7], pars->GC_11, amp[0]); 
  FFV1_0(w[9], w[4], w[7], pars->GC_11, amp[1]); 
  VVV1_0(w[6], w[7], w[10], pars->GC_10, amp[2]); 
  FFV1_0(w[1], w[11], w[10], pars->GC_11, amp[3]); 
  FFV1_0(w[12], w[3], w[10], pars->GC_11, amp[4]); 
  FFV1_0(w[5], w[14], w[15], pars->GC_11, amp[5]); 
  FFV1_0(w[16], w[13], w[10], pars->GC_11, amp[6]); 
  FFV1_0(w[17], w[4], w[15], pars->GC_11, amp[7]); 
  FFV1_0(w[1], w[18], w[10], pars->GC_11, amp[8]); 
  VVV1_0(w[2], w[10], w[15], pars->GC_10, amp[9]); 
  FFV1_0(w[1], w[20], w[21], pars->GC_11, amp[10]); 
  FFV1_0(w[16], w[3], w[21], pars->GC_11, amp[11]); 
  FFV1_0(w[17], w[19], w[7], pars->GC_11, amp[12]); 
  FFV1_0(w[5], w[22], w[7], pars->GC_11, amp[13]); 
  VVV1_0(w[2], w[7], w[21], pars->GC_10, amp[14]); 
  FFV1_0(w[23], w[20], w[10], pars->GC_11, amp[15]); 
  FFV1_0(w[5], w[14], w[24], pars->GC_11, amp[16]); 
  FFV1_0(w[17], w[4], w[24], pars->GC_11, amp[17]); 
  FFV1_0(w[25], w[3], w[10], pars->GC_11, amp[18]); 
  VVV1_0(w[2], w[10], w[24], pars->GC_10, amp[19]); 
  FFV1_0(w[1], w[20], w[27], pars->GC_11, amp[20]); 
  FFV1_0(w[26], w[14], w[7], pars->GC_11, amp[21]); 
  FFV1_0(w[16], w[3], w[27], pars->GC_11, amp[22]); 
  FFV1_0(w[28], w[4], w[7], pars->GC_11, amp[23]); 
  VVV1_0(w[2], w[7], w[27], pars->GC_10, amp[24]); 
  FFV1_0(w[1], w[29], w[10], pars->GC_11, amp[25]); 
  FFV1_0(w[1], w[20], w[30], pars->GC_11, amp[26]); 
  FFV1_0(w[5], w[31], w[7], pars->GC_11, amp[27]); 
  FFV1_0(w[5], w[14], w[32], pars->GC_11, amp[28]); 
  FFV1_0(w[33], w[3], w[10], pars->GC_11, amp[29]); 
  FFV1_0(w[16], w[3], w[30], pars->GC_11, amp[30]); 
  FFV1_0(w[34], w[4], w[7], pars->GC_11, amp[31]); 
  FFV1_0(w[17], w[4], w[32], pars->GC_11, amp[32]); 
  VVVV1_0(w[0], w[2], w[7], w[10], pars->GC_12, amp[33]); 
  VVVV3_0(w[0], w[2], w[7], w[10], pars->GC_12, amp[34]); 
  VVVV4_0(w[0], w[2], w[7], w[10], pars->GC_12, amp[35]); 
  VVV1_0(w[2], w[10], w[32], pars->GC_10, amp[36]); 
  VVV1_0(w[2], w[7], w[30], pars->GC_10, amp[37]); 

}
double P0_Sigma_sm_gu_guccx_qcd_4j::matrix_gu_guccx() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 38; 
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
  jamp[0] = +1./2. * (-1./3. * std::complex<double> (0, 1) * amp[3] - 1./3. *
      std::complex<double> (0, 1) * amp[4] + 1./3. * amp[6] + 1./3. * amp[8] +
      1./3. * amp[29]);
  jamp[1] = +1./2. * (+std::complex<double> (0, 1) * amp[1] - amp[2] +
      std::complex<double> (0, 1) * amp[3] - amp[7] - amp[8] +
      std::complex<double> (0, 1) * amp[9] - amp[31] - std::complex<double> (0,
      1) * amp[32] - amp[33] - amp[34] - amp[36]);
  jamp[2] = +1./2. * (+std::complex<double> (0, 1) * amp[0] + amp[2] +
      std::complex<double> (0, 1) * amp[4] - amp[11] - amp[13] +
      std::complex<double> (0, 1) * amp[14] - amp[29] - std::complex<double>
      (0, 1) * amp[30] + amp[33] - amp[35] - amp[37]);
  jamp[3] = +1./2. * (-1./3. * std::complex<double> (0, 1) * amp[0] - 1./3. *
      std::complex<double> (0, 1) * amp[1] + 1./3. * amp[12] + 1./3. * amp[13]
      + 1./3. * amp[31]);
  jamp[4] = +1./2. * (+1./3. * amp[5] + 1./3. * amp[7] + 1./3. * amp[16] +
      1./3. * amp[17]);
  jamp[5] = +1./2. * (-amp[5] - amp[6] - std::complex<double> (0, 1) * amp[9] -
      amp[21] - amp[22] + std::complex<double> (0, 1) * amp[24] -
      std::complex<double> (0, 1) * amp[28] + std::complex<double> (0, 1) *
      amp[30] + amp[34] + amp[35] + amp[36] + amp[37]);
  jamp[6] = +1./2. * (-amp[10] - amp[12] - std::complex<double> (0, 1) *
      amp[14] - amp[15] - amp[17] + std::complex<double> (0, 1) * amp[19] -
      std::complex<double> (0, 1) * amp[26] + std::complex<double> (0, 1) *
      amp[32] + amp[34] + amp[35] + amp[36] + amp[37]);
  jamp[7] = +1./2. * (+1./3. * amp[10] + 1./3. * amp[11] + 1./3. * amp[20] +
      1./3. * amp[22]);
  jamp[8] = +1./2. * (+1./3. * std::complex<double> (0, 1) * amp[3] + 1./3. *
      std::complex<double> (0, 1) * amp[4] + 1./3. * amp[15] + 1./3. * amp[18]
      + 1./3. * amp[25]);
  jamp[9] = +1./2. * (-std::complex<double> (0, 1) * amp[1] + amp[2] -
      std::complex<double> (0, 1) * amp[3] - amp[20] - amp[23] -
      std::complex<double> (0, 1) * amp[24] - amp[25] + std::complex<double>
      (0, 1) * amp[26] + amp[33] - amp[35] - amp[37]);
  jamp[10] = +1./2. * (-std::complex<double> (0, 1) * amp[0] - amp[2] -
      std::complex<double> (0, 1) * amp[4] - amp[16] - amp[18] -
      std::complex<double> (0, 1) * amp[19] - amp[27] + std::complex<double>
      (0, 1) * amp[28] - amp[33] - amp[34] - amp[36]);
  jamp[11] = +1./2. * (+1./3. * std::complex<double> (0, 1) * amp[0] + 1./3. *
      std::complex<double> (0, 1) * amp[1] + 1./3. * amp[21] + 1./3. * amp[23]
      + 1./3. * amp[27]);

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



