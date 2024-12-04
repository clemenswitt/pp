#include <iostream>
#include <fstream>

int main() {
    std::ifstream file{"Text.ASC"};
    if(!file.is_open()) {
        std::cerr << "Error loading file" << std::endl;
    }

    int anzUpperZeichen{0};
    int anzLowerZeichen{0};

    char zeichen{};
    while (file.get(zeichen)) {
        if(zeichen == ' ' || zeichen == '\n') {continue;}
        if(std::toupper(zeichen) == zeichen) anzUpperZeichen++;
        else if (std::tolower(zeichen) == zeichen) anzLowerZeichen++;
    }
    std::cout << "Anzahl Kleinbuchstaben: " << anzLowerZeichen << std::endl;
    std::cout << "Anzahl Großbuchstaben: " << anzUpperZeichen << std::endl;
    return 0;
}
