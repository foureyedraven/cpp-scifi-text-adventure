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
      // std::vector<Choice> getChoices();
      // std::vector<Location> getLocations();
      
      // get last
      // Location getLastLocation();
      // Choice getLastChoice();
      
      // set
      void setName(std::string name);
      void setKm(int km);
      // void setChoices(Choice choice);
      // void setLocations(Location location)

    private:
      std::string name_;
      int km_;
      // ? std::vector<Choice> choices;
      // ? std::vector<Location> locations;

  };
