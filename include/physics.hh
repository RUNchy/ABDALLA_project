#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4OpticalParameters.hh"
#include "G4Scintillation.hh"
class MyPhysicsList : public G4VModularPhysicsList 
{

public:
	MyPhysicsList();
	~MyPhysicsList();

};


#endif 
