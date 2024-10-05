#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Account {
    int accountNumber;
    string username;
    string password;
    double balance;
};

// Function to create a new account
void createAccount(vector<Account>& accounts) {
    Account newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cin.ignore();
    cout << "Enter username: ";
    getline(cin, newAccount.username);
    cout << "Enter password: ";
    getline(cin, newAccount.password);
    newAccount.balance = 0;

    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

// Function to login to an existing account
Account* login(vector<Account>& accounts) {
    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    for (auto& account : accounts) {
        if (account.username == username && account.password == password) {
            return &account;
        }
    }

    cout << "Invalid username or password." << endl;
    return nullptr;
}

// Function to deposit money
void deposit(Account& account) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    account.balance += amount;
    cout << "Deposit successful. New balance: $" << account.balance << endl;
    cin.ignore();
}

// Function to withdraw money
void withdraw(Account& account) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > account.balance) {
        cout << "Insufficient funds." << endl;
    } else {
        account.balance -= amount;
        cout << "Withdrawal successful. New balance: $" << account.balance << endl;
    }
    cin.ignore();
}

// Function to check account balance
void checkBalance(const Account& account) {
    cout << "Current balance: $" << account.balance << endl;
}

// Function to display account menu
void accountMenu(vector<Account>& accounts) {
    Account* loggedAccount = login(accounts);
    if (loggedAccount) {
        while (true) {
            cout << "Account Menu" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Check Balance" << endl;
            cout << "4. Logout" << endl;
            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    deposit(*loggedAccount);
                    break;
                case 2:
                    withdraw(*loggedAccount);
                    break;
                case 3:
                    checkBalance(*loggedAccount);
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice." << endl;
            }
        }
    }
}

// Function to display main menu
void mainMenu(vector<Account>& accounts) {
    while (true) {
        cout << "Banking System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                accountMenu(accounts);
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}

int main() {
    vector<Account> accounts;
    mainMenu(accounts);
    return 0;
}
