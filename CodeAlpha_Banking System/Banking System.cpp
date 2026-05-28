#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string details;

    Transaction(string t, double a, string d) {
        type = t;
        amount = a;
        details = d;
    }

    void display() {
        cout << type << " of " << amount << " | " << details << endl;
    }
};

class Account {
private:
    double balance;
    vector<Transaction> history;

public:
    Account(double initialBalance = 0) {
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount, "Amount credited"));
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdrawal", amount, "Amount debited"));
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void transfer(Account &toAccount, double amount) {
        if (amount <= balance) {
            balance -= amount;
            toAccount.balance += amount;
            history.push_back(Transaction("Transfer", amount, "Sent to another account"));
            toAccount.history.push_back(Transaction("Transfer", amount, "Received from another account"));
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }

    void showHistory() {
        cout << "--- Transaction History ---\n";
        for (auto &t : history) {
            t.display();
        }
    }
};

class Customer {
public:
    string name;
    int id;
    Account account;

    Customer(string n, int i, double initialBalance = 0) : account(initialBalance) {
        name = n;
        id = i;
    }

    void displayInfo() {
        cout << "Customer ID: " << id << ", Name: " << name << endl;
        account.showBalance();
    }
};

int main() {
    int id1, id2;
    string name1, name2;
    double bal1, bal2;

    cout << "Enter Customer 1 ID: ";
    cin >> id1;
    cout << "Enter Customer 1 Name: ";
    cin >> name1;
    cout << "Enter Customer 1 Initial Balance: ";
    cin >> bal1;

    cout << "\nEnter Customer 2 ID: ";
    cin >> id2;
    cout << "Enter Customer 2 Name: ";
    cin >> name2;
    cout << "Enter Customer 2 Initial Balance: ";
    cin >> bal2;

    Customer c1(name1, id1, bal1);
    Customer c2(name2, id2, bal2);

    int choice;
    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Show Balance\n";
        cout << "5. Show Transactions\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        double amount;
        switch (choice) {
            case 1:
                cout << "Deposit into (1 for " << c1.name << ", 2 for " << c2.name << "): ";
                int dChoice; cin >> dChoice;
                cout << "Enter amount: "; cin >> amount;
                if (dChoice == 1) c1.account.deposit(amount);
                else c2.account.deposit(amount);
                break;

            case 2:
                cout << "Withdraw from (1 for " << c1.name << ", 2 for " << c2.name << "): ";
                int wChoice; cin >> wChoice;
                cout << "Enter amount: "; cin >> amount;
                if (wChoice == 1) c1.account.withdraw(amount);
                else c2.account.withdraw(amount);
                break;

            case 3:
                cout << "Transfer from (1 for " << c1.name << ", 2 for " << c2.name << "): ";
                int tChoice; cin >> tChoice;
                cout << "Enter amount: "; cin >> amount;
                if (tChoice == 1) c1.account.transfer(c2.account, amount);
                else c2.account.transfer(c1.account, amount);
                break;

            case 4:
                c1.displayInfo();
                c2.displayInfo();
                break;

            case 5:
                cout << "\nTransactions of " << c1.name << ":\n";
                c1.account.showHistory();
                cout << "\nTransactions of " << c2.name << ":\n";
                c2.account.showHistory();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}