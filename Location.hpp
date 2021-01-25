#include <iostream>
#include <vector>
#include <string>
#pragma once

  class Location {
    public:
      Location(std::string, int, int, int, int, std::vector<std::string>);
      std::string getName();
      int getPosition();
      int getCost();
      int getKmFore(); //AU as float
      int getKmAft();
      std::vector<std::string> getTypes();

    private:
      std::string name_;
      int position_;
      int cost_;
      int km_fore_;
      int km_aft_;
      std::vector<std::string> types_;
};
