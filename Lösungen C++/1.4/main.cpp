#include <iostream>

int ggtRekursiv(const int a, const int b) {
    return b == 0 ? a : ggtRekursiv(b, a % b);
}

int ggtItterativ(int a, int b) {
    while(true) {
        if(b == 0) break;
        const int h = a % b;
        a = b;
        b = h;
    }
    return a;
}

int getUserInput(std::string_view inputText) {
    std::cout << inputText ;
    int input;
    std::cin >> input;

    return input;
}


int main() {
    //zum tracken der Anz. der Versuche erstellen wir eine lokale count-Variable
    int countVar {0};
    do {
        //erhöht die countVar um 1, Achtung: hier zu unterscheiden von countvar++, dies sind 2 unterschiedliche Operationen
        //1. ++countVar -> ++ Operator erhöht countVar um 1 und dann wird es returned (= more performant)
        //2. countVar++ -> es wird countvar kopiert, dann wird es erhöht und die Kopie wird zurückgegeben (= less performant)
        ++countVar;
        std::cout << "Versuch: " << countVar << '\n';

        const int zahlA{getUserInput("Geben Sie Zahl a ein: ")};
        const int zahlB{getUserInput("Geben Sie Zahl a ein: ")};

        std::cout << "GGT rekursiv: " << ggtRekursiv(zahlA, zahlB) << '\n';
        std::cout << "GGT iterativ: " << ggtItterativ(zahlA, zahlB) << '\n';

        std::cout << "-------------------------------------" << '\n';
    }while(countVar < 10);

}
