#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Account {
    string password;
    double balance = 0.0;
};

unordered_map<string, Account> accounts;

bool login(string& userId) {
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    string password;
    cin >> password;

    if (accounts.find(userId) != accounts.end() && accounts[userId].password == password) {
        cout << "Access Granted!" << endl;
        return true;
    } else {
        cout << "*** LOGIN FAILED! ***" << endl;
        return false;
    }
}

void createAccount() {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    if (accounts.find(userId) != accounts.end()) {
        cout << "User ID already exists!" << endl;
        return;
    }
    cout << "Please enter your password: ";
    cin >> password;

    accounts[userId] = Account{password, 0.0};
    cout << "Thank You! Your account has been created!" << endl;
}

void depositMoney(string userId) {
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;
    accounts[userId].balance += amount;
    cout << "Deposit successful!" << endl;
}

void withdrawMoney(string userId) {
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;
    if (amount > accounts[userId].balance) {
        cout << "Insufficient balance!" << endl;
    } else {
        accounts[userId].balance -= amount;
        cout << "Withdrawal successful!" << endl;
    }
}

void requestBalance(string userId) {
    cout << "Your balance is $" << accounts[userId].balance << "." << endl;
}

void mainMenu(string userId) {
    char option;
    do {
        cout << "d -> Deposit Money" << endl;
        cout << "w -> Withdraw Money" << endl;
        cout << "r -> Request Balance" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";
        cin >> option;

        switch (option) {
            case 'd':
                depositMoney(userId);
                break;
            case 'w':
                withdrawMoney(userId);
                break;
            case 'r':
                requestBalance(userId);
                break;
            case 'q':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    } while (option != 'q');
}

int main() {
    char option;

    cout << "Hi! Welcome to the ATM Machine!" << endl;

    do {
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";
        cin >> option;

        string userId;
        switch (option) {
            case 'l':
                if (login(userId)) {
                    mainMenu(userId);
                }
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                cout << "Thank you for using the ATM Machine. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    } while (option != 'q');

    return 0;
}

