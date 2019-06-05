#include "TROOT.h"

void loadPh2Analysis()
{
  
  gROOT->ProcessLine(".L DTNtupleBaseAnalyzer.C++");
  gROOT->ProcessLine(".L DTNtuplePh2Analyzer.C++");

}
