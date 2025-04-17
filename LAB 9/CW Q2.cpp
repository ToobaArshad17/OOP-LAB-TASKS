#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Logger {
private:
    vector<string> logs;
    static const size_t MAX_LOGS = 1000;
    string formatLog(const string& severity, const string& message) {
        return "[" + severity + "] " + message;
    }
    void addLog(const string& formattedLog) {
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin()); 
        }
        logs.push_back(formattedLog);
    }

public:
    void logInfo(const string& message) {
        addLog(formatLog("INFO", message));
    }
    
    void logWarning(const string& message) {
        addLog(formatLog("WARN", message));
    }
    
    void logError(const string& message) {
        addLog(formatLog("ERROR", message));
    }
    
    vector<string> getLogs(bool isAuthenticated) const {
        if (!isAuthenticated) {
            throw runtime_error("Authentication required to access logs");
        }
        return logs; 
    }
};

void networkModule(Logger& logger) {
    logger.logInfo("Network connection established");
    logger.logWarning("High network latency detected");
}

void databaseModule(Logger& logger) {
    logger.logInfo("Database connection pool initialized");
    logger.logError("Failed to execute SQL query");
}

int main() {
    Logger systemLogger;
    
    networkModule(systemLogger);
    databaseModule(systemLogger);
    
    try {
        auto logs = systemLogger.getLogs(false);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    try {
        auto logs = systemLogger.getLogs(true);
        cout << "\nSystem Logs:\n";
        for (const auto& log : logs) {
            cout << log << endl;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}