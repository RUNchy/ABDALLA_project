#include "ExG4PrimaryGeneratorAction01.hh"
// Подключаем необходимы заголовочные файлы
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include <cmath>



int iRun = 0;





ExG4PrimaryGeneratorAction01::ExG4PrimaryGeneratorAction01()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
{
	
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
    
   
    

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
 
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="e-");
  
  fParticleGun->SetParticleDefinition(particle);
  //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,-0.11,-1.29));
  
 fParticleGun->SetParticleEnergy(10*GeV);
}
//0.5 , 1.5 , 2 ,4(sk3) ,6(sk4) ,8(sk5),10(sk6)
ExG4PrimaryGeneratorAction01::~ExG4PrimaryGeneratorAction01()
{
  delete fParticleGun;
}




void ExG4PrimaryGeneratorAction01::GeneratePrimaries(G4Event* anEvent)
{
	
	double pi  = 3.14159265358979323846;
    double thetaMin=45*pi/180;
    double thetaMax=73*pi/180 ;
	double theta = thetaMin + G4UniformRand() * (thetaMax - thetaMin);
  G4double x0 = 0 *cm;
  G4double y0 = 9*cm;
  //G4double z0 = (0.5 * 1.25 +  0.00625*0.5)*cm;
  G4double z0 = (3.51)*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(theta,-1.,0.));
  //double energy =(G4UniformRand()+0.1)*10 *GeV ;
 	//fParticleGun->SetParticleEnergy(energy);
  fParticleGun->GeneratePrimaryVertex(anEvent);

    iRun++;
}
