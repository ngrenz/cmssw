// -*- C++ -*-
//
// Package:    DemoAnalyzer
// Class:      DemoAnalyzer
// 
/**\class DemoAnalyzer DemoAnalyzer.cc Niklas/DemoAnalyzer/plugins/DemoAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Niklas Grenz
//         Created:  Fri, 27 Nov 2015 16:13:05 GMT
// $Id$
//
//


// system include files
#include <memory>

// user include files

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "Alignment/CommonAlignmentMonitor/interface/AlignmentMonitorBase.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

// user inlude files like descripted in 
// https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookWriteFrameworkModule
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"

// framework & common header files
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/Provenance/interface/Provenance.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "Geometry/CommonDetUnit/interface/GeomDetUnit.h"
#include "DataFormats/DetId/interface/DetId.h"

//DQM services
//#include "FWCore/ServiceRegistry/interface/Service.h"
// tracker info
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "DataFormats/SiStripDetId/interface/StripSubdetector.h"
#include "DataFormats/SiPixelDetId/interface/PixelSubdetector.h"

// data in edm::event
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"

// helper files
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "CommonTools/Utils/interface/TFileDirectory.h"
#include "TString.h"
#include "TH1F.h"
#include "TProfile.h"
#include "TTree.h"
#include "FWCore/Utilities/interface/typelookup.h"

#include "FWCore/Framework/interface/EventSetupRecordImplementation.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/NoRecordException.h"
#include "FWCore/Framework/interface/DependentRecordTag.h"
//
// class declaration
//

class DemoAnalyzer : public edm::EDAnalyzer {
  public:
    explicit DemoAnalyzer(const edm::ParameterSet&);
    ~DemoAnalyzer();

    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
    bool printModules;

  protected:
    TH1F *book1D(std::string dir, std::string name, std::string title, int nchX, double lowX, double highX);

  private:
    TFileDirectory *directory(std::string dir);
    TH1F *book1Demo(std::string name, std::string title, int nchX, double lowX, double highX);
    virtual void beginJob() override;
    virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
    virtual void endJob() override;

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

//   DQMStore *dbe;

  // ----------member data ---------------------------
  // TrackerInfo
  // Pixel info
    int nPxlHits;
    TH1 *meTrackerPx[2];
    TH1F *meTrackerPxPhi;
    TH1F *meTrackerPxEta;
    TH1F *meTrackerPxBToF;
    TH1F *meTrackerPxBR;
    TH1F *meTrackerPxFToF;
    TH1F *meTrackerPxFZ;
    edm::InputTag PxlBrlLowSrc_;
    edm::InputTag PxlBrlHighSrc_;
    edm::InputTag PxlFwdLowSrc_;
    edm::InputTag PxlFwdHighSrc_;

    // Strip info
    int nSiHits;
    TH1F *meTrackerSi[2];
    TH1F *meTrackerSiPhi;
    TH1F *meTrackerSiEta;
    TH1F *meTrackerSiBToF;
    TH1F *meTrackerSiBR;
    TH1F *meTrackerSiFToF;
    TH1F *meTrackerSiFZ;
    edm::InputTag SiTIBLowSrc_;
    edm::InputTag SiTIBHighSrc_;
    edm::InputTag SiTOBLowSrc_;
    edm::InputTag SiTOBHighSrc_;
    edm::InputTag SiTIDLowSrc_;
    edm::InputTag SiTIDHighSrc_;
    edm::InputTag SiTECLowSrc_;
    edm::InputTag SiTECHighSrc_;

    std::map<std::vector<std::string>, TFileDirectory*> m_baseDirMap, m_iterDirMap;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//





//
// constructors and destructor
//
DemoAnalyzer::DemoAnalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  printModules = false;
  //Labels to use to extract information
  PxlBrlLowSrc_ = edm::InputTag("g4SimHits","TrackerHitsPixelBarrelLowTof");
  PxlBrlHighSrc_ = edm::InputTag("g4SimHits","TrackerHitsPixelBarrelHighTof");
  PxlFwdLowSrc_ = edm::InputTag("g4SimHits","TrackerHitsPixelEndcapLowTof");
  PxlFwdHighSrc_ = edm::InputTag("g4SimHits","TrackerHitsPixelEndcapHighTof");

  SiTIBLowSrc_ = edm::InputTag("g4SimHits","TrackerHitsTIBLowTof");
  SiTIBHighSrc_ = edm::InputTag("g4SimHits","TrackerHitsTIBHighTof");
  SiTOBLowSrc_ = edm::InputTag("g4SimHits","TrackerHitsTOBLowTof");
  SiTOBHighSrc_ = edm::InputTag("g4SimHits","TrackerHitsTOBHighTof");
  SiTIDLowSrc_ = edm::InputTag("g4SimHits","TrackerHitsTIDLowTof");
  SiTIDHighSrc_ = edm::InputTag("g4SimHits","TrackerHitsTIBHighTof");
  SiTECLowSrc_ = edm::InputTag("g4SimHits","TrackerHitsTECLowTof");
  SiTECHighSrc_ = edm::InputTag("g4SimHits","TrackerHitsTECHighTof");

  // initialize monitor elements
  for (Int_t i = 0; i < 2; ++i) {
    meTrackerPx[i] = 0;
    meTrackerSi[i] = 0;
  }
  meTrackerPxPhi = 0;
  meTrackerPxEta = 0;
  meTrackerPxBToF = 0;
  meTrackerPxBR = 0;
  meTrackerPxFToF = 0;
  meTrackerPxFZ = 0;
  meTrackerSiPhi = 0;
  meTrackerSiEta = 0;
  meTrackerSiBToF = 0;
  meTrackerSiBR = 0;
  meTrackerSiFToF = 0;
  meTrackerSiFZ = 0;

  //get dqm info and create histograms
  Char_t hname[200];
  Char_t htitle[200];
//  dbe = 0;
//  dbe = edm::Service<DQMStore>().operator->();
//  if (dbe) {
//    dbe->setVerbose(1);
//    dbe->showDirStructure();
 
    // Pixels
//    dbe->setCurrentFolder("GlobalHitsV/SiPixels");
    sprintf(hname,"hTrackerPx1");
    sprintf(htitle,"Pixel hits");
//    meTrackerPx[0] = dbe->book1Demo(hname,htitle,100,0.,10000.);
    sprintf(hname,"hTrackerPx2");
    meTrackerPx[1] = book1Demo(hname,htitle,100,-0.5,99.5);
    for (Int_t i = 0; i < 2; ++i) {
 //      meTrackerPx[i]->setAxisTitle("Number of Pixel Hits",1);
  //     meTrackerPx[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hTrackerPxPhi");
    sprintf(htitle,"Pixel hits phi/rad");
    meTrackerPxPhi = book1Demo(hname,htitle,100,-3.2,3.2);
  //   meTrackerPxPhi->setAxisTitle("Phi of Hits (rad)",1);
 //    meTrackerPxPhi->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxEta");
    sprintf(htitle,"Pixel hits eta");
    meTrackerPxEta = book1Demo(hname,htitle,100,-3.5,3.5);
 //    meTrackerPxEta->setAxisTitle("Eta of Hits",1);
 //    meTrackerPxEta->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxBToF");
    sprintf(htitle,"Pixel barrel hits, ToF/ns");
    meTrackerPxBToF = book1Demo(hname,htitle,100,0.,40.);
 //    meTrackerPxBToF->setAxisTitle("Time of Flight of Hits (ns)",1);
 //    meTrackerPxBToF->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxBR");
    sprintf(htitle,"Pixel barrel hits, R/cm");
    meTrackerPxBR = book1Demo(hname,htitle,100,0.,50.);
 //    meTrackerPxBR->setAxisTitle("R of Hits (cm)",1);
 //    meTrackerPxBR->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxFToF");
    sprintf(htitle,"Pixel forward hits, ToF/ns");
    meTrackerPxFToF = book1Demo(hname,htitle,100,0.,50.);
 //    meTrackerPxFToF->setAxisTitle("Time of Flight of Hits (ns)",1);
 //    meTrackerPxFToF->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxFZ");
    sprintf(htitle,"Pixel forward hits, Z/cm");
    meTrackerPxFZ = book1Demo(hname,htitle,200,-100.,100.);
 //    meTrackerPxFZ->setAxisTitle("Z of Hits (cm)",1);
 //    meTrackerPxFZ->setAxisTitle("Count",2);
    meTrackerPxFZ->GetXaxis()->SetTitle("Z of Hits (cm)");
    meTrackerPxFZ->GetYaxis()->SetTitle("Count");


    // Strips
   // dbe->setCurrentFolder("GlobalHitsV/SiStrips");
    sprintf(hname,"hTrackerSi1");
    sprintf(htitle,"Silicon hits");
    meTrackerSi[0] = book1Demo(hname,htitle,100,0.,10000.);
    sprintf(hname,"hTrackerSi2");
    meTrackerSi[1] = book1Demo(hname,htitle,100,-0.5,99.5);
    for (Int_t i = 0; i < 2; ++i) { 
 //      meTrackerSi[i]->setAxisTitle("Number of Silicon Hits",1);
 //      meTrackerSi[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hTrackerSiPhi");
    sprintf(htitle,"Silicon hits phi/rad");
    meTrackerSiPhi = book1Demo(hname,htitle,100,-3.2,3.2);
 //    meTrackerSiPhi->setAxisTitle("Phi of Hits (rad)",1);
 //    meTrackerSiPhi->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiEta");
    sprintf(htitle,"Silicon hits eta");
    meTrackerSiEta = book1Demo(hname,htitle,100,-3.5,3.5);
 //    meTrackerSiEta->setAxisTitle("Eta of Hits",1);
 //    meTrackerSiEta->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiBToF");
    sprintf(htitle,"Silicon barrel hits, ToF/ns");
    meTrackerSiBToF = book1Demo(hname,htitle,100,0.,50.);
 //    meTrackerSiBToF->setAxisTitle("Time of Flight of Hits (ns)",1);
 //    meTrackerSiBToF->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiBR");
    sprintf(htitle,"Silicon barrel hits, R/cm");
    meTrackerSiBR = book1Demo(hname,htitle,100,0.,200.);
  //   meTrackerSiBR->setAxisTitle("R of Hits (cm)",1);
 //    meTrackerSiBR->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiFToF");
    sprintf(htitle,"Silicon forward hits, ToF/ns");
    meTrackerSiFToF = book1Demo(hname,htitle,100,0.,75.);
 //    meTrackerSiFToF->setAxisTitle("Time of Flight of Hits (ns)",1);
 //    meTrackerSiFToF->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiFZ");
    sprintf(htitle,"Silicon forward hits, Z/cm");
    meTrackerSiFZ = book1Demo(hname,htitle,200,-300.,300.);
//    meTrackerSiFZ->setAxisTitle("Z of Hits (cm)",1);
 //    meTrackerSiFZ->setAxisTitle("Count",2);
 // }


}


DemoAnalyzer::~DemoAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//
TFileDirectory *DemoAnalyzer::directory(std::string dir)
{
   std::string::size_type lastPos = dir.find_first_not_of("/", 0);
   std::string::size_type pos = dir.find_first_of("/", lastPos);
   std::vector<std::string> dirs;

   bool isIter = false;
   if (dir.substr(lastPos, pos - lastPos) == std::string("iterN")) {
      isIter = true;
      lastPos = dir.find_first_not_of("/", pos);
      pos = dir.find_first_of("/", lastPos);
   }

   while (std::string::npos != pos  ||  std::string::npos != lastPos) {
      dirs.push_back(dir.substr(lastPos, pos - lastPos));
      lastPos = dir.find_first_not_of("/", pos);
      pos = dir.find_first_of("/", lastPos);
   }

   std::map<std::vector<std::string>, TFileDirectory*> *theMap;
   if (isIter) theMap = &m_iterDirMap;
   else theMap = &m_baseDirMap;

   std::vector<std::string> partial;
   TFileDirectory *last = (*theMap)[partial];
   for (unsigned int i = 0;  i < dirs.size();  i++) {
      partial.push_back(dirs[i]);
      if (theMap->find(partial) == theMap->end()) {
	 (*theMap)[partial] = new TFileDirectory(last->mkdir(dirs[i]));
      }
      last = (*theMap)[partial];
   }
   return last;
}

TH1F * DemoAnalyzer::book1D(std::string dir, std::string name, std::string title, int nchX, double lowX, double highX)
{
   return directory(dir)->make<TH1F>(name.c_str(), title.c_str(), nchX, lowX, highX);
}

TH1F * DemoAnalyzer::book1Demo(std::string name, std::string title, int nchX, double lowX, double highX) {
  return book1D ("/demo/", name, title, nchX, lowX, highX);
}




// ------------ method called for each event  ------------
void
DemoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  // geometry mapping
  static const int dTrk             = 1;
  static const int sdPxlBrl         = 1;
  static const int sdPxlFwd         = 2;
  static const int sdSiTIB          = 3;
  static const int sdSiTID          = 4;
  static const int sdSiTOB          = 5;
  static const int sdSiTEC          = 6;

  Handle<std::vector<PSimHit>> tracks;
  iEvent.getByLabel("g4SimHits",tracks);
//  LogInfo("Demo") << "number of tracks " <<tracks->size();

  nPxlHits = 0;
  TString eventoutput;

  //access the tracker geometry
  edm::ESHandle<TrackerGeometry> theTrackerGeometry;
  iSetup.get<TrackerDigiGeometryRecord>().get(theTrackerGeometry);  
  if (!theTrackerGeometry.isValid()) {
    edm::LogWarning("Demo")
      << "Unable to find TrackerDigiGeometryRecord in event!";
    return;
  }
  const TrackerGeometry& theTracker(*theTrackerGeometry);
    
  // iterator to access containers
  edm::PSimHitContainer::const_iterator itHit;

  ///////////////////////////////
  // get Pixel Barrel information
  ///////////////////////////////
  edm::PSimHitContainer thePxlBrlHits;
  // extract low container
  edm::Handle<edm::PSimHitContainer> PxlBrlLowContainer;
  iEvent.getByLabel(PxlBrlLowSrc_,PxlBrlLowContainer);
  if (PxlBrlLowContainer.isValid()) {
    thePxlBrlHits.insert(thePxlBrlHits.end(),PxlBrlLowContainer->begin(),
			 PxlBrlLowContainer->end());
  } else {
    LogDebug("Demo") << "Unable to find TrackerHitsPixelBarrelLowTof in event!";
  }
  // extract high container
  edm::Handle<edm::PSimHitContainer> PxlBrlHighContainer;
  iEvent.getByLabel(PxlBrlHighSrc_,PxlBrlHighContainer);
  if (PxlBrlHighContainer.isValid()) {
    thePxlBrlHits.insert(thePxlBrlHits.end(),PxlBrlHighContainer->begin(),
			 PxlBrlHighContainer->end());
  } else {
   LogDebug("Demo") << "Unable to find TrackerHitsPixelBarrelHighTof in event!";
  }

  int i = 1; int j = 0;
  // cycle through new container
  for (itHit = thePxlBrlHits.begin(); itHit != thePxlBrlHits.end(); ++itHit, ++i) {
    
    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();
    
    // check that expected detector is returned
    if ((detector == dTrk) && (subdetector == sdPxlBrl)) {
      
      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theTracker.idToDetUnit(theDetUnitId);
      
      if (!theDet) {
	edm::LogWarning("Demo")
	  << "Unable to get GeomDetUnit from PxlBrlHits for Hit " << i;
	continue;
      }
      
      ++j;
      
      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();
      
      if(meTrackerPxBToF) meTrackerPxBToF->Fill(itHit->tof());
      if(meTrackerPxBR) 
	meTrackerPxBR->Fill(bSurface.toGlobal(itHit->localPosition()).perp());
      if(meTrackerPxPhi) 
	meTrackerPxPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if(meTrackerPxEta) 
	meTrackerPxEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());
      
    } else {
      edm::LogWarning("Demo")
	<< "PxlBrl PSimHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dTrk << "," << sdPxlBrl
	<< "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through PxlBrl Hits

  eventoutput += "\n          Number of Pixel Barrel Hits collected:..... " + j;
  
  nPxlHits += j;
  
//  edm::Service<simtracker::services::RemapDetIdService> detIdRemapService;

  /////////////////////////////////
  // get Pixel Forward information
  ////////////////////////////////
  edm::PSimHitContainer thePxlFwdHits;
  // extract low container
  edm::Handle<edm::PSimHitContainer> PxlFwdLowContainer;
  iEvent.getByLabel(PxlFwdLowSrc_,PxlFwdLowContainer);
//  detIdRemapService->getByLabel( iEvent, PxlFwdLowSrc_, PxlFwdLowContainer ); // Temporary hack. See note above where detIdRemapService is declared.
  if (PxlFwdLowContainer.isValid()) {
     thePxlFwdHits.insert(thePxlFwdHits.end(),PxlFwdLowContainer->begin(),
			 PxlFwdLowContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsPixelEndcapLowTof in event!"; 
  }
  // extract high container
  edm::Handle<edm::PSimHitContainer> PxlFwdHighContainer;
  iEvent.getByLabel(PxlFwdHighSrc_,PxlFwdHighContainer);
//  detIdRemapService->getByLabel( iEvent, PxlFwdHighSrc_, PxlFwdHighContainer ); // Temporary hack. See note above where detIdRemapService is declared.
  if (PxlFwdHighContainer.isValid()) {
    thePxlFwdHits.insert(thePxlFwdHits.end(),PxlFwdHighContainer->begin(),
			 PxlFwdHighContainer->end());
  } else {
    LogDebug("GlobalHitsAnalyzer_fillTrk")
      << "Unable to find TrackerHitsPixelEndcapHighTof in event!";
  }
  // cycle through new container
  i = 1; j = 0;
  for (itHit = thePxlFwdHits.begin(); itHit != thePxlFwdHits.end(); ++itHit, ++i) {

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dTrk) && (subdetector == sdPxlFwd)) {

      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theTracker.idToDetUnit(theDetUnitId);

      if (!theDet) {
	edm::LogWarning("Demo")
	  << "Unable to get GeomDetUnit from PxlFwdHits for Hit " << i;;
	continue;
      }

      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();

      if(meTrackerPxFToF) meTrackerPxFToF->Fill(itHit->tof());
      if(meTrackerPxFZ) 
	meTrackerPxFZ->Fill(bSurface.toGlobal(itHit->localPosition()).z());
      if(meTrackerPxPhi) 
	meTrackerPxPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if(meTrackerPxEta) 
	meTrackerPxEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning("Demo")
	<< "PxlFwd PSimHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dTrk << "," << sdPxlFwd
	<< "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through PxlFwd Hits

  eventoutput += "\n          Number of Pixel Forward Hits collected:.... " + j;

  nPxlHits += j;

  if (meTrackerPx[0]) meTrackerPx[0]->Fill((float)nPxlHits);
  if (meTrackerPx[1]) meTrackerPx[1]->Fill((float)nPxlHits); 

  ///////////////////////////////////
  // get Silicon Barrel information
  //////////////////////////////////
  nSiHits = 0;
  edm::PSimHitContainer theSiBrlHits;
  // extract TIB low container
  edm::Handle<edm::PSimHitContainer> SiTIBLowContainer;
  iEvent.getByLabel(SiTIBLowSrc_,SiTIBLowContainer);
  if (SiTIBLowContainer.isValid()) {
    theSiBrlHits.insert(theSiBrlHits.end(),SiTIBLowContainer->begin(),
			SiTIBLowContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsTIBLowTof in event!";
  }
  // extract TIB high container
  edm::Handle<edm::PSimHitContainer> SiTIBHighContainer;
  iEvent.getByLabel(SiTIBHighSrc_,SiTIBHighContainer);
  if (SiTIBHighContainer.isValid()) {
    theSiBrlHits.insert(theSiBrlHits.end(),SiTIBHighContainer->begin(),
			SiTIBHighContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsTIBHighTof in event!";
  } 
  // extract TOB low container
  edm::Handle<edm::PSimHitContainer> SiTOBLowContainer;
  iEvent.getByLabel(SiTOBLowSrc_,SiTOBLowContainer);
  if (SiTOBLowContainer.isValid()) {
    theSiBrlHits.insert(theSiBrlHits.end(),SiTOBLowContainer->begin(),
			SiTOBLowContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsTOBLowTof in event!";
  }
  // extract TOB high container
  edm::Handle<edm::PSimHitContainer> SiTOBHighContainer;
  iEvent.getByLabel(SiTOBHighSrc_,SiTOBHighContainer);
  if (SiTOBHighContainer.isValid()) {
    theSiBrlHits.insert(theSiBrlHits.end(),SiTOBHighContainer->begin(),
			SiTOBHighContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsTOBHighTof in event!";
  }

  // cycle through new container
  i = 1; j = 0;
  for (itHit = theSiBrlHits.begin(); itHit != theSiBrlHits.end(); ++itHit, ++i) {

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dTrk) && 
	((subdetector == sdSiTIB) ||
	 (subdetector == sdSiTOB))) {

      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theTracker.idToDetUnit(theDetUnitId);

      if (!theDet) {
	edm::LogWarning("Demo")
	  << "Unable to get GeomDetUnit from SiBrlHits for Hit " << i;
	continue;
      }

      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();

      if(meTrackerSiBToF) meTrackerSiBToF->Fill(itHit->tof());
      if(meTrackerSiBR) 
	meTrackerSiBR->Fill(bSurface.toGlobal(itHit->localPosition()).perp());
      if(meTrackerSiPhi) 
	meTrackerSiPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if(meTrackerSiEta) 
	meTrackerSiEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning("Demo")
	<< "SiBrl PSimHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dTrk << "," << sdSiTIB
	<< " || " << sdSiTOB << "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through SiBrl Hits

  eventoutput += "\n          Number of Silicon Barrel Hits collected:... " + j;

  nSiHits += j;

  ///////////////////////////////////
  // get Silicon Forward information
  ///////////////////////////////////
  edm::PSimHitContainer theSiFwdHits;
  // extract TID low container
  edm::Handle<edm::PSimHitContainer> SiTIDLowContainer;
  iEvent.getByLabel(SiTIDLowSrc_,SiTIDLowContainer);
  if (SiTIDLowContainer.isValid()) {
     theSiFwdHits.insert(theSiFwdHits.end(),SiTIDLowContainer->begin(),
			SiTIDLowContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsTIDLowTof in event!";
  }
  // extract TID high container
  edm::Handle<edm::PSimHitContainer> SiTIDHighContainer;
  iEvent.getByLabel(SiTIDHighSrc_,SiTIDHighContainer);
  if (SiTIDHighContainer.isValid()) {
     theSiFwdHits.insert(theSiFwdHits.end(),SiTIDHighContainer->begin(),
			SiTIDHighContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsTIDHighTof in event!";
  }
  // extract TEC low container
  edm::Handle<edm::PSimHitContainer> SiTECLowContainer;
  iEvent.getByLabel(SiTECLowSrc_,SiTECLowContainer);
  if (SiTECLowContainer.isValid()) {
    theSiFwdHits.insert(theSiFwdHits.end(),SiTECLowContainer->begin(),
			SiTECLowContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsTECLowTof in event!";
  }
  // extract TEC high container
  edm::Handle<edm::PSimHitContainer> SiTECHighContainer;
  iEvent.getByLabel(SiTECHighSrc_,SiTECHighContainer);
  if (SiTECHighContainer.isValid()) {
    theSiFwdHits.insert(theSiFwdHits.end(),SiTECHighContainer->begin(),
			SiTECHighContainer->end());
  } else {
    LogDebug("Demo")
      << "Unable to find TrackerHitsTECHighTof in event!";
  }
   
  // cycle through container
  i = 1; j = 0;
  for (itHit = theSiFwdHits.begin(); itHit != theSiFwdHits.end(); ++itHit, ++i) {

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned 
    if ((detector == dTrk) && 
	((subdetector == sdSiTID) ||
	 (subdetector == sdSiTEC))) {
      
      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theTracker.idToDetUnit(theDetUnitId);
      
      if (!theDet) {
	edm::LogWarning("Demo")
	  << "Unable to get GeomDetUnit from SiFwdHits Hit " << i;
	return;
      }
      
      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();
      
      if(meTrackerSiFToF) meTrackerSiFToF->Fill(itHit->tof());
      if(meTrackerSiFZ) 
	meTrackerSiFZ->Fill(bSurface.toGlobal(itHit->localPosition()).z());
      if(meTrackerSiPhi) 
	meTrackerSiPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if(meTrackerSiEta) 
	meTrackerSiEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning("Demo")
	<< "SiFwd PSimHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dTrk << "," << sdSiTOB
	<< " || " << sdSiTEC << "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end check detector type
  } // end loop through SiFwd Hits

  eventoutput += "\n          Number of Silicon Forward Hits collected:.. " + j;

  nSiHits +=j;

  if (meTrackerSi[0]) meTrackerSi[0]->Fill((float)nSiHits);
  if (meTrackerSi[1]) meTrackerSi[1]->Fill((float)nSiHits); 

  edm::LogInfo("Demo") << eventoutput << "\n";



#ifdef THIS_IS_AN_EVENT_EXAMPLE
  Handle<ExampleData> pIn;
  iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
  ESHandle<SetupData> pSetup;
  iSetup.get<SetupRecord>().get(pSetup);
#endif

  if (printModules) {
    std::vector<const edm::Provenance*> AllProv;
    iEvent.getAllProvenance(AllProv);

    edm::LogInfo("Demo") << "Number of Provenances = " << AllProv.size();

    //Print provenanceInfo
    TString eventout("\nProvenance info:\n");      

    for (unsigned int i = 0; i < AllProv.size(); ++i) {
      eventout += "\n       ******************************";
      eventout += "\n       Module       : ";
      eventout += AllProv[i]->moduleLabel();
      eventout += "\n       ProductID    : ";
      eventout += AllProv[i]->productID().id();
      eventout += "\n       ClassName    : ";
      eventout += AllProv[i]->className();
      eventout += "\n       InstanceName : ";
      eventout += AllProv[i]->productInstanceName();
      eventout += "\n       BranchName   : ";
      eventout += AllProv[i]->branchName();
    }
    eventout += "\n       ******************************\n";
    edm::LogInfo("Demo") << eventout << "\n";
    printModules = false;
  }

  return;
}


// ------------ method called once each job just before starting event loop  ------------
void 
DemoAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
DemoAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
DemoAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
DemoAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
DemoAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
DemoAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
DemoAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(DemoAnalyzer);
