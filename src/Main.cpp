#include <iostream>
#include <string>
#include <unistd.h>
#include "../include/Downloader.h"
#include "../include/OutputColors.h"
#include "../include/UtilityTool.h"

int main() {
    UtilityTool::resolveHomePath();
#ifdef _WIN32
    UtilityTool::displayWelcomeUI();
    std::string userInput;
    do {
        std::cout << "Wybierz co chcesz pobierac (wprowadz cyferke):\n";
        std::cout << "1. Audio.\n";
        std::cout << "2. Video.\n";
        std::cout << "3. Zakoncz.\n";

        OutputColors::setTextColor(8);
        std::cout << "> ";
        OutputColors::setTextColor(7);

        std::getline(std::cin, userInput);

        if (userInput == "1") {
            Downloader::downloadAudioWindows();
        } else if (userInput == "2") {
            Downloader::downloadVideoWindows();
        }
        else if (userInput == "3") {
            break;
        }
        else {
            std::system("cls");
            OutputColors::setTextColor(4);
            std::cout << "Wprowadzono niepoprawna cyferke!\n";
            OutputColors::setTextColor(7);
            sleep(1);
            UtilityTool::displayWelcomeUI();
        }
    } while (true);
#else
    std::string userInput;
    UtilityTool::displayWelcomeUI();
    do {
        std::cout << "Wybierz co chcesz pobierać:\n";
        std::cout << "1. Audio.\n";
        std::cout << "2. Video.\n";
        std::cout << "3. Zakończ.\n";

        std::cout << "\033[90m";
        std::cout << "> ";
        std::cout << "\033[0m";

        std::getline(std::cin, userInput);

        if (userInput == "1") {
            Downloader::downloadAudioMacOs();
        } else if (userInput == "2") {
            Downloader::downloadVideoMacOs();
        } else if (userInput == "3") {
            break;
        } else {
            std::system("clear");
            std::cout << "\033[31m";
            std::cout << "Wprowadzono niepoprawna cyferkę!\n";
            std::cout << "\033[0m";
            sleep(1);
            UtilityTool::displayWelcomeUI();
        }
    } while (true);
#endif

    return 0;
}