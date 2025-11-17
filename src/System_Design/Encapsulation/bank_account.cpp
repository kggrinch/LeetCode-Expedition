#include "bank_account.h"

BankAccount::BankAccount() : balance_(0)
{

}

BankAccount::BankAccount(const double& start_amount) : balance_(start_amount)
{

}

void BankAccount::deposit(const double& amount)
{
    balance_ += amount;
}

bool BankAccount::withdraw(const double& amount, double& wallet)
{
    if (amount > balance_) return false;

    wallet += amount;
    balance_ -= amount;
    return true;
}

void BankAccount::check_balance()
{
    std::cout << "Balance: $" << balance_ << "\n";
}