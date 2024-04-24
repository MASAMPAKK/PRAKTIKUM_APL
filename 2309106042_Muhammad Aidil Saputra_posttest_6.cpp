#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::sort
#include <functional> // for std::greater
#include <limits> // for numeric_limits

using namespace std;

// Struct to store user address information
struct Address {
    string street;
    string city;
    string province;
};

// Struct to store user information
struct User {
    string name;
    string password;
    Address address; // Address is used inside the User struct
};

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add User\n";
    cout << "2. Display Users\n";
    cout << "3. Modify User Data\n";
    cout << "4. Delete User\n";
    cout << "5. Sort Users by Name (Descending Order)\n";
    cout << "6. Sort Users by Name Length (Ascending Order)\n";
    cout << "7. Sort Users by Password Length (Descending Order)\n";
    cout << "8. Search User by Name (Ascending Order)\n";
    cout << "9. Search User by Name (Descending Order)\n";
    cout << "10. Exit\n";
    cout << "Choose: ";
}

// Function to check if a user name already exists in the list
bool isUserNameExists(const vector<User>& users, const string& userName) {
    for (const User& user : users) {
        if (user.name == userName) {
            return true;
        }
    }
    return false;
}

// Function to add a new user
void addUser(vector<User>& users) {
    User newUser;
    cout << "\nEnter Name: ";
    getline(cin, newUser.name);
    while (newUser.name.empty() || isUserNameExists(users, newUser.name)) {
        if (newUser.name.empty()) {
            cout << "Name cannot be empty. Enter Name: ";
        } else {
            cout << "User with this name already exists. Please enter a different name.\n";
            cout << "Enter Name: ";
        }
        getline(cin, newUser.name);
    }
    
    cout << "Enter Password: ";
    getline(cin, newUser.password);
    while (newUser.password.empty()) {
        cout << "Password cannot be empty. Enter Password: ";
        getline(cin, newUser.password);
    }

    cout << "Enter Address (Street): ";
    getline(cin, newUser.address.street);
    while (newUser.address.street.empty()) {
        cout << "Address cannot be empty. Enter Address (Street): ";
        getline(cin, newUser.address.street);
    }

    cout << "Enter Address (City): ";
    getline(cin, newUser.address.city);
    while (newUser.address.city.empty()) {
        cout << "Address cannot be empty. Enter Address (City): ";
        getline(cin, newUser.address.city);
    }

    cout << "Enter Address (Province): ";
    getline(cin, newUser.address.province);
    while (newUser.address.province.empty()) {
        cout << "Address cannot be empty. Enter Address (Province): ";
        getline(cin, newUser.address.province);
    }

    users.push_back(newUser);
    cout << "User successfully added.\n";
}

// Function to display the list of users
void displayUsers(const vector<User>& users) {
    cout << "\nUser List:\n";
    for (const User& user : users) {
        cout << "Name: " << user.name << ", Password: " << user.password << endl;
        cout << "Address: " << user.address.street << ", " << user.address.city << ", " << user.address.province << endl;
    }
}

// Function to modify user data
void modifyUserData(vector<User>& users) {
    string userName;
    cout << "\nEnter the name of the user to modify: ";
    getline(cin, userName);

    auto it = find_if(users.begin(), users.end(), [&userName](const User& user) {
        return user.name == userName;
    });

    if (it != users.end()) {
        cout << "Enter new password: ";
        getline(cin, it->password);

        cout << "Enter new address (Street): ";
        getline(cin, it->address.street);

        cout << "Enter new address (City): ";
        getline(cin, it->address.city);

        cout << "Enter new address (Province): ";
        getline(cin, it->address.province);

        cout << "User data modified successfully.\n";
    } else {
        cout << "User not found.\n";
    }
}

// Function to delete user
void deleteUser(vector<User>& users) {
    string userName;
    cout << "\nEnter the name of the user to delete: ";
    getline(cin, userName);

    auto it = remove_if(users.begin(), users.end(), [&userName](const User& user) {
        return user.name == userName;
    });

    if (it != users.end()) {
        users.erase(it, users.end());
        cout << "User deleted successfully.\n";
    } else {
        cout << "User not found.\n";
    }
}

// Custom comparator function to sort users by name in descending order
bool compareByNameDescending(const User& u1, const User& u2) {
    return u1.name > u2.name;
}

// Custom comparator function to sort users by name length in ascending order
bool compareByNameLengthAscending(const User& u1, const User& u2) {
    return u1.name.length() < u2.name.length();
}

// Custom comparator function to sort users by password length in descending order
bool compareByPasswordLengthDescending(const User& u1, const User& u2) {
    return u1.password.length() > u2.password.length();
}

// Function to perform login
bool login() {
    string user, pass;
    int maxAttempts = 3;

    cout << "Welcome to the user account management program" << endl;

    for (int i = 1; i <= maxAttempts; i++) {
        cout << "Enter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;

        if (user == "aidil" && pass == "042") {
            cout << "Login successful" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            return true;
        } else {
            cout << "Incorrect username/password" << endl;
            if (i < maxAttempts) {
                cout << "You have " << maxAttempts - i << " attempts left" << endl;
            } else {
                cout << "You have exceeded the maximum number of attempts. Please try again later." << endl;
                return false;
            }
        }
    }
    return false;
}

// Binary search for ascending order
int binarySearchAscending(const vector<User>& users, const string& targetName) {
    int left = 0;
    int right = users.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (users[mid].name == targetName) {
            return mid;
        } else if (users[mid].name < targetName) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

// Function to search user by name (descending order)
int searchUserDescending(const vector<User>& users, const string& targetName) {
    for (int i = users.size() - 1; i >= 0; --i) {
        if (users[i].name == targetName) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    vector<User> userList;
    
    if (!login()) {
        return 1; // Exit the program if login fails
    }

    int choice;

    do {
        displayMenu();
        while (!(cin >> choice) || choice < 1 || choice > 10) {
            cout << "Invalid choice. Please enter a number between 1 and 10: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        switch (choice) {
            case 1:
                addUser(userList);
                break;
            case 2:
                displayUsers(userList);
                break;
            case 3:
                modifyUserData(userList);
                break;
            case 4:
                deleteUser(userList);
                break;
            case 5:
                sort(userList.begin(), userList.end(), compareByNameDescending);
                cout << "Users sorted by name in descending order.\n";
                break;
            case 6:
                sort(userList.begin(), userList.end(), compareByNameLengthAscending);
                cout << "Users sorted by name length in ascending order.\n";
                break;
            case 7:
                sort(userList.begin(), userList.end(), compareByPasswordLengthDescending);
                cout << "Users sorted by password length in descending order.\n";
                break;
            case 8: {
                // Sort users by name length in ascending order
                sort(userList.begin(), userList.end(), compareByNameLengthAscending);
                cout << "Users sorted by name length in ascending order:\n";
                displayUsers(userList);

                string name;
                cout << "Enter name to search: ";
                getline(cin, name);

                // Perform binary search on the sorted list
                int index = binarySearchAscending(userList, name);
                if (index != -1) {
                    cout << "User found at index " << index << endl;
                } else {
                    cout << "User not found.\n";
                }
                break;
            }
            case 9: {
                // Sort users by name in descending order
                sort(userList.begin(), userList.end(), compareByNameDescending);
                cout << "Users sorted by name in descending order:\n";
                displayUsers(userList);

                string name;
                cout << "Enter name to search: ";
                getline(cin, name);

                // Perform sequential search on the sorted list
                int index = searchUserDescending(userList, name);
                if (index != -1) {
                    cout << "User found at index " << index << endl;
                } else {
                    cout << "User not found.\n";
                }
                break;
            }
            case 10:
                cout << "Thank you! Exiting the program.\n";
                break;
        }
    } while (choice != 10);

    return 0;
}
