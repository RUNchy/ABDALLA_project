#include "physics.hh" 
#include "G4Scintillation.hh"
#include "G4SystemOfUnits.hh"
MyPhysicsList::MyPhysicsList()
{
	G4OpticalPhysics* opticalPhysics =new G4OpticalPhysics() ;		
	RegisterPhysics(new G4EmStandardPhysics());	
	RegisterPhysics(new G4OpticalPhysics());
	
}
MyPhysicsList::~MyPhysicsList()
{}
