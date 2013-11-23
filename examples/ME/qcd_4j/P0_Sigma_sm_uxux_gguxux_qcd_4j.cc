//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "P0_Sigma_sm_uxux_gguxux_qcd_4j.h"
#include "HelAmps_sm.h"

using namespace MG5_sm; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: u~ u~ > g g u~ u~ WEIGHTED=4
// Process: c~ c~ > g g c~ c~ WEIGHTED=4
// Process: d~ d~ > g g d~ d~ WEIGHTED=4
// Process: s~ s~ > g g s~ s~ WEIGHTED=4

//--------------------------------------------------------------------------
// Initialize process.

void P0_Sigma_sm_uxux_gguxux_qcd_4j::initProc(string param_card_name) 
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

void P0_Sigma_sm_uxux_gguxux_qcd_4j::sigmaKin() 
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
  const int denominators[nprocesses] = {144}; 

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
        t[0] = matrix_uxux_gguxux(); 

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
      t[0] = matrix_uxux_gguxux(); 

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

double P0_Sigma_sm_uxux_gguxux_qcd_4j::sigmaHat() 
{
  // Select between the different processes
  if(id1 == -3 && id2 == -3)
  {
    // Add matrix elements for processes with beams (-3, -3)
    return matrix_element[0]; 
  }
  else if(id1 == -4 && id2 == -4)
  {
    // Add matrix elements for processes with beams (-4, -4)
    return matrix_element[0]; 
  }
  else if(id1 == -1 && id2 == -1)
  {
    // Add matrix elements for processes with beams (-1, -1)
    return matrix_element[0]; 
  }
  else if(id1 == -2 && id2 == -2)
  {
    // Add matrix elements for processes with beams (-2, -2)
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

void P0_Sigma_sm_uxux_gguxux_qcd_4j::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  oxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]); 
  oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]); 
  vxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]); 
  vxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  ixxxxx(p[perm[4]], mME[4], hel[4], -1, w[4]); 
  ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]); 
  VVV1_1(w[2], w[3], pars->GC_10, pars->ZERO, pars->ZERO, w[6]); 
  FFV1_3(w[4], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[7]); 
  FFV1_1(w[1], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[8]); 
  FFV1_2(w[5], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[9]); 
  FFV1_3(w[5], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[10]); 
  FFV1_3(w[5], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[11]); 
  FFV1_2(w[4], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_3(w[4], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[13]); 
  FFV1_1(w[0], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[14]); 
  FFV1_1(w[0], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[15]); 
  FFV1_1(w[1], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[16]); 
  FFV1_3(w[4], w[15], pars->GC_11, pars->ZERO, pars->ZERO, w[17]); 
  FFV1_3(w[5], w[15], pars->GC_11, pars->ZERO, pars->ZERO, w[18]); 
  FFV1_2(w[4], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[19]); 
  FFV1_2(w[5], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[20]); 
  FFV1_1(w[15], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[21]); 
  FFV1_1(w[1], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[22]); 
  FFV1_1(w[0], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[23]); 
  FFV1_3(w[4], w[22], pars->GC_11, pars->ZERO, pars->ZERO, w[24]); 
  FFV1_3(w[5], w[22], pars->GC_11, pars->ZERO, pars->ZERO, w[25]); 
  FFV1_1(w[22], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[26]); 
  FFV1_2(w[4], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[27]); 
  FFV1_3(w[27], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[28]); 
  FFV1_3(w[27], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[29]); 
  FFV1_2(w[27], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[30]); 
  FFV1_2(w[5], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[31]); 
  FFV1_3(w[31], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[32]); 
  FFV1_3(w[31], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[33]); 
  FFV1_2(w[31], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[34]); 
  FFV1_1(w[23], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[35]); 
  VVV1_1(w[2], w[13], pars->GC_10, pars->ZERO, pars->ZERO, w[36]); 
  VVV1_1(w[2], w[10], pars->GC_10, pars->ZERO, pars->ZERO, w[37]); 
  FFV1_1(w[16], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[38]); 
  VVV1_1(w[2], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[39]); 
  VVV1_1(w[2], w[11], pars->GC_10, pars->ZERO, pars->ZERO, w[40]); 
  FFV1_2(w[19], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[41]); 
  FFV1_2(w[20], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[42]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[5], w[8], w[7], pars->GC_11, amp[0]); 
  FFV1_0(w[9], w[1], w[7], pars->GC_11, amp[1]); 
  VVV1_0(w[6], w[7], w[10], pars->GC_10, amp[2]); 
  FFV1_0(w[4], w[8], w[11], pars->GC_11, amp[3]); 
  FFV1_0(w[12], w[1], w[11], pars->GC_11, amp[4]); 
  VVV1_0(w[6], w[11], w[13], pars->GC_10, amp[5]); 
  FFV1_0(w[5], w[14], w[13], pars->GC_11, amp[6]); 
  FFV1_0(w[9], w[0], w[13], pars->GC_11, amp[7]); 
  FFV1_0(w[4], w[14], w[10], pars->GC_11, amp[8]); 
  FFV1_0(w[12], w[0], w[10], pars->GC_11, amp[9]); 
  FFV1_0(w[5], w[16], w[17], pars->GC_11, amp[10]); 
  FFV1_0(w[4], w[16], w[18], pars->GC_11, amp[11]); 
  FFV1_0(w[19], w[1], w[18], pars->GC_11, amp[12]); 
  FFV1_0(w[19], w[15], w[10], pars->GC_11, amp[13]); 
  FFV1_0(w[20], w[1], w[17], pars->GC_11, amp[14]); 
  FFV1_0(w[20], w[15], w[13], pars->GC_11, amp[15]); 
  FFV1_0(w[5], w[21], w[13], pars->GC_11, amp[16]); 
  VVV1_0(w[3], w[13], w[18], pars->GC_10, amp[17]); 
  FFV1_0(w[4], w[21], w[10], pars->GC_11, amp[18]); 
  VVV1_0(w[3], w[10], w[17], pars->GC_10, amp[19]); 
  FFV1_0(w[5], w[23], w[24], pars->GC_11, amp[20]); 
  FFV1_0(w[4], w[23], w[25], pars->GC_11, amp[21]); 
  FFV1_0(w[19], w[0], w[25], pars->GC_11, amp[22]); 
  FFV1_0(w[19], w[22], w[11], pars->GC_11, amp[23]); 
  FFV1_0(w[20], w[0], w[24], pars->GC_11, amp[24]); 
  FFV1_0(w[20], w[22], w[7], pars->GC_11, amp[25]); 
  FFV1_0(w[5], w[26], w[7], pars->GC_11, amp[26]); 
  VVV1_0(w[3], w[7], w[25], pars->GC_10, amp[27]); 
  FFV1_0(w[4], w[26], w[11], pars->GC_11, amp[28]); 
  VVV1_0(w[3], w[11], w[24], pars->GC_10, amp[29]); 
  FFV1_0(w[5], w[23], w[28], pars->GC_11, amp[30]); 
  FFV1_0(w[27], w[23], w[10], pars->GC_11, amp[31]); 
  FFV1_0(w[5], w[16], w[29], pars->GC_11, amp[32]); 
  FFV1_0(w[27], w[16], w[11], pars->GC_11, amp[33]); 
  FFV1_0(w[20], w[1], w[29], pars->GC_11, amp[34]); 
  FFV1_0(w[20], w[0], w[28], pars->GC_11, amp[35]); 
  FFV1_0(w[30], w[1], w[11], pars->GC_11, amp[36]); 
  VVV1_0(w[3], w[11], w[28], pars->GC_10, amp[37]); 
  FFV1_0(w[30], w[0], w[10], pars->GC_11, amp[38]); 
  VVV1_0(w[3], w[10], w[29], pars->GC_10, amp[39]); 
  FFV1_0(w[4], w[23], w[32], pars->GC_11, amp[40]); 
  FFV1_0(w[31], w[23], w[13], pars->GC_11, amp[41]); 
  FFV1_0(w[4], w[16], w[33], pars->GC_11, amp[42]); 
  FFV1_0(w[31], w[16], w[7], pars->GC_11, amp[43]); 
  FFV1_0(w[19], w[1], w[33], pars->GC_11, amp[44]); 
  FFV1_0(w[19], w[0], w[32], pars->GC_11, amp[45]); 
  FFV1_0(w[34], w[1], w[7], pars->GC_11, amp[46]); 
  VVV1_0(w[3], w[7], w[32], pars->GC_10, amp[47]); 
  FFV1_0(w[34], w[0], w[13], pars->GC_11, amp[48]); 
  VVV1_0(w[3], w[13], w[33], pars->GC_10, amp[49]); 
  FFV1_0(w[5], w[35], w[13], pars->GC_11, amp[50]); 
  FFV1_0(w[5], w[23], w[36], pars->GC_11, amp[51]); 
  FFV1_0(w[4], w[35], w[10], pars->GC_11, amp[52]); 
  FFV1_0(w[4], w[23], w[37], pars->GC_11, amp[53]); 
  FFV1_0(w[5], w[38], w[7], pars->GC_11, amp[54]); 
  FFV1_0(w[5], w[16], w[39], pars->GC_11, amp[55]); 
  FFV1_0(w[4], w[38], w[11], pars->GC_11, amp[56]); 
  FFV1_0(w[4], w[16], w[40], pars->GC_11, amp[57]); 
  FFV1_0(w[41], w[1], w[11], pars->GC_11, amp[58]); 
  FFV1_0(w[19], w[1], w[40], pars->GC_11, amp[59]); 
  FFV1_0(w[41], w[0], w[10], pars->GC_11, amp[60]); 
  FFV1_0(w[19], w[0], w[37], pars->GC_11, amp[61]); 
  FFV1_0(w[42], w[1], w[7], pars->GC_11, amp[62]); 
  FFV1_0(w[20], w[1], w[39], pars->GC_11, amp[63]); 
  FFV1_0(w[42], w[0], w[13], pars->GC_11, amp[64]); 
  FFV1_0(w[20], w[0], w[36], pars->GC_11, amp[65]); 
  VVVV1_0(w[2], w[3], w[7], w[10], pars->GC_12, amp[66]); 
  VVVV3_0(w[2], w[3], w[7], w[10], pars->GC_12, amp[67]); 
  VVVV4_0(w[2], w[3], w[7], w[10], pars->GC_12, amp[68]); 
  VVV1_0(w[3], w[10], w[39], pars->GC_10, amp[69]); 
  VVV1_0(w[3], w[7], w[37], pars->GC_10, amp[70]); 
  VVVV1_0(w[2], w[3], w[11], w[13], pars->GC_12, amp[71]); 
  VVVV3_0(w[2], w[3], w[11], w[13], pars->GC_12, amp[72]); 
  VVVV4_0(w[2], w[3], w[11], w[13], pars->GC_12, amp[73]); 
  VVV1_0(w[3], w[13], w[40], pars->GC_10, amp[74]); 
  VVV1_0(w[3], w[11], w[36], pars->GC_10, amp[75]); 

}
double P0_Sigma_sm_uxux_gguxux_qcd_4j::matrix_uxux_gguxux() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 76; 
  const int ncolor = 12; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; 
  static const double cf[ncolor][ncolor] = {{48, -6, 16, -2, 16, -2, 6, 6, 0,
      -2, 16, 0}, {-6, 48, -2, 16, -2, 16, 6, 6, 0, 16, -2, 0}, {16, -2, 48,
      -6, 6, 6, 16, -2, -2, 0, 0, 16}, {-2, 16, -6, 48, 6, 6, -2, 16, 16, 0, 0,
      -2}, {16, -2, 6, 6, 48, -6, 16, -2, 16, 0, 0, -2}, {-2, 16, 6, 6, -6, 48,
      -2, 16, -2, 0, 0, 16}, {6, 6, 16, -2, 16, -2, 48, -6, 0, 16, -2, 0}, {6,
      6, -2, 16, -2, 16, -6, 48, 0, -2, 16, 0}, {0, 0, -2, 16, 16, -2, 0, 0,
      48, 16, 16, 6}, {-2, 16, 0, 0, 0, 0, 16, -2, 16, 48, 6, 16}, {16, -2, 0,
      0, 0, 0, -2, 16, 16, 6, 48, 16}, {0, 0, 16, -2, -2, 16, 0, 0, 6, 16, 16,
      48}};

  // Calculate color flows
  jamp[0] = +1./2. * (-1./3. * std::complex<double> (0, 1) * amp[0] - 1./3. *
      std::complex<double> (0, 1) * amp[1] - std::complex<double> (0, 1) *
      amp[3] - amp[5] - std::complex<double> (0, 1) * amp[7] + amp[24] + 1./3.
      * amp[25] + 1./3. * amp[26] + amp[28] - std::complex<double> (0, 1) *
      amp[29] + 1./3. * amp[62] + amp[64] + std::complex<double> (0, 1) *
      amp[65] - amp[71] + amp[73] + amp[75]);
  jamp[1] = +1./2. * (+1./3. * std::complex<double> (0, 1) * amp[0] + 1./3. *
      std::complex<double> (0, 1) * amp[1] + std::complex<double> (0, 1) *
      amp[3] + amp[5] + std::complex<double> (0, 1) * amp[7] + amp[42] + 1./3.
      * amp[43] + 1./3. * amp[46] + amp[48] + std::complex<double> (0, 1) *
      amp[49] + 1./3. * amp[54] + amp[56] - std::complex<double> (0, 1) *
      amp[57] + amp[71] + amp[72] + amp[74]);
  jamp[2] = +1./2. * (+std::complex<double> (0, 1) * amp[0] + amp[2] + 1./3. *
      std::complex<double> (0, 1) * amp[3] + 1./3. * std::complex<double> (0,
      1) * amp[4] + std::complex<double> (0, 1) * amp[9] - amp[22] - 1./3. *
      amp[23] - amp[26] + std::complex<double> (0, 1) * amp[27] - 1./3. *
      amp[28] - 1./3. * amp[58] - amp[60] - std::complex<double> (0, 1) *
      amp[61] + amp[66] - amp[68] - amp[70]);
  jamp[3] = +1./2. * (-std::complex<double> (0, 1) * amp[0] - amp[2] - 1./3. *
      std::complex<double> (0, 1) * amp[3] - 1./3. * std::complex<double> (0,
      1) * amp[4] - std::complex<double> (0, 1) * amp[9] - amp[32] - 1./3. *
      amp[33] - 1./3. * amp[36] - amp[38] - std::complex<double> (0, 1) *
      amp[39] - amp[54] + std::complex<double> (0, 1) * amp[55] - 1./3. *
      amp[56] - amp[66] - amp[67] - amp[69]);
  jamp[4] = +1./2. * (+std::complex<double> (0, 1) * amp[1] - amp[2] + 1./3. *
      std::complex<double> (0, 1) * amp[6] + 1./3. * std::complex<double> (0,
      1) * amp[7] + std::complex<double> (0, 1) * amp[8] - amp[14] - 1./3. *
      amp[15] - 1./3. * amp[16] - amp[18] + std::complex<double> (0, 1) *
      amp[19] - amp[62] - std::complex<double> (0, 1) * amp[63] - 1./3. *
      amp[64] - amp[66] - amp[67] - amp[69]);
  jamp[5] = +1./2. * (-std::complex<double> (0, 1) * amp[1] + amp[2] - 1./3. *
      std::complex<double> (0, 1) * amp[6] - 1./3. * std::complex<double> (0,
      1) * amp[7] - std::complex<double> (0, 1) * amp[8] - amp[40] - 1./3. *
      amp[41] - amp[46] - std::complex<double> (0, 1) * amp[47] - 1./3. *
      amp[48] - 1./3. * amp[50] - amp[52] + std::complex<double> (0, 1) *
      amp[53] + amp[66] - amp[68] - amp[70]);
  jamp[6] = +1./2. * (-std::complex<double> (0, 1) * amp[4] + amp[5] -
      std::complex<double> (0, 1) * amp[6] - 1./3. * std::complex<double> (0,
      1) * amp[8] - 1./3. * std::complex<double> (0, 1) * amp[9] + amp[12] +
      1./3. * amp[13] + amp[16] - std::complex<double> (0, 1) * amp[17] + 1./3.
      * amp[18] + amp[58] + std::complex<double> (0, 1) * amp[59] + 1./3. *
      amp[60] + amp[71] + amp[72] + amp[74]);
  jamp[7] = +1./2. * (+std::complex<double> (0, 1) * amp[4] - amp[5] +
      std::complex<double> (0, 1) * amp[6] + 1./3. * std::complex<double> (0,
      1) * amp[8] + 1./3. * std::complex<double> (0, 1) * amp[9] + amp[30] +
      1./3. * amp[31] + amp[36] + std::complex<double> (0, 1) * amp[37] + 1./3.
      * amp[38] + amp[50] - std::complex<double> (0, 1) * amp[51] + 1./3. *
      amp[52] - amp[71] + amp[73] + amp[75]);
  jamp[8] = +1./2. * (+1./3. * amp[10] + amp[11] + 1./3. * amp[14] + amp[15] +
      std::complex<double> (0, 1) * amp[17] + 1./3. * amp[32] + amp[33] + 1./3.
      * amp[34] + amp[35] - std::complex<double> (0, 1) * amp[37] +
      std::complex<double> (0, 1) * amp[57] - std::complex<double> (0, 1) *
      amp[65] - amp[72] - amp[73] - amp[74] - amp[75]);
  jamp[9] = +1./2. * (-amp[10] - 1./3. * amp[11] - 1./3. * amp[12] - amp[13] -
      std::complex<double> (0, 1) * amp[19] - 1./3. * amp[42] - amp[43] - 1./3.
      * amp[44] - amp[45] + std::complex<double> (0, 1) * amp[47] -
      std::complex<double> (0, 1) * amp[55] + std::complex<double> (0, 1) *
      amp[61] + amp[67] + amp[68] + amp[69] + amp[70]);
  jamp[10] = +1./2. * (-1./3. * amp[20] - amp[21] - 1./3. * amp[24] - amp[25] -
      std::complex<double> (0, 1) * amp[27] - 1./3. * amp[30] - amp[31] -
      amp[34] - 1./3. * amp[35] + std::complex<double> (0, 1) * amp[39] -
      std::complex<double> (0, 1) * amp[53] + std::complex<double> (0, 1) *
      amp[63] + amp[67] + amp[68] + amp[69] + amp[70]);
  jamp[11] = +1./2. * (+amp[20] + 1./3. * amp[21] + 1./3. * amp[22] + amp[23] +
      std::complex<double> (0, 1) * amp[29] + 1./3. * amp[40] + amp[41] +
      amp[44] + 1./3. * amp[45] - std::complex<double> (0, 1) * amp[49] +
      std::complex<double> (0, 1) * amp[51] - std::complex<double> (0, 1) *
      amp[59] - amp[72] - amp[73] - amp[74] - amp[75]);

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



