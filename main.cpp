
#include "Player.h"


int main() {
    std::cout << "Add track enter\t  < 1 >" << std::endl
              << "Show track list\t  < 2 >" << std::endl
              << "Play enter\t  < 3 >" << std::endl
              << "Pause enter\t  < 4 >" << std::endl
              << "Next enter\t  < 5 >" << std::endl
              << "Stop enter\t  < 6 >" << std::endl
              << "Exit enter\t  < 0 >" << std::endl;

    auto *player = new Player;
    char ch;
    do {
        std::cout << "\nEnter the command: ";
        std::cin >> ch;
        switch (ch) {
            case '1':
                player->addTrack();
                break;
            case '2':
                player->displayTrackList();
                break;
            case '3':
                if ((!player->getPlay()) && (!player->getPause())) {
                    if (player->findTrack()) {
                        player->setPlay(true);
                        player->setPause(false);
                    }
                }
                break;
            case '4':
                if ((player->getPlay()) && (!player->getPause())) {
                    player->setPause(true);
                }
                break;
            case '5':
                player->nextTrack();
                break;
            case '6':
                std::cout << "Stop. " << std::endl;
                player->setPause(false);
                player->setPlay(false);
                break;
            case '0':
                std::cout << "Exit. " << std::endl;
                break;
            default:
                std::cout << "Enter error! " << std::endl;
                continue;
        }

    } while (ch != '0');

    delete player;
    player = nullptr;

    return 0;
}