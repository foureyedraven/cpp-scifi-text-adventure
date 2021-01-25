#include "Choice.hpp"
#include <iostream>
#include <string>

// custom constructor
Choice::Choice(std::string text, std::string personality, std::vector<std::string> location_types) {
    text_ = text;
    personality_ = personality;
    location_types_ = location_types;
}

// get
std::string Choice::getText() {
  return text_;
}

std::string Choice::getPersonality() {
  return personality_;
}

std::vector<std::string> Choice::getLocationTypes() {
  return location_types_;
}
