#ifndef DTNtuplePh2Analyzer_h
#define DTNtuplePh2Analyzer_h

#include "DTNtupleBaseAnalyzer.h"
#include <DataFormats/MuonDetId/interface/DTWireId.h>

#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TEfficiency.h"

#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <map>


class DTNtuplePh2Analyzer : public DTNtupleBaseAnalyzer
{

 public :

  DTNtuplePh2Analyzer(const TString & inFileName,
                      const TString & outFileName);
  ~DTNtuplePh2Analyzer();

  void virtual Loop() override;


 protected : 

  void virtual book() override;
  void fillMap();
  void clearMap();
  void compare();
  void virtual endJob() override;

  TFile f_outFile;

  std::map<DTWireId, std::vector<float> > m_ph1Digis;
  std::map<DTWireId, std::vector<float> > m_ph2Digis;

  std::map<TString, TH1*> m_plots;
  std::map<TString, TH2*> m_2Dplots;

  std::map<TString, TEfficiency*> m_eff;


};

#endif
