// *****************************************************
//
// author: Alessandra Cappati
//         12/07/2019
// 
// usage: specify the input files, 
//        the output directory, and other options 
//        at the end of the script
//
// run with:
//        root -l -b -q Plotter.C++
//
// *****************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

#include "TString.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TTree.h"
#include "TAxis.h"
#include "TF1.h"
#include "TGraph.h"
#include "TLine.h"
#include "TPaveText.h"
#include "TRandom3.h"
#include "TPaveText.h"


void doThePlots(){
 
 

}


void Plotter(){

  TString inputFile = "results.root";

  // define output directory
  TString outputPathPlots = "190712_plots";
  gSystem->Exec("mkdir -p "+outputPathPlots);

  

}
