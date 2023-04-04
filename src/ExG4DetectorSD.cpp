#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "ExG4DetectorSD.hh"
#include <vector>
#include<G4UserRunAction.hh>
#include<G4Run.hh>
#include<vector>
#include<cmath>
#include "G4OpticalPhoton.hh"
#include "G4VPhysicalVolume.hh"
using namespace std ;
ExG4DetectorSD::ExG4DetectorSD(G4String name):G4VSensitiveDetector(name)
{}

G4bool ExG4DetectorSD::ProcessHits(G4Step *aStep, G4TouchableHistory *)
{


	G4Track* track =aStep->GetTrack();
	track->SetTrackStatus(fStopAndKill);
	
	
	G4StepPoint* preStepPoint=aStep->GetPreStepPoint();
	G4StepPoint* postStepPoint =aStep->GetPostStepPoint();
	

	

	const G4VTouchable* touchable =preStepPoint->GetTouchable();
	G4int copyNo = touchable->GetCopyNumber();

	G4VPhysicalVolume* physVol =touchable->GetVolume();
	G4ThreeVector posDetector =physVol->GetTranslation();
	double z =posDetector.getZ();
	double y =posDetector.getY();
	G4ThreeVector posPhoton =preStepPoint->GetPosition();

	G4VPhysicalVolume* pv = aStep->GetPostStepPoint()->GetPhysicalVolume();
	
	G4double edep = aStep ->GetTotalEnergyDeposit();
	//G4double edep1 =edep / keV ;
	//cout << edep1 << "	" <<"   "<<"   "<<y<<"		"<<z<<endl ;
	double si_z =(0.0575/2);
	G4double hx = 3.5*cm;
	int num1 ;
	 	if(posDetector.getY()*0.1 >= 6.828125){ num1=10 ;}
		else if((posDetector.getY()*0.1 >=6.06875) &&(posDetector.getY()*0.1 <= 6.3596875) ){ num1=9 ;}
		else if((posDetector.getY()*0.1 >= 5.31015625) &&(posDetector.getY()*0.1 <= 5.60109375) ){ num1=8 ;}
		else if((posDetector.getY()*0.1 >= 4.546875) &&(posDetector.getY()*0.1 <= 4.8378125) ){ num1=7 ;}
		else if((posDetector.getY()*0.1 >= 3.7875) &&(posDetector.getY()*0.1 <= 4.0784375) ){ num1=6 ;}
		else if((posDetector.getY()*0.1 >= 3.028125) &&(posDetector.getY()*0.1 <= 3.3190625000000002) ){ num1=5 ;}
		else if((posDetector.getY()*0.1>= 2.2703125) &&(posDetector.getY()*0.1 <= 2.5612500000000002) ){ num1=4 ;}
		else if((posDetector.getY()*0.1 >= 1.5078125) &&(posDetector.getY()*0.1 <= 1.79875) ){ num1=3 ;}
		else if((posDetector.getY()*0.1 >= 0.7484375000000001) &&(posDetector.getY()*0.1 <= 1.0393750000000002) ){ num1=2 ;}
		else if((posDetector.getY()*0.1 >= -0.009375000000000001) &&(posDetector.getY()*0.1 <= 0.28156250000000005) ){ num1=1 ;}
		
		double sep ;
		int id ;
	double chan=0.23;

	if(pv->GetName() =="logicDet_siZ"){
	G4ThreeVector posDetector3 =physVol->GetTranslation();
	if(copyNo%4 ==1) {
			sep =3*si_z ;
			id=floor((posDetector3.getZ())/chan)+1;
		}
		else if(copyNo%4 ==2) {
			sep =si_z ;
			id=floor((posDetector3.getZ())/chan)+1;
		}
		else if(copyNo%4 ==3) {
			sep =-si_z;
			id=floor((posDetector3.getZ())/chan)+1;
		}
		else if(copyNo%4 ==0) {
			sep =-3*si_z;
			id=floor((posDetector3.getZ())/chan)	;
		}
	 
 		
		//cout << "Z_"<<num1<<","<<posDetector3.getZ()+sep<<","<<posDetector3.getY()<<","<< id <<endl;
		//man->FillNtupleDColumn(1,posDetector3.getZ()+sep);	
		//man->FillNtupleDColumn(2,posDetector3.getY());	
		/// L- For Sipm to measure the Z cor
	
	}
	else if(pv->GetName() =="logicDet_siX"){
		G4ThreeVector posDetector1 =physVol->GetTranslation();
		if(copyNo%4 ==1) {
			sep =3*si_z ;
			id=floor((posDetector1.getX()+35)/chan)+1 ;
		}
		else if(copyNo%4 ==2) {
			sep =si_z ;
			id=floor((posDetector1.getX()+35)/chan)+1 ;
		}
		else if(copyNo%4 ==3) {
			sep =-si_z;
			id=floor((posDetector1.getX()+35)/chan)+1 ;
		}
		else if(copyNo%4 ==0) {
			sep =-3*si_z;
			id=floor((posDetector1.getX()+35)/chan) ;	
		}
	G4AnalysisManager *man = G4AnalysisManager ::Instance();	
		 int evt =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	if(posDetector.getY()*0.1 >= 6.828125){
	 int evt10 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	 double x10=posDetector1.getX()+sep ;
	 double y10=posDetector1.getY(); 
	 man->FillNtupleDColumn(0,0,x10);
	man->FillNtupleDColumn(0,1,y10);
	man->FillNtupleIColumn(0,2,evt10);
	man->FillNtupleIColumn(0,3,id);
	man->AddNtupleRow(0);}
		else if((posDetector.getY()*0.1 >=6.06875) &&(posDetector.getY()*0.1 <= 6.3596875) ){
		int evt9 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID() ;	
	double x9=posDetector1.getX()+sep ;
	 double y9=posDetector1.getY();	
	  man->FillNtupleDColumn(1,0,x9);
	man->FillNtupleDColumn(1,1,y9);
	man->FillNtupleIColumn(1,2,evt9);
	man->FillNtupleIColumn(1,3,id);
	man->AddNtupleRow(1);}
		else if((posDetector.getY()*0.1 >= 5.31015625) &&(posDetector.getY()*0.1 <= 5.60109375) ){ 
	int evt8 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	 double x8=posDetector1.getX()+sep ;
	 double y8=posDetector1.getY();
	 man->FillNtupleDColumn(2,0,x8);
	man->FillNtupleDColumn(2,1,y8);
	man->FillNtupleIColumn(2,2,evt8);
		man->FillNtupleIColumn(2,3,id);
		man->AddNtupleRow(2);}
		else if((posDetector.getY()*0.1 >= 4.546875) &&(posDetector.getY()*0.1 <= 4.8378125) ){ 
	int evt7 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	 double x7=posDetector1.getX()+sep ;
	 double y7=posDetector1.getY();
	 man->FillNtupleDColumn(3,0,x7);
	man->FillNtupleDColumn(3,1,y7);
	man->FillNtupleIColumn(3,2,evt7);
	man->FillNtupleIColumn(3,3,id);
	man->AddNtupleRow(3);}
		else if((posDetector.getY()*0.1 >= 3.7875) &&(posDetector.getY()*0.1 <= 4.0784375) ){ 
		int evt6 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	double x6=posDetector1.getX()+sep ;
	double y6=posDetector1.getY();
	man->FillNtupleDColumn(4,0,x6);
	man->FillNtupleDColumn(4,1,y6);
	man->FillNtupleIColumn(4,2,evt6);
	man->FillNtupleIColumn(4,3,id);
	man->AddNtupleRow(4);}
		else if((posDetector.getY()*0.1 >= 3.028125) &&(posDetector.getY()*0.1 <= 3.3190625000000002) ){
	int evt5 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	double x5=posDetector1.getX()+sep ;
	double y5=posDetector1.getY();
	man->FillNtupleDColumn(5,0,x5);
	man->FillNtupleDColumn(5,1,y5);
	man->FillNtupleIColumn(5,2,evt5);
	man->FillNtupleIColumn(5,3,id);
	man->AddNtupleRow(5);}
		else if((posDetector.getY()*0.1>= 2.2703125) &&(posDetector.getY()*0.1 <= 2.5612500000000002) ){ 
	int evt4 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	double x4=posDetector1.getX()+sep ;
	double y4=posDetector1.getY();
	man->FillNtupleDColumn(6,0,x4);
	man->FillNtupleDColumn(6,1,y4);
	man->FillNtupleIColumn(6,2,evt4);
	man->FillNtupleIColumn(6,3,id);
	man->AddNtupleRow(6);}
	else if((posDetector.getY()*0.1 >= 1.5078125) &&(posDetector.getY()*0.1 <= 1.79875) ){ 
	int evt3 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	 double x3=posDetector1.getX()+sep ;
	 double y3=posDetector1.getY();
	  man->FillNtupleDColumn(7,0,x3);
	man->FillNtupleDColumn(7,1,y3);
	man->FillNtupleIColumn(7,2,evt3);
	man->FillNtupleIColumn(7,3,id);
	man->AddNtupleRow(7);}
		else if((posDetector.getY()*0.1 >= 0.7484375000000001) &&(posDetector.getY()*0.1 <= 1.0393750000000002) ){ 
	int evt2 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	 double x2=posDetector1.getX()+sep ;
	 double y2=posDetector1.getY();
	 man->FillNtupleDColumn(8,0,x2);
	man->FillNtupleDColumn(8,1,y2);
	man->FillNtupleIColumn(8,2,evt2);
	man->FillNtupleIColumn(8,3,id);
	man->AddNtupleRow(8);}
		else if((posDetector.getY()*0.1 >= -0.009375000000000001) &&(posDetector.getY()*0.1 <= 0.28156250000000005) ){		
	int evt1 =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	 double x1=posDetector1.getX()+sep ;
	 double y1=posDetector1.getY();
	 man->FillNtupleDColumn(9,0,x1);
	man->FillNtupleDColumn(9,1,y1);
	man->FillNtupleIColumn(9,2,evt1);
	man->FillNtupleIColumn(9,3,id);
	man->AddNtupleRow(9);}
		//cout<<"X_"<<num1<<","<<posDetector1.getX()+sep<<","<<posDetector1.getY()<<","<<id<<endl;
		
		
		/// T- For Sipm to measure the  X  cor
	}


	

	//G4double edep = aStep ->GetTotalEnergyDeposit();
	//man->FillNtupleDColumn(1,edep / keV);
	
//	man->AddNtupleRow(0);
	//cout << edep1 << "	" <<"   "<<"   "<<y<<"		"<<z<<endl ;
	/*
	double d=0.23 ;
	//double x =(posDetector.getZ());
	int id ;

	if (x<d){
		id=1 ;
	} 
	else if (x>d){
		id=floor(x/d)+1 ;
	}*/
	
	//cout<<posDetector[0]<<endl;
		//G4cout<<x<<"     "<<"         "<<id<<"   " <<endl;
		//cout<<physVol<<endl;
//	int evt =G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	//cout<<evt<<endl;
	//man->FillNtupleDColumn(1,posDetector[0]);	
	//man->FillNtupleDColumn(2,posDetector[1]);	
	//man->FillNtupleDColumn(3,posDetector[2]);
	//man->AddNtupleRow(0);	
    return true;
}


ExG4DetectorSD::~ExG4DetectorSD()
{}

