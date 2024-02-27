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
