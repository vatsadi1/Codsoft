#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

const string FILENAME = "todo_list.txt";

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete a task" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

void addTask() {
    ofstream file(FILENAME, ios::app);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    
    string task;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline left in the buffer
    cout << "Enter the task description: ";
    getline(cin, task);
    
    file << task << endl;
    file.close();
    
    cout << "Task added successfully." << endl;
}

void viewTasks() {
    ifstream file(FILENAME);
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    
    string task;
    int index = 1;
    while (getline(file, task)) {
        cout << index << ". " << task << endl;
        ++index;
    }
    file.close();
}

void deleteTask() {
    ifstream file(FILENAME);
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    
    vector<string> tasks;
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();
    
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }
    
    viewTasks();
    
    int taskNumber;
    cout << "Enter the number of the task to delete: ";
    cin >> taskNumber;
    
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    
    tasks.erase(tasks.begin() + (taskNumber - 1));
    
    ofstream outFile(FILENAME);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    
    for (const string& t : tasks) {
        outFile << t << endl;
    }
    outFile.close();
    
    cout << "Task deleted successfully." << endl;
}

int main() {
    int choice;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    }
    
    return 0;
}
