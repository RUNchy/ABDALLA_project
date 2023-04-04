

#ifndef ExG4ActionInitialization01_h
#define ExG4ActionInitialization01_h 1
#include "G4VUserActionInitialization.hh"
#include "run.hh"
/// Action initialization class.
/// Обязательный класс, который должен быть объявлен в проекте Geant4
/// Имя класса может быть другим, и он долже наследоваться от
/// класса G4VUserActionInitialization

class ExG4ActionInitialization01 : public G4VUserActionInitialization
{
  public:
    ExG4ActionInitialization01();//Конструктор
     ~ExG4ActionInitialization01();//Деструктор
    virtual void Build() const;
    virtual void BuildForMaster() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
