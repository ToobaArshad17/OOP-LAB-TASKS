#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void encryptToFile(const string& filename, const string& text) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    
    string encrypted;
    for (size_t i = 0; i < text.size(); ++i) {
        char encryptedChar = text[i] + (i + 1);
        encrypted += encryptedChar;
    }
    
    outFile << encrypted;
    outFile.close();
    
    cout << "Encrypted text inserted in file" << endl;
    cout << encrypted << endl;
}

string decryptFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return "";
    }
    
    string encrypted;
    getline(inFile, encrypted);
    inFile.close();
    
    string decrypted;
    for (size_t i = 0; i < encrypted.size(); ++i) {
        char decryptedChar = encrypted[i] - (i + 1);
        decrypted += decryptedChar;
    }
    
    return decrypted;
}

int main() {
    string inputText;
    const string filename = "encrypted.txt";
    
    cout << "Enter String = ";
    getline(cin, inputText);
    
    cout << "Normal Text:= " << inputText << endl;
    
    encryptToFile(filename, inputText);

    string decryptedText = decryptFromFile(filename);
    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decryptedText << endl;
    
    return 0;
}