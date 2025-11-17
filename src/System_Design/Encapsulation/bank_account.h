#ifndef ENCAPSULATION_BANK_ACCOUNT_H
#define ENCAPSULATION_BANK_ACCOUNT_H
#include <iostream>

class BankAccount
{

public:
    BankAccount();
    BankAccount(const double& start_amount);

    // Getters/Setters used to manage the balance attribute through to keep user management controlled.
    void deposit(const double& amount);
    bool withdraw(const double& amount, double& wallet);

    void check_balance();

private:
    double balance_;
};


#endif //ENCAPSULATION_BANK_ACCOUNT_H