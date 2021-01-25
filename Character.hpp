#include "Choice.hpp"
#include "Location.hpp"
#include <iostream>
#include <vector>
#include <string>
#pragma once


  class Character {
    public:
      // get
      std::string getName();
      int getKm();
      std::vector<Location> getLocations();
      std::vector<std::string> getProgress();

      // get last
      Location getLastLocation();
      
      // set
      void setName(std::string name);
      void setKm(int km);
      void setLocations(Location location);
      void setProgress(std::string progress);

    private:
      std::string name_;
      int km_;
      std::vector<Location> locations_;
      std::vector<std::string> progress_;
  };
