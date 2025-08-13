#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal) 
        : accountNumber(accNo), holderName(move(name)), balance(bal) {}

    int getAccountNumber() const { return accountNumber; }
    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful.\n";
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrawal successful.\n";
        return true;
    }

    void display() const {
        cout << left << setw(10) << accountNumber 
             << setw(20) << holderName 
             << fixed << setprecision(2) << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;
    const string fileName = "accounts.txt";

    void loadFromFile() {
        ifstream file(fileName);
        if (!file) return;
        
        accounts.clear();
        int accNo;
        string name;
        double bal;
        
        while (file >> accNo) {
            file.ignore();
            getline(file, name);
            file >> bal;
            accounts.emplace_back(accNo, name, bal);
        }
    }

    void saveToFile() {
        ofstream file(fileName);
        for (const auto &acc : accounts) {
            file << acc.getAccountNumber() << "\n"
                 << acc.getHolderName() << "\n"
                 << acc.getBalance() << "\n";
        }
    }

public:
    Bank() { loadFromFile(); }
    ~Bank() { saveToFile(); }

    void createAccount() {
        int accNo;
        string name;
        double initBal;

        cout << "Enter account number: ";
        cin >> accNo;
        cin.ignore();
        cout << "Enter holder name: ";
        getline(cin, name);
        cout << "Enter initial balance: ";
        cin >> initBal;

        accounts.emplace_back(accNo, name, initBal);
        cout << "Account created successfully.\n";
    }

    void depositMoney() {
        int accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                acc.deposit(amount);
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void withdrawMoney() {
        int accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                acc.withdraw(amount);
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void displayAccounts() const {
        cout << left << setw(10) << "Acc No" 
             << setw(20) << "Holder Name" 
             << "Balance" << endl;
        cout << string(40, '-') << endl;
        for (const auto &acc : accounts) {
            acc.display();
        }
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n=== Bank Management System ===\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display All Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.depositMoney(); break;
            case 3: bank.withdrawMoney(); break;
            case 4: bank.displayAccounts(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
