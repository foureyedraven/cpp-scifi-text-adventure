#include "Choice.hpp"
#include <iostream>
#include <vector>
#include <string>
#pragma once

class Branch {
  public:
    Branch(int, std::string, std::vector<Choice>);
    std::string getText();
    int getPosition();
    std::vector<Choice> getChoices();

  private:
    int position_;
    std::string text_;
    std::vector<Choice> choices_;
};
