#include <iostream>

#include "bank_account.h"

// Encapsulation - Hide internal details and expose only what's needed. Use private, protected, and public access specifiers.
//               - Use getters/setter to control what clients can access.


// Public - members declared public are accessible from anywhere in the program - inside the class, outside the class, and in derived classes.
//        - use when you want an API surface method that other classes/clients should be allowed to call.

// Protected - members declared protected are accessible from inside the class and derived classes. (Not accessible from outside the class)
//           - Use when you want child classes to have accesses but still want to hide the data from external code

// Private - members declared private are accessible only from inside the class. (Not accessible from outside the class or derived classes)

int main()
{
    BankAccount my_account;
    my_account.check_balance();
    my_account.deposit(2456.25);
    my_account.check_balance();

    double wallet{};
    my_account.withdraw(1000, wallet);
    std::cout << "My wallet: $" << wallet << "\n";
    my_account.check_balance();

    std::cout << my_account.withdraw(20000, wallet) << "\n";
    std::cout << "My wallet: $" << wallet << "\n";
    my_account.check_balance();


    return 0;
}