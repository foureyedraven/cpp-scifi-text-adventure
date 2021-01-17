#include "Branch.hpp"
#include <iostream>
#include <string>

// custom constructor
Branch::Branch(int position, std::string text) {
  position_ = position;
  text_ = text;
}

// get
std::string Branch::getText() {
  return text_;
}
int Branch::getPosition() {
  return position_;
}

// set
// void Branch::setText(std::string text) {
//   text_ = text;
// }
