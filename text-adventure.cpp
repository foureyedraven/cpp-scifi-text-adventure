// Imports
#include <iostream>
#include <string>
#include <vector>
#include "Location.hpp"
#include "Character.hpp"
#include "Branch.hpp"
#include "Choice.hpp"
#include <fstream>

// Main
int main() {
    // instantiate story data for event, location, choice, attitude
    // read story data for Branches (life events)
    std::ifstream infile("branches.txt");
    
    for (std::string line; std::getline(infile, line);) {
        std::vector<std::string> texts;
        texts.push_back(line);
        // if (!(iss >> text)) { break; } // error
    }
    // Branch first(0, "This is your first life event.\n");
    // Branch second(1, "This is your second life event.\n");
    // Branch third(2, "This is your third life event.\n");
    // Branch fourth(3, "This is your fourth life event.\n");
    // std::vector<Branch> branches;
    // find alt arr insert
    // branches.push_back(first);
    // branches.push_back(second);
    // branches.push_back(third);
    // branches.push_back(fourth);

    // read story data for Choices (per Branch)

    // instantiate character instance
    Character player;

    // intro setting
    // get player's character name
    // 
    std::string name;
    std::cout << "\nCONGRATULATIONS ON GRADUATING FROM LUNA UNIVERSITY\n\nWHAT NAME IS ON YOUR DIPLOMA?\n\n";
    std::cin >> name;
    player.setName(name);
    std::cout << "\nWELCOME TO THE SOLAR SYSTEM,\n" << player.getName() << "\n\n";

    // iterate through events (branches)
    // read intro
    // read choices
    // loop for user feedback
    // Loop through Branches, except last one, which
    // is run automatically through calculating Character
    // for (int i = 0; i < branches.size()-1; i++) {
    // std::string input;
    // std::cout << branches[i].getText();
    // while (input.size() == 0) {
    //     std::cin >> input;
    // }
    // }
}

// define game functions
// method to add user choice to progress vector
// method to derive nearest location for selected choice, and add to user's progress
// method to read out text one character at a time with a half second pause after characters and 1 second pause after new lines or .

