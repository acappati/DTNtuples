# DTNtuples
Ntuples for the analysis of the CMS drift tubes detector performance

## Preliminary instructions
**Note**: 
In the present days this code is evolving fast, hence the installation recipe may change often. Please keep an eye on this page to check for updates.

### Installation:
```
cmsrel CMSSW_10_6_0
cd CMSSW_10_6_0/src/
cmsenv
git cms-merge-topic oglez:Phase2_CMSSW_10_6_0_pre4_Summer2019 # phase-2 unpacker
git cms-merge-topic -u pozzobon:DTHough_NP_20190619_106X_noL1T # MTT-CHT emulator
git cms-merge-topic -u dtp2-tpg-am:AM_106X_dev # AM emulator
git clone https://github.com/battibass/DTNtuples.git DTDPGAnalysis/DTNtuples
scramv1 b -j 5
```

### Ntuple prduction:
```
cd DTDPGAnalysis/DTNtuples/test/
cmsRun dtDpgNtuples_slicetest_cfg.py nEvents=10000
# or
cmsRun dtDpgNtuples_phase2_cfg.py nEvents=10000
```

### Analysis:
```
root -b
root [0] .x loadExampleAnalysis.C

root [1] DTNtupleExampleAnalyzer analysis("DTDPGNtuple_10_6_0_SX5.root","results.root")
// or
root [1] DTNtupleExampleAnalyzer analysis("DTDPGNtuple_10_6_0_Phase2_Simulation.root","results.root")

root [2] analysis.Loop()
```

### Analysis Ph2:
```
root -b
root [0] .x loadPh2Analysis.C
root [1] DTNtuplePh2Analyzer analysis("/eos/cms/store/group/dpg_dt/comm_dt/commissioning_2019_data/ntuples/ST/DTDPGNtuple_run331909.root","results.root")
root [2] analysis.Loop()
```
