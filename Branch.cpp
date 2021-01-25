#include "Branch.hpp"
#include <iostream>
#include <string>

// custom constructor
Branch::Branch(int position, std::string text, std::vector<Choice> choices) {
  position_ = position;
  text_ = text;
  choices_ = choices;
}

// get
std::string Branch::getText() {
  return text_;
}
int Branch::getPosition() {
  return position_;
}
std::vector<Choice> Branch::getChoices() {
  return choices_;
}

