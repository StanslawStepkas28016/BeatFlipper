//
// Created by Stanisław Stepka on 08/04/2024.
//

#include <string>
#include <iostream>
#include <filesystem>
#include "../include/UtilityTool.h"
#include "../include/GlobalVariables.h"
#include "../include/OutputColors.h"


void UtilityTool::resolveHomePath() {
#ifdef _WIN32
    const char *homePath = std::getenv("USERPROFILE");
    if (homePath == nullptr) {
        OutputColors::setTextColor(4);
        std::cout << "Wystapil blad, przy wyszukiwaniu sciezki Home, napisz do mnie @prod.mustang!\n";
        OutputColors::setTextColor(7);
    }
    folderPath = std::filesystem::path(homePath) / "Biblioteki";
#else
    const char *homePath = std::getenv("HOME");
    if (homePath == nullptr) {
        std::cout << "\033[31m";
        std::cout << "Wystąpił błąd, przy wyszukiwaniu ścieżki HomePath, napisz do mnie @prod.mustang!\n";
        std::cout << "\033[0m";
    }
    folderPath = std::filesystem::path(homePath) / "Biblioteki";
#endif
}

void UtilityTool::displayWelcomeUI() {
#ifdef _WIN32
    std::system("cls");
    OutputColors::setTextColor(8);
    std::cout << "> BeatFlipper 2.0 - by Mustang <\n";
    OutputColors::setTextColor(7);
#else
    std::system("clear");
    std::cout << "\033[90m";
    std::cout << "> BeatFlipper 2.0 - by Mustang <\n";
    std::cout << "\033[0m";
#endif
}
