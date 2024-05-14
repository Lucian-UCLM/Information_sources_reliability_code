#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath> 

const int NUM_DOCUMENTS = 21173;
const int NUM_TOPICS = 20;
const std::string INPUT_FILE = ".\\data\\processed_composition.txt";

void readDocumentFile(const std::string& filename, double documents[NUM_DOCUMENTS][NUM_TOPICS]) {
    std::ifstream file(filename);
    std::string line;
    int i = 0;

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int id;
    int topicIndex;
    double topic;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> id; //Skipp the first two numbers
        iss >> id;

        topicIndex = 0;
        while (iss >> topic) {
            documents[i][topicIndex++] = topic;
        }
        i++;
    }
}

void printDocument(double documents[NUM_DOCUMENTS][NUM_TOPICS]) {
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        std::cout << "Document ID: " << i << std::endl;
        std::cout << "Topics: ";
        for (int j = 0; j < NUM_TOPICS; ++j) {
            std::cout << documents[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void calculateModulus(double documents[NUM_DOCUMENTS][NUM_TOPICS], double modulus[NUM_DOCUMENTS]) {
    double aux;
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        aux = 0.0;
        for (int j = 0; j < NUM_TOPICS; j++) {
            aux += documents[i][j] * documents[i][j];
        }
        modulus[i] = std::sqrt(aux);
    }
}

int main() {

    auto documents = new double[NUM_DOCUMENTS][NUM_TOPICS];
    auto similarity = new double[NUM_DOCUMENTS][NUM_DOCUMENTS];

    //maybe i can use another column in "documents" 
    //to store the modulus and not make another array
    auto modulus = new double[NUM_DOCUMENTS];

    readDocumentFile(INPUT_FILE, documents);

    calculateModulus(documents, modulus);

    // Calculate the similarity between documents
    double aux;

    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        for (int j = i; j < NUM_DOCUMENTS; j++) {
            aux = 0.0;
            if (i == j) {
                similarity[i][j] = 0.0;
                continue;
            }
            for (int k = 0; k < NUM_TOPICS; k++) {
                aux += documents[i][k] * documents[j][k];
            }
            similarity[i][j] = aux / (modulus[i] * modulus[j]);
        }
    }

    // Print the similarities in a file. This determines the format of the output file
    std::ofstream outputFile(".\\data\\similarity.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file" << std::endl;
        return 1;
    }

    //list of edges format
    outputFile << "source;target;weight;type" << std::endl;
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        for (int j = i+1; j < NUM_DOCUMENTS; j++) {
            //outputFile << i << ";" << j << ";" << similarity[i][j] << ";" << "undirected" << std::endl;
            outputFile <<  similarity[i][j] << "\t";
        }
        outputFile << std::endl;
    }
    outputFile.close();
    return 0;
}
