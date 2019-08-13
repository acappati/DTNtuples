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
#include "TEfficiency.h"


void doThePlots(TString inputFile, TString outputPathPlots)
{
  // read in file
  TFile *inFile = TFile::Open("results.root");

  // take histos
  TH1F* h_timeBoxPh1               = (TH1F*)inFile->Get("h_timeBoxPh1");
  TH1F* h_timeBoxPh2               = (TH1F*)inFile->Get("h_timeBoxPh2");
  TH1F* h_Ph2DigiWithoutPh1        = (TH1F*)inFile->Get("h_Ph2DigiWithoutPh1");
  TH1F* h_Ph2DigiMinusPh1Digi      = (TH1F*)inFile->Get("h_Ph2DigiMinusPh1Digi");
  TH1F* h_Ph2DigiMinusPh1Digi_zoom = (TH1F*)inFile->Get("h_Ph2DigiMinusPh1Digi_zoom");
  TH1F* h_Ph2DigiMinusPh1Digi_min  = (TH1F*)inFile->Get("h_Ph2DigiMinusPh1Digi_min");
  
  TH2F* h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1 = (TH2F*)inFile->Get("h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1");
  TH2F* h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2 = (TH2F*)inFile->Get("h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2");
  TH2F* h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3 = (TH2F*)inFile->Get("h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3");

  TH2F* h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1 = (TH2F*)inFile->Get("h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1");
  TH2F* h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2 = (TH2F*)inFile->Get("h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2");
  TH2F* h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3 = (TH2F*)inFile->Get("h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3");

  TEfficiency* eff2_Ph2DigiMatching = (TEfficiency*)inFile->Get("eff2_Ph2DigiMatching");


  // plot histos

  // --- time boxes
  TCanvas* c_timeBoxPh1 = new TCanvas("c_timeBoxPh1","c_timeBoxPh1");
  c_timeBoxPh1->cd();
  h_timeBoxPh1->Draw();
  c_timeBoxPh1->SaveAs(outputPathPlots + "/" + c_timeBoxPh1->GetName() + ".png");

  TCanvas* c_timeBoxPh2 = new TCanvas("c_timeBoxPh2","c_timeBoxPh2");
  c_timeBoxPh2->cd();
  h_timeBoxPh2->Draw();
  c_timeBoxPh2->SaveAs(outputPathPlots + "/" + c_timeBoxPh2->GetName() + ".png");


  // --- ph2 digi with no correspondence in ph1
  TCanvas* c_Ph2DigiWithoutPh1 = new TCanvas("c_Ph2DigiWithoutPh1","c_Ph2DigiWithoutPh1");
  c_Ph2DigiWithoutPh1->cd();
  h_Ph2DigiWithoutPh1->Draw();
  c_Ph2DigiWithoutPh1->SaveAs(outputPathPlots + "/" + c_Ph2DigiWithoutPh1->GetName() + ".png");

  TCanvas* c_Ph2DigiWithoutPh1_log = new TCanvas("c_Ph2DigiWithoutPh1_log","c_Ph2DigiWithoutPh1_log");
  c_Ph2DigiWithoutPh1_log->cd();
  c_Ph2DigiWithoutPh1_log->SetLogy();
  h_Ph2DigiWithoutPh1->Draw();
  c_Ph2DigiWithoutPh1_log->SaveAs(outputPathPlots + "/" + c_Ph2DigiWithoutPh1_log->GetName() + ".png");


  // --- ph2 - ph1 digi
  TCanvas* c_Ph2DigiMinusPh1Digi = new TCanvas("c_Ph2DigiMinusPh1Digi","c_Ph2DigiMinusPh1Digi");
  c_Ph2DigiMinusPh1Digi->cd();
  h_Ph2DigiMinusPh1Digi->Draw();
  c_Ph2DigiMinusPh1Digi->SaveAs(outputPathPlots + "/" + c_Ph2DigiMinusPh1Digi->GetName() + ".png");

  TCanvas* c_Ph2DigiMinusPh1Digi_log = new TCanvas("c_Ph2DigiMinusPh1Digi_log","c_Ph2DigiMinusPh1Digi_log");
  c_Ph2DigiMinusPh1Digi_log->cd();
  c_Ph2DigiMinusPh1Digi_log->SetLogy();
  h_Ph2DigiMinusPh1Digi->Draw();
  c_Ph2DigiMinusPh1Digi_log->SaveAs(outputPathPlots + "/" + c_Ph2DigiMinusPh1Digi_log->GetName() + ".png");


  // --- ph2 - ph1 digi zoom
  TCanvas* c_Ph2DigiMinusPh1Digi_zoom = new TCanvas("c_Ph2DigiMinusPh1Digi_zoom","c_Ph2DigiMinusPh1Digi_zoom");
  c_Ph2DigiMinusPh1Digi_zoom->cd();
  h_Ph2DigiMinusPh1Digi_zoom->Draw();
  c_Ph2DigiMinusPh1Digi_zoom->SaveAs(outputPathPlots + "/" + c_Ph2DigiMinusPh1Digi_zoom->GetName() + ".png");

  TCanvas* c_Ph2DigiMinusPh1Digi_zoom_log = new TCanvas("c_Ph2DigiMinusPh1Digi_zoom_log","c_Ph2DigiMinusPh1Digi_zoom_log");
  c_Ph2DigiMinusPh1Digi_zoom_log->cd();
  c_Ph2DigiMinusPh1Digi_zoom_log->SetLogy();
  h_Ph2DigiMinusPh1Digi_zoom->Draw();
  c_Ph2DigiMinusPh1Digi_zoom_log->SaveAs(outputPathPlots + "/" + c_Ph2DigiMinusPh1Digi_zoom_log->GetName() + ".png");


  // --- ph2 - ph1 digi min diff
  TCanvas* c_Ph2DigiMinusPh1Digi_min = new TCanvas("c_Ph2DigiMinusPh1Digi_min","c_Ph2DigiMinusPh1Digi_min");
  c_Ph2DigiMinusPh1Digi_min->cd();
  h_Ph2DigiMinusPh1Digi_min->Draw();
  c_Ph2DigiMinusPh1Digi_min->SaveAs(outputPathPlots + "/" + c_Ph2DigiMinusPh1Digi_min->GetName() + ".png");

  TCanvas* c_Ph2DigiMinusPh1Digi_min_log = new TCanvas("c_Ph2DigiMinusPh1Digi_min_log","c_Ph2DigiMinusPh1Digi_min_log");
  c_Ph2DigiMinusPh1Digi_min_log->cd();
  c_Ph2DigiMinusPh1Digi_min_log->SetLogy();
  h_Ph2DigiMinusPh1Digi_min->Draw();
  c_Ph2DigiMinusPh1Digi_min_log->SaveAs(outputPathPlots + "/" + c_Ph2DigiMinusPh1Digi_min_log->GetName() + ".png");


  // --- 2D hists
  // Wh2 Se12 St2
  // SL1
  TCanvas* c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1 = new TCanvas("c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1","c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1->cd();
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1->SetFillColor(kBlue);
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1->Draw("box");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1->SaveAs(outputPathPlots + "/" + c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L1->GetName() + ".png");

  TCanvas* c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2 = new TCanvas("c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2","c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2->cd();
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2->SetFillColor(kBlue);
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2->Draw("box");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2->SaveAs(outputPathPlots + "/" + c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L2->GetName() + ".png");

  TCanvas* c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3 = new TCanvas("c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3","c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3->cd();
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3->SetFillColor(kBlue);
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3->Draw("box");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3->SaveAs(outputPathPlots + "/" + c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL1L3->GetName() + ".png");

  // SL3
  TCanvas* c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1 = new TCanvas("c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1","c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1->cd();
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1->SetFillColor(kBlue);
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1->Draw("box");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1->SaveAs(outputPathPlots + "/" + c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L1->GetName() + ".png");

  TCanvas* c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2 = new TCanvas("c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2","c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2->cd();
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2->SetFillColor(kBlue);
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2->Draw("box");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2->SaveAs(outputPathPlots + "/" + c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L2->GetName() + ".png");

  TCanvas* c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3 = new TCanvas("c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3","c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3->cd();
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3->SetFillColor(kBlue);
  h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3->Draw("box");
  c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3->SaveAs(outputPathPlots + "/" + c_h2_Ph2DigiMinusPh1Digi_Wh2Se12St2SL3L3->GetName() + ".png");


  // --- tefficiency ph1 ph2 matching
  TCanvas* c_eff2_Ph2DigiMatching = new TCanvas("c_eff2_Ph2DigiMatching","c_eff2_Ph2DigiMatching");
  c_eff2_Ph2DigiMatching->cd();
  eff2_Ph2DigiMatching->Draw("COLZ");
  gPad->Update();
  TH2* h_eff2_Ph2DigiMatching = eff2_Ph2DigiMatching->GetPaintedHistogram();
  h_eff2_Ph2DigiMatching->SetMinimum(0.9);
  h_eff2_Ph2DigiMatching->SetMaximum(1.0);
  h_eff2_Ph2DigiMatching->Draw("same");
  gPad->Update();
  c_eff2_Ph2DigiMatching->SaveAs(outputPathPlots + "/" + c_eff2_Ph2DigiMatching->GetName() + ".png");
  

   
  
 
  cout<<" Plots done =) "<<endl;

}


void Plotter()
{

  TString inputFile = "results.root";

  // define output directory
  TString outputPathPlots = "~/www/DTDPG/plots_run329806";
  gSystem->Exec("mkdir -p "+outputPathPlots);

  // call funciton for plots
  doThePlots(inputFile, outputPathPlots);  

}
