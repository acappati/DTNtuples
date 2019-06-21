#include "DTNtuplePh2Analyzer.h"


DTNtuplePh2Analyzer::DTNtuplePh2Analyzer(const TString & inFileName,
						 const TString & outFileName) :
  f_outFile(outFileName,"RECREATE"), DTNtupleBaseAnalyzer(inFileName)  
{ 

}

DTNtuplePh2Analyzer::~DTNtuplePh2Analyzer() 
{ 

}

void DTNtuplePh2Analyzer::Loop()
{

  book();

  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntries();

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) 
    {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEvent(jentry);   nbytes += nb;

      if(jentry % 100 == 0) 
	std::cout << "[DTNtuplePh2Analyzer::Loop] processed : " 
		  << jentry << " entries\r" << std::flush;

      fillMap();

      compare();    

      clearMap();
      
    }

  std::cout << std::endl; 

  endJob();

}

void DTNtuplePh2Analyzer::book()
{

  f_outFile.cd();

  m_plots["h_Ph2DigiWithoutPh1"] = new TH1F("h_Ph2DigiWithoutPh1",
				            "Ph2 digi with no Ph1 correspondence; time (ns); entries/50 ns",
				            300,75000.,90000.); 

  m_plots["h_Ph2DigiMinusPh1Digi"] = new TH1F("h_Ph2DigiMinusPh1Digi",
				              "Ph2 digi offset wrt Ph1 digi; time (ns); entries/5 ns",
				              160,81700.,82500.); 

}

void DTNtuplePh2Analyzer::fillMap()
{
  // maps with ph1 digis
  for (std::size_t iDigi = 0; iDigi < digi_nDigis; ++iDigi){
    m_ph1Digis[ DTWireId(digi_wheel     ->at(iDigi), 
                         digi_station   ->at(iDigi), 
                         digi_sector    ->at(iDigi), 
                         digi_superLayer->at(iDigi), 
                         digi_layer     ->at(iDigi), 
                         digi_wire      ->at(iDigi)) ].push_back(digi_time->at(iDigi));
  }

  // maps with ph2 digis
  for (std::size_t iDigi = 0; iDigi < ph2Digi_nDigis; ++iDigi){
    m_ph2Digis[ DTWireId(ph2Digi_wheel     ->at(iDigi), 
                         ph2Digi_station   ->at(iDigi), 
                         ph2Digi_sector    ->at(iDigi), 
                         ph2Digi_superLayer->at(iDigi), 
                         ph2Digi_layer     ->at(iDigi), 
                         ph2Digi_wire      ->at(iDigi)) ].push_back(ph2Digi_time->at(iDigi));
  }
  

}

void DTNtuplePh2Analyzer::clearMap()
{
  // clear maps with ph1 digis
  for (std::size_t iDigi = 0; iDigi < digi_nDigis; ++iDigi){
    m_ph1Digis[ DTWireId(digi_wheel     ->at(iDigi), 
                         digi_station   ->at(iDigi), 
                         digi_sector    ->at(iDigi), 
                         digi_superLayer->at(iDigi), 
                         digi_layer     ->at(iDigi), 
                         digi_wire      ->at(iDigi)) ].clear();
  }

  // clear maps with ph2 digis
  for (std::size_t iDigi = 0; iDigi < ph2Digi_nDigis; ++iDigi){
    m_ph2Digis[ DTWireId(ph2Digi_wheel     ->at(iDigi), 
                         ph2Digi_station   ->at(iDigi), 
                         ph2Digi_sector    ->at(iDigi), 
                         ph2Digi_superLayer->at(iDigi), 
                         ph2Digi_layer     ->at(iDigi), 
                         ph2Digi_wire      ->at(iDigi)) ].clear();
  }

}

void DTNtuplePh2Analyzer::compare()
{
  // compare ph2 and ph1 digis
  for (auto const& x : m_ph2Digis)
  {
    if(x.second.size() == 0) continue;

    // save in histo ph2 digi that don't have ph1 digi corresponding 
    if(m_ph1Digis[x.first].size() == 0){
      for(auto const& a : x.second){
        m_plots["h_Ph2DigiWithoutPh1"]->Fill(a);
      }
    } 
    // save in histo ph2 digi and ph1 digi difference
    else{
      for(auto const& a : x.second){
        for(auto const& b : m_ph1Digis[x.first]){
          m_plots["h_Ph2DigiMinusPh1Digi"]->Fill(a-b);
        }
      }
    }
  }

}

void DTNtuplePh2Analyzer::endJob()
{

  f_outFile.cd();

  f_outFile.Write();
  f_outFile.Close();

}




