#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount(double initialBalance) {
        if (initialBalance < 0)
            throw invalid_argument("Initial balance cannot be negative.");
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount < 0)
            throw invalid_argument("Deposit amount cannot be negative.");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0)
            throw invalid_argument("Withdrawal amount cannot be negative.");
        if (amount > balance)
            throw runtime_error("Insufficient funds.");
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    try {
        BankAccount account(1000);  // Valid initial balance
        account.deposit(500);       // Valid deposit
        cout << "Balance after deposit: " << account.getBalance() << endl;

        account.withdraw(200);      // Valid withdrawal
        cout << "Balance after withdrawal: " << account.getBalance() << endl;

        account.withdraw(2000);     // This will throw exception
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
