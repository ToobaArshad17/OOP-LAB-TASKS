#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Logger {
    string baseFileName;
    int maxFileSize; // in bytes
    int logCount;

    string getCurrentLogFile() {
        return baseFileName + to_string(logCount) + ".txt";
    }

    void rotateLog() {
        logCount++;
    }

    public:
        Logger(string baseName, int maxSize) : baseFileName(baseName), maxFileSize(maxSize), logCount(1) {}

        void log(string message) {
            string currentFile = getCurrentLogFile();
            
            ofstream outFile(currentFile, ios::app);
            if (!outFile) {
                cerr << "Error opening log file.\n";
                return;
            }

            outFile << message << endl;
            outFile.close();

            if (fs::file_size(currentFile) > maxFileSize) {
                rotateLog();
            }
        }
};

int main() {
    Logger logger("log", 1024 * 1024); // 1MB

    for (int i = 1; i <= 5000; i++) {
        logger.log("This is log message number " + to_string(i));
    }

    cout << "Logging completed!\n";
    return 0;
}