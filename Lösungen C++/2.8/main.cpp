#include <iostream>
#include <fstream>
#include <cctype> //toUpper
int main()
{
    std::ifstream file{"Text.ASC"};
    if(!file.is_open()) {
        std::cerr << "Error loading file" << std::endl;
    }

    char uInput{};
    std::cout << "Bitte einen Buchstaben eingeben: ";
    std::cin >> uInput;

    int gesamtAnzZeichen{0};
    int anzGesZeichen{0};
    char zeichen;
    while(file.get(zeichen)) {
        if (zeichen == '\n' || zeichen == ' ') { continue;}
        gesamtAnzZeichen++;
        if(std::tolower(uInput) == std::tolower(zeichen)) {
            anzGesZeichen++;
        }
    }
    std::cout << "Anzahl gesuchte Zeichen: " << anzGesZeichen << std::endl;
    std::cout << "Anzahl gesamte Zeichen: " << gesamtAnzZeichen << std::endl;
    file.close();
}
