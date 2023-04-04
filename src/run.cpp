#include "run.hh"
#include"G4Run.hh"
MyRunAction::MyRunAction()
{
	  
	  G4AnalysisManager *man = G4AnalysisManager::Instance();
 	 man->SetNtupleMerging(true);
   	man->CreateNtuple("layer10","layer10");
		man->CreateNtupleDColumn("fX10");	
		man->CreateNtupleDColumn("fY10");
		man->CreateNtupleIColumn("fEvt10");	
		man->CreateNtupleIColumn("fChanN10");
		man->FinishNtuple(0);
		
		man->CreateNtuple("layer9","layer9");
		man->CreateNtupleDColumn("fX9");	
		man->CreateNtupleDColumn("fY9");
		man->CreateNtupleIColumn("fEvt9");	
		man->CreateNtupleIColumn("fChanN9");
		man->FinishNtuple(1);
		
		man->CreateNtuple("layer8","layer8");
		man->CreateNtupleDColumn("fX8");	
		man->CreateNtupleDColumn("fY8");
		man->CreateNtupleIColumn("fEvt8");	
		man->CreateNtupleIColumn("fChanN8");
		man->FinishNtuple(2);
		
		man->CreateNtuple("layer7","layer7");
		man->CreateNtupleDColumn("fX7");	
		man->CreateNtupleDColumn("fY7");
		man->CreateNtupleIColumn("fEvt7");	
		man->CreateNtupleIColumn("fChanN7");
		man->FinishNtuple(3);
		
		man->CreateNtuple("layer6","layer6");
		man->CreateNtupleDColumn("fX6");	
		man->CreateNtupleDColumn("fY6");
		man->CreateNtupleIColumn("fEvt6");	
		man->CreateNtupleIColumn("fChanN6");
		man->FinishNtuple(4);
		
		man->CreateNtuple("layer5","layer5");
		man->CreateNtupleDColumn("fX5");	
		man->CreateNtupleDColumn("fY5");
		man->CreateNtupleIColumn("fEvt5");	
		man->CreateNtupleIColumn("fChanN5");
		man->FinishNtuple(5);
		
		man->CreateNtuple("layer4","layer4");
		man->CreateNtupleDColumn("fX4");	
		man->CreateNtupleDColumn("fY4");
		man->CreateNtupleIColumn("fEvt4");	
		man->CreateNtupleIColumn("fChanN4");
		man->FinishNtuple(6);
		
		man->CreateNtuple("layer3","layer3");
		man->CreateNtupleDColumn("fX3");	
		man->CreateNtupleDColumn("fY3");
		man->CreateNtupleIColumn("fEvt3");	
		man->CreateNtupleIColumn("fChanN3");
		man->FinishNtuple(7);
		
		man->CreateNtuple("layer2","layer2");
		man->CreateNtupleDColumn("fX2");	
		man->CreateNtupleDColumn("fY2");
		man->CreateNtupleIColumn("fEvt2");	
		man->CreateNtupleIColumn("fChanN2");
		man->FinishNtuple(8);
		
		man->CreateNtuple("layer1","layer1");		
		man->CreateNtupleDColumn("fX1");	
		man->CreateNtupleDColumn("fY1");
		man->CreateNtupleIColumn("fEvt1");	
		man->CreateNtupleIColumn("fChanN1");
		man->FinishNtuple(9);
		
}		
MyRunAction::~MyRunAction()
{}

 void MyRunAction::BeginOfRunAction(const G4Run* run)
{

 G4AnalysisManager *man = G4AnalysisManager::Instance();
 /*
 int runID=run->GetRunID() ;
 std::stringstream strRunID;
	strRunID <<runID ;
	*/
  	man->OpenFile("output_Range_theta_45_73.root");


  

    

  
}
 void MyRunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->Write();
    man->CloseFile();


}

