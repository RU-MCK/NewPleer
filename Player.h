#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Player {
    class Track {
    public:
        std::string nameTrack = "noname";
        std::string dateTrack = "nodate";
        int duration = 0;
    };

    std::vector<Track> trackList{};
    bool play;
    bool pause;
public:
    Player();

    void setPlay(bool flag) { play = flag; }

    void setPause(bool flag) { pause = flag; }

    bool getPlay() const { return play; }

    bool getPause() const { return pause; }

    void addTrack();

    void displayTrackList() const;

    bool findTrack() const;

    void nextTrack() const;
};

Player::Player() {
    play = false;
    pause = false;
    trackList = {{"One",   "02.06.2012", 369},
                 {"Two",   "15.05.1998", 426},
                 {"Three", "31.12.2022", 560}};
}


void Player::addTrack() {
    char ch = 'y';
    Track track;
    while (ch == 'y') {
        std::cout << "\nEnter track name: ";
        std::cin >> track.nameTrack;
        std::cout << "Enter creation date (11.11.2011): ";
        std::cin >> track.dateTrack;
        if (track.dateTrack.size() != 10) {
            std::cout << "Enter error date.Repeat.";
            continue;
        }
        std::cout << "Enter duration track: ";
        std::cin >> track.duration;
        if (track.duration <= 0) {
            std::cout << "Enter error duration.Repeat.";
            continue;
        }
        Player::trackList.push_back(track);

        std::cout << "Add another track? (y/n) ";
        std::cin >> ch;
    }
}

void Player::displayTrackList() const {
    std::cout << std::endl;
    for (auto &track: trackList)
        std::cout << "\nTrack name: " << track.nameTrack
                  << "\nTrack creation: " << track.dateTrack
                  << "\nTrack duration: " << track.duration
                  << std::endl;

}

bool Player::findTrack() const {
    std::string name;
    std::cout << "Enter track name: ";
    std::cin >> name;
    for (auto &track: trackList) {
        if (track.nameTrack == name) {
            std::cout << "\nPlaying: " << track.nameTrack << " >>> "
                      << track.dateTrack << " >>> "
                      << track.duration << " >>>" << std::endl;
            return true;
        }
    }
     std::cout << "\nTrack not found." << std::endl;
    return false;
}

void Player::nextTrack() const {
    int i = 0;
    srand(time(nullptr));
    i = rand() % trackList.size();
    std::cout << "\nPlaying: " << trackList[i].nameTrack << " >>> "
              << trackList[i].dateTrack << " >>> "
              << trackList[i].duration << " >>>" << std::endl;
}
