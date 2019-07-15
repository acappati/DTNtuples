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


void doThePlots(TString inputFile, TString outputPathPlots)
{
  // read in file
  TFile *inFile = TFile::Open("results.root");

  // take histos
  TH1F* h_Ph2DigiWithoutPh1        = (TH1F*)inFile->Get("h_Ph2DigiWithoutPh1");
  TH1F* h_Ph2DigiMinusPh1Digi      = (TH1F*)inFile->Get("h_Ph2DigiMinusPh1Digi");
  TH1F* h_Ph2DigiMinusPh1Digi_zoom = (TH1F*)inFile->Get("h_Ph2DigiMinusPh1Digi_zoom");


  // plot histos
  TCanvas* c_Ph2DigiWithoutPh1 = new TCanvas("c_Ph2DigiWithoutPh1","c_Ph2DigiWithoutPh1");
  c_Ph2DigiWithoutPh1->cd();
  h_Ph2DigiWithoutPh1->Draw();
  c_Ph2DigiWithoutPh1->SaveAs(outputPathPlots + "/" + c_Ph2DigiWithoutPh1->GetName() + ".png");

  TCanvas* c_Ph2DigiMinusPh1Digi = new TCanvas("c_Ph2DigiMinusPh1Digi","c_Ph2DigiMinusPh1Digi");
  c_Ph2DigiMinusPh1Digi->cd();
  h_Ph2DigiMinusPh1Digi->Draw();
  c_Ph2DigiMinusPh1Digi->SaveAs(outputPathPlots + "/" + c_Ph2DigiMinusPh1Digi->GetName() + ".png");

  TCanvas* c_Ph2DigiMinusPh1Digi_zoom = new TCanvas("c_Ph2DigiMinusPh1Digi_zoom","c_Ph2DigiMinusPh1Digi_zoom");
  c_Ph2DigiMinusPh1Digi_zoom->cd();
  h_Ph2DigiMinusPh1Digi_zoom->Draw();
  c_Ph2DigiMinusPh1Digi_zoom->SaveAs(outputPathPlots + "/" + c_Ph2DigiMinusPh1Digi_zoom->GetName() + ".png");
  
  

   
  
 
  cout<<" Plots done =) "<<endl;

}


void Plotter()
{

  TString inputFile = "results.root";

  // define output directory
  TString outputPathPlots = "~/www/DTDPG/190715_plots";
  gSystem->Exec("mkdir -p "+outputPathPlots);

  // call funciton for plots
  doThePlots(inputFile, outputPathPlots);  

}
