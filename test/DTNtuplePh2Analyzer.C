#include "DTNtuplePh2Analyzer.h"
#include <DataFormats/MuonDetId/src/DTWireId.cc>


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

  for (std::size_t iDigi = 0; iDigi < digi_nDigis; ++iDigi)
    m_plots["hTimeBox"]->Fill(digi_time->at(iDigi));

}

void DTNtuplePh2Analyzer::endJob()
{

  f_outFile.cd();

  f_outFile.Write();
  f_outFile.Close();

}




