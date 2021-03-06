//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "P0_Sigma_sm_uux_uuuxux_qcd_4j.h"
#include "HelAmps_sm.h"

using namespace MG5_sm; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: u u~ > u u u~ u~ WEIGHTED=4
// Process: c c~ > c c c~ c~ WEIGHTED=4
// Process: d d~ > d d d~ d~ WEIGHTED=4
// Process: s s~ > s s s~ s~ WEIGHTED=4

//--------------------------------------------------------------------------
// Initialize process.

void P0_Sigma_sm_uux_uuuxux_qcd_4j::initProc(string param_card_name) 
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
  jamp2[0] = new double[6]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void P0_Sigma_sm_uux_uuuxux_qcd_4j::sigmaKin() 
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
  for(int i = 0; i < 6; i++ )
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
  const int denominators[nprocesses] = {144, 144}; 

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
        t[0] = matrix_uux_uuuxux(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_uux_uuuxux(); 
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
      t[0] = matrix_uux_uuuxux(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_uux_uuuxux(); 
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

double P0_Sigma_sm_uux_uuuxux_qcd_4j::sigmaHat() 
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

void P0_Sigma_sm_uux_uuuxux_qcd_4j::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  ixxxxx(p[perm[0]], mME[0], hel[0], +1, w[0]); 
  oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]); 
  oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]); 
  oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  ixxxxx(p[perm[4]], mME[4], hel[4], -1, w[4]); 
  ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]); 
  FFV1_3(w[0], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[6]); 
  FFV1_3(w[4], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[7]); 
  FFV1_1(w[3], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[8]); 
  FFV1_2(w[5], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[9]); 
  FFV1_3(w[5], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[10]); 
  FFV1_3(w[4], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[11]); 
  FFV1_1(w[2], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_3(w[5], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[13]); 
  FFV1_2(w[4], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[14]); 
  FFV1_3(w[0], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[15]); 
  FFV1_3(w[4], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[16]); 
  FFV1_1(w[3], w[15], pars->GC_11, pars->ZERO, pars->ZERO, w[17]); 
  FFV1_2(w[5], w[15], pars->GC_11, pars->ZERO, pars->ZERO, w[18]); 
  FFV1_1(w[1], w[15], pars->GC_11, pars->ZERO, pars->ZERO, w[19]); 
  FFV1_3(w[5], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[20]); 
  FFV1_2(w[4], w[15], pars->GC_11, pars->ZERO, pars->ZERO, w[21]); 
  FFV1_3(w[0], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[22]); 
  FFV1_1(w[2], w[22], pars->GC_11, pars->ZERO, pars->ZERO, w[23]); 
  FFV1_2(w[5], w[22], pars->GC_11, pars->ZERO, pars->ZERO, w[24]); 
  FFV1_1(w[1], w[22], pars->GC_11, pars->ZERO, pars->ZERO, w[25]); 
  FFV1_2(w[4], w[22], pars->GC_11, pars->ZERO, pars->ZERO, w[26]); 
  FFV1_2(w[0], w[16], pars->GC_11, pars->ZERO, pars->ZERO, w[27]); 
  FFV1_2(w[0], w[13], pars->GC_11, pars->ZERO, pars->ZERO, w[28]); 
  FFV1_2(w[0], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[29]); 
  FFV1_2(w[0], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[30]); 
  FFV1_2(w[0], w[20], pars->GC_11, pars->ZERO, pars->ZERO, w[31]); 
  FFV1_2(w[0], w[11], pars->GC_11, pars->ZERO, pars->ZERO, w[32]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[5], w[8], w[7], pars->GC_11, amp[0]); 
  FFV1_0(w[9], w[3], w[7], pars->GC_11, amp[1]); 
  VVV1_0(w[6], w[7], w[10], pars->GC_10, amp[2]); 
  FFV1_0(w[5], w[12], w[11], pars->GC_11, amp[3]); 
  FFV1_0(w[9], w[2], w[11], pars->GC_11, amp[4]); 
  VVV1_0(w[6], w[11], w[13], pars->GC_10, amp[5]); 
  FFV1_0(w[14], w[3], w[13], pars->GC_11, amp[6]); 
  FFV1_0(w[4], w[8], w[13], pars->GC_11, amp[7]); 
  FFV1_0(w[14], w[2], w[10], pars->GC_11, amp[8]); 
  FFV1_0(w[4], w[12], w[10], pars->GC_11, amp[9]); 
  FFV1_0(w[5], w[17], w[16], pars->GC_11, amp[10]); 
  FFV1_0(w[18], w[3], w[16], pars->GC_11, amp[11]); 
  VVV1_0(w[15], w[16], w[10], pars->GC_10, amp[12]); 
  FFV1_0(w[5], w[19], w[11], pars->GC_11, amp[13]); 
  FFV1_0(w[18], w[1], w[11], pars->GC_11, amp[14]); 
  VVV1_0(w[15], w[11], w[20], pars->GC_10, amp[15]); 
  FFV1_0(w[21], w[3], w[20], pars->GC_11, amp[16]); 
  FFV1_0(w[4], w[17], w[20], pars->GC_11, amp[17]); 
  FFV1_0(w[21], w[1], w[10], pars->GC_11, amp[18]); 
  FFV1_0(w[4], w[19], w[10], pars->GC_11, amp[19]); 
  FFV1_0(w[5], w[23], w[16], pars->GC_11, amp[20]); 
  FFV1_0(w[24], w[2], w[16], pars->GC_11, amp[21]); 
  VVV1_0(w[22], w[16], w[13], pars->GC_10, amp[22]); 
  FFV1_0(w[5], w[25], w[7], pars->GC_11, amp[23]); 
  FFV1_0(w[24], w[1], w[7], pars->GC_11, amp[24]); 
  VVV1_0(w[22], w[7], w[20], pars->GC_10, amp[25]); 
  FFV1_0(w[26], w[2], w[20], pars->GC_11, amp[26]); 
  FFV1_0(w[4], w[23], w[20], pars->GC_11, amp[27]); 
  FFV1_0(w[26], w[1], w[13], pars->GC_11, amp[28]); 
  FFV1_0(w[4], w[25], w[13], pars->GC_11, amp[29]); 
  FFV1_0(w[27], w[3], w[13], pars->GC_11, amp[30]); 
  FFV1_0(w[28], w[3], w[16], pars->GC_11, amp[31]); 
  FFV1_0(w[27], w[2], w[10], pars->GC_11, amp[32]); 
  FFV1_0(w[29], w[2], w[16], pars->GC_11, amp[33]); 
  FFV1_0(w[30], w[3], w[20], pars->GC_11, amp[34]); 
  FFV1_0(w[31], w[3], w[7], pars->GC_11, amp[35]); 
  FFV1_0(w[30], w[1], w[10], pars->GC_11, amp[36]); 
  FFV1_0(w[29], w[1], w[7], pars->GC_11, amp[37]); 
  FFV1_0(w[32], w[2], w[20], pars->GC_11, amp[38]); 
  FFV1_0(w[31], w[2], w[11], pars->GC_11, amp[39]); 
  FFV1_0(w[32], w[1], w[13], pars->GC_11, amp[40]); 
  FFV1_0(w[28], w[1], w[11], pars->GC_11, amp[41]); 

}
double P0_Sigma_sm_uux_uuuxux_qcd_4j::matrix_uux_uuuxux() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 42; 
  const int ncolor = 6; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {1, 1, 1, 1, 1, 1}; 
  static const double cf[ncolor][ncolor] = {{27, 9, 9, 3, 3, 9}, {9, 27, 3, 9,
      9, 3}, {9, 3, 27, 9, 9, 3}, {3, 9, 9, 27, 3, 9}, {3, 9, 9, 3, 27, 9}, {9,
      3, 3, 9, 9, 27}};

  // Calculate color flows
  jamp[0] = +1./4. * (-1./9. * amp[0] - 1./9. * amp[1] - 1./3. * amp[3] - 1./3.
      * amp[4] - 1./3. * amp[6] - 1./3. * amp[7] - 1./9. * amp[8] - 1./9. *
      amp[9] - amp[13] + std::complex<double> (0, 1) * amp[15] - amp[16] -
      1./3. * amp[18] - 1./3. * amp[19] - amp[21] - std::complex<double> (0, 1)
      * amp[22] - 1./3. * amp[23] - 1./3. * amp[24] - amp[29] - amp[30] - 1./3.
      * amp[32] - 1./3. * amp[33] - 1./3. * amp[34] - 1./3. * amp[35] - 1./9. *
      amp[36] - 1./9. * amp[37] - amp[39]);
  jamp[1] = +1./4. * (+1./3. * amp[0] + 1./3. * amp[1] + 1./9. * amp[3] + 1./9.
      * amp[4] + 1./9. * amp[6] + 1./9. * amp[7] + 1./3. * amp[8] + 1./3. *
      amp[9] + amp[11] + std::complex<double> (0, 1) * amp[12] + 1./3. *
      amp[13] + 1./3. * amp[14] + amp[19] + amp[23] - std::complex<double> (0,
      1) * amp[25] + amp[26] + 1./3. * amp[28] + 1./3. * amp[29] + 1./3. *
      amp[30] + 1./3. * amp[31] + amp[32] + amp[35] + 1./3. * amp[38] + 1./3. *
      amp[39] + 1./9. * amp[40] + 1./9. * amp[41]);
  jamp[2] = +1./4. * (+amp[3] - std::complex<double> (0, 1) * amp[5] + amp[6] +
      1./3. * amp[8] + 1./3. * amp[9] + 1./9. * amp[10] + 1./9. * amp[11] +
      1./3. * amp[13] + 1./3. * amp[14] + 1./3. * amp[16] + 1./3. * amp[17] +
      1./9. * amp[18] + 1./9. * amp[19] + 1./3. * amp[20] + 1./3. * amp[21] +
      amp[24] + std::complex<double> (0, 1) * amp[25] + amp[27] + 1./3. *
      amp[30] + 1./3. * amp[31] + 1./9. * amp[32] + 1./9. * amp[33] + amp[34] +
      1./3. * amp[36] + 1./3. * amp[37] + amp[41]);
  jamp[3] = +1./4. * (-amp[0] + std::complex<double> (0, 1) * amp[2] - 1./3. *
      amp[6] - 1./3. * amp[7] - amp[8] - 1./3. * amp[10] - 1./3. * amp[11] -
      amp[14] - std::complex<double> (0, 1) * amp[15] - amp[17] - 1./9. *
      amp[20] - 1./9. * amp[21] - 1./3. * amp[23] - 1./3. * amp[24] - 1./3. *
      amp[26] - 1./3. * amp[27] - 1./9. * amp[28] - 1./9. * amp[29] - 1./9. *
      amp[30] - 1./9. * amp[31] - 1./3. * amp[32] - 1./3. * amp[33] - amp[37] -
      amp[38] - 1./3. * amp[40] - 1./3. * amp[41]);
  jamp[4] = +1./4. * (-amp[1] - std::complex<double> (0, 1) * amp[2] - 1./3. *
      amp[3] - 1./3. * amp[4] - amp[9] - 1./3. * amp[10] - 1./3. * amp[11] -
      1./9. * amp[13] - 1./9. * amp[14] - 1./9. * amp[16] - 1./9. * amp[17] -
      1./3. * amp[18] - 1./3. * amp[19] - amp[20] + std::complex<double> (0, 1)
      * amp[22] - 1./3. * amp[26] - 1./3. * amp[27] - amp[28] - amp[31] - 1./3.
      * amp[34] - 1./3. * amp[35] - amp[36] - 1./9. * amp[38] - 1./9. * amp[39]
      - 1./3. * amp[40] - 1./3. * amp[41]);
  jamp[5] = +1./4. * (+1./3. * amp[0] + 1./3. * amp[1] + amp[4] +
      std::complex<double> (0, 1) * amp[5] + amp[7] + amp[10] -
      std::complex<double> (0, 1) * amp[12] + 1./3. * amp[16] + 1./3. * amp[17]
      + amp[18] + 1./3. * amp[20] + 1./3. * amp[21] + 1./9. * amp[23] + 1./9. *
      amp[24] + 1./9. * amp[26] + 1./9. * amp[27] + 1./3. * amp[28] + 1./3. *
      amp[29] + amp[33] + 1./9. * amp[34] + 1./9. * amp[35] + 1./3. * amp[36] +
      1./3. * amp[37] + 1./3. * amp[38] + 1./3. * amp[39] + amp[40]);

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



