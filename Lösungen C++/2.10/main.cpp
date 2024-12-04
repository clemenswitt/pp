#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

bool checkFileOpen(const std::ifstream& inputFile, const std::string& fileName) {
    if (!inputFile.is_open()) {
        std::cerr << "Die Datei " << fileName << " konnte nicht geöffnet werden!" << std::endl;
        return false;
    }
    return true;
}


bool checkFileOpen(const std::ofstream& outputFile, const std::string& fileName) {
    if (!outputFile.is_open()) {
        std::cerr << "Die Datei " << fileName << " konnte nicht erstellt werden!" << std::endl;
        return false;
    }
    return true;
}


std::vector<std::string> parseCSVLine(const std::string& line, char delimiter = ';') {
    std::vector<std::string> values;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        values.push_back(token);
    }
    return values;
}

void convertCSVToXML(const std::string& inputFileName, const std::string& outputFileName) {
    const std::array<std::string, 4> xmlCategories{"ID", "NAME", "ADRESSE", "TELEFON"};
    std::ifstream csvInput(inputFileName);
    std::ofstream out(outputFileName);

    if (!checkFileOpen(csvInput, inputFileName) || !checkFileOpen(out, outputFileName)) {
        return;
    }

    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    out << "<PERSONS>\n";

    std::string line{};
    while (std::getline(csvInput, line)) {
        std::vector<std::string> values = parseCSVLine(line);
        out << "  <PERSON>\n";
        for (size_t i = 0; i < values.size() && i < xmlCategories.size(); ++i) {
            out << "    <" << xmlCategories[i] << ">" << values[i] << "</" << xmlCategories[i] << ">\n";
        }
        out << "  </PERSON>\n";
    }

    out << "</PERSONS>\n";
    csvInput.close();
    out.close();
}

int main() {
    const std::string inputFileName = "BSP_CSV.FILE";
    const std::string outputFileName = "BSP_CSVCON.xml";

    convertCSVToXML(inputFileName, outputFileName);

    std::cout << "Datei in XML konvertiert!" << std::endl;
    return 0;
}