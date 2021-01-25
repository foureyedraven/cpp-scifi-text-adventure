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

// set
void Character::setName(std::string name) {
  name_ = name;
}

void Character::setKm(int km) {
  km_ += km;
}

void Character::setLocations(Location location) {
  locations_.push_back(location);
}

void Character::setProgress(std::string progress) {
  progress_.push_back(progress);
}
