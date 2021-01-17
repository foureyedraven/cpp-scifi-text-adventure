// #include "Choice.hpp"
#include <iostream>
#include <vector>
#include <string>
#pragma once

class Branch {
  public:
    Branch(int, std::string);
    std::string getText();
    int getPosition();

  private:
    int position_;
    std::string text_;
    // std::vector<Choice> choices;
};
