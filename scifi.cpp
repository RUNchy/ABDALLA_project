#include "G4RunManager.hh"
#include "G4UImanager.hh" // Менеджер взаимодействия с пользователем
#include "ExG4DetectorConstruction01.hh" // Структура детектора,
//должен определяться пользователем
#include "FTFP_BERT.hh" // Подключается физика и частицы
// используемые в проекте, использов предопределенный в Geant4
#include "ExG4ActionInitialization01.hh" // Пользовательские классы
//для получения данных о процессе моделирования
#include "G4VisExecutive.hh"//Визуализация
#include "G4UIExecutive.hh"//Выбор соответствуещего интерфейса пользователя
#include "physics.hh" 
#include "G4VModularPhysicsList.hh"
#include "G4MTRunManager.hh"
int main(int argc,char** argv)
{
    // Detect interactive mode (if no arguments) and define UI session
     //
     G4UIExecutive* ui = 0;
     if ( argc == 1 )
     {
       ui = new G4UIExecutive(argc, argv);
     }

CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
CLHEP::HepRandom::setTheSeed(time(NULL));

#ifdef G4MULTITHREADED
G4MTRunManager* runManager = new G4MTRunManager;
G4cout << "Multithreaded" << G4endl;
#else
G4RunManager* runManager = new G4RunManager;
G4cout << "Single threaded" << G4endl;
#endif
runManager->SetUserInitialization(new MyPhysicsList());
runManager->SetUserInitialization(new ExG4DetectorConstruction01);
runManager->SetUserInitialization(new ExG4ActionInitialization01);

//runManager->Initialize();

G4VisManager* visManager = new G4VisExecutive;
visManager->Initialize();

G4UImanager* UImanager = G4UImanager::GetUIpointer();
// Process macro or start UI session
//

if ( ! ui ) {
  // batch mode
  G4String command = "/control/execute ";
  G4String fileName = argv[1];
  UImanager->ApplyCommand(command+fileName);
    //std::cout << aRun;
}
else {
  // interactive mode
  UImanager->ApplyCommand("/control/execute init_vis.mac");
  ui->SessionStart();
  delete ui;
}

// Окончание работы, вызов деструктора (удаление) G4RunManager
 delete visManager;
 delete runManager;
return 0;
}
