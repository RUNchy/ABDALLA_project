
#include "ExG4ActionInitialization01.hh"
#include "ExG4PrimaryGeneratorAction01.hh"

ExG4ActionInitialization01::ExG4ActionInitialization01()
 : G4VUserActionInitialization()
{}

//Деструктор
ExG4ActionInitialization01::~ExG4ActionInitialization01()
{}
//Создание начального источника частиц
void ExG4ActionInitialization01::BuildForMaster() const
{

   MyRunAction *runAction =new MyRunAction(); 
    SetUserAction(runAction);

}




void ExG4ActionInitialization01::Build() const
{

	ExG4PrimaryGeneratorAction01 *generator =new ExG4PrimaryGeneratorAction01();
	SetUserAction(generator);//Задается начальный 
   
   MyRunAction *runAction =new MyRunAction(); 
    SetUserAction(runAction);
    

}
