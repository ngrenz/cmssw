import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

# initialize MessageLoger and output report
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.categories.append('Demo')
process.MessageLogger.cerr.INFO = cms.untracked.PSet(
    limit = cms.untracked.int32(-1)
)



process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'file:/afs/cern.ch/work/n/ngrenz/public/niklasTrackerGeometry/CMSSW_6_2_SLHCDEV_X_2015-11-22-1100/src/FourMuPt_1_200_cfi_GEN_SIM.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer')

process.p = cms.Path(process.demo)
