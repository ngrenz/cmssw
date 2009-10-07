import FWCore.ParameterSet.Config as cms

# EventContent for HLT related products.

# This file exports the following five EventContent blocks:
#   HLTriggerRAW  HLTriggerRECO  HLTriggerAOD (without DEBUG products)
#   HLTDebugRAW   HLTDebugFEVT                (with    DEBUG products)
#
# as these are used in Configuration/EventContent
#
# All else is internal and should not be used directly by non-HLT users.
#
HLTriggerRAW = cms.PSet(
    outputCommands = cms.vstring('drop *_hlt*_*_*', 
        'keep *_hltL1GtObjectMap_*_*', 
        'keep FEDRawDataCollection_rawDataCollector_*_*', 
        'keep FEDRawDataCollection_source_*_*', 
        'keep edmTriggerResults_*_*_*', 
        'keep triggerTriggerEvent_*_*_*')
)

HLTriggerRECO = cms.PSet(
    outputCommands = cms.vstring('drop *_hlt*_*_*', 
        'keep *_hltL1GtObjectMap_*_*', 
        'keep edmTriggerResults_*_*_*', 
        'keep triggerTriggerEvent_*_*_*')
)

HLTriggerAOD = cms.PSet(
    outputCommands = cms.vstring('drop *_hlt*_*_*', 
        'keep *_hltL1GtObjectMap_*_*', 
        'keep edmTriggerResults_*_*_*', 
        'keep triggerTriggerEvent_*_*_*')
)

HLTDebugRAW = cms.PSet(
    outputCommands = cms.vstring('drop *_hlt*_*_*', 
        'keep *_hltAlCaEtaRegRecHitsCosmics_*_*', 
        'keep *_hltAlCaEtaRegRecHits_*_*', 
        'keep *_hltAlCaPhiSymStream_*_*', 
        'keep *_hltAlCaPi0RegRecHitsCosmics_*_*', 
        'keep *_hltAlCaPi0RegRecHits_*_*', 
        'keep *_hltBLifetimeL25AssociatorStartupU_*_*', 
        'keep *_hltBLifetimeL25AssociatorStartup_*_*', 
        'keep *_hltBLifetimeL25BJetTagsStartupU_*_*', 
        'keep *_hltBLifetimeL25BJetTagsStartup_*_*', 
        'keep *_hltBLifetimeL25JetsStartupU_*_*', 
        'keep *_hltBLifetimeL25JetsStartup_*_*', 
        'keep *_hltBLifetimeL25TagInfosStartupU_*_*', 
        'keep *_hltBLifetimeL25TagInfosStartup_*_*', 
        'keep *_hltBLifetimeL3AssociatorStartupU_*_*', 
        'keep *_hltBLifetimeL3AssociatorStartup_*_*', 
        'keep *_hltBLifetimeL3BJetTagsStartupU_*_*', 
        'keep *_hltBLifetimeL3BJetTagsStartup_*_*', 
        'keep *_hltBLifetimeL3JetsStartupU_*_*', 
        'keep *_hltBLifetimeL3JetsStartup_*_*', 
        'keep *_hltBLifetimeL3TagInfosStartupU_*_*', 
        'keep *_hltBLifetimeL3TagInfosStartup_*_*', 
        'keep *_hltBLifetimeRegionalCtfWithMaterialTracksStartupU_*_*', 
        'keep *_hltBLifetimeRegionalCtfWithMaterialTracksStartup_*_*', 
        'keep *_hltBSoftMuonL25BJetTagsByDR_*_*', 
        'keep *_hltBSoftMuonL25BJetTagsUByDR_*_*', 
        'keep *_hltBSoftMuonL25JetsU_*_*', 
        'keep *_hltBSoftMuonL25Jets_*_*', 
        'keep *_hltBSoftMuonL25TagInfosU_*_*', 
        'keep *_hltBSoftMuonL25TagInfos_*_*', 
        'keep *_hltBSoftMuonL3BJetTagsByDR_*_*', 
        'keep *_hltBSoftMuonL3BJetTagsByPt_*_*', 
        'keep *_hltBSoftMuonL3BJetTagsUByDR_*_*', 
        'keep *_hltBSoftMuonL3BJetTagsUByPt_*_*', 
        'keep *_hltBSoftMuonL3TagInfosU_*_*', 
        'keep *_hltBSoftMuonL3TagInfos_*_*', 
        'keep *_hltCorrectedHybridSuperClustersL1Isolated_*_*', 
        'keep *_hltCorrectedHybridSuperClustersL1NonIsolated_*_*', 
        'keep *_hltCorrectedMulti5x5EndcapSuperClustersWithPreshowerL1Isolated_*_*', 
        'keep *_hltCorrectedMulti5x5EndcapSuperClustersWithPreshowerL1NonIsolated_*_*', 
        'keep *_hltCsc2DRecHits_*_*', 
        'keep *_hltCscSegments_*_*', 
        'keep *_hltCtfL1IsoLargeWindowWithMaterialTracks_*_*', 
        'keep *_hltCtfL1IsoWithMaterialTracks_*_*', 
        'keep *_hltCtfL1NonIsoLargeWindowWithMaterialTracks_*_*', 
        'keep *_hltCtfL1NonIsoWithMaterialTracks_*_*', 
        'keep *_hltDt1DRecHits_*_*', 
        'keep *_hltDt4DSegments_*_*', 
        'keep *_hltElectronL1IsoLargeWindowDetaDphi_*_*', 
        'keep *_hltElectronL1NonIsoLargeWindowDetaDphi_*_*', 
        'keep *_hltGctDigis_*_*', 
        'keep *_hltGtDigis_*_*', 
        'keep *_hltHITCtfWithMaterialTracks1E31_*_*', 
        'keep *_hltHITCtfWithMaterialTracks8E29_*_*', 
        'keep *_hltHITIPTCorrector1E31_*_*', 
        'keep *_hltHITIPTCorrector8E29_*_*', 
        'keep *_hltHtMet_*_*', 
        'keep *_hltHybridSuperClustersL1Isolated_*_*', 
        'keep *_hltHybridSuperClustersL1NonIsolated_*_*', 
        'keep *_hltIcone5Central1_*_*', 
        'keep *_hltIcone5Central2_*_*', 
        'keep *_hltIcone5Central3_*_*', 
        'keep *_hltIcone5Central4_*_*', 
        'keep *_hltIcone5Tau1_*_*', 
        'keep *_hltIcone5Tau2_*_*', 
        'keep *_hltIcone5Tau3_*_*', 
        'keep *_hltIcone5Tau4_*_*', 
        'keep *_hltIconeCentral1Regional_*_*', 
        'keep *_hltIconeCentral2Regional_*_*', 
        'keep *_hltIconeCentral3Regional_*_*', 
        'keep *_hltIconeCentral4Regional_*_*', 
        'keep *_hltIconeTau1Regional_*_*', 
        'keep *_hltIconeTau2Regional_*_*', 
        'keep *_hltIconeTau3Regional_*_*', 
        'keep *_hltIconeTau4Regional_*_*', 
        'keep *_hltIsolPixelTrackProd1E31_*_*', 
        'keep *_hltIsolPixelTrackProd8E29_*_*', 
        'keep *_hltIterativeCone5CaloJetsRegional_*_*', 
        'keep *_hltIterativeCone5CaloJets_*_*', 
        'keep *_hltL1GtObjectMap_*_*', 
        'keep *_hltL1HLTDoubleLooseIsoTau15JetsMatch_*_*', 
        'keep *_hltL1HLTDoubleLooseIsoTau15Trk5JetsMatch_*_*', 
        'keep *_hltL1HLTSingleIsoTau30JetsMatch_*_*', 
        'keep *_hltL1HLTSingleLooseIsoTau20JetsMatch_*_*', 
        'keep *_hltL1IsoEgammaRegionalCTFFinalFitWithMaterial_*_*', 
        'keep *_hltL1IsoElectronTrackIsol_*_*', 
        'keep *_hltL1IsoElectronsRegionalCTFFinalFitWithMaterial_*_*', 
        'keep *_hltL1IsoHLTClusterShape_*_*', 
        'keep *_hltL1IsoLargeWindowElectronPixelSeeds_*_*', 
        'keep *_hltL1IsoPhotonHollowTrackIsol_*_*', 
        'keep *_hltL1IsoRecoEcalCandidate_*_*', 
        'keep *_hltL1IsoSiStripElectronPixelSeeds_*_*', 
        'keep *_hltL1IsoStartUpElectronPixelSeeds_*_*', 
        'keep *_hltL1IsolatedElectronHcalIsol_*_*', 
        'keep *_hltL1IsolatedPhotonEcalIsol_*_*', 
        'keep *_hltL1IsolatedPhotonHcalIsol_*_*', 
        'keep *_hltL1NonIsoEgammaRegionalCTFFinalFitWithMaterial_*_*', 
        'keep *_hltL1NonIsoElectronTrackIsol_*_*', 
        'keep *_hltL1NonIsoElectronsRegionalCTFFinalFitWithMaterial_*_*', 
        'keep *_hltL1NonIsoHLTClusterShape_*_*', 
        'keep *_hltL1NonIsoLargeWindowElectronPixelSeeds_*_*', 
        'keep *_hltL1NonIsoPhotonHollowTrackIsol_*_*', 
        'keep *_hltL1NonIsoRecoEcalCandidate_*_*', 
        'keep *_hltL1NonIsoSiStripElectronPixelSeeds_*_*', 
        'keep *_hltL1NonIsoStartUpElectronPixelSeeds_*_*', 
        'keep *_hltL1NonIsolatedElectronHcalIsol_*_*', 
        'keep *_hltL1NonIsolatedPhotonEcalIsol_*_*', 
        'keep *_hltL1NonIsolatedPhotonHcalIsol_*_*', 
        'keep *_hltL1extraParticles_*_*', 
        'keep *_hltL25TauConeIsolation_*_*', 
        'keep *_hltL25TauCtfWithMaterialTracks_*_*', 
        'keep *_hltL25TauJetPixelTracksAssociatorNoL2_*_*', 
        'keep *_hltL25TauJetPixelTracksAssociator_*_*', 
        'keep *_hltL25TauJetTracksAssociator_*_*', 
        'keep *_hltL25TauLeadingTrackPtCutSelector_*_*', 
        'keep *_hltL25TauPixelTracksConeIsolationNoL2_*_*', 
        'keep *_hltL25TauPixelTracksConeIsolation_*_*', 
        'keep *_hltL25TauPixelTracksIsolationSelectorNoL2_*_*', 
        'keep *_hltL25TauPixelTracksIsolationSelector_*_*', 
        'keep *_hltL25TauPixelTracksLeadingTrackPtCutSelectorNoL2_*_*', 
        'keep *_hltL25TauPixelTracksLeadingTrackPtCutSelector_*_*', 
        'keep *_hltL2MuonCandidates_*_*', 
        'keep *_hltL2MuonIsolations_*_*', 
        'keep *_hltL2MuonSeeds_*_*', 
        'keep *_hltL2Muons_*_*', 
        'keep *_hltL2TauIsolationProducer_*_*', 
        'keep *_hltL2TauIsolationSelectorNoCut_*_*', 
        'keep *_hltL2TauJets_*_*', 
        'keep *_hltL2TauNarrowConeIsolationProducer_*_*', 
        'keep *_hltL2TauRelaxingIsolationSelector_*_*', 
        'keep *_hltL3MuonCandidates_*_*', 
        'keep *_hltL3MuonIsolations_*_*', 
        'keep *_hltL3Muons_*_*', 
        'keep *_hltL3TauConeIsolation_*_*', 
        'keep *_hltL3TauCtfWithMaterialTracks_*_*', 
        'keep *_hltL3TauIsolationSelector_*_*', 
        'keep *_hltL3TauJetTracksAssociator_*_*', 
        'keep *_hltL3TkTracksFromL2_*_*', 
        'keep *_hltL3TrackCandidateFromL2_*_*', 
        'keep *_hltL3TrajectorySeed_*_*', 
        'keep *_hltMCJetCorJetIcone5HF07_*_*', 
        'keep *_hltMCJetCorJetIcone5PU_*_*', 
        'keep *_hltMCJetCorJetIcone5Regional_*_*', 
        'keep *_hltMCJetCorJetIcone5_*_*', 
        'keep *_hltMet_*_*', 
        'keep *_hltMulti5x5EndcapSuperClustersWithPreshowerL1Isolated_*_*', 
        'keep *_hltMulti5x5EndcapSuperClustersWithPreshowerL1NonIsolated_*_*', 
        'keep *_hltMulti5x5SuperClustersL1Isolated_*_*', 
        'keep *_hltMulti5x5SuperClustersL1NonIsolated_*_*', 
        'keep *_hltMuonDTDigis_*_*', 
        'keep *_hltMuonRPCDigis_*_*', 
        'keep *_hltMuonTauIsoL2IsoFilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauIsoL2IsoFiltered_*_*', 
        'keep *_hltMuonTauIsoL2PreFilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauIsoL2PreFiltered_*_*', 
        'keep *_hltMuonTauIsoL3IsoFilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauIsoL3IsoFiltered_*_*', 
        'keep *_hltMuonTauIsoL3PreFilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauIsoL3PreFiltered_*_*', 
        'keep *_hltMuonTauL1FilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauL1Filtered_*_*', 
        'keep *_hltOfflineBeamSpot_*_*', 
        'keep *_hltPixelMatchElectronsL1Iso_*_*', 
        'keep *_hltPixelMatchElectronsL1NonIso_*_*', 
        'keep *_hltPixelMatchLargeWindowElectronsL1Iso_*_*', 
        'keep *_hltPixelMatchLargeWindowElectronsL1NonIso_*_*', 
        'keep *_hltPixelTracks_*_*', 
        'keep *_hltPixelVertices_*_*', 
        'keep *_hltRpcRecHits_*_*', 
        'keep *_hltSelector4JetsRegional_*_*', 
        'keep *_hltSelector4JetsU_*_*', 
        'keep *_hltSelector4Jets_*_*', 
        'keep *_hltSiPixelClusters_*_*', 
        'keep *_hltSiPixelRecHits_*_*', 
        'keep *_hltSiStripRawToClustersFacility_*_*', 
        'keep *_hltTowerMakerForAll_*_*', 
        'keep *_hltTowerMakerForMuons_*_*', 
        'keep FEDRawDataCollection_rawDataCollector_*_*', 
        'keep FEDRawDataCollection_source_*_*', 
        'keep L1MuGMTCands_hltGtDigis_*_*', 
        'keep L1MuGMTReadoutCollection_hltGtDigis_*_*', 
        'keep edmTriggerResults_*_*_*', 
        'keep triggerTriggerEventWithRefs_*_*_*', 
        'keep triggerTriggerEvent_*_*_*')
)

HLTDebugFEVT = cms.PSet(
    outputCommands = cms.vstring('drop *_hlt*_*_*', 
        'keep *_hltAlCaEtaRegRecHitsCosmics_*_*', 
        'keep *_hltAlCaEtaRegRecHits_*_*', 
        'keep *_hltAlCaPhiSymStream_*_*', 
        'keep *_hltAlCaPi0RegRecHitsCosmics_*_*', 
        'keep *_hltAlCaPi0RegRecHits_*_*', 
        'keep *_hltBLifetimeL25AssociatorStartupU_*_*', 
        'keep *_hltBLifetimeL25AssociatorStartup_*_*', 
        'keep *_hltBLifetimeL25BJetTagsStartupU_*_*', 
        'keep *_hltBLifetimeL25BJetTagsStartup_*_*', 
        'keep *_hltBLifetimeL25JetsStartupU_*_*', 
        'keep *_hltBLifetimeL25JetsStartup_*_*', 
        'keep *_hltBLifetimeL25TagInfosStartupU_*_*', 
        'keep *_hltBLifetimeL25TagInfosStartup_*_*', 
        'keep *_hltBLifetimeL3AssociatorStartupU_*_*', 
        'keep *_hltBLifetimeL3AssociatorStartup_*_*', 
        'keep *_hltBLifetimeL3BJetTagsStartupU_*_*', 
        'keep *_hltBLifetimeL3BJetTagsStartup_*_*', 
        'keep *_hltBLifetimeL3JetsStartupU_*_*', 
        'keep *_hltBLifetimeL3JetsStartup_*_*', 
        'keep *_hltBLifetimeL3TagInfosStartupU_*_*', 
        'keep *_hltBLifetimeL3TagInfosStartup_*_*', 
        'keep *_hltBLifetimeRegionalCtfWithMaterialTracksStartupU_*_*', 
        'keep *_hltBLifetimeRegionalCtfWithMaterialTracksStartup_*_*', 
        'keep *_hltBSoftMuonL25BJetTagsByDR_*_*', 
        'keep *_hltBSoftMuonL25BJetTagsUByDR_*_*', 
        'keep *_hltBSoftMuonL25JetsU_*_*', 
        'keep *_hltBSoftMuonL25Jets_*_*', 
        'keep *_hltBSoftMuonL25TagInfosU_*_*', 
        'keep *_hltBSoftMuonL25TagInfos_*_*', 
        'keep *_hltBSoftMuonL3BJetTagsByDR_*_*', 
        'keep *_hltBSoftMuonL3BJetTagsByPt_*_*', 
        'keep *_hltBSoftMuonL3BJetTagsUByDR_*_*', 
        'keep *_hltBSoftMuonL3BJetTagsUByPt_*_*', 
        'keep *_hltBSoftMuonL3TagInfosU_*_*', 
        'keep *_hltBSoftMuonL3TagInfos_*_*', 
        'keep *_hltCorrectedHybridSuperClustersL1Isolated_*_*', 
        'keep *_hltCorrectedHybridSuperClustersL1NonIsolated_*_*', 
        'keep *_hltCorrectedMulti5x5EndcapSuperClustersWithPreshowerL1Isolated_*_*', 
        'keep *_hltCorrectedMulti5x5EndcapSuperClustersWithPreshowerL1NonIsolated_*_*', 
        'keep *_hltCsc2DRecHits_*_*', 
        'keep *_hltCscSegments_*_*', 
        'keep *_hltCtfL1IsoLargeWindowWithMaterialTracks_*_*', 
        'keep *_hltCtfL1IsoWithMaterialTracks_*_*', 
        'keep *_hltCtfL1NonIsoLargeWindowWithMaterialTracks_*_*', 
        'keep *_hltCtfL1NonIsoWithMaterialTracks_*_*', 
        'keep *_hltDt1DRecHits_*_*', 
        'keep *_hltDt4DSegments_*_*', 
        'keep *_hltElectronL1IsoLargeWindowDetaDphi_*_*', 
        'keep *_hltElectronL1NonIsoLargeWindowDetaDphi_*_*', 
        'keep *_hltGctDigis_*_*', 
        'keep *_hltGtDigis_*_*', 
        'keep *_hltHITCtfWithMaterialTracks1E31_*_*', 
        'keep *_hltHITCtfWithMaterialTracks8E29_*_*', 
        'keep *_hltHITIPTCorrector1E31_*_*', 
        'keep *_hltHITIPTCorrector8E29_*_*', 
        'keep *_hltHtMet_*_*', 
        'keep *_hltHybridSuperClustersL1Isolated_*_*', 
        'keep *_hltHybridSuperClustersL1NonIsolated_*_*', 
        'keep *_hltIcone5Central1_*_*', 
        'keep *_hltIcone5Central2_*_*', 
        'keep *_hltIcone5Central3_*_*', 
        'keep *_hltIcone5Central4_*_*', 
        'keep *_hltIcone5Tau1_*_*', 
        'keep *_hltIcone5Tau2_*_*', 
        'keep *_hltIcone5Tau3_*_*', 
        'keep *_hltIcone5Tau4_*_*', 
        'keep *_hltIconeCentral1Regional_*_*', 
        'keep *_hltIconeCentral2Regional_*_*', 
        'keep *_hltIconeCentral3Regional_*_*', 
        'keep *_hltIconeCentral4Regional_*_*', 
        'keep *_hltIconeTau1Regional_*_*', 
        'keep *_hltIconeTau2Regional_*_*', 
        'keep *_hltIconeTau3Regional_*_*', 
        'keep *_hltIconeTau4Regional_*_*', 
        'keep *_hltIsolPixelTrackProd1E31_*_*', 
        'keep *_hltIsolPixelTrackProd8E29_*_*', 
        'keep *_hltIterativeCone5CaloJetsRegional_*_*', 
        'keep *_hltIterativeCone5CaloJets_*_*', 
        'keep *_hltL1GtObjectMap_*_*', 
        'keep *_hltL1HLTDoubleLooseIsoTau15JetsMatch_*_*', 
        'keep *_hltL1HLTDoubleLooseIsoTau15Trk5JetsMatch_*_*', 
        'keep *_hltL1HLTSingleIsoTau30JetsMatch_*_*', 
        'keep *_hltL1HLTSingleLooseIsoTau20JetsMatch_*_*', 
        'keep *_hltL1IsoEgammaRegionalCTFFinalFitWithMaterial_*_*', 
        'keep *_hltL1IsoElectronTrackIsol_*_*', 
        'keep *_hltL1IsoElectronsRegionalCTFFinalFitWithMaterial_*_*', 
        'keep *_hltL1IsoHLTClusterShape_*_*', 
        'keep *_hltL1IsoLargeWindowElectronPixelSeeds_*_*', 
        'keep *_hltL1IsoPhotonHollowTrackIsol_*_*', 
        'keep *_hltL1IsoRecoEcalCandidate_*_*', 
        'keep *_hltL1IsoSiStripElectronPixelSeeds_*_*', 
        'keep *_hltL1IsoStartUpElectronPixelSeeds_*_*', 
        'keep *_hltL1IsolatedElectronHcalIsol_*_*', 
        'keep *_hltL1IsolatedPhotonEcalIsol_*_*', 
        'keep *_hltL1IsolatedPhotonHcalIsol_*_*', 
        'keep *_hltL1NonIsoEgammaRegionalCTFFinalFitWithMaterial_*_*', 
        'keep *_hltL1NonIsoElectronTrackIsol_*_*', 
        'keep *_hltL1NonIsoElectronsRegionalCTFFinalFitWithMaterial_*_*', 
        'keep *_hltL1NonIsoHLTClusterShape_*_*', 
        'keep *_hltL1NonIsoLargeWindowElectronPixelSeeds_*_*', 
        'keep *_hltL1NonIsoPhotonHollowTrackIsol_*_*', 
        'keep *_hltL1NonIsoRecoEcalCandidate_*_*', 
        'keep *_hltL1NonIsoSiStripElectronPixelSeeds_*_*', 
        'keep *_hltL1NonIsoStartUpElectronPixelSeeds_*_*', 
        'keep *_hltL1NonIsolatedElectronHcalIsol_*_*', 
        'keep *_hltL1NonIsolatedPhotonEcalIsol_*_*', 
        'keep *_hltL1NonIsolatedPhotonHcalIsol_*_*', 
        'keep *_hltL1extraParticles_*_*', 
        'keep *_hltL25TauConeIsolation_*_*', 
        'keep *_hltL25TauCtfWithMaterialTracks_*_*', 
        'keep *_hltL25TauJetPixelTracksAssociatorNoL2_*_*', 
        'keep *_hltL25TauJetPixelTracksAssociator_*_*', 
        'keep *_hltL25TauJetTracksAssociator_*_*', 
        'keep *_hltL25TauLeadingTrackPtCutSelector_*_*', 
        'keep *_hltL25TauPixelTracksConeIsolationNoL2_*_*', 
        'keep *_hltL25TauPixelTracksConeIsolation_*_*', 
        'keep *_hltL25TauPixelTracksIsolationSelectorNoL2_*_*', 
        'keep *_hltL25TauPixelTracksIsolationSelector_*_*', 
        'keep *_hltL25TauPixelTracksLeadingTrackPtCutSelectorNoL2_*_*', 
        'keep *_hltL25TauPixelTracksLeadingTrackPtCutSelector_*_*', 
        'keep *_hltL2MuonCandidates_*_*', 
        'keep *_hltL2MuonIsolations_*_*', 
        'keep *_hltL2MuonSeeds_*_*', 
        'keep *_hltL2Muons_*_*', 
        'keep *_hltL2TauIsolationProducer_*_*', 
        'keep *_hltL2TauIsolationSelectorNoCut_*_*', 
        'keep *_hltL2TauJets_*_*', 
        'keep *_hltL2TauNarrowConeIsolationProducer_*_*', 
        'keep *_hltL2TauRelaxingIsolationSelector_*_*', 
        'keep *_hltL3MuonCandidates_*_*', 
        'keep *_hltL3MuonIsolations_*_*', 
        'keep *_hltL3Muons_*_*', 
        'keep *_hltL3TauConeIsolation_*_*', 
        'keep *_hltL3TauCtfWithMaterialTracks_*_*', 
        'keep *_hltL3TauIsolationSelector_*_*', 
        'keep *_hltL3TauJetTracksAssociator_*_*', 
        'keep *_hltL3TkTracksFromL2_*_*', 
        'keep *_hltL3TrackCandidateFromL2_*_*', 
        'keep *_hltL3TrajectorySeed_*_*', 
        'keep *_hltMCJetCorJetIcone5HF07_*_*', 
        'keep *_hltMCJetCorJetIcone5PU_*_*', 
        'keep *_hltMCJetCorJetIcone5Regional_*_*', 
        'keep *_hltMCJetCorJetIcone5_*_*', 
        'keep *_hltMet_*_*', 
        'keep *_hltMulti5x5EndcapSuperClustersWithPreshowerL1Isolated_*_*', 
        'keep *_hltMulti5x5EndcapSuperClustersWithPreshowerL1NonIsolated_*_*', 
        'keep *_hltMulti5x5SuperClustersL1Isolated_*_*', 
        'keep *_hltMulti5x5SuperClustersL1NonIsolated_*_*', 
        'keep *_hltMuonDTDigis_*_*', 
        'keep *_hltMuonRPCDigis_*_*', 
        'keep *_hltMuonTauIsoL2IsoFilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauIsoL2IsoFiltered_*_*', 
        'keep *_hltMuonTauIsoL2PreFilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauIsoL2PreFiltered_*_*', 
        'keep *_hltMuonTauIsoL3IsoFilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauIsoL3IsoFiltered_*_*', 
        'keep *_hltMuonTauIsoL3PreFilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauIsoL3PreFiltered_*_*', 
        'keep *_hltMuonTauL1FilteredNoL1Tau_*_*', 
        'keep *_hltMuonTauL1Filtered_*_*', 
        'keep *_hltOfflineBeamSpot_*_*', 
        'keep *_hltPixelMatchElectronsL1Iso_*_*', 
        'keep *_hltPixelMatchElectronsL1NonIso_*_*', 
        'keep *_hltPixelMatchLargeWindowElectronsL1Iso_*_*', 
        'keep *_hltPixelMatchLargeWindowElectronsL1NonIso_*_*', 
        'keep *_hltPixelTracks_*_*', 
        'keep *_hltPixelVertices_*_*', 
        'keep *_hltRpcRecHits_*_*', 
        'keep *_hltSelector4JetsRegional_*_*', 
        'keep *_hltSelector4JetsU_*_*', 
        'keep *_hltSelector4Jets_*_*', 
        'keep *_hltSiPixelClusters_*_*', 
        'keep *_hltSiPixelRecHits_*_*', 
        'keep *_hltSiStripRawToClustersFacility_*_*', 
        'keep *_hltTowerMakerForAll_*_*', 
        'keep *_hltTowerMakerForMuons_*_*', 
        'keep FEDRawDataCollection_rawDataCollector_*_*', 
        'keep FEDRawDataCollection_source_*_*', 
        'keep L1MuGMTCands_hltGtDigis_*_*', 
        'keep L1MuGMTReadoutCollection_hltGtDigis_*_*', 
        'keep edmTriggerResults_*_*_*', 
        'keep triggerTriggerEventWithRefs_*_*_*', 
        'keep triggerTriggerEvent_*_*_*')
)
