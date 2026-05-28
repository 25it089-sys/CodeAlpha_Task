#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct User {
    string username;
    string password;
};

vector<User> users;  // store credentials in memory

bool isUserExists(const string& username) {
    for (auto &u : users) {
        if (u.username == username) return true;
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    if (isUserExists(username)) {
        cout << "Error: Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    users.push_back({username, password});
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    bool success = false;
    for (auto &u : users) {
        if (u.username == username && u.password == password) {
            success = true;
            break;
        }
    }

    if (success)
        cout << "Login successful! Welcome, " << username << ".\n";
    else
        cout << "Error: Invalid username or password.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
