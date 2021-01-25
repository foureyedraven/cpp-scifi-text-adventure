#include <iostream>
#include <vector>
#include <string>
#pragma once

class Choice {
    public:
        Choice(std::string, std::string, std::vector<std::string>);
        std::string getText();
        std::string getPersonality();
        std::vector<std::string> getLocationTypes();
    private:
        std::string text_;
        std::string personality_;
        std::vector<std::string> location_types_;
};
