#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void displayMenu() {
    cout << "1. Write to file" << endl;
    cout << "2. Read from file" << endl;
    cout << "3. Exit" << endl;
}


void writeFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        string input;
        cout << "Enter text. Press Ctrl + Z (Windows) or Ctrl + D (Unix-like) to save and exit." << endl;
        cin.ignore();
        while (getline(cin, input)) {
            file << input << endl;
        }
        cout << "Text saved to " << filename << endl;
        file.close();
    } else {
        cerr << "Unable to open file " << filename << endl;
    }
}


void readFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "Contents of " << filename << ":" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file " << filename << endl;
    }
}


int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
