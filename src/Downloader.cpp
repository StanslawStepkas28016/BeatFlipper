#include <string>
#include <iostream>
#include <unistd.h>
#include <regex>
#include "../include/Downloader.h"
#include "../include/GlobalVariables.h"
#include "../include/OutputColors.h"

/* Metoda pobiera wyznaczony przez użytkownika Bit, metoda jak sama nazwa wskazuje
 * zdefiniowana stricte pod użytkowników MacOs (sprawdzane na MacOs Ventura i Monterey). */
void Downloader::downloadAudioMacOs() {
    std::string link;
    std::string outputPath;

    std::system("clear");
    std::cout << "Wprowadź link do bita:\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadź, gdzie ma się pobrać Beat (ścieżka):\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, outputPath);

    std::erase(outputPath, '\'');

    std::string command = '"' + folderPath.string() + "/yt-dlp_macos" + '"' +
                          " -f bestaudio -x --audio-format wav --ffmpeg-location " + '"' + folderPath.string() + '"' +
                          " --no-playlist --quiet --ignore-errors --no-warnings --output "
                          + "'" + outputPath + "/%(title)s.%(ext)s'" + " \"" + link + "\"";

    // Usunięcie wyjścia z YT-DLP.
    command += " > /dev/null 2>&1";

    std::cout << "\n";
    std::cout << "Pobieram plik...\n";

    std::system(command.c_str());

    std::cout << "\n";
    std::cout << "\033[92m";
    std::cout << "Pobrano plik!\n";
    std::cout << "\033[0m";

    sleep(1);

    std::system("clear");
}

/* Metoda pobiera wyznaczony przez użytkownika Filmik, natywnie wybiera format mp4,
 * z Audio w codecu m4a/wav, w zależności od dostępnego formatu, metoda stricte pod MacOs/Unix. */
void Downloader::downloadVideoMacOs() {
    std::string link;
    std::string outputPath;
    std::string timestamps;

    std::system("clear");
    std::cout << "Wprowadź link do filmiku:\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, link);

    std::cout << "\n";

    do {
        std::cout << "Wprowadź zakres czasowy (np. 01:23-01:50) lub wciśnij enter jeśli chcesz pobrać cały plik:\n";

        std::cout << "\033[90m";
        std::cout << "> ";
        std::cout << "\033[0m";
        std::getline(std::cin, timestamps);

        std::regex timestampRegex(R"(\d{2}:\d{2}-\d{2}:\d{2})");
        if (!timestamps.empty()
            && !std::regex_match(timestamps, timestampRegex)) {
            std::system("clear");
            std::cout << "\033[31m";
            std::cout << "Wprowadziłeś timestamp'y niepoprawnie, użyj formatu mm:ss-mm:ss.\n";
            std::cout << "\033[0m";
            sleep(1);
            std::system("clear");
        } else {
            break;
        }
    } while (true);

    std::cout << "\n";
    std::cout << "Wprowadź, gdzie ma się pobrać filmik (ścieżka):\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, outputPath);

    std::erase(outputPath, '\'');

    std::string command = '"' + folderPath.string() + "/yt-dlp_macos" + '"';

    if (!timestamps.empty()) {
        command += " --download-sections \"*" + timestamps + "\"";
    }

    command += static_cast<std::string>(" --ffmpeg-location ") + '"' + folderPath.string() + '"' +
            " -S vcodec:h264,fps,res,acodec:m4a --no-warnings --no-playlist --output " +
            "'" + outputPath + "/%(title)s.%(ext)s'" + " \"" + link + "\"";

    if (!timestamps.empty()) {
        command += " --postprocessor-args \"-hide_banner -loglevel error\"";
    }

    // Usunięcie wyjścia z YT-DLP.
    command += " > /dev/null 2>&1";

    std::cout << "\n";
    std::cout << "Pobieram plik...\n";

    std::system(command.c_str());

    std::cout << "\n";
    std::cout << "\033[92m";
    std::cout <<
            "Pobrano plik, poczekaj chwilę (około 15 sekund) - plik musi zostać przekonwertowany na mp4, na ten moment moze pokazywac sie rozszerzenie .part :)\n";
    std::cout << "\033[0m";

    sleep(1);

    std::system("clear");
}

/* Metoda pobiera wyznaczony przez użytkownika Bit, metoda jak sama nazwa wskazuje
 * zdefiniowana stricte pod użytkowników Windows (sprawdzane na Windowsie 10 oraz 11). */
void Downloader::downloadAudioWindows() {
#ifdef _WIN32
    std::string link;
    std::string outputPath;

    std::system("cls");
    std::cout << "Wprowadz link do bita:\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadz, gdzie ma sie pobrac bit (sciezka np. C:\\Users\\Adam\\Downloads\\Bity):\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, outputPath);

    std::string command = "\"\"" + folderPath.string() + "\\yt-dlp.exe" + "\"" +
                          " -f bestaudio -x --audio-format wav --no-playlist --output "
                          + "\"" + outputPath + "\\%(title)s.%(ext)s\" " + "\"" + link + "\" > NUL\"";

    std::cout << "\n";
    std::cout << "Pobieram plik...\n\n";

    std::system(command.c_str());

    std::cout << "\n";
    OutputColors::setTextColor(10);
    std::cout << "Pobrano plik!\nZaraz nastapi przekierowanie do menu glownego :)";
    OutputColors::setTextColor(7);
    sleep(3);
#endif
}

/* Metoda pobiera wyznaczony przez użytkownika Filmik, natywnie wybiera format mp4,
 * z Audio w kodeku m4a/wav, w zależności od dostępnego formatu, metoda stricte pod Windows. */
void Downloader::downloadVideoWindows() {
#ifdef _WIN32
    std::string link;
    std::string outputPath;

    std::system("cls");
    std::cout << "Wprowadz link do Filmiku:\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadz, gdzie ma sie pobrac filmik (sciezka):\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, outputPath);

    std::string command = "\"\"" + folderPath.string() + "\\yt-dlp.exe" + "\"" +
                          " -S ext:mp4:m4a --no-playlist --output "
                          + "\"" + outputPath + "\\%(title)s.%(ext)s\" " + "\"" + link + "\" > NUL\"";

    std::cout << "\n";
    std::cout << "Pobieram plik...\n";
    std::cout << "Przy dluzszych filmikach moze potrwac to chwilke dluzej!\n";

    std::system(command.c_str());

    std::cout << "\n";
    OutputColors::setTextColor(10);
    std::cout << "Pobrano plik!\nOkno zamknie sie automatycznie za 3 sekundy :)";
    OutputColors::setTextColor(7);
    sleep(3);
#endif
}
