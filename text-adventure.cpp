// g++ *.cpp 
// ./a.out
// clear && g++ -std=c++11 *.cpp && ./a.out

// Imports
#include <iostream>
#include <string>
#include <vector>
#include "Location.hpp"
#include "Character.hpp"
#include "Branch.hpp"
#include "Choice.hpp"
#include <fstream>
#include <unistd.h>
#include <regex>

void readStoryText(std::string);
Location getNearestLocationByType(std::vector<std::string>);

// Main
int main() {
    // instantiate story data for event (branch), location, choice, attitude
    std::vector<Branch> branches;
    Choice choiceA1(" >> An NGO on Earth needs animal care interns. The atmosphere on Earth is decent, for now, and the work would be manual labour, cleaning up after the animals. There are few opportunities to get this close to real wildlife these days. What do you think?", "helper", {"water", "planet", "sparse population"});
    Choice choiceA2(" >> You could stay on Luna and intern for a tech company. Are you interested in the growing engineering space on Luna? Or maybe you just want to stay here for a while? Your work would entail doing minor jobs for full-time staff. You could make some good network connections that might help you later on. How about it?", "builder", {/* no input on location means stay put */});
    Choice choiceA3(" >> Flight school is a good option that lets you join the growing interplanetary delivery fleet. There are countless competitors vying for pilots, although the pay is on commission. This would certainly feed your travel bug, if you've got one. Do you want to do this?", "adventurer", {"air", "satellite?"});
    Choice choiceB1(" >> J wants to build a new product. Their parents are inventors, you know. It could be a solid bet. What do you have to offer? Do you trust J to make you a good deal? You're valuable, right? Even if your technical achievements are few. How about it?", "builder", {"dense", "rich"});
    Choice choiceB2(" >> TK is your older friend who wants to realise their dream of building a grocery and hardware co-op. You would be a financial investor as well as help build it from the ground up. Maybe you can bring in the customers, or maybe you can design the supply chain. Anything is up for grabs at this point. Do you want to do it?", "helper", {"earth", "dense"});
    Choice choiceB3(" >> C wants to rent one of those newer units and settle into the groove of their current life. That sounds relaxing, doesn't it? You can keep doing what you're doing here. Who needs change? Do you want to rent a home with your friend and stay a while?", "homebody", {/* no input on location means stay put */});
    Choice choiceC1(" >> Do you feel the need to work with your hands? Get in touch with the material world? Sitting in a chair most of the time can't be good for your body, or your soul!", "builder", {""});
    Choice choiceC2(" >> Do you feel the need to help people? Social action is very rewarding, or so I understand it. According to my data, people's happiness quotient rises when they feel they have helped others. Is this what you need?", "helper", {"populated"});
    Choice choiceC3(" >> Do you feel the need to be alone? Maybe society is getting you down, or you just need more time to yourself to reenergize. I can understand that, I think. Do you want to do something solo?", "loner", {"low population", "distant"});
    Choice choiceD1(" >> You want to start a book club? A multiplanetary one? I think that's a great idea. It's important to socialise, no matter where you are. And I know you have stories to tell! No, no, you've definitely lived a life! For what it's worth, I enjoy reading, or being, your diary. So, you gonna start a book club?", "social", {"planet"});
    Choice choiceD2(" >> You want to travel? It's true, there are plenty of opportunities and experiences elsewhere. The asteroids are known to  regenerate hearts and minds, since there isn't much to do but work and rest. It's a unique experience second to none. The moons tend towards exciting topology, whether ice, volcanoes or acidic gas. The research satellites are fun places to go. I've heard they have the best cafeterias and game rooms. So, wanna hitch a ride to the nearest small body?", "adventurer", {"tiny"});
    Choice choiceD3(" >> You want to build something with your own hands? That's an exciting prospect, and it will take you to more populated places that share resources. It would be too much to try to buy all the tools you need yourself, you'll need to join a co-op. Is this what you want to do? ", "social", {"populated"});
    Choice choiceE1(" >> Do you want to support the small business economy?", "", {});
    Choice choiceE2(" >> Do you want to lend a hand to the nearby humanitarian efforts?", "", {});
    Choice choiceE3(" >> Do you want to go to a small body and help build a new independent society from the massively multiplanetary corps colonies?", "", {});
    
    Choice final1("You're ready to start your own farm co-op in the unforgiving nearby LOCATION.BODY. ", "", {});
    Choice final2("You're not done traveling; you're getting your own ship and joining the gig workforce. By now, you'll have enough experience to grab seniority; your level of trust from your network is high. You're planning to be based out of the nearest satellite, LOCATION.BODY.", "", {});
    Choice final3("You believe supporting the natural world is the most important thing to do in this busy solar system. You're moving to LOCATION.BODY to work with an avian care NGO.", "", {});
    
    Branch firstEvent(0, "Now that you've graduated from Luna University with a degree in Arts & Humanities, what have you lined up for yourself? \n\nOh you haven't lined up a job yet? Well, lucky for you, the university Placement Program still has spaces left. Here are the choices. What are you interested in?\n\n", {choiceA1, choiceA2, choiceA3});
    Branch secondEvent(1, "The working world isn't the same as university life, is it? Less socialising, less comforts, less time to daydream. But hey, you're making your way in the world. This is what it was all for!\n\nI noticed you at least made a few new friends. Of course I read your diary, everything you do is recorded. You could even say I AM your diary. I'm here to help you make choices. So, how about those friends? Are you interested in joining them on something new?\n\n", {choiceB1, choiceB2, choiceB3});
    Branch thirdEvent(2, "Hey... I couldn't help but notice your entries have been downers lately. How is that venture with FRIEND going? Have you learned a lot about yourself lately? What would you say you've realized about yourself? Let's get you out of this rut and doing what you actually want to be doing with your life, finally! \n\n", {choiceC1, choiceC2, choiceC3});
    Branch fourthEvent(3, "Hey NAME, it's been a year. What do you think of the ATTITUDE life? Does it suit you? Oh, you're fixing to start something yourself? Like J or TK? I wonder how they're doing. Actually, I can tell you; J's product didn't work out, but they're working for a multiplanetary now. TK's co-op is still going, but it's not growing. I'll bet you will succeed, whatever that means for you. I've noticed your emotional health stats have stabilized and your happiness quotient is averaging higher than before. That's great! So, what's this new thing you want to do? \n\n", {choiceD1, choiceD2, choiceD3});
    Branch fifthEvent(4, "Good morning, NAME. Here is a review of your accomplishments. You've gone from BRANCH 1 to BRANCH 2 to BRANCH 3 and lately BRANCH 4, and have been KM km across the Solar System. You tend to be a/an ATTITUDE-type person. You have no appointments today.\n\nToday's news: Multiplanetary Corps Clash. Tensions between multiplans have escalated to physical attacks, where freighters have had their engines destroyed and left to drift in space. Some freights have been raided by unnamed groups, but so far all staff have been rescued by Red Sol humanitarian vessels. While multiplan CEOs have not claimed the attacks on each others' freights, Luna News has noticed competitors take advantage of open competitor trade routes immediately after the attacks.\n\nMedical Crisis on Earth. Several diseases have ripped through the farming co-ops on Earth, which may lead to losses in fabric and seed production for the satellites. Red Sol has deployed all available medical and transport staff to deliver aid and generate medicines for the Earth population.\n\nLuna Loses Economic Sovereignty. The Council of Earth has cancelled Luna's independent trade sovereignty over allegations that the Council of Luna's chief economist has been feeding competitor trade data to multiplans, which in turn led to the physical attacks on multiplan freighters. The Council of Earth fears these attacks will destroy smaller competitors, literally, and return the Solar System to interplanetary monopolies. The chief economist was last seen on a private vehicle bound for Venus's Eros luxury satellite.\n\nNot a slow news day!\n\nThere's something on your mind, isn't there? Something you've been meaning to do? Your latest endeavour has been very successful, but you're no longer just thinking about yourself. You want to help others. What do you want to do?\n\n", {choiceE1, choiceE2, choiceE3});

    branches.push_back(firstEvent);
    branches.push_back(secondEvent);
    branches.push_back(thirdEvent);
    branches.push_back(fourthEvent);
    branches.push_back(fifthEvent);
    
    // instantiate Locations
    Location sol("Sol Research Station", 0, 10000, 0, 180000, {"satellite", "tiny", "dense"});
    Location mercury("Mercury", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location venus("Venus", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location earth("Earth", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location luna("Luna", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location mars("Mars", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location asteroid1("Vesta", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location asteroid2("Fortuna", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location asteroid3("Hebe", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location europa("Europa", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location callisto("Callisto", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location saturnring("Saturn's Ring Satellite", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    Location titan("Titan", 1, 1000, 180000, 100000, {"planet", "tiny", "hot", "sparse", "earth"});
    


    std::vector<Location> solarsystem;
    solarsystem.push_back(sol);

    // instantiate character instance
    Character player;

    // intro setting
    // get player's character name
    std::string name;
    readStoryText("CONGRATULATIONS ON GRADUATING FROM LUNA UNIVERSITY\n\nWHAT NAME IS ON YOUR DIPLOMA?");
    std::cin >> name;
    std::cout << '\n';
    player.setName(name);
    readStoryText("WELCOME TO THE SOLAR SYSTEM, ");
    readStoryText(player.getName());

    // iterate through events (branches)
    for (Branch & it : branches) {
        std::string input;
        // print out story
        readStoryText(it.getText());
        while (input.size() == 0) {
            for (Choice & cit : it.getChoices()) {
                std::cout << cit.getText() << '\n' << '\n';
            }
            readStoryText("Type in some words from your choice, and hit enter.");
            std::cin >> input;
            
            // find chosen choice based on text matching
            for (Choice & cit : it.getChoices()) {
                if (std::regex_match (cit.getText(), std::regex(input))) {
                    // apply personality to progress
                    // choose location based on location_reqs
                    // add location to player.history
                    // increment player km traveled
                    player.setProgress(cit.getPersonality());
                    player.setLocations(getNearestLocationByType(cit.getLocationTypes()));
                }
            }
        }
        
        input.erase();
        // print out delay of . . . . 
        // if going to a new location; "You're headed to: NAME" else "You're on: NAME"
        // print out scene of location. relative sunlight from last? "the sun is a little dimmer"
        // print out delay of . . . . or (time passes...) before repeat
    }

    // calculate ending based on player.progress
    // print out ending
}

// define game functions
// method to read out text one character at a time with a half second pause after characters and 1 second pause after new lines or terminal punctuation
// // adds \n\n after each text body
// // replaces caps words with pointers?
// // could CAPS or whatever key words be replaced with pointers to proper case, and log to progress vectors?
// // 
void readStoryText(std::string text) {
    // print text one character at a time
    for (char i : text) {
        int delay = 50000;
        std::cout << i;
        fflush( stdout );
        if (i == '\n' || i == '.' || i == '?') {
            usleep(delay * 10);
        } else {
            usleep(delay);
        }
    }
    std::cout << '\n' << '\n';
}

// method to derive nearest location for selected choice, and add to user's progress
// // based on types listed in choice
// // if no types listed, stay put
// // if nearest bodies dont contain types, check next nearest
// // or maybe order all locations by distance, and choose first best choice
Location getNearestLocationByType(std::vector<std::string> location_type) {
    // sort locations by how close in KM?
    // compare given location_type with vector of Locations
}


