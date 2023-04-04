#include "ExG4DetectorConstruction01.hh"
#include "ExG4DetectorSD.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4RotationMatrix.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"


ExG4DetectorConstruction01::ExG4DetectorConstruction01()
: G4VUserDetectorConstruction()
{ }



ExG4DetectorConstruction01::~ExG4DetectorConstruction01()
{ }



G4VPhysicalVolume* ExG4DetectorConstruction01::Construct()
{  
 
  G4NistManager* nist = G4NistManager::Instance();
    
//-------------------------------------------------------------------------------------------

  G4Material* det_mat = nist->FindOrBuildMaterial("G4_POLYSTYRENE");

  G4bool checkOverlaps = false; //// =========>> overlaps check 

//-------------------------------------------------------------------------------------------
    
  // Detector parameters

  
	
  std::vector<G4double> energy = {1.239841939*eV/0.9, 1.239841939*eV/0.2};
  std::vector<G4double> rindexPolystyrene = {1.59, 1.57};
  std::vector<G4double> lxe_ABSL  = { 35. * cm, 35. * cm};
  std::vector<G4double> air_absl  = { 0.009150635 *cm,0.009150635 *cm};
  std::vector<G4double> rindexInner = {1.49,1.49};
  std::vector<G4double> rindexOutter = {1.42,1.42};
  std::vector<G4double> scint= { 0.1, 1.0 };
  std::vector<G4double> rin_air= {1,1};
  std::vector<G4double> ri_si= {1.58,1.58};
  std::vector<G4double> efficiency   = { 0.0, 0.47 };
  
    G4MaterialPropertiesTable *mptPolystyrene = new G4MaterialPropertiesTable();
	  mptPolystyrene->AddProperty("RINDEX", energy, rindexPolystyrene);
	  mptPolystyrene->AddProperty("SCINTILLATIONCOMPONENT1",energy,scint);
	 	mptPolystyrene->AddProperty("ABSLENGTH", energy, lxe_ABSL);
	  mptPolystyrene->AddConstProperty("SCINTILLATIONYIELD" , 8000./MeV);
	  mptPolystyrene->AddConstProperty("SCINTILLATIONTIMECONSTANT1" , 2.8*ns);
	  mptPolystyrene->AddConstProperty("RESOLUTIONSCALE" , 1.0);
	  mptPolystyrene->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
	  mptPolystyrene->AddConstProperty("SCINTILLATIONYIELD2", 0.0);
	  det_mat->SetMaterialPropertiesTable(mptPolystyrene);
	  
	  /// for C5H8O2 inner-shell 
  G4Material* det_mat1 =new G4Material("C4H8O2",1.19*g/cm3,3);
		 det_mat1->AddElement(nist->FindOrBuildElement("C"),4);
		 det_mat1->AddElement(nist->FindOrBuildElement("H"),8);
		 det_mat1->AddElement(nist->FindOrBuildElement("O"),2);
		 G4MaterialPropertiesTable *mpInner = new G4MaterialPropertiesTable();
		 mpInner->AddProperty("RINDEX",energy,rindexInner,2);
		 det_mat1->SetMaterialPropertiesTable(mpInner);

 //////////////Defining elements //////////////
		 G4Element* C =nist->FindOrBuildElement("C"); 
		 G4Element* H =nist->FindOrBuildElement("H"); 
		 G4Element* O=nist->FindOrBuildElement("O");
		 G4Element* F=nist->FindOrBuildElement("F");
  /// for   C4H5O2F3        outter-shell ////////// 
	G4Material* det_mat2 =new G4Material("C4H5O2F3",1.43*g/cm3,4);
		 det_mat2->AddElement(C,4);
		 det_mat2->AddElement(H,5);
		 det_mat2->AddElement(O,2);
		 det_mat2->AddElement(F,3);
	G4MaterialPropertiesTable *mpOutter = new G4MaterialPropertiesTable();
		 mpOutter->AddProperty("RINDEX",energy,rindexOutter,2);
		 det_mat2->SetMaterialPropertiesTable(mpOutter);
		 
////////////// detector parameters ///////////////
  G4double innerRadius = 0.*cm;
  G4double outerRadius = 0.0125*cm;
  G4double hx = 3.5*cm;
  G4double startAngle = 0.*deg;
  G4double spanningAngle = 360.*deg;
  G4double zShift = outerRadius*1.7320508075688772;
  double D5=0.025*cm;
  G4double R = (0.0125-(0.0125*0.06))*cm;
  G4double innerRadius1 = R;
  G4double R1 = (0.0125-(0.0125*0.03))*cm;

  G4double innerRadius2 = R1;
  G4double R2 = 0.0125*cm;
  
  G4RotationMatrix rotm  = G4RotationMatrix();
  rotm.rotateY(90*deg);
    
    
   G4RotationMatrix rotm1  = G4RotationMatrix();
  rotm1.rotateZ(90*deg);
  ///###########################################
  //######### 1 -layer ######################
  //#####################################
  //G4ThreeVector position11 = G4ThreeVector(0,0,0*cm);
  //G4Transform3D transform11 = G4Transform3D(rotm,position11);

    double si_y =(0.00625/2)*cm;
	double si_z =(0.00575/2)*cm;
	double si_x =(0.00575/2)*cm ;
    


  	 G4Element* Si =new G4Element("Silicon","Si",14.,28.09*g/mole) ;
    G4Material *sipm_mat=new G4Material ( "SiPM" , 2.33*g/cm3,1);
		sipm_mat->AddElement(Si,1);
	
	G4MaterialPropertiesTable *si_mat = new G4MaterialPropertiesTable();
	si_mat->AddProperty("RINDEX",energy,ri_si,2);
	//si_mat->AddProperty("EFFICIENCY",energy,efficiency,2);
	sipm_mat->SetMaterialPropertiesTable(si_mat);
    
    
    
 
  G4double world_sizeXY = 30*cm;//Размер по x и y будут одинаковы - ширина и высота
  G4double world_sizeZ  = 30*cm;//Размер по z - толщина
  // Выбор материала для мира из предопределенных в Geant4, берем воздух
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");
  G4MaterialPropertiesTable *air = new G4MaterialPropertiesTable();
  air->AddProperty("RINDEX",energy,rin_air,2);
  air->AddProperty("ABSLENGTH", energy, air_absl);
  world_mat->SetMaterialPropertiesTable(air);
  // Создание объема для мира, определяется просто сама форма объема, берем параллелепипед
  G4Box* solidWorld =
    new G4Box("World",                       //its name, название объема
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size, его размеры
    
    

  // Логический объем, здесь подключается материал, из которого сделан объем
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid, объем
                        world_mat,           //its material, материал объема
                        "World");            //its name, название логического объема
                                             //совпадает с названием объема, но
                                             //для Geant4 это разные объекты
                                             //объем и логический объем

  //Физический объем, а теперь наш логический объем помещаем в "ральный" мир
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation, нет вращения
                      G4ThreeVector(),       //at (0,0,0), расположение в центре (0,0,0)
                      logicWorld,            //its logical volume, логический объем этого физического
                      "World",               //its name, название физического объема
                      0,                     //its mother  volume, материнский объем, этот самый первый
                      false,                 //no boolean operation, без логических (булевых) операций
                      0,                     //copy number, номер копии
                      checkOverlaps);        //overlaps checking, флаг проверки перекрытия объемов
                     
  ///////////////////////////////////////////////////////////////////////////////////////////


///// sipm/////////////////////

/*G4Box *solidDetector =new G4Box("SolidDetector",si_y,si_y,si_z);
  G4LogicalVolume* logicDet_si = new G4LogicalVolume(solidDetector, sipm_mat, "logicDet_si"); */
////////////////

///////// inner layer /////////////
G4Tubs* solidDInner = new G4Tubs("solidDInner", innerRadius1, R1, hx, startAngle, spanningAngle);

  
 G4LogicalVolume* logicDetInner = new G4LogicalVolume(solidDInner, det_mat1, "logicDetInner");


////////////////////
//////////////// outter layer //////////////

 G4Tubs* solidDOuter = new G4Tubs("solidDOuter", innerRadius2, R2, hx, startAngle, spanningAngle);

  
 G4LogicalVolume* logicDetOuter = new G4LogicalVolume(solidDOuter, det_mat2, "logicDetOuter");  


////////////////
///////// detector construction /////////////

  G4Tubs* solidDet11
    = new G4Tubs("Detector",
                 innerRadius,
                 R,
                 hx,
                 startAngle,
                 spanningAngle);

  //Логический объем
  G4LogicalVolume* logicDet =
    new G4LogicalVolume(solidDet11,           
                        det_mat,            
                       "Detector");    
   //G4VisAttributes* worldAtt= new G4VisAttributes(G4Colour(1.0,1.0,1.0));
	//logicDet11 ->SetVisAttributes(worldAtt);     
  for(int i=0;i<120;i++){ ///////for(int i=0;i<120;i++)
  			for(int j=0;j<280;j++){ /////for(int j=0;j<280;j++)
  			double inc = (i % 2 == 0) ? 0 : 0.5*D5;
  			double sep ;
  		if ((i >= 12)&&(i<24)  ){ sep =0.5*cm ;}
    else if ((i >= 24)&&(i<36)  ){ sep =2*0.5*cm ;}
    else if ((i >= 36)&&(i<48)  ){ sep = 3 *0.5*cm ;}
    else if ((i >= 48)&&(i<60) ){ sep = 4*0.5*cm ;}
    else if ((i >= 60)&&(i<72) ){ sep = 5*0.5*cm ;}
    else if ((i >= 72)&&(i<84) ){ sep =6*0.5*cm ;}
    else if ((i >= 84)&&(i<96) ){ sep =7*0.5*cm ;}
    else if ((i >= 96)&&(i<108) ){ sep =8*0.5*cm ;}
    else if ((i >= 108)&&(i<120) ){ sep =9*0.5*cm ;}
    else if ((i <12)) { sep = 0 ;}
if ( (i < 6) || ((i>=12) && (i<18 )) || ((i>=24) && (i<30) ) || ((i>=36) && (i<42) ) || ((i>=48) && (i<54 )) || ((i>=60) && (i<66 )) || ((i>=72) && (i<78 )) || ((i>=84) && (i<90 )) || ((i>=96) && (i<102 )) || ((i>=108) && (i<114 ))   ) {	
 		 new G4PVPlacement(G4Transform3D(rotm,G4ThreeVector(0,0.866025404*i*D5+sep,(D5 + j*D5+inc))),               
                    logicDet,                
                    "Detector",             
                    logicWorld,             
                    false,                  
                    0,                       
                    checkOverlaps);   
                     
                    
     new G4PVPlacement(G4Transform3D(rotm,G4ThreeVector(0,0.866025404*i*D5+sep,(D5 + j*D5+inc))),               
                    logicDetInner,                
                    "DetInner",             
                    logicWorld,             
                    false,                  
                    0,                       
                    checkOverlaps);       
                    
     new G4PVPlacement(G4Transform3D(rotm,G4ThreeVector(0,0.866025404*i*D5+sep,(D5 + j*D5+inc))),               
                    logicDetOuter,                
                    "DetOutter",             
                    logicWorld,             
                    false,                  
                    0,                       
                    checkOverlaps);  
                 } 
     else {
     
     	new G4PVPlacement(G4Transform3D(rotm1,G4ThreeVector((D5+ j*D5+inc-hx),0.866025404*i*D5+0.03*cm+sep,hx)),               
                    logicDet,                
                    "Detector",             
                    logicWorld,             
                    false,                  
                    0,                       
                    checkOverlaps);  
                    
      new G4PVPlacement(G4Transform3D(rotm1,G4ThreeVector((D5+ j*D5+inc-hx),0.866025404*i*D5+0.03*cm+sep,hx)),               
                    logicDetInner,                
                    "DetInner",             
                    logicWorld,             
                    false,                  
                    0,                       
                    checkOverlaps);  
                    
     	new G4PVPlacement(G4Transform3D(rotm1,G4ThreeVector((D5+ j*D5+inc-hx),0.866025404*i*D5+0.03*cm+sep,hx)),               
                    logicDetOuter,                
                    "DetOutter",             
                    logicWorld,             
                    false,                  
                    0,                       
                    checkOverlaps);  
     
    		 }      
}
}

G4Box *solidDetector =new G4Box("SolidDetector",si_y,si_y,si_z);
 G4LogicalVolume* logicDet_si = new G4LogicalVolume(solidDetector, sipm_mat, "logicDet_si"); 
 for(int i=1;i<=440;i++){ /////////for(int i=1;i<=440;i++)
  			
  			for(int j=1;j<1223;j++){ /////////for(int j=1;j<1223;j++)
  			
  			double sep1 ;
  			if( (i >=1) && (i<=44) ){ sep1 =0;}
  			else if ( (i>44) && (i<=88)) {sep1 =0.5*cm-3*D5/4+si_y/2 ;}
  			else if ( (i>88) && (i<=132)) {sep1 =2*0.5*cm-3*D5/2+3*si_y/2 ;}
  			else if ( (i>132) && (i<=176)) {sep1 =3*0.5*cm-2*D5+3*si_y/2;}
  		  	else if ( (i>176) && (i<=220)) {sep1 =4*0.5*cm-2*D5-4*si_y;}
  		  	else if ( (i>220) && (i<=264)) {sep1 =5*0.5*cm-5*D5/2-5*si_y;}
  		  	else if ( (i>264) && (i<=308)) {sep1 =6*0.5*cm -3*D5-6*si_y;}
  		  	else if ( (i>308) && (i<=352)) {sep1 =7*0.5*cm -4*D5-3.5*si_y/2;}
  		  	else if ( (i>352) && (i<=396)) {sep1 =8*0.5*cm-5*D5+si_y;}
  		  	else if ( (i>396)) {sep1 =9*0.5*cm-0.125*cm-4*si_y;}
  			if( ((i>= 1) && (i<=22)) || ((i>44) && (i<=66)) || ((i>88) && (i<=110)) || ((i>132) && (i<=154)) || ((i>176) && (i<=198)) || ((i>220) && (i<=242)) || ((i>264) && (i<=286)) || ((i>308) && (i<=330)) || ((i>352) && (i<=374)) || ((i>396) && (i<=418))){ 
  			 G4VPhysicalVolume* phys_Sipm = 
    new G4PVPlacement(0,                    
                      G4ThreeVector(-hx-(si_y),si_y*2*i-D5/2-si_y+sep1,si_z*2*j),      
                      logicDet_si,           
                      "logicDet_siZ",              
                      logicWorld,                     
                      false,                 
                      j,                     
                      checkOverlaps);  ///checkOverlaps
  			}
  			
  		else {
  		
  		G4VPhysicalVolume* phys_Sipm = new G4PVPlacement(G4Transform3D(rotm,                    
                      G4ThreeVector(si_z*2*j-hx,si_y*2*i-D5/2-7*si_y/2+0.03*cm+sep1,2*hx+si_y)),    
                      logicDet_si,           
                      "logicDet_siX",              
                      logicWorld,                     
                      false,                 
                      j,                     
                      checkOverlaps);  ///checkOverlaps
  		
  		
  		}
  			}
  			}


///////////////////////////////////////////////////////////////////////////////////////////////   
    //////////////////////////////////////////////////////////////////////////

    
    //always return the physical World
  //Всегда возвращает физический объем
  //
 
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    
    
void ExG4DetectorConstruction01::ConstructSDandField()
{
	
   
   
   //  ExG4DetectorSD *sensDet = new ExG4DetectorSD("Detector");
	//logicDet->SetSensitiveDetector(sensDet);
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
	ExG4DetectorSD *detector = new ExG4DetectorSD("DetectorSD");
	SDman->AddNewDetector(detector);
	SetSensitiveDetector("logicDet_si", detector);
	//SetSensitiveDetector("Detector", detector);

  

}
