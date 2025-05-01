#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TaskManager {
    string filename;

    public:
        TaskManager(string file) : filename(file) {}

        void addTask(string task) {
            ofstream outFile(filename, ios::app);
            if (!outFile) {
                cerr << "Error opening task file.\n";
                return;
            }
            outFile << "[ ] " << task << endl;
            outFile.close();
        }

        void viewTasks() {
            ifstream inFile(filename);
            if (!inFile) {
                cerr << "Error opening task file.\n";
                return;
            }

            string line;
            int count = 1;
            while (getline(inFile, line)) {
                cout << count++ << ". " << line << endl;
            }
            inFile.close();
        }

        void markTaskDone(int taskNumber) {
            ifstream inFile(filename);
            if (!inFile) {
                cerr << "Error opening task file.\n";
                return;
            }

            vector<string> tasks;
            string line;
            while (getline(inFile, line)) {
                tasks.push_back(line);
            }
            inFile.close();

            if (taskNumber < 1 || taskNumber > tasks.size()) {
                cout << "Invalid task number.\n";
                return;
            }

            if (tasks[taskNumber - 1].find("[ ]") != string::npos) {
                tasks[taskNumber - 1].replace(0, 3, "[x]");
            }

            ofstream outFile(filename);
            for (const auto& task : tasks) {
                outFile << task << endl;
            }
            outFile.close();
        }
};

int main() {
    TaskManager manager("tasks.txt");

    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            cout << "Enter task: ";
            string task;
            getline(cin, task);
            manager.addTask(task);
        } else if (choice == 2) {
            manager.viewTasks();
        } else if (choice == 3) {
            cout << "Enter task number to mark as done: ";
            int num;
            cin >> num;
            manager.markTaskDone(num);
        }
    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}