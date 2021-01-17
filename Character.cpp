#include "Character.hpp"
#include <iostream>
#include <string>

// get
std::string Character::getName() {
  return name_;
}

int Character::getKm() {
  return km_;
}
    
      // std::vector<Choice> getChoices();
      // std::vector<Location> getLocations();
      
      // // get last
      // Location getLastLocation();
      // Choice getLastChoice();
      
// set
void Character::setName(std::string name) {
  name_ = name;
}

void Character::setKm(int km) {
  km_ += km;
}

      // void setChoices(Choice choice);
      // void setLocations(Location location);