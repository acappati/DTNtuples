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
      
    }

  std::cout << std::endl; 

  endJob();

}

void DTNtuplePh2Analyzer::book()
{

  f_outFile.cd();

  m_plots["hTimeBox"] = new TH1F("hTimeBox",
				 "Ph2 time box; time (ns); entries/5 ns",
				 250,0.,1250.); 

}

void DTNtuplePh2Analyzer::fillMap()
{
  // eg map with one histogram
  for (std::size_t iDigi = 0; iDigi < digi_nDigis; ++iDigi)
    m_plots["hTimeBox"]->Fill(digi_time->at(iDigi));

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

void DTNtuplePh2Analyzer::endJob()
{

  f_outFile.cd();

  f_outFile.Write();
  f_outFile.Close();

}




