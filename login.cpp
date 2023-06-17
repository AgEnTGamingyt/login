#include <iostream>
#include <string>
#include <map>

using namespace std;

// User structure to hold user information
struct User {
    string username;
    string password;
};

// Map to store username-password pairs
map<string, string> users;

// Function to register a new user
void registerUser() {
    User newUser;
    cout << "Enter username: ";
    cin >> newUser.username;

    // Check if the username already exists
    if (users.count(newUser.username) > 0) {
        cout << "Username already exists. Please choose a different username." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> newUser.password;

    // Add the new user to the map
    users[newUser.username] = newUser.password;
    cout << "Registration successful!" << endl;
}

// Function to authenticate a user
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    // Check if the username exists in the map
    if (users.count(username) == 0) {
        cout << "Username not found." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Check if the entered password matches the stored password
    if (users[username] == password) {
        cout << "Login successful!" << endl;
    }
    else {
        cout << "Incorrect password." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Login and Registration System" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
