#include <iostream>

char getUserInput(std::string_view inputMessage) {
    char userInput {};
    std::cout << inputMessage;
    std::cin >> userInput;

    return userInput;
}



int main() {
    const int userInput {static_cast<int>(getUserInput("Geben Sie ein ASCII-Zeichen ein: "))};
    constexpr int verknuepfung{0x20};

    //Manipulator-Keywords für das std::ostream-Objekt, welches std::cout benutzt
    std::cout << "Hex-Darstellung: " << std::hex << userInput << "\n";
    std::cout << "Oct-Darstellung: " << std::oct << userInput << "\n";
    std::cout << "Dec-Darstellung: " << std::dec << userInput << "\n";

    //^ -> ist der Operator für XOR, beide Werte werden Bitweise XOR
    std::cout << "Verknüpfung XOR mit 0x20: " << (userInput^verknuepfung) << "\n";


}
