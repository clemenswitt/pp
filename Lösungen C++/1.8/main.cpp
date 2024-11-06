#include <iostream>


//Für s(n)=1+1/2+1/3+1/4+....+1/n
double GeradeSumme(const int summenGlieder) {
    double summe {0};
    for (int i = 1; i <= summenGlieder; ++i) {
        summe += 1.0/i;
    }
    return summe;
}

//Für s(n)=1+1/3+1/5+1/7+.... +1/n
double UngeradeSumme(const int summenGlieder) {
    double summe {0};
    for (int i = 1; i <= summenGlieder; i = i + 2) {
        summe += 1.0/i;
    }
    return summe;
}

//Für s(n)=1-1/2+1/3-1/4+-.... -+1/n
double VorzeichenwechselSumme(const int summenGlieder) {
    double summe {0};
    int vorzeichen {1};
    for (int i = 1; i <= summenGlieder; ++i) {
        summe += vorzeichen * (1.0 / i);
        vorzeichen = -vorzeichen;
    }

    return summe;
}

int getUserInput(std::string_view inputText) {
    std::cout << inputText;

    int userInput {};
    std::cin >> userInput;

    return userInput;
}


int main()
{
    //const int n {getUserInput("Wie viele Glieder sollen berechnet werden: ")};

    constexpr int testArray[] = {1,10,11,1000,1001,1000000,1000001};

    for(const int element : testArray) {
        std::cout << "Gerade Summe: " << GeradeSumme(element) << std::endl;

        std::cout << "Ungerade Summe: " << UngeradeSumme(element) << std::endl;

        std::cout << "Vorzeichenwechsel Summe: " << VorzeichenwechselSumme(element) << std::endl;
    }


    return 0;
}
