#include "Location.hpp"
#include <iostream>
#include <string>

// custom constructor
Location::Location(
    std::string name,
    int position,
    int cost,
    int km_fore,
    int km_aft,
    std::vector<std::string> types
) {
    name_ = name;
    position_ = position;
    cost_ = cost;
    km_fore_ = km_fore;
    km_aft_ = km_aft;
    types_ = types;
}

// get
std::string Location::getName() {
  return name_;
}
int Location::getPosition() {
  return position_;
}
std::vector<std::string> Location::getTypes() {
  return types_;
}
int Location::getCost() {
    return cost_;
}
int Location::getKmFore() {
    return km_fore_;
}
int Location::getKmAft() {
    return km_aft_;
}

